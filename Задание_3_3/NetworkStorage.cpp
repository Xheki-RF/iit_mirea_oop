#include "NetworkDevice.h"
#include "NetworkStorage.h"
#include "DataStorage.h"
#include <string>

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