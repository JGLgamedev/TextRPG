#include <iostream>
#include "Character.h"
#include "AttackAction.h"
#include "MagicAction.h"

using namespace std;

/**
    Constructor
    Takes the character's stats as arguments.
    FightAction pointer set to NULL.
*/
Character::Character(string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints) :
    m_name(name),
    m_lifePoints(lifePoints),
    m_maxLifePoints(lifePoints),
    m_magicPoints(magicPoints),
    m_maxMagicPoints(magicPoints),
    m_attackPoints(attackPoints),
    m_defensePoints(defensePoints),
    m_speedPoints(speedPoints),
    m_action(NULL)
{}

/**
    Destructor
    Delete the FightAction since it was created dynamically
*/
Character::~Character()
{
    cleanAction();
}

/**
    Accessors for the different attributes
*/
string Character::getName() const { return m_name; }
int Character::getLifePoints() const { return m_lifePoints; }
int Character::getMagicPoints() const { return m_magicPoints; }
int Character::getAttackPoints() const { return m_attackPoints; }
int Character::getDefensePoints() const { return m_defensePoints; }
int Character::getSpeedPoints() const { return m_speedPoints; }
std::vector<Magic*> Character::getMagics() const { return m_magics; }

/**
    Reduce HP by the given value
    Charatcer dies if its HP reaches 0.
*/
void Character::reduceLifePoints(int valueToReduce)
{
    m_lifePoints -= valueToReduce;
    if (m_lifePoints < 0)
        m_lifePoints = 0;

    cout << m_name << " has lost " << valueToReduce << " HP. And now has " << m_lifePoints << " HP." << endl;
    Sleep(1000);

    if (m_lifePoints == 0) {
        cout << m_name << " is dead!" << endl;
        Sleep(1000);
    }
}

/**
    Reduce MP by the given value
*/
void Character::reduceMagicPoints(int valueToReduce)
{
    m_magicPoints -= valueToReduce;
    if (m_magicPoints < 0)
        m_magicPoints = 0;

    cout << m_name << " has lost " << valueToReduce << " MP. And now has " << m_magicPoints << " MP." << endl;
    Sleep(1000);
}

/**
    Reduce HP by the given value
    Can't recover more than max HP
*/
void Character::recoverLifePoints(int valueToRecover)
{
    m_lifePoints += valueToRecover;
    if (m_lifePoints > m_maxLifePoints)
        m_lifePoints = m_maxLifePoints;

    cout << m_name << " has regained " << valueToRecover << " HP. And now has " << m_lifePoints << " HP." << endl;
    Sleep(1000);
}

/**
    Reduce MP by the given value
    Can't recover more than max MP
*/
void Character::recoverMagicPoints(int valueToRecover)
{
    m_magicPoints += valueToRecover;
    if (m_magicPoints > m_maxMagicPoints)
        m_magicPoints = m_maxMagicPoints;

    cout << m_name << " has regained " << valueToRecover << " MP. And now has " << m_magicPoints << " MP." << endl;
    Sleep(1000);
}

/**
    Check if Character is dead.
    Return (bool) : TRUE if dead, FALSE if alive
*/
bool Character::isDead() const
{
    return (m_lifePoints == 0);
}

/**
    Delete the FightAction that was dynamically created attack() or cast()
    Set FightAction pointer to NULL
*/
void Character::cleanAction()
{
    if(m_action != NULL){
        delete m_action;
        m_action = NULL;
    }
}

/**
    Play the defined FightAction during a turn and delete it after
*/
void Character::playAction()
{
    m_action->play();
    cleanAction();
}

/**
    Dynamically creates an AttackAction
    target (Character*) : pointer to the Character to attack
*/
void Character::attack(Character* target)
{
    cleanAction();
    m_action = new AttackAction(this, target);
}

/**
    Dynamically creates a MagicAction
    target (Character*) : pointer to the Character to attack if it is an offensive magic, ally if it is a support magic
*/
void Character::cast(Magic* magic, Character* target)
{
    cleanAction();
    m_action = new MagicAction(magic, this, target);
}
