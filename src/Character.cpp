#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints) :
    m_name(name),
    m_lifePoints(lifePoints),
    m_maxLifePoints(lifePoints),
    m_magicPoints(magicPoints),
    m_maxMagicPoints(magicPoints),
    m_attackPoints(attackPoints),
    m_defensePoints(defensePoints)
{
    //ctor
}

Character::~Character()
{
    //dtor
}

string Character::getName() const
{
    return m_name;
}

int Character::getLifePoints() const
{
    return m_lifePoints;
}

int Character::getMagicPoints() const
{
    return m_magicPoints;
}

int Character::getAttackPoints() const
{
    return m_attackPoints;
}
int Character::getDefensePoints() const
{
    return m_defensePoints;
}

void Character::reduceLifePoints(int valueToReduce)
{
    m_lifePoints -= valueToReduce;
    if (m_lifePoints < 0)
        m_lifePoints = 0;
    cout << m_name << " has lost " << valueToReduce << " HP. And now has " << m_lifePoints << " HP." << endl;

}

void Character::reduceMagicPoints(int valueToReduce)
{
    m_magicPoints -= valueToReduce;
    if (m_magicPoints < 0)
        m_magicPoints = 0;
    cout << m_name << " has lost " << valueToReduce << " MP. And now has " << m_magicPoints << " MP." << endl;
}
void Character::recoverLifePoints(int valueToRecover)
{
    m_lifePoints += valueToRecover;
    if (m_lifePoints > m_maxLifePoints)
        m_lifePoints = m_maxLifePoints;
    cout << m_name << " has regained " << valueToRecover << " HP. And now has " << m_lifePoints << " HP." << endl;
}
void Character::recoverMagicPoints(int valueToRecover)
{
    m_magicPoints += valueToRecover;
    if (m_magicPoints > m_maxMagicPoints)
        m_magicPoints = m_maxMagicPoints;
    cout << m_name << " has regained " << valueToRecover << " MP. And now has " << m_magicPoints << " MP." << endl;
}
