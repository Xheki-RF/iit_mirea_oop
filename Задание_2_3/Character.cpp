#include "Character.h"
#include <string>

Character::Character(std::string name, int health, int mana)
{
  this->name = name; 
  this->health = health; 
  this->mana = mana;
}

void getInfo(const Character& ch)
{
  printf("Hero: %s | Health = %d | Mana = %d\n", ch.name.c_str(), ch.health, ch.mana);
}