#include "Healer.h"
#include "Character.h"

void Healer::setStats(Character& ch)
{
  ch.health += 20; 
  ch.mana += 10;
}
