#ifndef __DEVICE_H
#define __DEVICE_H

#include <string>

class Device
{
private:
    std::string name;
    int N, P;

public:
    Device(std::string name, int N, int P);
    void show();
};


#endif