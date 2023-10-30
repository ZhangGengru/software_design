#include<string>
#include<iostream>

using namespace std;

class Television
{
public:
	void action(string name)
	{
		cout << "����ִ��" << name << endl;;
	}
};

class AbstractCommand
{
public:
	AbstractCommand(Television* tv) :tv(tv) {}
	virtual void execute() = 0;
protected:
	Television* tv;
};
class TVOpenCommand :public AbstractCommand
{
public:
	TVOpenCommand(Television* tv) :AbstractCommand(tv){}
	void execute()
	{
		tv->action("����");
	}
};
class TVCloseCommand :public AbstractCommand
{
public:
	TVCloseCommand(Television* tv) :AbstractCommand(tv) {}
	void execute()
	{
		tv->action("�ػ�");
	}
};
class TVChangeCommand :public AbstractCommand
{
public:
	TVChangeCommand(Television* tv) :AbstractCommand(tv) {}
	void execute()
	{
		tv->action("��Ƶ��");
	}
};
class Controller
{
public:
	void ReceiveCmd(AbstractCommand* cmd)
	{
		command = cmd;
	}
	void DelCmd()
	{
		command->execute();
	}
private:
	AbstractCommand* command;
};
int main()
{
	Controller* control = new Controller;
	Television* tv = new Television;

	AbstractCommand* open = new TVOpenCommand(tv);
	AbstractCommand* close = new TVCloseCommand(tv);
	AbstractCommand* change = new TVChangeCommand(tv);

	control->ReceiveCmd(open);
	control->DelCmd();
	control->ReceiveCmd(change);
	control->DelCmd();
	control->ReceiveCmd(close);
	control->DelCmd();
}