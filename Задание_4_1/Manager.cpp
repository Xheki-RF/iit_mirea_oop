#include "Employee.h"
#include "Manager.h"
#include <string>

Manager::Manager(std::string name, int n): Employee(name)
{
    nprojects = n;
}

void Manager::showProjects()
{
    printf("Manager::showProjects -> %d\n", nprojects);
}

void Manager::showRole()
{
    printf("Manager::showRole -> Manager\n");
}