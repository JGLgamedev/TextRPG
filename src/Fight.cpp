#include "Fight.h"
#include <iostream>
#include <algorithm>
#include "Monster.h"

using namespace std;

/**
    Constructor
    player : the Fighter controlled by the player
*/
Fight::Fight(PlayerCharacter &player):
    m_player(&player)
{}

/**
    Destructor (virtual)
    Calls delete all objects created using addEnemy
*/
Fight::~Fight()
{
    deleteEnemies();
}

/**
    Start the Fight
    Loops as long as the fight is not over
    2 outcomes : all enemies are defeated and the fight is won, or the player is defeated and the fight is lost
    Return (bool) : true if the fight is won, false if the fight is lost.
*/
bool Fight::start()
{
    // Security if the function is called while no enemies are spawned.
    if(m_enemies.size() == 0){
        cout << "No enemies to fight." << endl;
        return true;
    }

    cout << "Fight!" << endl;

    do{
        prepareTurn();
        startTurn();
        turnAftermath();
    } while (!isOver()); // check if fight is over

    if(m_enemies.empty()){
        cout << "Fight won!" << endl;
        return true;
    }
    else{
        cout << "Fight lost!" << endl;
        deleteEnemies(); // delete the remaining enemies to prevent memory leak
        return false;
    }
}

/**
    Turn preparations
    All fighters select their actions.
    m_fighters starts empty, gets populated, and ordered.
    Eache Character's action is set.
*/
void Fight::prepareTurn()
{
    printPlayerInfo(); //

    m_fighters.clear();
    choosePlayerAction();
    chooseEnemiesActions();
    orderFighters();
}

/**
    Start a battle turn
    Play each fighter plays its action
*/
void Fight::startTurn()
{
    for(vector<Character*>::iterator fighter=m_fighters.begin(); fighter!=m_fighters.end(); ++fighter){
        if(!(*fighter)->isDead()) // dead fighters can't fight
            (*fighter)->playAction();
        if(m_player->isDead()) // quit loop if player is killed. Fight is lost.
            break;
    }
}

/**
    After a battle turn
    Delete dead enemies.
*/
void Fight::turnAftermath()
{
    for(vector<Character*>::iterator fighter=m_fighters.begin(); fighter!=m_fighters.end(); ++fighter){
        if((*fighter)->isDead() &&
           (*fighter) != m_player) // don't delete the player Character as it wasn't dynamically created
            deleteEnemy((*fighter));
    }
}

/**
    Check if the fight is over
    Either the enemies are defeated or the player is dead
*/
bool Fight::isOver()
{
    return (m_enemies.empty() || m_player->isDead());
}

/**
    Ask player's input for the next battle turn
    Player can choose between Attack and Magic.
*/
void Fight::choosePlayerAction()
{
    int chosenAction = 0;
    bool choiceDone = false;
    Magic* chosenMagic = NULL;
    Character* chosenEnemy = NULL;

    cout << "1. Attack" << endl;
    cout << "2. Magic" << endl;
    cout << "Action?" << endl;

    do{
        chosenAction = getSingleDigitInt(); // get a single digit integer from user
        switch(chosenAction){
            case 1: // player chooses Attack
                chosenEnemy = chooseEnemy();
                m_player->attack(chosenEnemy);
                choiceDone = true;
                break;
            case 2: // player chooses Magic
                chosenMagic = chooseMagic();
                if(chosenMagic->getIsOffensive()){ // if it's an offensive attack (Fire Ball), the player has to choose a target
                    chosenEnemy = chooseEnemy();
                    m_player->cast(chosenMagic, chosenEnemy);
                }
                else // if its a defensive attack (Heal), the target is the player
                    m_player->cast(chosenMagic, m_player);
                choiceDone = true;
                break;
        }
    } while(!choiceDone); // loop as long as the player hasn't made a suitable choice
    m_fighters.push_back(m_player); // one the player is all set, at it to the list of fighters
}

/**
    Ask player's input to select an enemy to attack
    Can be used for a physical attack or a magic attack
    Return (Character*) : pointer to the selected enemy
*/
Character* Fight::chooseEnemy()
{
    int chosenAction = -1;
    bool choiceDone = false;
    Character* chosenEnemy(NULL);

    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end(); ++enemy){
        cout << distance(m_enemies.begin(), enemy)+1 << ". " << (*enemy)->getName() << endl; // output the list of enemies for the player to select (+1 since the first enemy is number 0)
    }

    cout << "Attack which enemy?" << endl;
    do{
        chosenAction = getSingleDigitInt(); // get a single digit integer from user
        if(chosenAction <= int(m_enemies.size())){
            chosenEnemy = m_enemies[chosenAction-1]; // the selected enemy is the number entered by the player -1
            choiceDone = true;
        }
    } while(!choiceDone); // loop as long as the player hasn't made a suitable choice
    return chosenEnemy;
}

/**
    Ask player's input to select a magic
    Return (Magic*) : pointer to the selected magic spell
*/
Magic* Fight::chooseMagic()
{
    int chosenAction = -1;
    bool choiceDone = false;
    vector<Magic*> magics = m_player->getMagics();
    Magic* chosenMagic(NULL);

    for(vector<Magic*>::iterator magic=magics.begin(); magic!=magics.end(); ++magic){
        cout << distance(magics.begin(), magic)+1 << ". " << (*magic)->getName() << " " << (*magic)->getMpCost() << endl; // output the list of magic spells for the player to select (+1 since the first magic is number 0)
    }

    do{
        chosenAction = getSingleDigitInt(); // get a single digit integer from user
        if(chosenAction <= int(magics.size())){
            chosenMagic = magics[chosenAction-1]; // the selected magic spell is the number entered by the player -1
            choiceDone = true;
        }
    } while(!choiceDone); // loop as long as the player hasn't made a suitable choice
    return chosenMagic;
}

/**
    Get a single digit integer from user.
    Loop until a good input is given
*/
int Fight::getSingleDigitInt()
{
    string userInput;
    bool badInput = true;

    do{
        cin >> userInput;
        if(userInput.size() == 1 && isdigit(userInput[0])) {
            badInput = false;
        }
        else{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(badInput);

    return stoi(userInput);

}

/**
    Select the actions used by the enemies during the turn
    Here they only attacdk the player
*/
void Fight::chooseEnemiesActions()
{
    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end(); ++enemy){
        (*enemy)->attack(m_player);
        m_fighters.push_back((*enemy));
    }
}

/**
    Function used to order fighters by speed
*/
bool compSpeed(Character* a, Character* b)
{
    return (a->getSpeedPoints() > b->getSpeedPoints());
}

/**
    Order fighters by speed using compSpeed function
*/
void Fight::orderFighters()
{
    sort(m_fighters.begin(), m_fighters.end(), compSpeed);
}

/**
    Spawn an enemy from the given attributes
    The enemy is dynamically created and will be manually deleted
    The new enemy is added to the list of enemies
*/
void Fight::addEnemy(string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints)
{
    Character* newMonster = new Monster(name, lifePoints, magicPoints, attackPoints, defensePoints, speedPoints);
    m_enemies.push_back(newMonster);

    cout << newMonster->getName() << " appears!" << endl;
    Sleep(1000);
}

/**
    Simple UI function to output the HP and HP of the player
*/
void Fight::printPlayerInfo() const
{
    cout << endl;
    cout << "*********" << endl;
    cout << "HP: " << m_player->getLifePoints() << endl;
    cout << "MP: " << m_player->getMagicPoints() << endl;
    cout << "*********" << endl;
}

/**
    Delete a given enemy
    Manually delete the enemy and remove it from the list of enemies
*/
void Fight::deleteEnemy(Character* enemy)
{
    delete enemy;
    m_enemies.erase(remove(m_enemies.begin(), m_enemies.end(), enemy), m_enemies.end()); // erase–remove idiom
}

/**
    Delete all enemies
    Manually delete all enemies and remove them from the list of enemies
*/
void Fight::deleteEnemies()
{
    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end();){
        delete (*enemy);
        enemy = m_enemies.erase(enemy);
    }
    m_fighters.clear();
}
