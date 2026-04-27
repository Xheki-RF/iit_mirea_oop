#ifndef __TEAMLEAD_H
#define __TEAMLEAD_H

#include "Developer.h"
#include "Manager.h"
#include <string>

class TeamLead: public Developer, public Manager
{
private:
    int level;

public:
    TeamLead(std::string name, int ntasks, int nprojects, int level);
    void showLevel();
    void showLeadName();
    void setName(std::string new_name);
    void showRole();
};


#endif