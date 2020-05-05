#include <iostream>
#include "PlayerCharacter.h"
#include "Monster.h"
#include "Fight.h"

using namespace std;

int main()
{
    // Start a Fight
    PlayerCharacter player("Player", 100, 20, 10, 5, 20);
    Fight fight(player);
    fight.addEnemy("Bat", 10, 0, 10, 0, 30);
    fight.addEnemy("Troll", 20, 0, 20, 5, 5);
    fight.start();


    return 0;
}
