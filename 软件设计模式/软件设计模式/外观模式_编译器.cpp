#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;

class Scanner
{
public:
	void Scan() { cout << "词法分析" << endl; }
};
class Parser
{
public:
	void Parse() { cout << "语法分析" << endl; }
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