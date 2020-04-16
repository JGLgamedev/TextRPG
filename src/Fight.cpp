#include "Fight.h"
#include "Attack.h"
#include <iostream>

using namespace std;

Fight::Fight(PlayerCharacter &player):
    m_player(&player),
    m_fightIsOver(false)
{}

Fight::~Fight()
{
    deleteEnemies();
    deleteActions();
}

void Fight::start()
{
    cout << "Fight!" << endl;

    while(!m_fightIsOver){
        startTurn();
        m_fightIsOver = isFightOver();
    }
    cout << "Fight ended!" << endl;
}

void Fight::startTurn()
{
    printPlayerInfo();
    choosePlayerAction();
    chooseEnemiesActions();

    while(m_fightActions.size() > 0){
        m_fightActions[0]->playAction();
        finishAction(0);
        turnAftermath();
    }
}

void Fight::turnAftermath()
{
    // if the player is dead
    if(m_player->getLifePoints() == 0) {
        // add what happens if the player is dead
    }
    // REWORK THE FOR LOOPS !!!
    // BUG IF 2 ENEMIES DIE THE SAME TURN !!!
    for(int i=0; i<m_enemies.size(); i++) {
        // check if an enemy has died
        if(m_enemies[i]->getLifePoints() == 0){
            // if an enemy has died, check if he has a remaining action, if so, delete it
            for(int j=0; j<m_fightActions.size(); j++) {
               if(m_fightActions[j]->getProtag() == m_enemies[i]){
                    finishAction(j);
               }
            }
            killEnemy(i);
        }
    }
}

bool Fight::isFightOver()
{
    if(m_enemies.empty())
        return true;
    return false;
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
}

void Fight::chooseEnemyToAttack()
{
    int chosenAction = -1;
    bool choiceDone = false;

    for(int i=0; i<m_enemies.size(); i++){
        cout << i+1 << ". Attack " << m_enemies[i]->getName() << endl;
    }
    // add option to go back to previous menu
    cout << "Attack which enemy?" << endl;

    do{
        cin >> chosenAction;
        if(chosenAction <= m_enemies.size()){
            m_fightActions.push_back(new Attack(m_player, m_enemies[chosenAction-1]));
            choiceDone = true;
        }

    } while(!choiceDone);
}

void Fight::chooseEnemiesActions()
{
    for(int i=0; i<m_enemies.size(); i++){
        m_fightActions.push_back(new Attack(m_enemies[i], m_player));
    }
}

void Fight::addEnemy(Character* enemy)
{
    m_enemies.push_back(enemy);
}

void Fight::printPlayerInfo() const
{
    cout << endl;
    cout << "*********" << endl;
    cout << "HP: " << m_player->getLifePoints() << endl;
    cout << "MP: " << m_player->getMagicPoints() << endl;
    cout << "*********" << endl;
}

void Fight::killEnemy(int enemyIndex)
{
    delete m_enemies[enemyIndex];
    m_enemies.erase(m_enemies.begin() + enemyIndex);
}

void Fight::deleteEnemies()
{
    while(m_enemies.size() > 0){
        killEnemy(0);
    }
    cout << "Enemies: " << m_enemies.size() <<endl;
}

void Fight::finishAction(int actionIndex)
{
    delete m_fightActions[actionIndex];
    m_fightActions.erase(m_fightActions.begin() + actionIndex);
}

void Fight::deleteActions()
{
    while(m_fightActions.size() > 0){
        finishAction(0);
    }
    cout << "Actions: " << m_fightActions.size() << endl;
}
