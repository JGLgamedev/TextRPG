#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <vector>
#include "Character.h"

/**
    Derives from Character
    The PlayerCharacter class represents the Character controlled by the player.
    A PlayerCharacter is created before the fight, and exits the fight without being deleted.
*/
class PlayerCharacter : public Character
{
    public:
        PlayerCharacter(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints);
        virtual ~PlayerCharacter();
};

#endif // PLAYERCHARACTER_H
