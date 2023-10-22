#include<string>
#include<iostream>

using namespace std;

class Attachment
{
public:
	void download() { cout << "download Attachment" << endl; }
};

class Email_ab
{
public:
	Email_ab() {};
	virtual ~Email_ab() {};
	virtual Email_ab* clone() { return nullptr; };
	virtual void display() {};
	virtual Attachment* getAttachment() { return nullptr; };
protected:
	Attachment* attachment;
};

class Email :public Email_ab
{
public:
	Email() = default;
	Email(Attachment& attachment);
	Email(const Email& email);
	~Email() { delete attachment; }
	Email* clone();
	void display();
	Attachment* getAttachment();
};

Email::Email(Attachment& attachment)
{
	this->attachment = new Attachment();
	*this->attachment = attachment;
}

Email::Email(const Email& email)
{
	attachment = new Attachment();
	*attachment = *email.attachment;
}

Email* Email::clone()
{
	return new Email(*this);
}

void Email::display()
{
	cout << "²é¿´ÓÊ¼þ" << endl;
}

Attachment* Email::getAttachment()
{
	return attachment;
}

//int main()
//{
//	Attachment attachment;
//	Email* email = new Email(attachment);
//	Email* copy_email;
//	copy_email = email->clone();
//	cout << (email == copy_email) << endl;
//	cout << (email->getAttachment() == copy_email->getAttachment()) << endl;;
//}



