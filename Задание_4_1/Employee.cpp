#include "Employee.h"
#include <string>

Employee::Employee(std::string name)
{
    this->name = name;
}

void Employee::getName()
{
    printf("Employee::showName -> %s\n", name.c_str());
}

void Employee::showRole()
{
    printf("Employee::showRole -> Employee\n");
}