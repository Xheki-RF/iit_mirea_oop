#include <iostream>
#include "Character.h"


// By value
void changeHP(Character chr)
{
    if (chr.getHP() < 50)
    {
        chr.changeHP(10);
    }
    else
    {
        chr.changeHP(-5);
    }
}

// By pointer
void changeHP(Character* chr)
{
    if (chr->getHP() < 50)
    {
        chr->changeHP(10);
    }
    else
    {
        chr->changeHP(-5);
    }
}


int main()
{
    Character *obj = new Character();
    int initial_hp;

    std::cin >> initial_hp;

    obj->setHP(initial_hp);

    changeHP(*obj);
    changeHP(obj);

    printf("HelthPoint: %d", obj->getHP());

    delete obj;
}