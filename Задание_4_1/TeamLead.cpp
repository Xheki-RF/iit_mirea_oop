#include "Developer.h"
#include "Manager.h"
#include "TeamLead.h"
#include "Employee.h"
#include <string>

TeamLead::TeamLead(std::string name, int ntasks, int nprojects, int level): Developer(name, ntasks), Manager(name, nprojects), Employee(name)
{
    this->level = level;
}

void TeamLead::showLevel()
{
    printf("TeamLead::showLevel -> %d\n", level);
}

void TeamLead::showLeadName()
{
    printf("TeamLead::showLeadName -> %s\n", name.c_str());
}

void TeamLead::setName(std::string new_name)
{
    name = new_name;
}

void TeamLead::showRole()
{
    printf("TeamLead::showRole -> TeamLead\n");
}