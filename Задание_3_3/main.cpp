#include "NetworkStorage.h"
#include <iostream>
#include <vector>


void printInfo(std::vector<NetworkStorage*> obj_list)
{
    for (int i; i < obj_list.size(); i++)
    {
        if (obj_list[i] == nullptr)
        {
            std::cout << "Empty pointer\n";
        }
        else
        {
            obj_list[i]->getInfo();
        }
    }
}


int main()
{
    int amnt_device, v, size, min_v;
    std::string name;

    std::cin >> amnt_device;



    std::vector<NetworkStorage*> device_container;

    for (int i = 0; i < amnt_device; i++)
    {
        std::cin >> name >> v >> size;
        NetworkStorage *addr = new NetworkStorage(name, v, size);
        device_container.push_back(addr);
    }

    device_container.push_back(nullptr);

    std::cout << "Initial state\n";

    printInfo(device_container);

    std::cin >> min_v;

    for (int i = 0; i < device_container.size(); i++)
    {   
        if (device_container[i] != nullptr && device_container[i]->getV() < min_v)
        {
            name = device_container[i]->getN();
            size = device_container[i]->getDS();

            NetworkStorage* addr = new NetworkStorage(name, min_v * 2, size);

            device_container[i] = addr;
        }
    }

    std::cout << "Modified state\n";

    printInfo(device_container);
}