#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;

class Scanner
{
public:
	void Scan() { cout << "�ʷ�����" << endl; }
};
class Parser
{
public:
	void Parse() { cout << "�﷨����" << endl; }
};
class Compiler
{
public:
	void run()
	{
		Scanner scanner;
		Parser parse;
		scanner.Scan();
		parse.Parse();
	}
};
int main()
{
	Compiler comp;
	comp.run();
}