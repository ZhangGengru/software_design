#include<string>
#include<iostream>

using namespace std;

//目标类
class Robot
{
public:
	virtual void cry() = 0;
	virtual void run() = 0;
};
//适配者类
class Dog
{
public:
	void wang() { cout << "dog wang" << endl; }
	void run() { cout << "dog run" << endl; }
};
class Bird
{
public:
	void tweedle() { cout << "bird tweedle" << endl; }
	void fly() { cout << "bird fly" << endl; }
};
//适配器类
class dogAdapter :public Robot,Dog
{
public:
	void cry() { cout << "robot like:"; Dog::wang(); }
	void run() { cout << "robot like:"; Dog::run(); }
};
class birdAdapter :public Robot, Bird
{
public:
	void cry() { cout << "robot like:"; Bird::tweedle(); }
	void run() { cout << "robot like:"; Bird::fly(); }
};
int main()
{
	Robot* dog = new dogAdapter();
	Robot* bird = new birdAdapter();
	dog->cry(); dog->run();
	bird->cry(); bird->run();
	return 0;
}