#include<string>
#include<iostream>

using namespace std;

class OS
{
public:
	virtual void InstallOS_Imp() = 0;
};
class Windows :public OS
{
public:
	void InstallOS_Imp() { cout << "Install Windows" << endl; }
};
class Linux :public OS
{
public:
	void InstallOS_Imp() { cout << "Install Linux" << endl; }
};
class MacOS :public OS
{
public:
	void InstallOS_Imp() { cout << "Install MacOS" << endl; }
};

class Computer
{
public:
	virtual void InstallOS(OS* os) {};
};
class DellCompuer:public Computer
{
public:
	void InstallOS(OS* os) { cout << "Dell"; os->InstallOS_Imp(); };
};
class HPCompuer :public Computer
{
public:
	void InstallOS(OS* os) { cout << "HP"; os->InstallOS_Imp(); };
};
class AppleCompuer :public Computer
{
public:
	void InstallOS(OS* os) { cout << "Apple"; os->InstallOS_Imp(); };
};
int main()
{
	OS* os1 = new Windows();
	OS* os2 = new MacOS();
	Computer* computer1 = new AppleCompuer();
	Computer* computer2 = new DellCompuer();
	computer1->InstallOS(os2);
	computer2->InstallOS(os1);
	delete os1, os2, computer1, computer2;
}