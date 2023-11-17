#pragma once
#include<string>
#include<iostream>
#include"AbstractState.h"
#include"HighState.h"

using namespace std;

class MiddleState :public AbstractState
{
public:
	MiddleState(AbstractState* state)
	{
		this->acc = state->getAAccount();
		this->point = state->getPoint();
		this->stateName = "����";
	}
	void checkState(int score)
	{
		if (point >= 1000)
			acc->setState(new HighState(this));
		else if (point < 0)
		{
			cout << "����" << endl;
			point += score;
		}
		else if (point <= 100)
			acc->setState(new PrimaryState(this));
	}
	void downloadFile(int score)
	{
		cout << acc->getName() << "�����ļ����۳�" << score << "����" << endl;
		point -= score;
		checkState(point);
		cout << "ʣ�����Ϊ" << point << "��ǰ����Ϊ" << acc->getState()->getStateName() << endl;
	}
	void writeNote(int score)
	{
		cout << acc->getName() << "�������ԣ�����" << score << "*2����" << endl;
		point += score*2;
		checkState(point);
		cout << "ʣ�����Ϊ:" << point << "��ǰ����Ϊ:" << acc->getState()->getStateName() << endl;
	}
};