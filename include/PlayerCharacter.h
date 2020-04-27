#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "Character.h"
#include <vector>

class PlayerCharacter : public Character
{
    public:
        PlayerCharacter(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints);
        virtual ~PlayerCharacter();

    protected:

    private:
};

#endif // PLAYERCHARACTER_H
