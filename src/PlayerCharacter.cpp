#include "PlayerCharacter.h"
#include "Magic.h"

using namespace std;

/**
    Constructor
    Takes the character's stats as arguments.
    Dynamically creates 2 Magic spells learned by the PlayerCharacter
*/
PlayerCharacter::PlayerCharacter(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints) :
    Character(name, lifePoints, magicPoints, attackPoints, defensePoints, speedPoints)
{
    m_magics.push_back(new Magic("Heal", 30, 5, false)); // Support Magic, heals the player
    m_magics.push_back(new Magic("Fire Ball", 20, 10, true)); // Offensive Magic, hurts a Character
}

/**
    Destructor
    Deletes the Magic spells created in the constructor
*/
PlayerCharacter::~PlayerCharacter()
{
    for(vector<Magic*>::iterator magic=m_magics.begin(); magic!=m_magics.end();){
        delete(*magic);
        magic = m_magics.erase(magic);
    }
}
