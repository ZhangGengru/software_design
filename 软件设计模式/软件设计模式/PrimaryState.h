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
		this->stateName = "新手";
	}
	PrimaryState(FormAccount* acc)
	{
		this->acc = acc;
		this->point = 0;
		this->stateName = "新手";
	}
	void downloadFile(int score) { cout << "对不起" << acc->getName() << "没有下载权限" << endl; }
	void writeNote(int score)
	{
		cout << acc->getName() << "发布留言，增加" << score << "积分" << endl;
		point += score;
		checkState(point);
		cout << "剩余积分为:" << point << "当前级别为:" << acc->getState()->getStateName() << endl;
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