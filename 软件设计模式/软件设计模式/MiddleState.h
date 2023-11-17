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
		this->stateName = "高手";
	}
	void checkState(int score)
	{
		if (point >= 1000)
			acc->setState(new HighState(this));
		else if (point < 0)
		{
			cout << "余额不足" << endl;
			point += score;
		}
		else if (point <= 100)
			acc->setState(new PrimaryState(this));
	}
	void downloadFile(int score)
	{
		cout << acc->getName() << "下载文件，扣除" << score << "积分" << endl;
		point -= score;
		checkState(point);
		cout << "剩余积分为" << point << "当前级别为" << acc->getState()->getStateName() << endl;
	}
	void writeNote(int score)
	{
		cout << acc->getName() << "发布留言，增加" << score << "*2积分" << endl;
		point += score*2;
		checkState(point);
		cout << "剩余积分为:" << point << "当前级别为:" << acc->getState()->getStateName() << endl;
	}
};