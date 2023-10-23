#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;	

class Phone
{
public:
	Phone() {};
	virtual ~Phone() {};
	virtual void ShowDecorate() = 0;
};
class iPhone :public Phone
{
public:
	iPhone() { m_name = "iPhone"; }
	~iPhone() {}
	void ShowDecorate() { cout << m_name << "的装饰" << endl; }
private:
	string m_name; //手机名称
};
class HUAWEI :public Phone
{
public:
	HUAWEI() { m_name = "HUAWEI"; }
	~HUAWEI() {}
	void ShowDecorate() { cout << m_name << "的装饰" << endl; }
private:
	string m_name; //手机名称
};
//装饰类
class DecoratorPhone :public Phone
{
public:
	DecoratorPhone(Phone *phone) { m_phone = phone; }
	virtual void ShowDecorate() { m_phone->ShowDecorate(); }
private:
	Phone *m_phone;//要装饰的手机
};
class DecoratorPhoneA :public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone* m_phone) :DecoratorPhone(m_phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "增加挂件" << endl; }
};
class DecoratorPhoneB :public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone* m_phone) :DecoratorPhone(m_phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "屏幕贴膜" << endl; }
};
int main()
{
	shared_ptr<Phone> iphone = make_shared<iPhone>();
	shared_ptr<Phone> dpa = make_shared<DecoratorPhoneA>(iphone.get());
	shared_ptr<Phone> dpb = make_shared<DecoratorPhoneB>(iphone.get());
	dpa->ShowDecorate();
	dpb->ShowDecorate();
	return 0;
}