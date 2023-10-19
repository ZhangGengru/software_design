#include<string>
#include<iostream>

using namespace std;

//抽象电视类
class TV
{
public:
	virtual void play() = 0;
};
//海尔电视类
class HaierTV :public TV
{
public:
	void play() { cout << "海尔电视"; }
};
//海信电视
class HisenseTV :public TV
{
public:
	void play() { cout << "海信电视"; }
};
//电视工厂
class TVfactory
{
public:
	static TV* produceTV(string Brand)
	{
		if (Brand == "Haire")
			return new HaierTV();
		else if (Brand == "Hisense")
			return new HisenseTV();
		else
			cout << "不生产该品牌" << endl;
	}
};