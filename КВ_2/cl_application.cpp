#include "cl_application.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include <iostream>
#include <queue>
#include <vector>

cl_application::cl_application(cl_base* p_head_object): cl_base(p_head_object)
{
}

void cl_application::build_tree_objects()
{
    std::string root_name, parent_name, child_name;
    std::cin >> root_name;
    set_name(root_name);

    cl_base* current = this;

    int class_affil;

    while (std::cin >> parent_name)
    {
        if (parent_name == "endtree")
            break;

        std::cin >> child_name >> class_affil;

        if (class_affil < 2 || class_affil > 6)
            continue;

        cl_base* parent = this->findObjectFromRoot(parent_name);

        if (parent == nullptr)
            continue;

        if (this->findObjectFromRoot(child_name) != nullptr)
            continue;

        switch (class_affil)
        {
        case 2:
            current = new cl_2(parent, child_name);
            break;
        case 3:
            current = new cl_3(parent, child_name);
            break;
        case 4:
            current = new cl_4(parent, child_name);
            break;
        case 5:
            current = new cl_5(parent, child_name);
            break;
        case 6:
            current = new cl_6(parent, child_name);
            break;
        }
    }
}

int cl_application::exec_app()
{
    std::cout << "Object tree\n";
    printTree();
    std::cout << "The tree of objects and their readiness\n";

    std::string name;
    int state;

    while (std::cin >> name >> state)
    {
        cl_base* obj = findObjectFromRoot(name);

        if (obj != nullptr)
        {
            obj->setReady(state);
        }
    }

    printTreeReady();

    return 0;
}