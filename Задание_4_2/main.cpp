#include "Device.h"
#include <string>
#include <iostream>

int main()
{
    std::string name1, name2, name3;
    std::cin >> name1 >> name2 >> name3;

    Device dev1(name1);
    Device *dev2 = new Device(name2);
    Device *dev3 = new Device(name3);

    dev1.show();
    dev2->show();
    dev3->show();

    Device::showStats();

    delete dev2;

    Device::showStats();

    delete dev3;

    return 0;
}