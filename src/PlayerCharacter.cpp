#include "PlayerCharacter.h"

#include <iostream>
#include "AttackMagic.h"
#include "HealingMagic.h"

using namespace std;

PlayerCharacter::PlayerCharacter(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints) :
    Character(name, lifePoints, magicPoints, attackPoints, defensePoints, speedPoints)
{
    m_magics.push_back(new HealingMagic("Heal", 30, 5, false));
    m_magics.push_back(new AttackMagic("Fire Ball", 15, 5, false));
    m_magics.push_back(new AttackMagic("Ice Breath", 15, 10, true));
}

PlayerCharacter::~PlayerCharacter()
{
    for(vector<Magic*>::iterator magic=m_magics.begin(); magic!=m_magics.end();){
        delete(*magic);
        magic = m_magics.erase(magic);
    }
}
