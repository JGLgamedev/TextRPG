#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

/**
    Derives from Character
    The Monster class represents a monster that will participate in a Fight.
    Monster are dynamically created during the Fight, and deleted during or at the end of the fight.
*/
class Monster : public Character
{
    public:
        Monster(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints);
        virtual ~Monster();
};

#endif // MONSTER_H
