#include<string>
#include<iostream>

using namespace std;

//抽象管理者
class Manager
{
public:
	Manager(Manager* manager, string name) :m_manager(manager), m_name(name){}
	virtual void DealWithRequest(string name,int num){}
protected:
	Manager* m_manager;//上级
	string m_name;
};
//经理
class CommonManger :public Manager
{
public:
	CommonManger(Manager* manager, string name):Manager(manager,name){}
	void DealWithRequest(string name, int num)
	{
		if (num < 500)
		{
			cout << "经理" << m_name << "批准" << name << "加薪" << num << endl;
		}
		else
		{
			cout << "经理" << name << "无法处理，交给总监处理" << endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};
//总监
class Majordomo :public Manager
{
public:
	Majordomo(Manager* manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)
	{
		if (num < 1000)
		{
			cout << "总监" << m_name << "批准" << name << "加薪" << num << endl;
		}
		else
		{
			cout << "总监" << name << "无法处理，交给总经理处理" << endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};
//总经理
class GeneralManger :public Manager
{
public:
	GeneralManger(Manager* manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)
	{
		cout << "总经理" << m_name << "批准" << name << "加薪" << num << endl;
	}
};
int main()
{
	Manager* general = new GeneralManger(nullptr, "A");//总经理没有上级
	Manager* majordomo = new Majordomo(general, "B");
	Manager* common = new CommonManger(majordomo, "C");
	common->DealWithRequest("D", 300);
	common->DealWithRequest("E", 600);
	common->DealWithRequest("F", 1000);
	delete general, majordomo, common;
	return 0;
}