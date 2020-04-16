#include "Attack.h"
#include <iostream>

using namespace std;

Attack::Attack(Character* attacker, Character* target) :
    FightAction(attacker),
    m_target(target)
{}

Attack::~Attack()
{}

void Attack::playAction()
{
    cout << m_protag->getName() << " attacks " << m_target->getName() << "!" << endl;
    m_target->reduceLifePoints(m_protag->getAttackPoints());
}
