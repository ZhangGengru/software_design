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
	void ShowDecorate() { cout << m_name << "��װ��" << endl; }
private:
	string m_name; //�ֻ�����
};
class HUAWEI :public Phone
{
public:
	HUAWEI() { m_name = "HUAWEI"; }
	~HUAWEI() {}
	void ShowDecorate() { cout << m_name << "��װ��" << endl; }
private:
	string m_name; //�ֻ�����
};
//װ����
class DecoratorPhone :public Phone
{
public:
	DecoratorPhone(Phone *phone) { m_phone = phone; }
	virtual void ShowDecorate() { m_phone->ShowDecorate(); }
private:
	Phone *m_phone;//Ҫװ�ε��ֻ�
};
class DecoratorPhoneA :public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone* m_phone) :DecoratorPhone(m_phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "���ӹҼ�" << endl; }
};
class DecoratorPhoneB :public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone* m_phone) :DecoratorPhone(m_phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "��Ļ��Ĥ" << endl; }
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