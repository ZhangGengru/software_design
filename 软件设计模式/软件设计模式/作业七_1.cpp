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
			cout<<"�Ƴ�"<<this->name<<"��׼��"<<num<<"Ԫ�Ĳ��÷�"<<endl;
		}
		else
		{
			cout<<"�Ƴ��޷���׼"<<num<<"Ԫ�Ĳ��÷ѣ���������"<<endl;
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
			cout<<"����"<<this->name<<"��׼��"<<num<<"Ԫ�Ĳ��÷�"<<endl;
		}
		else
		{
			cout<<"�����޷���׼"<<num<<"Ԫ�Ĳ��÷ѣ�������У��"<<endl;
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
			cout<<"��У��"<<this->name<<"��׼��"<<num<<"Ԫ�Ĳ��÷�"<<endl;
		}
		else
		{
			cout<<"��У���޷���׼"<<num<<"Ԫ�Ĳ��÷ѣ�����У��"<<endl;
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
		cout<<"У��"<<this->name<<"��׼��"<<num<<"Ԫ�Ĳ��÷�"<<endl;
	}
};
int main()
{
	Manager* xiaozhang = new XiaoZhang(NULL, "����");
	Manager* fuxiaozhang = new FuXiaoZhang(xiaozhang, "����");
	Manager* chuzhang = new ChuZhang(fuxiaozhang, "����");
	Manager* kezhang = new KeZhang(chuzhang, "����");
	kezhang->DealWithRequest(1000);
	kezhang->DealWithRequest(10000);
	kezhang->DealWithRequest(100000);
	kezhang->DealWithRequest(1000000);
}
