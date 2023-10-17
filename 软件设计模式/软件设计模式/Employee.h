#pragma once
#include<string>
#include<iostream>

using namespace std;

class Employee
{
public:
	void walk() { cout << "walk方法" << endl; }
	void eat(string food) { cout << food << "被吃了" << endl; }
private:
	string name = "Jacob";
	int age;
	string sex;
};

