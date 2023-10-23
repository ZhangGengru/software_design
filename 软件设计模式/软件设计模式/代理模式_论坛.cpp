#include<string>
#include<iostream>

using namespace std;

class AbstractPermission
{
public:
	virtual void modifyUserInfo() = 0;
	virtual void viewNote() = 0;
	virtual void publishNote() = 0;
	virtual void modifyNote() = 0;
	virtual void setLevel(int level) = 0;
};
class RealPermission :public AbstractPermission
{
	virtual void modifyUserInfo(){ cout << "�޸��û���Ϣ" << endl; }
	virtual void viewNote() { cout << "�鿴����" << endl; }
	virtual void publishNote() { cout << "����������" << endl; }
	virtual void modifyNote() { cout << "�޸ķ�������" << endl; }
	virtual void setLevel(int level) {}
};
class PermissionProxy :public AbstractPermission
{
public:
	virtual void modifyUserInfo()
	{
		if (level == 0)
			cout << "û��Ȩ��" << endl;
		else
			permission->modifyNote();
	}
	virtual void viewNote()
	{
		permission->viewNote();
	}
	virtual void publishNote()
	{
		if (level == 0)
			cout << "û��Ȩ��" << endl;
		else
			permission->publishNote();
	}
	virtual void modifyNote()
	{
		if (level == 0)
			cout << "û��Ȩ��" << endl;
		else
			permission->modifyNote();
	}
	virtual void setLevel(int level)
	{
		this->level = level;
	}
private:
	shared_ptr<AbstractPermission> permission = make_shared<RealPermission>();
	int level = 0;
};
int main()
{
	shared_ptr<AbstractPermission> permission = make_shared<PermissionProxy>();
	permission->modifyUserInfo();
	permission->viewNote();
	permission->publishNote();
	permission->modifyNote();
	cout << "-----------------------------------" << endl;
	permission->setLevel(1);
	permission->modifyUserInfo();
	permission->viewNote();
	permission->publishNote();
	permission->modifyNote();
}