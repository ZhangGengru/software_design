#pragma once
#include<string>
#include<iostream>
#include"AbstractState.h"
#include"MiddleState.h"
#include"PrimaryState.h"

using namespace std;

class HighState:public AbstractState
{
public:
	HighState(AbstractState* state)
	{
		this->acc = state->getAAccount();
		this->point = state->getPoint();
		this->stateName = "ר��";
	}
	void checkState(int score)
	{
		if (point < 0)
		{
			cout << "���㣬����ʧ��" << endl;
			point += score;
		}
		else if (point <= 100)
		{
			this->acc->setState(new PrimaryState(this));
		}
		else if (point <= 1000)
		{
			acc->setState(new MiddleState(this));
		}
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
		point += score * 2;
		checkState(point);
		cout << "ʣ�����Ϊ:" << point << "��ǰ����Ϊ:" << acc->getState()->getStateName() << endl;
	}
};