#pragma once
#include"FormAccount.h"
#include<string>
#include<iostream>

using namespace std;
class AbstractState
{
public:
	virtual void checkState(int score) = 0;
	virtual void downloadFile(int score) = 0;
	virtual void writeNote(int score) = 0;
	void replyNote(int score)
	{
		cout<<acc->getName()<<"回复留言，增加"<<score<<"积分"<<endl;
		point += score;
		checkState(point);
		cout<<"剩余积分为:"<<point<<"当前级别为:"<<acc->getState()->getStateName()<<endl;
	};
	void setPoint(int point){this->point = point; }
	int getPoint(){ return point; }
	void setStateName(string stateName){ this->stateName = stateName; }
	string getStateName(){ return stateName; }
	//FormAccount* getAccount(){ return acc; }
	FormAccount* getAAccount() { return acc; }
protected:
	FormAccount* acc;
	int point;
	string stateName;
};
