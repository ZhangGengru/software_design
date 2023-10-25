#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;
class Algorithm
{
public:
	virtual void ImplementAlgorithm() = 0;
};
class RoundRobin :public Algorithm
{
public:
	void ImplementAlgorithm() { cout << "RoundRobin" << endl; }
};
class Preemptive :public Algorithm
{
public:
	void ImplementAlgorithm() { cout << "Preemptive" << endl; }
};
class OS
{
public:
	OS(string os_name):os_name(os_name){}
	virtual void UseAlgorithm(Algorithm* alg) = 0;
private:
	string os_name;//操作系统名称
};
class Windows :public OS
{
public:
	Windows(string os_name):OS(os_name){}
	void UseAlgorithm(Algorithm* alg) { cout << "Windows use: "; alg->ImplementAlgorithm(); }
};	
class Uinx :public OS
{
public:
    Uinx(string os_name) :OS(os_name) {}
	void UseAlgorithm(Algorithm* alg) { cout << "Uinx use: "; alg->ImplementAlgorithm(); }
};
class Linux :public OS
{
public:
    Linux(string os_name) :OS(os_name) {}
	void UseAlgorithm(Algorithm* alg) { cout << "Linux use: "; alg->ImplementAlgorithm(); }
};
int main()
{
	shared_ptr<Algorithm> alg1 = make_shared<RoundRobin>();
	shared_ptr<Algorithm> alg2 = make_shared<Preemptive>();
	shared_ptr<OS> os1 = make_shared<Windows>("Windows");
	shared_ptr<OS> os2 = make_shared<Uinx>("Uinx");
	os1->UseAlgorithm(alg1.get());
	os2->UseAlgorithm(alg2.get());
}