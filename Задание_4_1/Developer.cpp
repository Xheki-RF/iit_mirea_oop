#include "Developer.h"
#include <string>

Developer::Developer(std::string name, int n): Employee(name)
{
    ntasks = n;
}

void Developer::showTasks()
{
    printf("Developer::showTasks -> %d\n", ntasks);
}

void Developer::showRole()
{
    printf("Developer::showRole -> Developer\n");
}