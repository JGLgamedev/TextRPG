#ifndef MAGIC_H
#define MAGIC_H

#include <string>

/**
    The Magic class represents a magic spell a Character can learn
*/
class Magic
{
    public:
        Magic(std::string name, int power, int mpCost, bool isOffensive);
        virtual ~Magic();

        /** Accessors */
        std::string getName()const;
        int getPower() const;
        int getMpCost() const;
        bool getIsOffensive() const;

    private:
        /** The name will be displayed during battle */
        std::string m_name;
        /** The strength of the magic spell */
        int m_power;
        /** The number of MP the caster will loose if this magic spell is used */
        int m_mpCost;
        /** An offensive magic spell will target an enemy, a support spell will target the caster */
        bool m_isOffensive;
};

#endif // MAGIC_H
