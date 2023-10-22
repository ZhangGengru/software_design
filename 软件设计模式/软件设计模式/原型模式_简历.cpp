#define _CRT_SECURE_NO_WARNINGS

#include<string>
#include<iostream>

using namespace std;

class Resume
{
protected:
	char* name;
public:
	Resume() { };
	virtual ~Resume() { };
	virtual Resume* Clone() { return NULL; }
	virtual void Set(string name) { };
	virtual void Show() { };
};	
class ResumeA :public Resume
{
public:
	ResumeA(const char* str);
	ResumeA(const ResumeA& r);
	~ResumeA();
	ResumeA* Clone();
	void Show();	
};

ResumeA::ResumeA(const char* str)
{
	if (str == NULL)
	{
		name = new char[1];
		name[0] = '\0';
	}
	else
	{
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
}
ResumeA::ResumeA(const ResumeA& r)
{
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}

ResumeA::~ResumeA()
{
	delete[] name;
}

ResumeA* ResumeA::Clone()
{
	return new ResumeA(*this);
}

void ResumeA::Show()
{
	cout << "ResumeA:" << name << endl;
}

//int main()
//{
//	ResumeA* r1 = new ResumeA("A");
//	ResumeA* r2 = new ResumeA("B");
//	ResumeA* r3 = r1->Clone();
//	ResumeA* r4 = r2->Clone();
//	r1->Show();
//	r2->Show();
//	delete r1, r2;
//	r1 = r2 = nullptr;
//	r3->Show();
//	r4->Show();
//	delete r3, r4;
//	r3 = r4 = nullptr;
//}




