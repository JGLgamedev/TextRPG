#include <iostream>
#include "Attack.h"
#include "Character.h"

using namespace std;

Attack::Attack(Character* attacker, Character* target) :
    FightAction(),
    m_attacker(attacker),
    m_target(target)
{}

Attack::~Attack()
{}

void Attack::play()
{
    cout << m_attacker->getName() << " attacks " << m_target->getName() << "!" << endl;
    Sleep(1000);
    int damage = m_attacker->getAttackPoints() - m_target->getDefensePoints();
    if (damage < 0)
        damage = 0;
    m_target->reduceLifePoints(damage);
}
