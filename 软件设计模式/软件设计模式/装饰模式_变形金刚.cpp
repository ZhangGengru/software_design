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
	Car() { cout << "���ν����һ����" << endl; }
	void move() { cout << "�ڵ����ƶ�" << endl; }
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
	Robot(shared_ptr<Transform> transform) :Change(transform) { cout << "��ɻ�����" << endl; }
	void say() { cout << "˵��" << endl; }
};
class Airplane :public Change
{
public:
	Airplane(shared_ptr<Transform> transform) :Change(transform) { cout << "��ɷɻ�" << endl; }
	void move() { fly(); }
private:
	void fly() { cout << "��" << endl; }
};
int main()
{
	shared_ptr<Transform> camaro;
	camaro = make_shared<Car>();
	camaro->move();
	camaro = make_shared<Airplane>(camaro);
	camaro->move();
}