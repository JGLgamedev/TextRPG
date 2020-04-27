#ifndef FIGHTACTION_H
#define FIGHTACTION_H

#include <string>

class FightAction
{
    public:
        FightAction();
        virtual ~FightAction();
        virtual void play() =0;
        std::string getType() const;

    protected:
        std::string m_type;

    private:

};

#endif // FIGHTACTION_H
