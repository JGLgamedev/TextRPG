#include <iostream>
#include "PlayerCharacter.h"
#include "Monster.h"
#include "Fight.h"

using namespace std;

int main()
{
/*
    // Create player Character
    string playerName;
    cout << "Name ?" << endl;
    getline(cin, playerName);
    PlayerCharacter player(playerName, 100, 20, 10, 5);
*/

    PlayerCharacter player("Test", 100, 20, 10, 5);

    Fight fight(player);
    fight.addEnemy(new Monster("Rat", 15, 0, 10, 0));
    fight.addEnemy(new Monster("Bat", 20, 0, 20, 0));
    fight.start();

    return 0;
}
