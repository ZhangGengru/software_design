#pragma once
#include"AbstractState.h"
#include"PrimaryState.h"
#include<string>
#include<iostream>

using namespace std;

class FormAccount
{
public:
	FormAccount(string name)
	{
		this->name = name;
		this->state = new PrimaryState(this);
		cout<<this->name<<" register successfully!"<<endl;
		cout<<"-------------------------"<<endl;
	}
	void setState(AbstractState* state) { this->state = state; }
	AbstractState* getState() { return this->state; }
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
	void downloadFile(int score){state->downloadFile(score);}
	void writeNote(int score){state->writeNote(score);}
	void replyNote(int score) { state->replyNote(score); }

private:
	AbstractState* state;
	string name;
};
