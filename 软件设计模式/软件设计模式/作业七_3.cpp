#include<list>
#include<string>
#include<iostream>

using namespace std;

class CallButton;
class Observer
{
public:
	virtual void Update() = 0;
	void setRoom(CallButton* callbutton)
	{
		CallButtonlist.push_back(callbutton);
	}
protected:
	list<CallButton*> CallButtonlist;
};
class CallButton
{
public:
	CallButton(int num):num(num){}
	void Attach(Observer* observer) { observers.push_back(observer); }
	void Remove(Observer* observer) { observers.remove(observer); }
	void Notify()
	{
		for (auto iter = observers.begin(); iter != observers.end(); iter++)
			(*iter)->Update();
	}
	virtual void SetStatus() = 0;
	virtual string GetStatus() { return status; }
	int getNum() { return num; }
private:
	list<Observer*>observers;
protected:
	string status;
	int num;
};
class RoomCallButton :public CallButton
{
public:
	RoomCallButton(int num):CallButton(num){}
	virtual void SetStatus() { status = "房间" + to_string(num) + "警报"; }

};
class Observer1 :public Observer
{
public:
	Observer1(string name) :name(name){}
	void Update()
	{
		for (auto iter = CallButtonlist.begin(); iter != CallButtonlist.end(); iter++)
		{
			string status = (*iter)->GetStatus();
			cout << name << " " << status << endl;
		}
	}
private:
	
	string name;
};
class Observer2 :public Observer
{
public:
	Observer2(string name) :name(name) {}
	void setRoom(CallButton* callbutton)
	{
		CallButtonlist.push_back(callbutton);
	}
	void Update()
	{
		for (auto iter = CallButtonlist.begin(); iter != CallButtonlist.end(); iter++)
		{
			string status = (*iter)->GetStatus();
			cout << name << " " << status << endl;
		}
	}
private:
	string name;
};

int main()
{
	CallButton* room1 = new RoomCallButton(1);
	//CallButton* room2 = new RoomCallButton(2);

	Observer* observer1 = new Observer1("语音播报器"); 
	Observer* observer2 = new Observer2("显示应答器");

	room1->Attach(observer1);
	room1->Attach(observer2);
	observer1->setRoom(room1);
	observer2->setRoom(room1);
	room1->SetStatus();
	room1->Notify();
}