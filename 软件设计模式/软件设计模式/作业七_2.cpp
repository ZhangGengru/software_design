#include<string>
#include<iostream>

using namespace std;

//������ߣ���ʦ
class Chef
{
public:
	void cook(string name)
	{
		cout << "��ʦ��" << name << endl;
	}
};
//��������ࣺ���
class Commend
{
public:
	Commend(Chef* chef) :c_chef(chef){}
	virtual void excute() = 0;
protected:
	Chef* c_chef;
};
//����������
class BeefCmd :public Commend
{
public:
	BeefCmd(Chef* chef):Commend(chef){}
	void excute()
	{
		c_chef->cook("�ཷ��ţ��");
	}
};
class PotatoCmd :public Commend
{
public:
	PotatoCmd(Chef* chef) :Commend(chef) {}
	void excute()
	{
		c_chef->cook("�ཷ������");
	}
};
//��������ߣ�����Ա
class Waiter
{
public:
	void RecieveCmd(Commend* cmd)
	{
		this->cmd = cmd;
	}
	void DealCmd()
	{
		cmd->excute();
	}
private:
	Commend* cmd;
};
int main()
{
	Waiter* waiter = new Waiter;
	Chef* chef = new Chef;

	Commend* beef = new BeefCmd(chef);
	Commend* potato = new PotatoCmd(chef);

	waiter->RecieveCmd(beef);
	waiter->DealCmd();

	waiter->RecieveCmd(potato);
	waiter->DealCmd();
	return 0;
}