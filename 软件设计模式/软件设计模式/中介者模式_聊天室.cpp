#include<string>
#include<iostream>
#include<map>

using namespace std;

class AbstractChatRoom;

class Member
{
public:
	Member(string name) :m_name(name){}
	string getname() { return m_name; }
	void setChatRoom(AbstractChatRoom* chatRoom) { m_chatRoom = chatRoom; }
	virtual void SendText(string to, string message) = 0;
	virtual void SendImage(string to, string image) = 0;
	virtual void ReceiveText(string from, string message) = 0;
	virtual void ReceiveImage(string from, string image) = 0;
protected:
	AbstractChatRoom* m_chatRoom;
	string m_name;
};
class AbstractChatRoom
{
public:
	virtual void Register(Member* member) = 0;
	virtual void SendText(string from, string to, string message) = 0;
	virtual void SendImage(string from, string to, string image) = 0;
};;
class DiamondMember :public Member
{
public:
	DiamondMember(string name) :Member(name){}
	void SendText(string to, string message) 
	{ 
		cout << "钻石会员"<<m_name<<"发送信息" << endl; 
		m_chatRoom->SendText(m_name, to, message);
	}
	void SendImage(string to, string image)
	{
		cout << "钻石会员"<<m_name<<"发送图片" << endl; 
		m_chatRoom->SendImage(m_name, to, image);
	}
	void ReceiveText(string from, string message)
	{
		cout << "钻石会员"<<m_name<<"接收信息" << endl;
		cout << from << "发送信息给" << m_name << "内容为" << message << endl;
	}
	void ReceiveImage(string from, string image)
	{
		cout << "钻石会员"<<m_name<<"接收图片" << endl;
		cout << from << "发送图片给" << m_name << "内容为" << image << endl;
	}
};
class CommonMember :public Member
{
public:
	CommonMember(string name) :Member(name) {}
	void SendText(string to, string message)
	{
		cout << "普通会员" << m_name << "发送信息" << endl;
		m_chatRoom->SendText(m_name, to, message);
	}
	void SendImage(string to, string image)
	{
		cout << "普通会员" << m_name << "不能发送图片" << endl;
	}
	void ReceiveText(string from, string message)
	{
		cout << "普通会员" << m_name << "接收信息" << endl;
		cout << from << "发送信息给" << m_name << "内容为" << message << endl;
	}
	void ReceiveImage(string from, string image)
	{
		cout<<"普通会员" << m_name << "接收图片" << endl;
		cout<<from << "发送图片给" << m_name << "内容为" << image << endl;
	}
};
class ChatRoom :public AbstractChatRoom
{
public:	
	void Register(Member* member)
	{
		m_members.insert(make_pair(member->getname(), member));
		member->setChatRoom(this);
	}
	void SendText(string from, string to, string message)
	{
		m_members[to]->ReceiveText(from, message);
	}
	void SendImage(string from, string to, string image)
	{
		m_members[to]->ReceiveImage(from, image);
	}
private:
	map<string, Member*> m_members;
};

int main()
{
	AbstractChatRoom* chatRoom = new ChatRoom();
	Member* member1 = new DiamondMember("张三");
	Member* member2 = new CommonMember("李四");
	chatRoom->Register(member1);
	chatRoom->Register(member2);
	member1->SendText("李四", "你好");
	member2->SendText("张三", "你好");
	member1->SendImage("李四", "图片");
	member2->SendImage("张三", "图片");
	return 0;
}