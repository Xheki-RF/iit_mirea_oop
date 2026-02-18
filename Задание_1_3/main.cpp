#include <iostream>
#include "main.h"
using namespace std;


void A::setY(int y)
{
    this->y = y;
}
int A::getY()
{
    return y;
}
void A::set_vars()
{
    if (x % 2 == 0)
    {
        x /= 2;
    }
    else
    {
        x *= 2;
    }

    if (y % 2 == 0)
    {
        y /= 2;
    }
    else
    {
        y *= 2;
    }
}


int main()
{
    A a;

    int num1;
    int num2;

    cin >> num1 >> num2;

    a.x = num1;
    a.setY(num2);

    a.set_vars();

    printf("Open value: %d", a.x);
    printf("\nHidden value: %d", a.getY());
}
