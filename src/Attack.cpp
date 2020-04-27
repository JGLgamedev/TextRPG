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
    m_target->reduceLifePoints(m_attacker->getAttackPoints());
}
