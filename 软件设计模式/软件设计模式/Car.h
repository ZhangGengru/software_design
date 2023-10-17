#pragma once
#include<string>
#include<iostream>

using namespace std;
class Car
{
	virtual void move()= 0;
};
class BMW :Car
{
	void move() { cout << "BWMµÄmove" << endl; }
};

