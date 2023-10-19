#include<string>
#include<iostream>


using namespace std;

//���������
class TV
{
public:
	virtual void play() = 0;
};
//����������
class HaierTV :public TV
{
public:
	void play() { cout << "��������"; }
};
//���ŵ���
class HisenseTV :public TV
{
public:
	void play() { cout << "���ŵ���"; }
};
//������
class TVfacotry
{
public:
	virtual TV* produceTV() = 0;
};
//�����������ӹ���
class HaierTVfactory :public TVfacotry
{
public:
	TV* produceTV()
	{
		cout << "������������" << endl;
		return new HaierTV();
	}
};
class HisenseTVfactory :public TVfacotry
{
public:
	TV* produceTV()
	{
		cout << "�������ŵ���" << endl;
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