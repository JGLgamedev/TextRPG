#include "Monster.h"
#include <iostream>

/**
    Constructor
    Takes the character's stats as arguments.
*/
Monster::Monster(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints) :
    Character(name, lifePoints, magicPoints, attackPoints, defensePoints, speedPoints)
{}

/**
    Destructor
*/
Monster::~Monster()
{}
