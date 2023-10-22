#include<string>
#include<iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance();
private:
	Singleton()=default;
	static Singleton* singleton;
};
Singleton* Singleton::singleton = nullptr;
Singleton* Singleton::GetInstance()
{
	if (singleton == nullptr)
		singleton = new Singleton();
	return singleton;
}
//int main()
//{
//	Singleton* a = Singleton::GetInstance();
//	Singleton* b = Singleton::GetInstance();
//	cout << (a == b) << endl;
//}