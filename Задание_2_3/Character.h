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
    Character(std::string n, int h, int m) : name(n), health(h), mana(m) {}
    friend void getInfo(Character &chr);
    friend class Healer;
};


void getInfo(Character& chr)
{
    printf("Hero: %s | Health = %d | Mana = %d\n", chr.name.c_str(), chr.health, chr.mana);
}

class Healer
{
public:
    void setStats(Character& chr) { chr.health += 20; chr.mana += 10; }
};


#endif