#ifndef FIGHTACTION_H
#define FIGHTACTION_H

/**
    Abstract class.
    The FightAction class represents an action done by a Character during a battle turn.
    One is created during the preparation phase, and deleted after the turn.
*/

class FightAction
{
    public:
        FightAction();
        virtual ~FightAction();
        virtual void play() =0;
};

#endif // FIGHTACTION_H
