#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;

class Transform
{
public:
	virtual void move() = 0;
};

class Car :public Transform
{
public:
	Car() { cout << "变形金刚是一辆车" << endl; }
	void move() { cout << "在地上移动" << endl; }
};
class Change :public Transform
{
public:
	Change(shared_ptr<Transform> transform) :m_transform(transform) {}
	void move() { m_transform->move(); }
private:
	shared_ptr<Transform> m_transform;
};
class Robot :public Change
{
public:
	Robot(shared_ptr<Transform> transform) :Change(transform) { cout << "变成机器人" << endl; }
	void say() { cout << "说话" << endl; }
};
class Airplane :public Change
{
public:
	Airplane(shared_ptr<Transform> transform) :Change(transform) { cout << "变成飞机" << endl; }
	void move() { fly(); }
private:
	void fly() { cout << "飞" << endl; }
};
int main()
{
	shared_ptr<Transform> camaro;
	camaro = make_shared<Car>();
	camaro->move();
	camaro = make_shared<Airplane>(camaro);
	camaro->move();
}