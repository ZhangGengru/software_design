#include<string>
#include<iostream>

using namespace std;

class Car
{
public:
	Car(string name) :name(name) {};
	void driver() { cout << "120km/h" << endl; }
	void driver180() { cout << "180km/h" << endl; }//��չһ�������������޸�driver����
private:
	string name;
};
int main()
{
	Car car("Benz");
	car.driver();
	car.driver180();
}