#include<string>
#include<iostream>

using namespace std;

class AlarmSystem;
class State
{
public:
	virtual void CurrentTreState(AlarmSystem* as) = 0;
	virtual void CurrentTelState(AlarmSystem* as) = 0;
	void Alarm() { cout << "报警" << endl; }
};
class AlarmSystem
{
public:
	AlarmSystem(State* st) :state(st){}
	void setTime(int t) { time = t; }
	int getTime() { return time; }
	void setState(State* state) { this->state = state; }
	State* getState() { return state; }
	void useTre() { state->CurrentTreState(this); }
	void useTel() { state->CurrentTelState(this); }
	void useAlarm() { state->Alarm(); }
private:
	int time;
	State* state;
};
class night2State :public State
{
	virtual void CurrentTreState(AlarmSystem* as)
	{
		cout << "当前时间：" << as->getTime() << "晚上不能使用金库" << endl;
		cout << "向警报中心发送紧急事态" << endl;
	}
	virtual void CurrentTelState(AlarmSystem* as)
	{
		cout << "当前时间：" << as->getTime() << "呼叫报警中心留言电话" << endl;
	}
};
class dayState :public State
{
	virtual void CurrentTreState(AlarmSystem* as)
	{
		if (as->getTime() > 9&&as->getTime()<15)
		{
			cout << "当前时间：" << as->getTime() << "使用金库" << endl;
			cout << "在报警中心留下记录" << endl;
		}
		else
		{
			as->setState(new night2State());
			as->useTre();
		}
	}
	virtual void CurrentTelState(AlarmSystem* as) 
	{
		if (as->getTime() > 9 && as->getTime() < 15)
		{
			cout << "当前时间：" << as->getTime() << "使用电话" << endl;
			cout << "呼叫报警中心" << endl;
		}
		else
		{
			as->setState(new night2State());
			as->useTel();
		}
	}
};
class night1State :public State
{
	virtual void CurrentTreState(AlarmSystem* as)
	{
		if (as->getTime() < 9)
		{
			cout << "当前时间：" << as->getTime() << endl;
			cout<< "晚上不能使用金库" << endl;
			cout << "向警报中心发送紧急事态" << endl;
		}
		else
		{
			as->setState(new dayState());
			as->useTre();
		}
	}
	virtual void CurrentTelState(AlarmSystem* as)
	{
		if (as->getTime() < 9)
		{
			cout << "当前时间：" << as->getTime() << endl;
			cout<<"呼叫报警中心留言电话" << endl;
		}
		else
		{
			as->setState(new dayState());
			as->useTel();
		}
	}
};
int main()
{
	AlarmSystem* als = new AlarmSystem(new night1State());
	for (int i = 0; i < 23; i+=5)
	{
		als->setTime(i);
		als->useTre();
		als->useTel();
		als->useAlarm();
	}
}