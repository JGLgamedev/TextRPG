#ifndef FIGHTACTION_H
#define FIGHTACTION_H

class FightAction
{
    public:
        FightAction();
        virtual ~FightAction();
        virtual void play() =0;

    protected:

    private:

};

#endif // FIGHTACTION_H
