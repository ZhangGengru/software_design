#include<iostream>
#include<string>
using namespace std;

class Manager
{
public:
	Manager(Manager* manager, string name) :manager(manager), name(name) {}
	virtual void DealWithRequest(int num) = 0;
protected:
	Manager* manager;
	string name;
};
class KeZhang :public Manager
{
public:
	KeZhang(Manager* manager, string name) :Manager(manager, name) {}
	virtual void DealWithRequest(int num)
	{
		if (num < 10000)
		{
			cout<<"科长"<<this->name<<"批准了"<<num<<"元的差旅费"<<endl;
		}
		else
		{
			cout<<"科长无法批准"<<num<<"元的差旅费，交给处长"<<endl;
			manager->DealWithRequest(num);
		}
	}
};
class ChuZhang :public Manager
{
public:
	ChuZhang(Manager* manager, string name) :Manager(manager, name) {}
	virtual void DealWithRequest(int num)
	{
		if (num < 50000)
		{
			cout<<"处长"<<this->name<<"批准了"<<num<<"元的差旅费"<<endl;
		}
		else
		{
			cout<<"处长无法批准"<<num<<"元的差旅费，交给副校长"<<endl;
			manager->DealWithRequest(num);
		}
	}
};
class FuXiaoZhang :public Manager
{
public:
	FuXiaoZhang(Manager* manager, string name) :Manager(manager, name) {}
	virtual void DealWithRequest(int num)
	{
		if (num < 100000)
		{
			cout<<"副校长"<<this->name<<"批准了"<<num<<"元的差旅费"<<endl;
		}
		else
		{
			cout<<"副校长无法批准"<<num<<"元的差旅费，交给校长"<<endl;
			manager->DealWithRequest(num);
		}
	}
};
class XiaoZhang :public Manager
{
public:
	XiaoZhang(Manager* manager, string name) :Manager(manager, name) {}
	virtual void DealWithRequest(int num)
	{
		cout<<"校长"<<this->name<<"批准了"<<num<<"元的差旅费"<<endl;
	}
};
int main()
{
	Manager* xiaozhang = new XiaoZhang(NULL, "张三");
	Manager* fuxiaozhang = new FuXiaoZhang(xiaozhang, "李四");
	Manager* chuzhang = new ChuZhang(fuxiaozhang, "王五");
	Manager* kezhang = new KeZhang(chuzhang, "赵六");
	kezhang->DealWithRequest(1000);
	kezhang->DealWithRequest(10000);
	kezhang->DealWithRequest(100000);
	kezhang->DealWithRequest(1000000);
}
