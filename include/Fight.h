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
        std::vector<FightAction*> m_fightActions;
        bool m_fightIsOver;
        void startTurn();
        void printPlayerInfo() const;
        void choosePlayerAction();
        void chooseEnemyToAttack();
        void chooseEnemiesActions();
        void turnAftermath();
        bool isFightOver();
        void killEnemy(int enemyIndex);
        void finishAction(int actionIndex);
        void deleteEnemies();
        void deleteActions();
};

#endif // FIGHT_H
