#include "Monster.h"
#include <iostream>

Monster::Monster(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints) :
    Character(name, lifePoints, magicPoints, attackPoints, defensePoints, speedPoints)
{}

Monster::~Monster()
{}
