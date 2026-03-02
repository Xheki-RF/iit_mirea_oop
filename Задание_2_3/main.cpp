#include <iostream>
#include "Character.h"
#include <string>

int main()
{
    std::string name;
    int health, mana;

    std::cin >> name >> health >> mana;

    Character hero(name, health, mana);

    getInfo(hero);

    Healer healer;

    healer.setStats(hero);

    getInfo(hero);
}