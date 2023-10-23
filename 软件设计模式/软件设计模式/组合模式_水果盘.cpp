#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;

class MyElement
{
public:
	virtual void eat() = 0;
	virtual void add(shared_ptr<MyElement> element) {};
	virtual void Delete(shared_ptr<MyElement> element) {};
};
//叶子节点 水果
class Apple :public MyElement
{
public:
	void eat() { cout << "吃苹果" << endl;}
};
class Banana :public MyElement
{
public:
	void eat() { cout << "吃香蕉" << endl; }
};
class Pear :public MyElement
{
public:
	void eat() { cout << "吃梨" << endl; }
};
//容器节点 水果盘
class FruitPlate :public MyElement
{
public:
	void add(shared_ptr<MyElement> element)
	{
		m_list.push_back(element);
	}
	void Delete(shared_ptr<MyElement> element)
	{
		auto iter = m_list.begin();
		for (iter; iter != m_list.end(); iter++)
		{
			if (*iter == element)
			{
				m_list.erase(iter);
				cout << "Delete successfully" << endl;
				return;
			}
		}
		cout << "Delete fail" << endl;
	}
	void eat()
	{
		for (auto iter : m_list)
			iter->eat();
	}
private:
	list<shared_ptr<MyElement>> m_list;
};
int main()
{
	shared_ptr<MyElement> apple = make_shared<Apple>();
	shared_ptr<MyElement> banana = make_shared<Banana>();
	shared_ptr<MyElement> pear = make_shared<Pear>();
	shared_ptr<MyElement> fruitPlate1 = make_shared<FruitPlate>();
	fruitPlate1->add(apple);
	fruitPlate1->add(banana);
	fruitPlate1->add(pear);
	fruitPlate1->eat();
}