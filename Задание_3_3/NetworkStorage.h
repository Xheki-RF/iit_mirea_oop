#ifndef __NETWORKSTORAGE_H
#define __NETWORKSTORAGE_H

#include "DataStorage.h"
#include "NetworkDevice.h"
#include <string>
#include <vector>

class NetworkStorage : public NetworkDevice, public DataStorage
{
private:
    std::string device_name;

public:
    NetworkStorage(std::string name, int v, int size);
    std::string getN();
    void getInfo();
    static void printInfo(std::vector<NetworkStorage*> obj_list);
};


#endif