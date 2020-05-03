#include "HealingMagic.h"

HealingMagic::HealingMagic(std::string name, int power, int mpCost, bool isGlobal):
    Magic(name, power, mpCost, isGlobal, false)
{}

HealingMagic::~HealingMagic()
{}
