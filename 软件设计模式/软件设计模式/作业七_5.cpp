#include<string>
#include<iostream>
#include<list>

using namespace std;

class Observer
{
public:
	virtual void Update() = 0;
};
class AbFireDetector
{
public:
	void Attach(Observer* Device) { DeviceList.push_back(Device); }
	void Remove(Observer* Device) { DeviceList.remove(Device); }
	void Notify()
	{
		for (auto iter = DeviceList.begin(); iter != DeviceList.end(); iter++)
		{
			(*iter)->Update();
		}
	}
	virtual void setStatus() {};
private:
	list<Observer*> DeviceList;
protected:
	string status;
};
class FireDetector :public AbFireDetector
{
public:
	virtual void setStatus()
	{
		status = "发生火灾"; 
		cout << status << endl;
		Notify();
		
	};
};
class WarningLight :public Observer
{
public:
	virtual void Update() { flicker(); }
	void flicker() { cout << "警示灯闪烁" << endl; }
};
class Alarm :public Observer
{
public:
	virtual void Update() { alarm(); }
	void alarm() { cout << "报警器发出警报" << endl; }
};
class SecurityDoor :public Observer
{
	virtual void Update() { open(); }
	void open() { cout << "安全逃生门开启" << endl; }
};
class InsulateDoor :public Observer
{
public:
	virtual void Update() { close(); }
	void close() { cout << "隔离门自动关闭" << endl; }
};
int main()
{
	AbFireDetector* firedetector = new FireDetector();
	Observer* warnlight = new WarningLight();
	Observer* alarm = new Alarm();
	Observer* securitydoor = new SecurityDoor();
	Observer* insulateddoor = new InsulateDoor();
	firedetector->Attach(warnlight);
	firedetector->Attach(alarm);
	firedetector->Attach(securitydoor);
	firedetector->Attach(insulateddoor);
	firedetector->setStatus();
	return 0;

}