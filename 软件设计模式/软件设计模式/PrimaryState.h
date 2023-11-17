#pragma once
#include<string>
#include<iostream>
#include"AbstractState.h"
#include"MiddleState.h"
#include"HighState.h"


using namespace std;
class PrimaryState :public AbstractState
{
public:
	PrimaryState(AbstractState* state)
	{
		this->acc = state->getAAccount();
		this->point = state->getPoint();
		this->stateName = "����";
	}
	PrimaryState(FormAccount* acc)
	{
		this->acc = acc;
		this->point = 0;
		this->stateName = "����";
	}
	void downloadFile(int score) { cout << "�Բ���" << acc->getName() << "û������Ȩ��" << endl; }
	void writeNote(int score)
	{
		cout << acc->getName() << "�������ԣ�����" << score << "����" << endl;
		point += score;
		checkState(point);
		cout << "ʣ�����Ϊ:" << point << "��ǰ����Ϊ:" << acc->getState()->getStateName() << endl;
	}
	void checkState(int score)
	{
		if (score >= 1000)
		{
			acc->setState(new HighState(this));
		}
		else if (score >= 100)
		{
			acc->setState(new MiddleState(this));
		}
	}
};