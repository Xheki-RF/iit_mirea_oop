#include "Character.h"

void Character::setHP(int hp)
{
    this->hp = hp;
}

int Character::getHP()
{
    return hp;
}

void Character::changeHP(int hp)
{
    this->hp += hp;
}
