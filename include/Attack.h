#ifndef ATTACK_H
#define ATTACK_H

#include "FightAction.h"

class Attack : public FightAction
{
    public:
        Attack(Character* attacker, Character* target);
        virtual ~Attack();
        virtual void playAction();

    protected:

    private:
        Character* m_target;
};

#endif // ATTACK_H
