#include "NetworkDevice.h"

NetworkDevice::NetworkDevice(int v)
{
    this->v = v;
}

void NetworkDevice::setV(int v)
{
    this->v = v;
}

int NetworkDevice::getV()
{
    return v;
}