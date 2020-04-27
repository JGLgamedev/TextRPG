#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"


class Monster : public Character
{
    public:
        Monster(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints);
        virtual ~Monster();

    protected:

    private:
};

#endif // MONSTER_H
