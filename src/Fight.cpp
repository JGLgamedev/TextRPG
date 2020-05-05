#include "Fight.h"
#include <iostream>
#include <algorithm>
#include "Monster.h"

using namespace std;

Fight::Fight(PlayerCharacter &player):
    m_player(&player)
{}

Fight::~Fight()
{
    deleteEnemies();
}

bool Fight::start()
{
    cout << "Fight!" << endl;
    do{
        prepareTurn();
        startTurn();
        turnAftermath();
    } while (!isOver());

    if(m_enemies.empty()){
        cout << "Fight won!" << endl;
        return true;
    }
    else{
        cout << "Fight lost!" << endl;
        deleteEnemies();
        return false;
    }

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
        if(!(*fighter)->isDead())
            (*fighter)->playAction();
    }
}

void Fight::turnAftermath()
{
    for(vector<Character*>::iterator fighter=m_fighters.begin(); fighter!=m_fighters.end(); ++fighter){
        if((*fighter)->isDead() && (*fighter) != m_player)
            deleteEnemy((*fighter));
    }
}

bool Fight::isOver()
{
    return (m_enemies.empty() || m_player->isDead());
}

void Fight::choosePlayerAction()
{
    int chosenAction = -1;
    bool choiceDone = false;
    Magic* chosenMagic = NULL;
    Character* chosenEnemy = NULL;

    cout << "1. Attack" << endl;
    cout << "2. Magic" << endl;
    cout << "Action?" << endl;

    do{
        cin >> chosenAction;
        switch(chosenAction){
            case 1:
                chosenEnemy = chooseEnemy();
                m_player->attack(chosenEnemy);
                choiceDone = true;
                break;
            case 2:
                chosenMagic = chooseMagic();
                if(chosenMagic->getIsOffensive()){
                    chosenEnemy = chooseEnemy();
                    m_player->cast(chosenMagic, chosenEnemy);
                }
                else
                    m_player->cast(chosenMagic, m_player);
                choiceDone = true;
                break;
        }
    } while(!choiceDone);
    m_fighters.push_back(m_player);
}

Character* Fight::chooseEnemy()
{
    int chosenAction = -1;
    bool choiceDone = false;
    Character* chosenEnemy(NULL);

    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end(); ++enemy){
        cout << distance(m_enemies.begin(), enemy)+1 << ". " << (*enemy)->getName() << endl;
    }
    // no option to go back to previous menu
    cout << "Attack which enemy?" << endl;

    do{
        cin >> chosenAction;
        if(chosenAction <= int(m_enemies.size())){ // dirty cast
            chosenEnemy = m_enemies[chosenAction-1];
            choiceDone = true;
        }
    } while(!choiceDone);
    return chosenEnemy;
}

Magic* Fight::chooseMagic()
{
    int chosenAction = -1;
    bool choiceDone = false;
    vector<Magic*> magics = m_player->getMagics();
    Magic* chosenMagic(NULL);

    for(vector<Magic*>::iterator magic=magics.begin(); magic!=magics.end(); ++magic){
        cout << distance(magics.begin(), magic)+1 << ". " << (*magic)->getName() << " " << (*magic)->getMpCost() << endl;
    }

    do{
        cin >> chosenAction;
        if(chosenAction <= int(magics.size())){ // dirty cast
            chosenMagic = magics[chosenAction-1];
            choiceDone = true;
        }
    } while(!choiceDone);
    return chosenMagic;
}

void Fight::chooseEnemiesActions()
{
    for(vector<Character*>::iterator enemy=m_enemies.begin(); enemy!=m_enemies.end(); ++enemy){
        (*enemy)->attack(m_player);
        m_fighters.push_back((*enemy));
    }
}

bool compSpeed(Character* a, Character* b)
{
    return (a->getSpeedPoints() > b->getSpeedPoints());
}

void Fight::orderFighters()
{
    sort(m_fighters.begin(), m_fighters.end(), compSpeed);
}

void Fight::addEnemy(string name, int lifePoints, int magicPoints, int attackPoints, int defensePoints, int speedPoints)
{
    Character* newMonster = new Monster(name, lifePoints, magicPoints, attackPoints, defensePoints, speedPoints);
    m_enemies.push_back(newMonster);

    cout << newMonster->getName() << " appears!" << endl;
    Sleep(1000);
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
