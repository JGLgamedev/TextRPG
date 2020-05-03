#include <iostream>
#include "MagicAction.h"
#include "Character.h"

using namespace std;

MagicAction::MagicAction(Magic* magic, Character* attacker, Character* target):
    FightAction(),
    m_magic(magic),
    m_attacker(attacker),
    m_target(target)
{}

MagicAction::~MagicAction()
{}

void MagicAction::play()
{
    cout << m_attacker->getName() << " uses magic " << m_magic->getName() << " on " << m_target->getName() << endl;
    Sleep(1000);

    if(m_magic->getIsOffensive())
        m_target->reduceLifePoints(m_magic->getPower());
    else
        m_target->recoverLifePoints(m_magic->getPower());
    m_attacker->reduceMagicPoints(m_magic->getMpCost());
}
