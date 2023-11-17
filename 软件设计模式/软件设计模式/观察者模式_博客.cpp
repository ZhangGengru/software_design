#include<string>
#include<iostream>
#include<list>

using namespace std;

class Observer
{
public:
	Observer(){}
	virtual ~Observer() {};
	virtual void Update()=0;
};
class Blog
{
public:
	Blog(){}
	virtual ~Blog() {}
	void Attach(Observer* observer) { observers.push_back(observer); }
	void Remove(Observer* observer) { observers.remove(observer); }
	void Notify()	//֪ͨ�۲���
	{
		list<Observer*>::iterator iter = observers.begin();
		for (iter; iter != observers.end(); iter++)
			(*iter)->Update();
	}
	virtual void SetStatus(string s) { status = s; }//����״̬
	virtual string GetStatus() { return status; }
private:
	list<Observer*> observers;
protected:
	string status;
};
class BlogCSDN :public Blog
{
public:
	BlogCSDN(string name) :name(name) {};
	virtual void SetStatus(string s) { status = "CSDN֪ͨ��" + name + s; }//����״̬
	string GetStatus() { return status; }
private:
	string name;//��������
};
class ObserverBlog :public Observer
{
public:
	ObserverBlog(string name,Blog*blog):name(name),blog(blog){}
	void Update()//��ȡ����״̬
	{
		string status = blog->GetStatus();
		cout << name << "-----------------" << status << endl;
	}
private:
	string name;//�۲�������
	Blog* blog;//�۲�Ĳ���
};
int main()
{
	Blog* blog = new BlogCSDN("zgr0629");
	Observer* observer1 = new ObserverBlog("tlm", blog);
	Observer* observer2 = new ObserverBlog("qqqq", blog);
	blog->Attach(observer1);
	blog->Attach(observer2);
	blog->SetStatus("����xxxxx");
	blog->Notify();
	delete blog, observer1, observer2;
	return 0;
}