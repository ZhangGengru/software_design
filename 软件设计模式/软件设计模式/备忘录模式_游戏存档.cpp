#include<string>
#include<iostream>
#include<vector>


using namespace std;

class Memento
{
	friend class GameRole;
private:
	Memento(int vitality, int attack, int defense) :vitality(vitality), attack(attack), defense(defense){}
	Memento& operator=(const Memento& memento)
	{
		vitality = memento.vitality;
		attack = memento.attack;
		defense = memento.defense;
		return *this;
	}
private:
	int vitality;//生命力
	int attack;//攻击力
	int defense;//防御力

};
class GameRole
{
public:
	GameRole():vitality(100),attack(100),defense(100){}
	Memento* Save()
	{
		//Memento memento(vitality, attack, defense);
		return new Memento(vitality, attack, defense);
	}
	void Load(Memento* memento)
	{
		vitality = memento->vitality;
		attack = memento->attack;
		defense = memento->defense;
	}
	void Show()
	{
		cout << "生命力：" << vitality << endl;
		cout << "攻击力：" << attack << endl;
		cout << "防御力：" << defense << endl;
	}
	void Attack()
	{
		vitality -= 10;
		attack -= 10;
		defense -=10;
	}

private:
	int vitality;//生命力
	int attack;//攻击力
	int defense;//防御力
};
class Caretaker
{
public:
	void Save(Memento* memento)
	{
		m_mementos.push_back(memento);
	}
	Memento* Load(int index)
	{
		return m_mementos[index];
	}
private:
	vector<Memento*> m_mementos;
};

int main()
{
	Caretaker caretaker;
	GameRole gameRole;
	gameRole.Show();
	caretaker.Save(gameRole.Save());
	gameRole.Attack();
	gameRole.Show();
	//恢复
	gameRole.Load(caretaker.Load(0));
	gameRole.Show();
	return 0;
}