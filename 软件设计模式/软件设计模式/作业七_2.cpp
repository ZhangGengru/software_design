#include<string>
#include<iostream>

using namespace std;

//命令处理者：厨师
class Chef
{
public:
	void cook(string name)
	{
		cout << "厨师做" << name << endl;
	}
};
//命令抽象类：点菜
class Commend
{
public:
	Commend(Chef* chef) :c_chef(chef){}
	virtual void excute() = 0;
protected:
	Chef* c_chef;
};
//具体命令类
class BeefCmd :public Commend
{
public:
	BeefCmd(Chef* chef):Commend(chef){}
	void excute()
	{
		c_chef->cook("青椒炒牛肉");
	}
};
class PotatoCmd :public Commend
{
public:
	PotatoCmd(Chef* chef) :Commend(chef) {}
	void excute()
	{
		c_chef->cook("青椒炒土豆");
	}
};
//命令接收者：服务员
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