#ifndef FIGHTACTION_H
#define FIGHTACTION_H

#include "Character.h"

class FightAction
{
    public:
        FightAction(Character* protag);
        virtual ~FightAction();
        virtual void playAction() =0;
        Character* getProtag() const;

    protected:
        Character* m_protag;
    private:

};

#endif // FIGHTACTION_H
