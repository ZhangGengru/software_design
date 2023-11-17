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
		this->stateName = "专家";
	}
	void checkState(int score)
	{
		if (point < 0)
		{
			cout << "余额不足，下载失败" << endl;
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
		cout << acc->getName() << "下载文件，扣除" << score << "积分" << endl;
		point -= score;
		checkState(point);
		cout << "剩余积分为" << point << "当前级别为" << acc->getState()->getStateName() << endl;
	}
	void writeNote(int score)
	{
		cout << acc->getName() << "发布留言，增加" << score << "*2积分" << endl;
		point += score * 2;
		checkState(point);
		cout << "剩余积分为:" << point << "当前级别为:" << acc->getState()->getStateName() << endl;
	}
};