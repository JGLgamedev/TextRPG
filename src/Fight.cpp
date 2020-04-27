#include "Fight.h"
#include <iostream>
#include <algorithm>

using namespace std;

Fight::Fight(PlayerCharacter &player):
    m_player(&player)
{}

Fight::~Fight()
{
    deleteEnemies();
}

void Fight::start()
{
    cout << "Fight!" << endl;
    do{
        prepareTurn();
        startTurn();
        turnAftermath();
    } while (!isOver());
    cout << "Fight ended!" << endl;
}

void Fight::prepareTurn()
{
    printPlayerInfo();

    m_fighters.clear();
    choosePlayerAction();
    chooseEnemiesActions();
    orderFighters();
}

void Fight::startTurn()
{
    for(vector<Character*>::iterator fighter=m_fighters.begin(); fighter!=m_fighters.end(); ++fighter){
        if((*fighter)->getLifePoints() != 0)
            (*fighter)->playAction();
    }
}

void Fight::turnAftermath()
{
    for(vector<Character*>::iterator fighter=m_fighters.begin(); fighter!=m_fighters.end(); ++fighter){
        if((*fighter)->getLifePoints() == 0)
            deleteEnemy((*fighter));
    }
}

bool Fight::isOver()
{
    return (m_enemies.empty());
}

void Fight::choosePlayerAction()
{
    int chosenAction = -1;
    bool choiceDone = false;

    cout << "1. Attack" << endl;
    cout << "Action?" << endl;

    do{
        cin >> chosenAction;
        switch(chosenAction){
            case 1:
                chooseEnemyToAttack();
                choiceDone = true;
                break;
            default:
                break;
        }
    } while(!choiceDone);
    m_fighters.push_back(m_player);
}

void Fight::chooseEnemyToAttack()
{
    int chosenAction = -1;
    bool choiceDone = false;

    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end(); ++enemy){
        cout << distance(m_enemies.begin(), enemy)+1 << ". Attack " << (*enemy)->getName() << endl;
    }
    // add option to go back to previous menu
    cout << "Attack which enemy?" << endl;

    do{
        cin >> chosenAction;
        if(chosenAction <= int(m_enemies.size())){ // dirty cast
            m_player->attack(m_enemies[chosenAction-1]);
            choiceDone = true;
        }
    } while(!choiceDone);
}

void Fight::chooseEnemiesActions()
{
    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end(); ++enemy){
        (*enemy)->attack(m_player);
        m_fighters.push_back((*enemy));
    }
}

void Fight::orderFighters()
{
    // order m_fighters by speed
}

void Fight::addEnemy(Character* enemy)
{
    m_enemies.push_back(enemy);
    cout << enemy->getName() << " appears!" << endl;
}

void Fight::printPlayerInfo() const
{
    cout << endl;
    cout << "*********" << endl;
    cout << "HP: " << m_player->getLifePoints() << endl;
    cout << "MP: " << m_player->getMagicPoints() << endl;
    cout << "*********" << endl;
}

void Fight::deleteEnemy(Character* enemy)
{
    delete enemy;
    m_enemies.erase(remove(m_enemies.begin(), m_enemies.end(), enemy), m_enemies.end());
}

void Fight::deleteEnemies()
{
    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end();){
        delete (*enemy);
        enemy = m_enemies.erase(enemy);
    }
}
