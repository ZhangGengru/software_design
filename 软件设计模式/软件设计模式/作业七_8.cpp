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
		cout << "打七折" << endl;
		price *= 0.7;
	}
};
class ChildDiscount :DiscountSta
{
public:
	virtual void discount(double& price)
	{
		cout << "优惠15元" << endl;
		price -= 15;
	}
};
class VIPDiscount :DiscountSta
{
public:
	virtual void discount(int& price)
	{
		cout << "半价并积分" << endl;
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
		cout << "票价为：" << price << endl;
	}
private:
	DiscountSta* discount;
	double price;
};
