#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;

//������
class WindowsMediaPlayer
{
public:
	WindowsMediaPlayer(string name) :m_name(name) {}
	void play() { cout << "windowsplayer������Ƶ" << m_name << endl; }
private:
	string m_name;//��Ƶ����
};
class RealPlayer
{
public:
	RealPlayer(string name) :m_name(name) {}
	void play() { cout << "RealPlayer������Ƶ" << m_name << endl; }
private:
	string m_name;//��Ƶ����
};
//������
class PlayerAdapter
{
public:
	virtual void play() = 0;
};
class player :public PlayerAdapter
{
public:
	void play() { m_player->play(); }
private:
	shared_ptr<WindowsMediaPlayer> m_player;
};
int main()
{
	shared_ptr<WindowsMediaPlayer> player1 = make_shared<WindowsMediaPlayer>("ս��");
	player1->play();
	shared_ptr<RealPlayer> player2 = make_shared<RealPlayer>("�������");
	player2->play();
}