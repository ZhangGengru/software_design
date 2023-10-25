#include<iostream>
#include<string>
#include<list>
#include<memory>
#include<vector>

using namespace std;

class Beverage
{
public:
	Beverage() = default;
	virtual void add(shared_ptr<Beverage> beverage) {}
	virtual string returnName() { return ""; }
	virtual int returnPrice() = 0;
};
class Milk :public Beverage
{
public:
	Milk(string Be_Name, int price) :Be_Name(Be_Name),price(price) {}
	void add(shared_ptr<Beverage> beverage)
	{
		cond_list.push_back(beverage);
		cout<<"加入"<<beverage->returnName()<<endl;
	}
	int returnPrice()
	{
		int sum = 0;
		for (auto iter : cond_list)
			sum += iter->returnPrice();
		return sum + this->price;
	}
private:
	string Be_Name;
	int price;
	vector<shared_ptr<Beverage>> cond_list;
};
class Coffee :public Beverage
{
public:
    Coffee(string Be_Name, int price) :Be_Name(Be_Name), price(price) {}
	void add(shared_ptr<Beverage> beverage) 
	{
		cond_list.push_back(beverage); 
		cout << "加入" << beverage->returnName() << endl;
	}
	int returnPrice()
	{
		int sum = 0;
		for (auto iter : cond_list)
			sum += iter->returnPrice();
		return sum + this->price;
	}
private:
	string Be_Name;
	int price;
	vector<shared_ptr<Beverage>> cond_list;
};
class MilkTea :public Beverage
{
public:
    MilkTea(string Be_Name, int price) :Be_Name(Be_Name), price(price) {}
	void add(shared_ptr<Beverage> beverage) 
	{ 
		cond_list.push_back(beverage);
		cout << "加入" << beverage->returnName() << endl;
	}
	int returnPrice()
	{
		int sum = 0;
		for (auto iter : cond_list)
			sum += iter->returnPrice();
		return sum + this->price;
	}
private:
	string Be_Name;
	int price;
	vector<shared_ptr<Beverage>> cond_list;
};
class CondimentDecorator :public Beverage
{
public:
	CondimentDecorator(string name, int price, shared_ptr<Beverage> beverage):Con_name(name),Con_price(price)
	{
		this->beverage = beverage;
	}
	virtual string returnName() { return ""; }
protected:
	string Con_name;
	int Con_price;
	shared_ptr<Beverage> beverage;
};
class Strawberry :public CondimentDecorator
{
public:
	Strawberry(string name, int price, shared_ptr<Beverage> beverage) :CondimentDecorator(name, price, beverage) {}
	int returnPrice() { return Con_price; }
	virtual string returnName() { return this->Con_name; }
};
class Pudding :public CondimentDecorator
{
public:
    Pudding(string name, int price, shared_ptr<Beverage> beverage) :CondimentDecorator(name, price, beverage) {}
	int returnPrice() { return Con_price; }
	virtual string returnName() { return this->Con_name; }
};
class Cheese :public CondimentDecorator
{
public:
    Cheese(string name, int price, shared_ptr<Beverage> beverage) :CondimentDecorator(name, price, beverage) {}
	int returnPrice() { return Con_price; }
	virtual string returnName() { return this->Con_name; }
};
int main()
{
	shared_ptr<Beverage> drink = make_shared<Milk>("牛奶", 10);
	shared_ptr<Beverage> Cond1 = make_shared<Strawberry>("草莓", 5, drink);
	shared_ptr<Beverage> Cond2 = make_shared<Pudding>("布丁", 5, drink);
	drink->add(Cond1);
	drink->add(Cond2);
	cout<<drink->returnPrice();
}