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
    PlayerCharacter player(playerName, 100, 20);
    */

    PlayerCharacter player("Test", 100, 20, 10, 5);

    Fight* pFight = new Fight(player);
    pFight->addEnemy(new Monster("Rat", 15, 0, 2, 0));
    //pFight->addEnemy(new Monster("Troll", 25, 0, 10, 0));
    pFight->start();

    delete pFight;
    pFight = NULL;


    return 0;
}
