#ifndef FIGHT_H
#define FIGHT_H

#include "PlayerCharacter.h"
#include "FightAction.h"

/**
    The Fight class handles the battle between the player and one or several monsters.
    This class dynamically creates monsters using the addEnemy method.
    The battle is then started using the start method.
    Player actions are requested and the differents steps of the battle
    are printed in the console.
    The battle ends by either the player's victory or the player's defeat
*/
class Fight
{
    public:
        Fight(PlayerCharacter &player);
        virtual ~Fight();

        bool start();
        void addEnemy(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints);

    private:
        /** Character controlled by the player. */
        PlayerCharacter* m_player;
        /** List of enemies. Must be clear at the end of the fight .*/
        std::vector<Character*> m_enemies;
        /** List of fighters for a battle turn. Consists of the player and the enemies. Must be clear at the end of the turn. */
        std::vector<Character*> m_fighters;

        void startTurn();
        void prepareTurn();
        void turnAftermath();
        void printPlayerInfo() const;
        void choosePlayerAction();
        Character* chooseEnemy();
        Magic* chooseMagic();
        void chooseEnemiesActions();
        void orderFighters();
        bool isOver();
        void deleteEnemy(Character* enemy);
        void deleteEnemies();
};

#endif // FIGHT_H
