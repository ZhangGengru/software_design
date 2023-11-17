#include<string>
#include<iostream>
#include<vector>


using namespace std;

class Memento
{
	friend class userInfo;
private:
	Memento(string account, string password, string telNo):account(account), password(password), telNo(telNo){}
	void setAccount(string account) { this->account = account; }
	void setPassword(string password) { this->password = password; }
	void setTelNo(string telNo) { this->telNo = telNo; }
	string getAccount() { return account; }
	string getPassword() { return password; }
	string getTelNo() { return telNo; }
private:
	string account;
	string password;
	string telNo;
};
class userInfo
{
public:
	Memento* createMemento()
	{
		return new Memento(account, password, telNo);
	}
	string getAccout() { return account; }
	string getPassword() { return password; }
	string getTelNo() { return telNo; }
	void setAccout(string accout) { this->account = account; }
	void setPassword(string password) { this->password = password; }
	void setTelNo(string telNo) { this->telNo = telNo; }
	void restoreMemento(Memento* memento)
	{
		this->account = memento->getAccount();
		this->password = memento->getPassword();
		this->telNo = memento->getTelNo();
	}
	void show()
	{
		cout<<"account:"<<account<<endl;
		cout<<"password:"<<password<<endl;
		cout<<"telNo:"<<telNo<<endl;
	}
private:
	string account;
	string password;
	string telNo;
};
class Caretaker
{
public:
	void addMemento(Memento* memento)
	{
		mementos.push_back(memento);
	}
	Memento* getMemento(int index)
	{
		return mementos[index];
	}
private:
	vector<Memento*> mementos;
};
int main()
{
	userInfo user;
	Caretaker caretaker;
	user.setAccout("zhangsan");
	user.setPassword("123456");
	user.setTelNo("123456789");
	cout<<"³õÊ¼×´Ì¬"<<endl;
	user.show();
	//±£´æ×´Ì¬
	caretaker.addMemento(user.createMemento());
	cout << "-----------------------------------------" << endl;
	user.setPassword("654321");
	user.setTelNo("987654321");
	cout<<"ÐÞ¸Äºó×´Ì¬"<<endl;
	user.show();
	cout << "-----------------------------------------" << endl;
	//»Ö¸´×´Ì¬
	user.restoreMemento(caretaker.getMemento(0));
	cout<<"»Ö¸´ºó×´Ì¬"<<endl;
	user.show();
	return 0;
}