#include "Sensor.h"
#include <iostream>

void Sensor::setX(int x)
{
    this->x = x * 3;
}

Sensor::Sensor(int x, int y)
{
    setX(x);
    this->y = y;
}

void Sensor::setXY(int x, int y)
{
    setX(x);
    this->y = y;
}

void Sensor::getXY()
{
    printf("Sensor: %d %d\n", x, y);
}