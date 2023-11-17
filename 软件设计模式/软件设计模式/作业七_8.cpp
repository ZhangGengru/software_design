#include<string>
#include<iostream>

using namespace std;

class DiscountSta
{
public:
	virtual void discount(double& price) = 0;
protected:
};
class StudentDiscount :DiscountSta
{
public:
	virtual void discount(double& price)
	{
		cout << "������" << endl;
		price *= 0.7;
	}
};
class ChildDiscount :DiscountSta
{
public:
	virtual void discount(double& price)
	{
		cout << "�Ż�15Ԫ" << endl;
		price -= 15;
	}
};
class VIPDiscount :DiscountSta
{
public:
	virtual void discount(int& price)
	{
		cout << "��۲�����" << endl;
		price /=2;
	}
};
class MovieTicket
{
public:
	MovieTicket(double p) :price(p){}
	void setDiscount(DiscountSta* ds)
	{
		discount = ds;
	}
	void showPrice()
	{
		discount->discount(price);
		cout << "Ʊ��Ϊ��" << price << endl;
	}
private:
	DiscountSta* discount;
	double price;
};
