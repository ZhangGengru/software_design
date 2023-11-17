#include<string>
#include<iostream>

using namespace std;

class TemperatureSystem;
class State
{
public:
	virtual void setTemperatue(TemperatureSystem* system,int temp) = 0;
	virtual void turnOff(TemperatureSystem* system) = 0;
	virtual void turnOn(TemperatureSystem* system) = 0;
};
class OffState :public State
{
public:
	virtual void setTemperatue(TemperatureSystem* system,int temp);
	virtual void turnOff(TemperatureSystem* system);
	virtual void turnOn(TemperatureSystem* system);
};
class OnState :public State
{
public:
	virtual void setTemperatue(TemperatureSystem* system, int temp);
	virtual void turnOff(TemperatureSystem* system);
	virtual void turnOn(TemperatureSystem* system);
};
class TemperatureSystem
{
	friend class OffState;
	friend class OnState;
public:
	TemperatureSystem()
	{
		offstate = new OffState();
		onstate = new OnState();
		currentstate = offstate;
	}
	void setTemperature(int temp)
	{
		currentstate->setTemperatue(this, temp);
	}
	void turnOff()
	{
		currentstate->turnOff(this);
	}
	void turnOn()
	{
		currentstate->turnOn(this);
	}
	void setState(State* state)
	{
		currentstate = state;
	}
private:
	int Temperature;
	State* offstate;
	State* onstate;
	State* currentstate;
};

void OffState::setTemperatue(TemperatureSystem* system, int temp)
{
	cout << "ϵͳδ����" << endl;
}
void OffState::turnOff(TemperatureSystem* system)
{
	cout << "ϵͳδ����" << endl;
}
void OffState::turnOn(TemperatureSystem* system)
{
	system->setState(system->onstate);
}
void OnState::setTemperatue(TemperatureSystem* system, int temp)
{
	system->Temperature = temp;
	cout << "��ǰ�¶�Ϊ��" << system->Temperature << endl;
	if (system->Temperature > 20)
	{
		cout << "�¶ȹ���,����20" << endl;
		this->setTemperatue(system, 20);
	}
	else if (system->Temperature < 10)
	{
		cout << "�¶ȹ��ͣ�����10" << endl;
		this->setTemperatue(system, 10);
	}
	else
	{
		cout << "�¶�����" << endl;
	}
}
void OnState::turnOn(TemperatureSystem* system)
{
	cout << "ϵͳ�ѿ���" << endl;
}
void OnState::turnOff(TemperatureSystem* system)
{
	system->setState(system->offstate);
}