#include<string>
#include<iostream>

using namespace std;
//������
class TV
{
public:
	virtual void show() = 0;
};
class HaierTV :public TV
{
public:
	void show() { cout << "Haier����" << endl; }
};
class TCL_TV :public TV
{
public:
	void show() { cout << "TCL����" << endl; }
};
//�յ���
class Airconditioner
{
public:
	virtual void show() = 0;
};
class HaierAirconditioner :public Airconditioner
{
public:
	void show() { cout << "Haier�յ�" << endl; }
};
class TCLAirconditioner :public Airconditioner
{
public:
	void show() { cout << "TCL�յ�" << endl; }
};
//������
class Factory
{
public:
	virtual TV* CreateTV() = 0;
	virtual Airconditioner* CreateAirConditioner() = 0;
};
class HaierFactory :public Factory
{
	TV* CreateTV()
	{
		cout << "������������" << endl;
		return new HaierTV();
	}
	Airconditioner* CreateAirConditioner()
	{
		cout << "���������յ�" << endl;
		return new HaierAirconditioner();
	}
};
class TCLFactory :public Factory
{
	TV* CreateTV()
	{
		cout << "����TCL����" << endl;
		return new TCL_TV();
	}
	Airconditioner* CreateAirConditioner()
	{
		cout << "����TCL�յ�" << endl;
		return new TCLAirconditioner();
	}
};
class Client
{
	void fn()
	{
		TV* TV;
		Airconditioner* AirConditioner;
		Factory* Factory;
		Factory = new TCLFactory();
		TV = Factory->CreateTV();
		AirConditioner = Factory->CreateAirConditioner();
	}
};