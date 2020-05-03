#include "PlayerCharacter.h"

#include <iostream>
#include "Magic.h"

using namespace std;

PlayerCharacter::PlayerCharacter(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints) :
    Character(name, lifePoints, magicPoints, attackPoints, defensePoints, speedPoints)
{
    m_magics.push_back(new Magic("Heal", 30, 5, false));
    m_magics.push_back(new Magic("Fire Ball", 20, 10, true));
}

PlayerCharacter::~PlayerCharacter()
{
    for(vector<Magic*>::iterator magic=m_magics.begin(); magic!=m_magics.end();){
        delete(*magic);
        magic = m_magics.erase(magic);
    }
}
