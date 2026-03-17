#include "Item.h"
#include <string>


Item::Item()
{
    name = "Unknown";
    durability = 0;

    printf("Item (Cnstr): %s", name.c_str());
}

Item::Item(std::string name, int durability)
{
    this->name = name;
    this->durability = durability;

    printf("Item (ParamCnstr): %s\n", this->name.c_str());
}

Item::Item(Item &item)
{
    name = item.name;
    durability = item.durability;

    printf("Item (CopyCnstr): %s\n", name.c_str());
}

Item::~Item()
{
    printf("~Item (Dcnstr): %s\n", name.c_str());
}

void Item::incDurability(int value)
{
    durability += value;
}

void Item::decDurability(int value)
{
    durability -= value;
}

std::string Item::getItemName()
{
    return name;
}

int Item::getItemDurability()
{
    return durability;
}