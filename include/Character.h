#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <windows.h>
#include "FightAction.h"
#include "Magic.h"

/**
    The Character class represents a character that will participate in a Fight.
    It has differents stats used during combat, as well as a list of magic spells usable in combat.
    A FightAction is dynamically created each turn and deleted when it is played.
*/
class Character
{
    public:
        Character(std::string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints);
        virtual ~Character();

        /** Accessors */
        std::string getName() const;
        int getLifePoints() const;
        int getMagicPoints() const;
        int getAttackPoints() const;
        int getDefensePoints() const;
        int getSpeedPoints() const;
        std::vector<Magic*> getMagics() const;

        void reduceLifePoints(int valueToReduce);
        void reduceMagicPoints(int valueToReduce);
        void recoverLifePoints(int valueToRecover);
        void recoverMagicPoints(int valueToRecover);
        bool isDead() const;
        void attack(Character* target);
        void cast(Magic* magic, Character* target);
        void playAction();

    protected:
        /** The name will be displayed during battle */
        std::string m_name;
        /** Character stats */
        int m_lifePoints;
        int m_maxLifePoints;
        int m_magicPoints;
        int m_maxMagicPoints;
        int m_attackPoints;
        int m_defensePoints;
        int m_speedPoints;
        /** The action that will be played in the next battle turn */
        FightAction* m_action;
        /** List of Magic learned */
        std::vector<Magic*> m_magics;

        void cleanAction();
};

#endif // CHARACTER_H
