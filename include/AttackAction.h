#ifndef ATTACK_H
#define ATTACK_H

#include "FightAction.h"

// forward declaration
class Character;

/**
    Derives from FightAction
    The AttackAction represents a physical attack used during a battle turn.
*/
class AttackAction : public FightAction
{
    public:
        AttackAction(Character* attacker, Character* target);
        virtual ~AttackAction();
        virtual void play();

    private:
        /** Pointer to the Character launching the action */
        Character* m_attacker;
        /** Pointer to the Character receiving the effects of the action */
        Character* m_target;
};

#endif // ATTACK_H
