#include "Fight.h"
#include <iostream>

using namespace std;

Fight::Fight(PlayerCharacter &player):
    m_player(&player),
    m_focusedEnemyIndex(-1)
{}

Fight::~Fight()
{}

void Fight::start()
{
    cout << "Fight!" << endl;

    while (!m_enemies.empty()){
        printPlayerInfo();
        choosePlayerAction();
        playerTurn();
        if(!m_enemies.empty())
            enemyTurn();
    }
    cout << "Fight ended!" << endl;
}

void Fight::addEnemy(Character* enemy)
{
    m_enemies.push_back(enemy);
}

void Fight::choosePlayerAction()
{
    int chosenAction = 0;
    bool choiceDone = false;

    cout << "Action?" << endl;
    for(int i=0; i<m_enemies.size(); i++){
        cout << i+1 << ". Attack " << m_enemies[i]->getName() << endl;
    }
    do{
        cin >> chosenAction;
        if(chosenAction <= m_enemies.size()){
            m_focusedEnemyIndex = chosenAction-1;
            choiceDone = true;
        }
    } while(!choiceDone);
}

void Fight::playerTurn()
{
    cout << "Player turn" << endl;
    Character* enemy = m_enemies[m_focusedEnemyIndex];
    enemy->reduceLifePoints(m_player->getAttackPoints());
    if (enemy->getLifePoints() <= 0){
        delete enemy;
        m_enemies.erase(m_enemies.begin() + m_focusedEnemyIndex);
    }
}

void Fight::enemyTurn()
{
    cout << "Enemy turn" << endl;
    for(int i=0; i<m_enemies.size(); i++){
        cout << m_enemies[i]->getName() << " attacks!" << endl;
        m_player->reduceLifePoints(m_enemies[i]->getAttackPoints());
    }
}

void Fight::printPlayerInfo() const
{
    cout << endl;
    cout << "*********" << endl;
    cout << "HP: " << m_player->getLifePoints() << endl;
    cout << "MP: " << m_player->getMagicPoints() << endl;
    cout << "*********" << endl;
}
