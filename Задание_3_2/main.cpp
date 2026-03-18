#include "Sensor.h"
#include "SmartSensor.h"
#include <iostream>

int main()
{
    int x, y;

    std::cin >> x >> y;

    SmartSensor ss(x, y, x, y);

    ss.Sensor::getXY();
    ss.getXY();

    int z;

    std::cin >> z;

    ss.Sensor::y = z;
    ss.y = z;

    ss.getXY();
    ss.Sensor::getXY();

    int a, b;

    std::cin >> a >> b;

    if (a > 0)
    {
        ss.setXY(a + 1, b + 1);
        ss.Sensor::setXY(a - 1, b - 1);
        ss.getXY();
        ss.Sensor::getXY();
    }
    else
    {
        ss.Sensor::setXY(a + 1, b + 1);
        ss.setXY(a - 1, b - 1);
        ss.getXY();
        ss.Sensor::getXY();
    }

    return (0);
}