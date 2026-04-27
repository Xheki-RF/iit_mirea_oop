#ifndef __MANAGER_H
#define __MANAGER_H

#include "Employee.h"
#include <string>

class Manager: virtual public Employee
{
private:
    int nprojects;

public:
    Manager(std::string name, int n);
    void showProjects();
    void showRole();
};


#endif