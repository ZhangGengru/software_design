#include<string>
#include<iostream>

using namespace std;

class MealBuilder;
class Meal;
class KFCwaiter;
//���õ��Ĳ�Ʒ Meal
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
//Builder������
class MealBuilder
{
public:
	virtual void buildFood() = 0;
	virtual void buildDrink() = 0;
	Meal getMeal() { return meal; }
protected:
	Meal meal;
};
//����BuilderA��
class MealBuilderA:public MealBuilder
{
	void buildFood() { meal.setFood("�������ȱ�"); }
	void buildDrink() { meal.setDrink("����"); }
};
//����BuilderB��
class MealBuilderB :public MealBuilder
{
	void buildFood() { meal.setFood("�¶������ȱ�"); }
	void buildDrink() { meal.setDrink("ѩ��"); }
};
//ָ������
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
