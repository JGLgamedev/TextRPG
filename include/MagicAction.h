#ifndef MAGICACTION_H
#define MAGICACTION_H

#include "FightAction.h"
#include "Magic.h"

class Character;

class MagicAction : public FightAction
{
    public:
        MagicAction(Magic* magic, Character* attacker, Character* target);
        virtual ~MagicAction();
        virtual void play();

    protected:

    private:
        Magic* m_magic;
        Character* m_attacker;
        Character* m_target;
};

#endif // MAGICACTION_H
