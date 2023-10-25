#include<iostream>
#include<string>
#include<list>
#include<memory>
#include<vector>
using namespace std;

class Employee
{
public:
	virtual void cal_bonus(){}
	virtual double get_sale() { return 0.0; }
	virtual double get_teamsale() {return 0.0; }
	virtual double get_reward() { return 0.0; }
	virtual string get_kind() { return ""; }
	virtual void set_bouns(double bouns) { }
private:
	string name;
	string kind;
	double sale;
	double bouns = 0;
};
class CommonEmployee :public Employee
{
public:
	CommonEmployee(double sale,double reward):sale(sale),reward(reward) {}
	double get_sale() { return sale; }
	virtual void set_bouns(double bouns) { this->bouns += bouns; }
	double get_reward() { return reward; }
	virtual string get_kind() { return kind; }
private:
	string kind = "普通员工";
	double sale;
	double reward;
	double bouns = 0;
};
class Manager :public Employee
{
public:
	Manager(double sale, double reward) :sale(sale), reward(reward)
	{
		int sum = 0;
		for (auto iter : m_list)
			sum += iter->get_sale();
		teamSale = sum;
	}
	double get_sale() { return sale;}
	double get_teamsale() { return teamSale; }
	virtual void set_bouns(double bouns) { this->bouns += bouns; }
	virtual double get_reward() { return 0.0; }
	virtual string get_kind() { return kind; }
	void set_list(shared_ptr<Employee> employee)
	{
		m_list.push_back(employee);
	}
private:
string kind = "经理";
	double sale;
	double reward;
	double teamSale;
	double bouns = 0;
	vector<shared_ptr<Employee>> m_list;//下属员工
};
class Bouns :public Employee
{
public:
	Bouns(shared_ptr<Employee> employee) :m_employee(employee) {}
	virtual void cal_bonus() {};
protected:
	shared_ptr<Employee> m_employee;
};
class PersonalBonus :public Bouns
{
public:
	PersonalBonus(shared_ptr<Employee> employee) :Bouns(employee) {}
	void cal_bonus()
	{
		double sale = m_employee->get_sale();
		m_employee->set_bouns(sale*0.03);
	}
};
class PersonalReward :public Bouns
{
public:
	PersonalReward(shared_ptr<Employee> employee) :Bouns(employee) {}
	void cal_bonus()
	{
		double reward = m_employee->get_reward();
		m_employee->set_bouns(reward * 0.001);
	}
};
class TeamBonus :public Bouns
{
public:
	TeamBonus(shared_ptr<Employee> employee) :Bouns(employee) {}
void cal_bonus()
	{
	if (m_employee->get_kind() != "经理")
	{
		cout<<"你没有团队奖金"<<endl;
		return;
	}
		double teamsale = m_employee->get_teamsale();
		m_employee->set_bouns(teamsale * 0.01);
	}
};

int main()
{
	shared_ptr<Employee> employee1 = make_shared<CommonEmployee>(10000, 1000);
	shared_ptr<Employee> employee2 = make_shared<CommonEmployee>(20000, 2000);
	shared_ptr<Manager> Manager1 = make_shared<Manager>(30000, 3000);
	Manager1->set_list(employee1);
	Manager1->set_list(employee2);
	shared_ptr<Bouns> bouns1 = make_shared<PersonalBonus>(employee1);
	shared_ptr<Bouns> bouns2 = make_shared<PersonalReward>(employee1);
	shared_ptr<Bouns> bouns3 = make_shared<TeamBonus>(Manager1);
}