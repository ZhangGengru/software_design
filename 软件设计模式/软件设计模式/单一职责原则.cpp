#include<string>
#include<iostream>

using namespace std;

class Vehicle
{
public:
	void run(string type)
	{
		if (type == "car")
			cout << "car" << endl;
		else if (type == "ship")
			cout << "ship"<<endl;
		else if (type == "plane")
			cout << "plane" << endl;
	}
};
//��������Υ����һְ��ԭ��
//��Ϊ������һְ��
class CarVehicle
{
public:
	void run() { cout << "car" << endl; }
};
class ShipVehicle
{
public:
	void run() { cout << "ship" << endl; }
};
class PlaneVehicle
{
public:
	void run() { cout << "plane" << endl; }
};