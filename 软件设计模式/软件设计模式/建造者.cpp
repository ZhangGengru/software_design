#include<string>
#include<iostream>

using namespace std;

class MealBuilder;
class Meal;
class KFCwaiter;
//最后得到的产品 Meal
class Meal
{
public:
	void setFood(string food) { this->food = food; }
	void setDrink(string drink) { this->drink = drink; }
	string getFood() { return food; }
	string getDrink() { return drink; }
private:
	string food;
	string drink;
};
//Builder抽象类
class MealBuilder
{
public:
	virtual void buildFood() = 0;
	virtual void buildDrink() = 0;
	Meal getMeal() { return meal; }
protected:
	Meal meal;
};
//具体BuilderA类
class MealBuilderA:public MealBuilder
{
	void buildFood() { meal.setFood("香辣鸡腿堡"); }
	void buildDrink() { meal.setDrink("可乐"); }
};
//具体BuilderB类
class MealBuilderB :public MealBuilder
{
	void buildFood() { meal.setFood("奥尔良鸡腿堡"); }
	void buildDrink() { meal.setDrink("雪碧"); }
};
//指挥者类
class KFCwaiter
{
public:
	KFCwaiter(MealBuilder* mb) { mb_Builder = mb; }
	Meal Create()
	{
		mb_Builder->buildFood();
		mb_Builder->buildDrink();
		return mb_Builder->getMeal();
	}
private:
	MealBuilder* mb_Builder;
};
//int main()
//{
//	MealBuilderA mbA;
//	KFCwaiter kfcWaiter(&mbA);
//	Meal meal = kfcWaiter.Create();
//	cout << meal.getFood();
//	cout << meal.getDrink();
//}
