#ifndef HEALINGMAGIC_H
#define HEALINGMAGIC_H

#include "Magic.h"


class HealingMagic : public Magic
{
    public:
        HealingMagic(std::string name, int power, int mpCost, bool isGlobal);
        virtual ~HealingMagic();

    protected:

    private:
};

#endif // HEALINGMAGIC_H
