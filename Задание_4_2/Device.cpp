#include "Device.h"
#include <string>

int Device::nactive = 0;
int Device::ndevices = 0;

Device::Device(std::string name)
{
    this->name = name;
    ndevices += 1;
    nactive += 1;
    id = ndevices;
}

void Device::show()
{
    printf("Device::show -> %s %d\n", name.c_str(), id);
}

void Device::showStats()
{
    printf("Device::showStats -> created: %d active: %d\n", ndevices, nactive);
}

Device::~Device()
{
    nactive -= 1;
}