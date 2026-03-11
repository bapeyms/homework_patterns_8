#include <iostream>
using namespace std;

class Character
{
protected:
	double atk;
	double speed;
	double hp;
	double shield;
public:
	Character(double a, double s, double h, double sh)
	{
		atk = a;
		speed = s;
		hp = h;
		shield = sh;
	}
	double getAtk()
	{
		return atk;
	}
	double getSpeed()
	{
		return speed;
	}
	double getHp()
	{
		return hp;
	}
	double getShield()
	{
		return shield;
	}

	void setAtk(double atk)
	{
		this->atk = atk;
	}
	void setSpeed(double speed)
	{
		this->speed = speed;
	}
	void setHp(double hp)
	{
		this->hp = hp;
	}
	void setShield(double shield)
	{
		this->shield = shield;
	}
};
class Person : public Character
{
public:
	Person(double a, double s, double h, double sh) 
		: Character(20, 20, 150, 0) {}
};
class Elf : public Character
{
public:
	Elf(double a, double s, double h, double sh)
		: Character(20, 20, 150, 0) {}
};

class CharacterDecorator : public Character
{
protected:
	Character* character;
public:
	CharacterDecorator(double a, double s, double h, double sh, Character* ch) 
		: Character(a, s, h, sh) 
	{
		this->character = ch;
	}
};
class PersonWarrior : public CharacterDecorator
{
public:
	PersonWarrior(Character* ch) : CharacterDecorator(ch->setAtk(atk + 20), ch->setSpeed(10), ch->setHp(50), ch->setShield(20), ch) {};
};

int main()
{
	return 0;
}