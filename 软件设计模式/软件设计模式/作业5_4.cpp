#include<iostream>
#include<string>
#include<list>
#include<memory>
#include<vector>

using namespace std;

class Meal
{
public:
	Meal(string meal):mealKind(meal) {}
	virtual ~Meal() = default;
	virtual void Add(shared_ptr<Meal> meal) {}
	virtual void Show(int depth) {}
protected:
	string mealKind;
};
class DifferentMeal :public Meal
{
public:
	DifferentMeal(string name):Meal(name) {}
	void Add(shared_ptr<Meal> meal) { mealList.push_back(meal); }
	void Show(int depth)
	{
		for(int i=0;i<depth;i++)
			cout << "-";
		cout<< mealKind << endl;
		for (auto iter : mealList)
			iter->Show(depth + 2);
	}
private:
	list<shared_ptr<Meal>> mealList;
};
class Meal1 :public Meal
{
public:
	Meal1(string name = "²ËÊ½1") :Meal(name) {}
	void Show(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << mealKind << endl;
	}
};
class Meal2 :public Meal
{
public:
	Meal2(string name = "²ËÊ½2") :Meal(name) {}
	void Show(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << mealKind << endl;
	}
};
int main()
{
	shared_ptr<Meal> meal = make_shared<DifferentMeal>("ËùÓĞ²Ëµ¥");
	shared_ptr<Meal> mealA = make_shared<DifferentMeal>("¼å±ıÎİ²Ëµ¥");
	meal->Add(mealA);
	shared_ptr<Meal> meal1 = make_shared<Meal1>("¼å±ıÎİ²ËÊ½1");
	shared_ptr<Meal> meal2 = make_shared<Meal2>("¼å±ıÎİ²ËÊ½2");
	mealA->Add(meal1);
	mealA->Add(meal2);
	shared_ptr<Meal> mealB = make_shared<DifferentMeal>("²ÍÌü²Ëµ¥");
	meal->Add(mealB);
	shared_ptr<Meal> meal3 = make_shared<Meal1>("²ÍÌü²ËÊ½1");
	shared_ptr<Meal> meal4 = make_shared<Meal2>("²ÍÌü²ËÊ½2");
	mealB->Add(meal3);
	mealB->Add(meal4);
	shared_ptr<Meal> mealC = make_shared<DifferentMeal>("¿§·ÈÌü²Ëµ¥");
	meal->Add(mealC);
	shared_ptr<Meal> meal5 = make_shared<Meal1>("¿§·ÈÌü²ËÊ½1");
	shared_ptr<Meal> meal6 = make_shared<Meal2>("¿§·ÈÌü²ËÊ½2");
	mealC->Add(meal5);
	mealC->Add(meal6);
	meal->Show(0);
	return 0;
}