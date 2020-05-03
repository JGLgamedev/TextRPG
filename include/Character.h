#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <windows.h>
#include "FightAction.h"
#include "Magic.h"

class Character
{
    public:
        Character(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints);
        virtual ~Character();
        std::string getName() const;
        int getLifePoints() const;
        int getMagicPoints() const;
        int getAttackPoints() const;
        int getDefensePoints() const;
        int getSpeedPoints() const;
        std::vector<Magic*> getMagics();
        void reduceLifePoints(int valueToReduce);
        void reduceMagicPoints(int valueToReduce);
        void recoverLifePoints(int valueToRecover);
        void recoverMagicPoints(int valueToRecover);
        bool isDead() const;
        void attack(Character* target);
        void playAction();

    protected:
        std::string m_name;
        int m_lifePoints;
        int m_maxLifePoints;
        int m_magicPoints;
        int m_maxMagicPoints;
        int m_attackPoints;
        int m_defensePoints;
        int m_speedPoints;
        std::vector<Magic*> m_magics;
        FightAction* m_action;
        void cleanAction();

    private:

};

#endif // CHARACTER_H
