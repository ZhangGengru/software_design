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
//上述程序违反单一职责原则
//改为下述单一职责
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