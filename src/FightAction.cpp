#include "FightAction.h"

FightAction::FightAction(Character* protag) :
    m_protag(protag)
{}

FightAction::~FightAction()
{}

Character* FightAction::getProtag() const
{
    return m_protag;
}
