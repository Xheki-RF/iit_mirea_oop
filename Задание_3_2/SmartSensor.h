#ifndef __SMARTSENSOR_H
#define __SMARTSENSOR_H

#include "Sensor.h"

class SmartSensor : public Sensor
{
private:
    int x;

public:
    int y;

public:
    SmartSensor(int x_base, int y_base, int x, int y);
    void setXY(int x, int y);
    void getXY();
};

#endif