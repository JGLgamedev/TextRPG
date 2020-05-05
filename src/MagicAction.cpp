#include <iostream>
#include "MagicAction.h"
#include "Character.h"

using namespace std;

/**
    Constructor
*/
MagicAction::MagicAction(Magic* magic, Character* attacker, Character* target):
    FightAction(),
    m_magic(magic),
    m_attacker(attacker),
    m_target(target)
{}

/**
    Destructor
*/
MagicAction::~MagicAction()
{}

/**
    Calculates and deals the magic effect done to the target.
    Uses the magic spell's Power.
*/
void MagicAction::play()
{
    cout << m_attacker->getName() << " uses magic " << m_magic->getName() << " on " << m_target->getName() << "!" << endl;
    Sleep(1000);

    if(m_magic->getIsOffensive()) // if it's an offensive spell, reduce HP
        m_target->reduceLifePoints(m_magic->getPower());
    else // if it's a support spell, recover HP
        m_target->recoverLifePoints(m_magic->getPower());
    m_attacker->reduceMagicPoints(m_magic->getMpCost()); // reduce the caster's MP
}
