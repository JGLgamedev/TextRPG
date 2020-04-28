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

    // Start a Fight
    PlayerCharacter player("Toto", 100, 20, 10, 5, 20);
    Fight fight(player);
    fight.addEnemy(new Monster("Bat", 15, 0, 10, 0, 30));
    fight.addEnemy(new Monster("Troll", 20, 0, 20, 0, 5));
    fight.start();


    return 0;
}
