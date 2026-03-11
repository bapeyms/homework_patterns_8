#include <iostream>
#include <string>
using namespace std;

class Character 
{
protected:
    string modifiers;
    string name;
public:
    virtual ~Character() {}
    virtual string getModifiers() 
    { 
        return modifiers; 
    }
    virtual string getName()
    {
        return name;
    }
    virtual void move(double& atk, double& speed, double& hp, double& shield) = 0;
};

class Person : public Character 
{
public:
    Person() 
    { 
        modifiers = "Human"; 
        name = "Human";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override 
    {
        atk += 20;
        speed += 20;
        hp += 150;
        shield += 0;
    }
};

class CharacterDecorator : public Character
{
protected:
    Character* character;
public:
    CharacterDecorator(Character* ch) : character(ch) {}
    virtual ~CharacterDecorator() 
    {
        if (character) 
        {
            delete character;
            character = nullptr;
        }
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        if (character)
        {
            character->move(atk, speed, hp, shield);
        }
    }

    string getModifiers() override
    {
        return character->getModifiers();
    }
};

class PersonWarrior : public CharacterDecorator 
{
public:
    PersonWarrior(Character* ch) : CharacterDecorator(ch) {}
    ~PersonWarrior() {}

    string getModifiers() override 
    {
        return CharacterDecorator::getModifiers() + " -> Human Warrior";
    }
    string getName() override
    {
        return "Human Warrior";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override 
    {
        CharacterDecorator::move(atk, speed, hp, shield);

        atk += 20;
        speed += 10;
        hp += 50;
        shield += 20;
    }
};
class Swordsman : public CharacterDecorator 
{
public:
    Swordsman(Character* ch) : CharacterDecorator(ch) {}
    ~Swordsman() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Swordsman";
    }
    string getName() override
    {
        return "Swordsman";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override 
    {
        CharacterDecorator::move(atk, speed, hp, shield);
        atk += 40;
        speed -= 10;
        hp += 50;
        shield += 40;
    }
};
class Archer : public CharacterDecorator
{
public:
    Archer(Character* ch) : CharacterDecorator(ch) {}
    ~Archer() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Archer";
    }
    string getName() override
    {
        return "Archer";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        CharacterDecorator::move(atk, speed, hp, shield);
        atk += 20;
        speed += 20;
        hp += 50;
        shield += 10;
    }
};
class Rider : public CharacterDecorator
{
public:
    Rider(Character* ch) : CharacterDecorator(ch) {}
    ~Rider() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Rider";
    }
    string getName() override
    {
        return "Rider";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        CharacterDecorator::move(atk, speed, hp, shield);
        atk -= 10;
        speed += 40;
        hp += 200;
        shield += 100;
    }
};

class Elf : public Character
{
public:
    Elf()
    {
        modifiers = "Elf";
        name = "Elf";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        atk += 15;
        speed += 30;
        hp += 100;
        shield += 0;
    }
};
class ElfWarrior : public CharacterDecorator
{
public:
    ElfWarrior(Character* ch) : CharacterDecorator(ch) {}
    ~ElfWarrior() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Elf Warrior";
    }
    string getName() override
    {
        return "Elf Warrior";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        CharacterDecorator::move(atk, speed, hp, shield);

        atk += 20;
        speed -= 10;
        hp += 100;
        shield += 20;
    }
};
class ElfMagician : public CharacterDecorator
{
public:
    ElfMagician(Character* ch) : CharacterDecorator(ch) {}
    ~ElfMagician() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Elf Magician";
    }
    string getName() override
    {
        return "Elf Magician";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        CharacterDecorator::move(atk, speed, hp, shield);

        atk += 10;
        speed += 10;
        hp -= 50;
        shield += 10;
    }
};
class Crossbowman : public CharacterDecorator
{
public:
    Crossbowman(Character* ch) : CharacterDecorator(ch) {}
    ~Crossbowman() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Crossbowman";
    }
    string getName() override
    {
        return "Crossbowman";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        CharacterDecorator::move(atk, speed, hp, shield);

        atk += 20;
        speed += 10;
        hp += 50;
        shield -= 10;
    }
};
class EvilMagician : public CharacterDecorator
{
public:
    EvilMagician(Character* ch) : CharacterDecorator(ch) {}
    ~EvilMagician() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Evil Magician";
    }
    string getName() override
    {
        return "Evil Magician";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        CharacterDecorator::move(atk, speed, hp, shield);

        atk += 70;
        speed += 20;
        hp += 0;
        shield += 0;
    }
};
class KindMagician : public CharacterDecorator
{
public:
    KindMagician(Character* ch) : CharacterDecorator(ch) {}
    ~KindMagician() {}

    string getModifiers() override
    {
        return CharacterDecorator::getModifiers() + " -> Kind Magician";
    }
    string getName() override
    {
        return "Kind Magician";
    }

    void move(double& atk, double& speed, double& hp, double& shield) override
    {
        CharacterDecorator::move(atk, speed, hp, shield);

        atk += 50;
        speed += 30;
        hp += 100;
        shield += 30;
    }
};

void printHeroInfo(Character* c) 
{
    double a = 0, s = 0, h = 0, sh = 0;
    c->move(a, s, h, sh);

    cout << ">> Profession: Applied '" << c->getModifiers() << "' modifiers" << endl;
    cout << "--- Character Info ---" << endl;
    cout << "Name: " << c->getName() << endl;
    cout << "Attack: " << a << " | Speed: " << s << " | HP: " << h << " | Shield: " << sh << endl;
    cout << "----------------------\n\n";
}

int main() 
{
    cout << "------------ HUMAN ------------" << endl;
    Character* myHero1 = new Person();
    printHeroInfo(myHero1);
    myHero1 = new PersonWarrior(myHero1);
    printHeroInfo(myHero1);
    myHero1 = new Swordsman(myHero1);
    printHeroInfo(myHero1);
    myHero1 = new Archer(myHero1);
    printHeroInfo(myHero1);
    myHero1 = new Rider(myHero1);
    printHeroInfo(myHero1);

    cout << "------------ ELF ------------" << endl;
    Character* myHero2 = new Elf();
    printHeroInfo(myHero2);
    myHero2 = new ElfWarrior(myHero2);
    printHeroInfo(myHero2);
    myHero2 = new ElfMagician(myHero2);
    printHeroInfo(myHero2);
    myHero2 = new Crossbowman(myHero2);
    printHeroInfo(myHero2);

    Character* evilElf = new Elf();
    evilElf = new ElfMagician(evilElf);
    evilElf = new EvilMagician(evilElf);
    printHeroInfo(evilElf);

    Character* goodElf = new Elf();
    goodElf = new ElfMagician(goodElf);
    goodElf = new KindMagician(goodElf);
    printHeroInfo(goodElf);

    delete myHero1;
    delete myHero2;

    return 0;
}