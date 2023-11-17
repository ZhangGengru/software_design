#include<string>
#include<iostream>
#include<vector>


using namespace std;

class ReplaceAlgorithm
{
public:
	virtual void Replace() = 0;
};
class LRU :public ReplaceAlgorithm
{
public:
	virtual void Replace() { cout << "Least Recently Used replace algorithm" << endl; }
};
class FIFO :public ReplaceAlgorithm
{
public:
	virtual void Replace() { cout << "First in First out replace algorithm" << endl; }
};
class Random :public ReplaceAlgorithm
{
public:
	virtual void Replace() { cout << "Random replace algorithm" << endl; }
};

class Cache
{
public:
	Cache(ReplaceAlgorithm* ra):ra(ra){}
	~Cache() { delete ra; }
	void Replace() { ra->Replace(); }
private:
	ReplaceAlgorithm* ra;
};
int main()
{
	ReplaceAlgorithm* ra = new FIFO();
	Cache cache(ra);
	cache.Replace();
}