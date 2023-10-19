#include<string>
#include<iostream>

using namespace std;
//电视类
class TV
{
public:
	virtual void show() = 0;
};
class HaierTV :public TV
{
public:
	void show() { cout << "Haier电视" << endl; }
};
class TCL_TV :public TV
{
public:
	void show() { cout << "TCL电视" << endl; }
};
//空调类
class Airconditioner
{
public:
	virtual void show() = 0;
};
class HaierAirconditioner :public Airconditioner
{
public:
	void show() { cout << "Haier空调" << endl; }
};
class TCLAirconditioner :public Airconditioner
{
public:
	void show() { cout << "TCL空调" << endl; }
};
//工厂类
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
		cout << "生产海尔电视" << endl;
		return new HaierTV();
	}
	Airconditioner* CreateAirConditioner()
	{
		cout << "生产海尔空调" << endl;
		return new HaierAirconditioner();
	}
};
class TCLFactory :public Factory
{
	TV* CreateTV()
	{
		cout << "生产TCL电视" << endl;
		return new TCL_TV();
	}
	Airconditioner* CreateAirConditioner()
	{
		cout << "生产TCL空调" << endl;
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