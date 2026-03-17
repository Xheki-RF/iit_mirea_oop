#ifndef __ITEM_H
#define __ITEM_H

#include <string>

class Item
{
private:
    std::string name;
    int durability;

public:
    Item();
    Item(std::string, int durability);
    Item(Item &item);
    ~Item();

public:
    void incDurability(int value);
    void decDurability(int value);
    std::string getItemName();
    int getItemDurability();
};

#endif