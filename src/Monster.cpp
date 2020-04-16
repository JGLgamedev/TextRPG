#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints) :
    Character(name, lifePoints, magicPoints, attackPoints, defensePoints)
{
    //ctor
    cout << m_name << " appears." << endl;
}

Monster::~Monster()
{
    //dtor
    cout << m_name << " is killed." << endl;
}
