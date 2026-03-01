#include "ClassA.h"
#include "StructA.h"
#include <iostream>


int main()
{
    StructA obj_st;
    ClassA obj_cl;

    int num1;
    int num2;

    std::cin >> num1;

    obj_st.setY(num1);
    obj_cl.setY(num1);

    std::cin >> num2;

    obj_st.x = num2;
    obj_cl.x = num2;

    printf("The value of the public obj_st object property = %d\n", obj_st.x);
    printf("The value of the public obj_cl object property = %d\n", obj_cl.x);
    printf("The value of the obj_st object's private property = %d\n", obj_st.getY());
    printf("The value of the obj_cl object's private property = %d", obj_cl.getY());
}