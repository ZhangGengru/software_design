#include<string>
#include<iostream>

using namespace std;

class AlarmSystem;
class State
{
public:
	virtual void CurrentTreState(AlarmSystem* as) = 0;
	virtual void CurrentTelState(AlarmSystem* as) = 0;
	void Alarm() { cout << "����" << endl; }
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
		cout << "��ǰʱ�䣺" << as->getTime() << "���ϲ���ʹ�ý��" << endl;
		cout << "�򾯱����ķ��ͽ�����̬" << endl;
	}
	virtual void CurrentTelState(AlarmSystem* as)
	{
		cout << "��ǰʱ�䣺" << as->getTime() << "���б����������Ե绰" << endl;
	}
};
class dayState :public State
{
	virtual void CurrentTreState(AlarmSystem* as)
	{
		if (as->getTime() > 9&&as->getTime()<15)
		{
			cout << "��ǰʱ�䣺" << as->getTime() << "ʹ�ý��" << endl;
			cout << "�ڱ����������¼�¼" << endl;
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
			cout << "��ǰʱ�䣺" << as->getTime() << "ʹ�õ绰" << endl;
			cout << "���б�������" << endl;
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
			cout << "��ǰʱ�䣺" << as->getTime() << endl;
			cout<< "���ϲ���ʹ�ý��" << endl;
			cout << "�򾯱����ķ��ͽ�����̬" << endl;
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
			cout << "��ǰʱ�䣺" << as->getTime() << endl;
			cout<<"���б����������Ե绰" << endl;
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