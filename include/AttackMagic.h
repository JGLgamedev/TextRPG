#ifndef ATTACKMAGIC_H
#define ATTACKMAGIC_H

#include "Magic.h"


class AttackMagic : public Magic
{
    public:
        AttackMagic(std::string name, int power, int mpCost, bool isGlobal);
        virtual ~AttackMagic();

    protected:

    private:
};

#endif // ATTACKMAGIC_H
