#ifndef __DEVICE_H
#define __DEVICE_H

#include <string>

class Device
{
public:
    static int ndevices;
    static int nactive;

private:
    std::string name;
    int id;

public:
    Device(std::string name);
    void show();
    static void showStats();
    ~Device();
};

#endif