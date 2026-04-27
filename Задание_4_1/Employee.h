#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <string>

class Employee
{
protected:
    std::string name;

public:
    Employee(std::string name);
    void getName();
    virtual void showRole();
};

#endif