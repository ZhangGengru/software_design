#include<iostream>
#include<string>
#include<list>
#include<memory>

using namespace std;

//适配者
class WindowsMediaPlayer
{
public:
	WindowsMediaPlayer(string name) :m_name(name) {}
	void play() { cout << "windowsplayer播放视频" << m_name << endl; }
private:
	string m_name;//视频名称
};
class RealPlayer
{
public:
	RealPlayer(string name) :m_name(name) {}
	void play() { cout << "RealPlayer播放视频" << m_name << endl; }
private:
	string m_name;//视频名称
};
//适配器
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
	shared_ptr<WindowsMediaPlayer> player1 = make_shared<WindowsMediaPlayer>("战狼");
	player1->play();
	shared_ptr<RealPlayer> player2 = make_shared<RealPlayer>("赛博朋克");
	player2->play();
}