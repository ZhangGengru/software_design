#include<string>
#include<iostream>
#include<list>
#include<memory>

using namespace std;

class War;
class State
{
public:
	virtual void CurrentState(War* war) = 0;
};
class War
{
public:
	War(State*state):state(state),day(0){}
	int GetDay() { return day; }
	void SetDay(int day) { this->day = day; }
	void SetState(State* state) { this->state = state; }
	void getState() { state->CurrentState(this); }

private:
	State* state;
	int day;
};
class EndState :public State
{
public:
	void End(War* war)
	{
		cout << "第" << war->GetDay() << "天，结束" << endl;
	}
	void CurrentState(War* war) { End(war); }
};
class AnaphaseState :public State
{
public:
	void Anaphase(War* war) //后期具体行为
	{
		if (war->GetDay() < 30)
			cout << "第" << war->GetDay() << "天，后期" << endl;
		else
		{
			war->SetState(new EndState());
			war->getState();
		}
	}
	void CurrentState(War* war) { Anaphase(war); }
};
class MetaphaseState :public State
{
public:
	void Metaphase(War* war) //中期具体行为
	{
		if (war->GetDay() < 20)
			cout << "第" << war->GetDay() << "天，中期" << endl;
		else
		{
			war->SetState(new AnaphaseState());
			war->getState();
		}
	}
	void CurrentState(War* war) { Metaphase(war); }
};
class ProphaseState :public State
{
public:
	void Prophase(War* war) //前期具体行为
	{
		if(war->GetDay()<10)
			cout<<"第"<<war->GetDay()<<"天，准备"<<endl;
		else
		{
		
			war->SetState(new MetaphaseState());
			war->getState();
		}
	}
	void CurrentState(War* war) { Prophase(war); }
};
int main()
{
	War* war = new War(new ProphaseState());
	for (int i = 0; i < 40; i++)
	{
		war->SetDay(i);
		war->getState();
	}
	return 0;
}