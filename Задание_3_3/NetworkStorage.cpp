#include "NetworkDevice.h"
#include "NetworkStorage.h"
#include "DataStorage.h"
#include <string>
#include <iostream>

NetworkStorage::NetworkStorage(std::string name, int v, int size) : NetworkDevice(v), DataStorage(size) 
{
    device_name = name;
}

std::string NetworkStorage::getN()
{
    return device_name;
}

void NetworkStorage::getInfo()
{
    printf("%s %d %d\n", device_name.c_str(), getV(), getDS());
}

void NetworkStorage::printInfo(std::vector<NetworkStorage*> obj_list)
{
    for (int i = 0; i < obj_list.size(); i++)
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