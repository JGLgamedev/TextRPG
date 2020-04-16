#include "PlayerCharacter.h"

#include <iostream>

using namespace std;

PlayerCharacter::PlayerCharacter(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints) :
    Character(name, lifePoints, magicPoints, attackPoints, defensePoints)
{
    //ctor
}

PlayerCharacter::~PlayerCharacter()
{
    //dtor
}
