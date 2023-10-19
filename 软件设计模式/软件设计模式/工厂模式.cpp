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
//工厂类
class TVfacotry
{
public:
	virtual TV* produceTV() = 0;
};
//生产海尔电视工厂
class HaierTVfactory :public TVfacotry
{
public:
	TV* produceTV()
	{
		cout << "生产海尔电视" << endl;
		return new HaierTV();
	}
};
class HisenseTVfactory :public TVfacotry
{
public:
	TV* produceTV()
	{
		cout << "生产海信电视" << endl;
		return new HisenseTV();
	}
};
class Client
{
	void fn()
	{
		TV* tv;
		TVfacotry* TVfactory;
		TVfactory = new HisenseTVfactory();
		tv = TVfactory->produceTV();
	}
};