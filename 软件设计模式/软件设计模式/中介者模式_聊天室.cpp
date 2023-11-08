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
		cout << "��ʯ��Ա"<<m_name<<"������Ϣ" << endl; 
		m_chatRoom->SendText(m_name, to, message);
	}
	void SendImage(string to, string image)
	{
		cout << "��ʯ��Ա"<<m_name<<"����ͼƬ" << endl; 
		m_chatRoom->SendImage(m_name, to, image);
	}
	void ReceiveText(string from, string message)
	{
		cout << "��ʯ��Ա"<<m_name<<"������Ϣ" << endl;
		cout << from << "������Ϣ��" << m_name << "����Ϊ" << message << endl;
	}
	void ReceiveImage(string from, string image)
	{
		cout << "��ʯ��Ա"<<m_name<<"����ͼƬ" << endl;
		cout << from << "����ͼƬ��" << m_name << "����Ϊ" << image << endl;
	}
};
class CommonMember :public Member
{
public:
	CommonMember(string name) :Member(name) {}
	void SendText(string to, string message)
	{
		cout << "��ͨ��Ա" << m_name << "������Ϣ" << endl;
		m_chatRoom->SendText(m_name, to, message);
	}
	void SendImage(string to, string image)
	{
		cout << "��ͨ��Ա" << m_name << "���ܷ���ͼƬ" << endl;
	}
	void ReceiveText(string from, string message)
	{
		cout << "��ͨ��Ա" << m_name << "������Ϣ" << endl;
		cout << from << "������Ϣ��" << m_name << "����Ϊ" << message << endl;
	}
	void ReceiveImage(string from, string image)
	{
		cout<<"��ͨ��Ա" << m_name << "����ͼƬ" << endl;
		cout<<from << "����ͼƬ��" << m_name << "����Ϊ" << image << endl;
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
	Member* member1 = new DiamondMember("����");
	Member* member2 = new CommonMember("����");
	chatRoom->Register(member1);
	chatRoom->Register(member2);
	member1->SendText("����", "���");
	member2->SendText("����", "���");
	member1->SendImage("����", "ͼƬ");
	member2->SendImage("����", "ͼƬ");
	return 0;
}