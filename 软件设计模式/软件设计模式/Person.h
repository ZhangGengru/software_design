#pragma once
#pragma once
#include<string>
#include<iostream>

using namespace std;

class Person
{
public:
	void eat() { cout << "eat����" << endl; }
private:
	string name;
	int age;
	string address;
};
class Student :Person
{
public:
	void study() { cout << "study����" << endl; }
private:
	string No;
};


