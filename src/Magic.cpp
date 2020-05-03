#include "Magic.h"

using namespace std;

Magic::Magic(string name, int power, int mpCost, bool isOffensive):
    m_name(name),
    m_power(power),
    m_mpCost(mpCost),
    m_isOffensive(isOffensive)
{}

Magic::~Magic()
{}

string Magic::getName()const
{
    return m_name;
}

int Magic::getPower() const
{
    return m_power;
}

int Magic::getMpCost() const
{
    return m_mpCost;
}

bool Magic::getIsOffensive() const
{
    return m_isOffensive;
}
