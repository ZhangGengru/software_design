#include<string>
#include<iostream>
#include<list>

using namespace std;
class Observer
{
public:
	virtual void response() = 0;
};
class Subject
{
public:
	void attach(Observer*observer) { observers.push_back(observer); }
	void remove(Observer* observer) { observers.remove(observer); }
	virtual void cry() = 0;
protected:
	list<Observer*> observers;
};
class Cat :public Subject
{
	void cry()
	{
		cout << "Ã¨½Ð£¡" << endl;
		cout << "-------------------" << endl;
		for (auto iter = observers.begin(); iter != observers.end(); iter++)
			(*iter)->response();
	}
};
class Dog :public Observer
{
	void response() { cout << "¹·¸ú×Å½Ð" << endl; }
};
class Mouse :public Observer
{
	void response() { cout << "ÀÏÊóÅ¬Á¦ÌÓÅÜ" << endl; }
};
int main()
{
	Subject* cat = new Cat();
	Observer* obs1 = new Dog();
	Observer* obs2 = new Mouse();
	cat->attach(obs1);
	cat->attach(obs2);
	cat->cry();
	return 0;
}