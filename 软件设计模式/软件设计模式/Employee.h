#pragma once
#include<string>
#include<iostream>

using namespace std;

class Employee
{
public:
	void walk() { cout << "walk����" << endl; }
	void eat(string food) { cout << food << "������" << endl; }
private:
	string name = "Jacob";
	int age;
	string sex;
};

