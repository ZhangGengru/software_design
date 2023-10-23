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
	virtual void modifyUserInfo(){ cout << "修改用户信息" << endl; }
	virtual void viewNote() { cout << "查看帖子" << endl; }
	virtual void publishNote() { cout << "发布新帖子" << endl; }
	virtual void modifyNote() { cout << "修改发帖内容" << endl; }
	virtual void setLevel(int level) {}
};
class PermissionProxy :public AbstractPermission
{
public:
	virtual void modifyUserInfo()
	{
		if (level == 0)
			cout << "没有权限" << endl;
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
			cout << "没有权限" << endl;
		else
			permission->publishNote();
	}
	virtual void modifyNote()
	{
		if (level == 0)
			cout << "没有权限" << endl;
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