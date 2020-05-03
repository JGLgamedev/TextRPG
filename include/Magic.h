#ifndef MAGIC_H
#define MAGIC_H

#include <string>

class Magic
{
    public:
        Magic(std::string name, int power, int mpCost, bool isGlobal, bool isOffensive);
        virtual ~Magic();
        std::string getName()const;
        int getPower() const;
        int getMpCost() const;
        bool getIsGlobal() const;
        bool getIsOffensive() const;

    protected:

    private:
        std::string m_name;
        int m_power;
        int m_mpCost;
        bool m_isGlobal;
        bool m_isOffensive;
};

#endif // MAGIC_H
