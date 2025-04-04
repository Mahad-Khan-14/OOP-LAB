#include <iostream>
#include <string>
using namespace std;

class Character
{
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "None")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() { cout << name << " performs a basic attack!\n"; }
    virtual void defend() { cout << name << " defends normally!\n"; }
    virtual void displayStats()
    {
        cout << "Character: " << name << "\nLevel: " << level
             << "\nHealth: " << healthPoints << "\nWeapon: " << weaponType << "\n";
    }
};

class Warrior : public Character
{
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, int armor, int dmg, string weapon = "Sword")
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(dmg) {}

    void attack() override
    {
        cout << name << " slashes with " << weaponType << " dealing " << meleeDamage << " damage!\n";
    }
};

class Mage : public Character
{
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int sp, string weapon = "Staff")
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(sp) {}

    void defend() override
    {
        cout << name << " uses a magical barrier, reducing damage!\n";
    }
};

class Archer : public Character
{
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, int arrows, int accuracy, string weapon = "Bow")
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override
    {
        cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy!\n";
        if (arrowCount > 0)
            arrowCount--;
        else
            cout << name << " has no arrows left!\n";
    }
};

class Rogue : public Character
{
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, int stealth, int agi, string weapon = "Dagger")
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void displayStats() override
    {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << "\nAgility: " << agility << "\n";
    }
};

int main()
{
    Warrior w(1, "Thor", 10, 150, 50, 30);
    Mage m(2, "Merlin", 12, 100, 80, 40);
    Archer a(3, "Legolas", 15, 120, 20, 90);
    Rogue r(4, "Ezio", 14, 110, 70, 95);

    w.displayStats();
    w.attack();
    cout << "-------------------\n";

    m.displayStats();
    m.defend();
    cout << "-------------------\n";

    a.displayStats();
    a.attack();
    cout << "-------------------\n";

    r.displayStats();

    return 0;
}
