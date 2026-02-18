#include <iostream>
#include "ClassA.h"
using namespace std;


int main()
{
    ClassA obj;

    int num1;
    int num2;

    cin >> num1 >> num2;

    obj.x = num1;
    obj.setY(num2);

    obj.set_vars();

    printf("Open value: %d", obj.x);
    printf("\nHidden value: %d", obj.getY());

    return 0;
}
