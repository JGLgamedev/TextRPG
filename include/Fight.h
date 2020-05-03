#ifndef FIGHT_H
#define FIGHT_H

#include "PlayerCharacter.h"
#include "FightAction.h"

class Fight
{
    public:
        Fight(PlayerCharacter &player);
        virtual ~Fight();
        void start();
        void addEnemy(Character* enemy);

    protected:

    private:
        PlayerCharacter* m_player;
        std::vector<Character*> m_enemies;
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
