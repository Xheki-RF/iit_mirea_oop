#ifndef __CHARACTER__H
#define __CHARACTER__H

#include <string>

class Healer;

class Character
{
private:
    std::string name;
    int health;
    int mana;

public:
    Character(std::string name, int health, int mana);
    friend void getInfo(const Character &chr);
    friend class Healer;
};


#endif