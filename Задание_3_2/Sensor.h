#ifndef __SENSOR_H
#define __SENSOR_H

class Sensor
{
private:
    int x;

public:
    int y;

public:
    Sensor(int x, int y);
    void setXY(int x, int y);
    void getXY();

private:
    void setX(int x);
};

#endif