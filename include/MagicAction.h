#ifndef MAGICACTION_H
#define MAGICACTION_H

#include "FightAction.h"
#include "Magic.h"

// forward declaration
class Character;

/**
    Derives from FightAction
    The MagicAction represents a magic spell used during a battle turn.
*/
class MagicAction : public FightAction
{
    public:
        MagicAction(Magic* magic, Character* attacker, Character* target);
        virtual ~MagicAction();
        virtual void play();

    private:
        /** The magic spell to use */
        Magic* m_magic;
        /** Pointer to the Character launching the action */
        Character* m_attacker;
        /** Pointer to the Character receiving the effects of the action */
        Character* m_target;
};

#endif // MAGICACTION_H
