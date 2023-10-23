#include<string>
#include<iostream>

using namespace std;
class Color
{
public:
	virtual void bepaint(string penType, string name) = 0;
};
class Red :public Color
{
	void bepaint(string penType, string name)
	{
		cout << "red " << penType <<name << endl;
	}
};
class Green :public Color
{
	void bepaint(string penType, string name)
	{
		cout << "red " << penType <<name << endl;
	}
};
class Blue :public Color
{
	void bepaint(string penType, string name)
	{
		cout << "red " << penType <<name << endl;
	}
};
class White :public Color
{
	void bepaint(string penType, string name)
	{
		cout << "red " << penType<< name << endl;
	}
};
class Black :public Color
{
	void bepaint(string penType, string name)
	{
		cout << "red " << penType<< name << endl;
	}
};
class Pen
{
public:
	void setColor(Color* color) { this->color = color; }
	virtual void draw(string name) {};
protected:
	Color* color;
};
class SmallPen:public Pen
{
public:
	void draw(string name)
	{
		string penType = "Ð¡ºÅÃ«±Ê»æÖÆ ";
		color->bepaint(penType, name);
	}
};
class MiddlePen :public Pen
{
public:
	void draw(string name)
	{
		string penType = "ÖÐºÅÃ«±Ê»æÖÆ ";
		color->bepaint(penType, name);
	}
};
class BigPen :public Pen
{
public:
	void draw(string name)
	{
		string penType = "´óºÅÃ«±Ê»æÖÆ ";
		color->bepaint(penType, name);
	}
};
int main()
{
	Color* color = new Red();
	Pen* middlePen = new MiddlePen();
	middlePen->setColor(color);
	middlePen->draw("Hello world");
	delete color, middlePen;
}