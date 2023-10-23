#include<string>
#include<iostream>
#include<list>
#include<memory>

using namespace std;

class Company
{
public:
	Company(string name) { m_name = name; }
	virtual ~Company(){}
	virtual void Add(shared_ptr<Company> pCom) {};
	virtual void Show(int depth) {};
protected:
	string m_name;
};
//具体公司
class ConcreteCompany :public Company
{
public:
	ConcreteCompany(string name) :Company(name) {}
	virtual ~ConcreteCompany() {};
	void Add(shared_ptr<Company> pCom) { m_listCompany.push_back(pCom); }
	void Show(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name;
		auto iter = m_listCompany.begin();
		for (iter; iter != m_listCompany.end(); iter++)
			(*iter)->Show(depth + 2);
	}
private:
	list<shared_ptr<Company>> m_listCompany;
};
//具体的部分，财务部
class FinanceDepartment :public Company
{
public:
	FinanceDepartment(string name):Company(name){}
	virtual ~FinanceDepartment() {};
	virtual void Show(int depth)//已经是叶子节点，无需添加
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
	}
};
//具体的部门，人力资源部
class HRDepartment :public Company
{
public:
	HRDepartment(string name) :Company(name) {}
	virtual ~HRDepartment() {};
	virtual void Show(int depth)//已经是叶子节点，无需添加
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
	}
};
int main()
{
	shared_ptr<Company> root = make_shared<ConcreteCompany>("总公司");
	shared_ptr<Company> leaf1 = make_shared<FinanceDepartment>("财务部");
	shared_ptr<Company> leaf2 = make_shared<HRDepartment>("人力资源部");
	root->Add(leaf1);
	root->Add(leaf2);

	//分公司A
	shared_ptr<Company> mid1 = make_shared<ConcreteCompany>("分公司A");
	shared_ptr<Company> leaf3 = make_shared<FinanceDepartment>("财务部");
	shared_ptr<Company> leaf4 = make_shared<HRDepartment>("人力资源部");
	mid1->Add(leaf3);
	mid1->Add(leaf4);

	//分公司B	
	shared_ptr<Company> mid2 = make_shared<ConcreteCompany>("分公司B");
	shared_ptr<Company> leaf5 = make_shared<FinanceDepartment>("财务部");
	shared_ptr<Company> leaf6 = make_shared<HRDepartment>("人力资源部");
	mid2->Add(leaf5);
	mid2->Add(leaf6);
	root->Add(mid1);
	root->Add(mid2);	
	root->Show(0);

}