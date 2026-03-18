#include "SmartSensor.h"
#include <iostream>

SmartSensor::SmartSensor(int x_base, int y_base, int x, int y) : Sensor(x_base, y_base)
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