#include "Item.h"
#include <iostream>


void incDur(Item& item)
{
    item.incDurability(10);
}

void damageItem(Item item)
{
    item.decDurability(5);
    printf("Inside damageItem: %s durability = %d\n", item.getItemName().c_str(), item.getItemDurability());
}

Item* createDamagedItem(int mode)
{
    if (mode == 0) 
    {
        return nullptr;
    }

    Item *item = new Item("Broken", 0);

    return item;
}

int main()
{
    std::string name;
    int durability;
    int mode;

    std::cin >> name >> durability >> mode;

    Item item(name, durability);

    incDur(item);

    printf("After repair: %s durability = %d\n", item.getItemName().c_str(), item.getItemDurability());

    damageItem(item);

    printf("After damage: %s durability = %d\n", item.getItemName().c_str(), item.getItemDurability());

    Item* new_item = createDamagedItem(mode);

    if (new_item == nullptr)
    {
        std::cout << "Broken pointer nullptr\n";
    }
    else
    {
        printf("Broken item: %s durability = %d\n", new_item->getItemName().c_str(), new_item->getItemDurability());
    }

    delete new_item;
}