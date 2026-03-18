#include "SmartSensor.h"
#include <iostream>

SmartSensor::SmartSensor(int x, int y) : Sensor(x, y)
{
    this->x = x;
    this->y = y;
}

void SmartSensor::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

void SmartSensor::getXY()
{
    printf("SmartSensor: %d %d\n", x, y);
}