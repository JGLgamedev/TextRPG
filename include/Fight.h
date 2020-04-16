#ifndef FIGHT_H
#define FIGHT_H

#include "PlayerCharacter.h"

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
        int m_focusedEnemyIndex;
        void playerTurn();
        void enemyTurn();
        void printPlayerInfo() const;
        void choosePlayerAction();
};

#endif // FIGHT_H
