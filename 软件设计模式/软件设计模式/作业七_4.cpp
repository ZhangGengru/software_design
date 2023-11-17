#include<string>
#include<iostream>
#include<list>

using namespace std;

class WuYe;
class Observer
{
public:
	virtual void Update(WuYe* wuye) = 0;	
	void AddWuye(WuYe*wuye) { WuYelist.push_back(wuye); }
protected:
	list<WuYe*> WuYelist;
};
class WuYe
{
public:
	WuYe(Observer* man,string sta = "未售出") :manager(man),status(sta) {}
	virtual void SetStatus() = 0;
	virtual string GetStatus() { return status; }
	void Notify()
	{
		manager->Update(this);
	}
private:
	Observer* manager;
protected:
	string status;
};
class GongYu :public WuYe
{
public:
	GongYu(Observer* man):WuYe(man){}
	virtual void SetStatus() { status = "公寓售出"; }
	virtual string GetStatus() { return status; }
};
class ShangPu :public WuYe
{
public:
	ShangPu(Observer* man) :WuYe(man) {}
	virtual void SetStatus() { status = "商铺售出"; }
	virtual string GetStatus() { return status; }
};
class Manager :public Observer
{
public:
	Manager(string name ):name(name){}
	virtual void Update(WuYe* wuye)
	{
		cout << wuye->GetStatus() << endl;
	}
private:
	string name;
};

int main()
{
	Observer* manager = new Manager("ZGR");
	WuYe* Shangpu = new ShangPu(manager);
	WuYe* Gongyu = new GongYu(manager);
	manager->AddWuye(Shangpu);
	manager->AddWuye(Gongyu);
	Shangpu->SetStatus();
	Shangpu->Notify();
	Gongyu->SetStatus();
	Gongyu->Notify();
}