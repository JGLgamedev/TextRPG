#ifndef ATTACK_H
#define ATTACK_H

#include "FightAction.h"

// forward declaration
// see stackoverflow.com/questions/4964482/how-to-create-two-classes-in-c-which-use-each-other-as-data
class Character;

class Attack : public FightAction
{
    public:
        Attack(Character* attacker, Character* target);
        virtual ~Attack();
        virtual void play();

    protected:

    private:
        Character* m_attacker;
        Character* m_target;
};

#endif // ATTACK_H
