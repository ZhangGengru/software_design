#include<string>
#include<iostream>

using namespace std;

class Car
{
public:
	Car(string name) :name(name) {};
	void driver() { cout << "120km/h" << endl; }
	void driver180() { cout << "180km/h" << endl; }//扩展一个方法，不能修改driver方法
private:
	string name;
};
int main()
{
	Car car("Benz");
	car.driver();
	car.driver180();
}