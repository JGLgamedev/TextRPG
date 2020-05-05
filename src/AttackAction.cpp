#include <iostream>
#include "AttackAction.h"
#include "Character.h"

using namespace std;

/**
    Constructor
    m_attacker (Character*) : Pointer to the Character launching the action
    m_target (Character*) : Pointer to the Character receiving the effects of the action
*/
AttackAction::AttackAction(Character* attacker, Character* target) :
    FightAction(),
    m_attacker(attacker),
    m_target(target)
{}

/**
    Destructor
*/
AttackAction::~AttackAction()
{}

/**
    Calculates and deals the damage done to the target.
    Uses the attacker's Attack Points and the target's Defense Points.
*/
void AttackAction::play()
{
    cout << m_attacker->getName() << " attacks " << m_target->getName() << "!" << endl;
    Sleep(1000);
    int damage = m_attacker->getAttackPoints() - m_target->getDefensePoints();
    if (damage < 0)
        damage = 0;
    m_target->reduceLifePoints(damage);
}
