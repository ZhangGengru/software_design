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
//���ӹ���
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
			cout << "��������Ʒ��" << endl;
	}
};