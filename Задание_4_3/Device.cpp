#include "Device.h"

Device::Device(std::string name, int N, int P)
{
    if (name.empty())
        throw std::string("Error: empty name");

    if (N <= 0)
        throw -1;

    if (P > 100)
        throw 100;
    
    this->name = name;
    this->N = N;
    this->P = P;
}

void Device::show()
{
    printf("Device::Show-> %s %d %d\n", name.c_str(), N, P);
}