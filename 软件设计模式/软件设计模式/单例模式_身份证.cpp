#include<string>
#include<iostream>

using namespace std;

class IdentityCardNo
{
public:
	static IdentityCardNo* getInstance();
	string getIdentityCardNo();
private:
	string No;
	static IdentityCardNo* instance;
	IdentityCardNo() {};
	void setIdentityCardNo(string N0);
};
IdentityCardNo* IdentityCardNo::instance = nullptr;

IdentityCardNo* IdentityCardNo::getInstance()
{
	if (instance == nullptr)
	{
		cout << "first time" << endl;
		instance = new IdentityCardNo();
		instance->setIdentityCardNo("1111111111");
	}
	else
		cout << "you have made a IDcard";
	return instance;
}

string IdentityCardNo::getIdentityCardNo()
{
	return No;
}

void IdentityCardNo::setIdentityCardNo(string No)
{
	this->No = No;
}
//int main()
//{
//	IdentityCardNo* member1 = IdentityCardNo::getInstance();
//	IdentityCardNo* member2 = IdentityCardNo::getInstance();
//	cout << member1->getIdentityCardNo()<<endl;
//	cout << member2->getIdentityCardNo() << endl;;
//}
