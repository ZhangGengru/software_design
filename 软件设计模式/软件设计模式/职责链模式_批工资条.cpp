#include<string>
#include<iostream>

using namespace std;

//���������
class Manager
{
public:
	Manager(Manager* manager, string name) :m_manager(manager), m_name(name){}
	virtual void DealWithRequest(string name,int num){}
protected:
	Manager* m_manager;//�ϼ�
	string m_name;
};
//����
class CommonManger :public Manager
{
public:
	CommonManger(Manager* manager, string name):Manager(manager,name){}
	void DealWithRequest(string name, int num)
	{
		if (num < 500)
		{
			cout << "����" << m_name << "��׼" << name << "��н" << num << endl;
		}
		else
		{
			cout << "����" << name << "�޷����������ܼദ��" << endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};
//�ܼ�
class Majordomo :public Manager
{
public:
	Majordomo(Manager* manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)
	{
		if (num < 1000)
		{
			cout << "�ܼ�" << m_name << "��׼" << name << "��н" << num << endl;
		}
		else
		{
			cout << "�ܼ�" << name << "�޷����������ܾ�����" << endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};
//�ܾ���
class GeneralManger :public Manager
{
public:
	GeneralManger(Manager* manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)
	{
		cout << "�ܾ���" << m_name << "��׼" << name << "��н" << num << endl;
	}
};
int main()
{
	Manager* general = new GeneralManger(nullptr, "A");//�ܾ���û���ϼ�
	Manager* majordomo = new Majordomo(general, "B");
	Manager* common = new CommonManger(majordomo, "C");
	common->DealWithRequest("D", 300);
	common->DealWithRequest("E", 600);
	common->DealWithRequest("F", 1000);
	delete general, majordomo, common;
	return 0;
}