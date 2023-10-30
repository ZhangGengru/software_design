#include<string>
#include<iostream>
#include<vector>

using namespace std;

class TVIterator
{
public:
	virtual void setChannel(int i) = 0;
	virtual string currentChannel() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool isLast() = 0;
	virtual bool isFirst() = 0;
};
class Television
{
public:
	virtual TVIterator* createIterator() = 0;
};
class SkyworthIterator :public TVIterator
{
public:
	void setChannel(int i)
	{
		current = i;
	}
	string currentChannel()
	{
		return channels[current];
	}
	void next()
	{
		if (current < channels.size())
		{
			current++;
		}
	}
	void previous()
	{
		if (current > 0)
		{
			current--;
		}
	}
	bool isLast()
	{
		return current == channels.size() - 1;
	}
	bool isFirst()
	{
		return current == 0;
	}
private:
	int current = 0;
	vector<string> channels = { "CCTV-1","CCTV-2","CCTV-3","CCTV-4","CCTV-5","CCTV-6","CCTV-7","CCTV-8",
	"CCTV-9","CCTV-10","CCTV-11","CCTV-12","CCTV-13","CCTV-14","CCTV-15" };
};

class SkyworthTelevision :public Television
{
public:
	TVIterator* createIterator()
	{
		return new SkyworthIterator();
	}
};
void display(TVIterator* it)
{
	it->setChannel(0);
	cout<<"电视机频道："<<endl;
	while (!it->isLast())
	{
		cout << it->currentChannel() << " ";
		it->next();
	}
	cout << endl;
}
int main()
{
	Television* tv = new SkyworthTelevision();
	TVIterator* it = tv->createIterator();
	display(it);
}