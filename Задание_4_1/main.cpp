#include "Employee.h"
#include "Developer.h"
#include "Manager.h"
#include "TeamLead.h"
#include <string>
#include <iostream>

int main()
{
    std::string name, new_name;
    int ntasks, nprojects, level;

    std::cin >> name >> ntasks >> nprojects >> level;
    std::cin >> new_name;

    TeamLead tl(name, ntasks, nprojects, level);

    tl.getName();
    tl.showLeadName();

    tl.setName(new_name);

    tl.getName();
    tl.showLeadName();

    tl.showTasks();
    tl.showProjects();
    tl.showLevel();

    Developer *dev;
    Manager *man;
    Employee *emp;

    dev = &tl;
    man = &tl;
    emp = &tl;

    dev->showRole();
    man->showRole();
    emp->showRole();

    return 0;
}