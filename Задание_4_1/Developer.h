#ifndef __DEVELOPER_H
#define __DEVELOPER_H

#include "Employee.h"
#include <string>

class Developer: virtual public Employee
{
private:
    int ntasks;

public:
    Developer(std::string name, int n);
    void showTasks();
    void showRole();
};


#endif