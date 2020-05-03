#include "AttackMagic.h"

AttackMagic::AttackMagic(std::string name, int power, int mpCost, bool isGlobal):
    Magic(name, power, mpCost, isGlobal, true)
{}

AttackMagic::~AttackMagic()
{}
