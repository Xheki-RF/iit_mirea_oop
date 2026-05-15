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

        cl_base* parent = this->find_object(parent_name);

        if (parent == nullptr)
            continue;

        if (this->find_object(child_name) != nullptr)
            continue;

        if (class_affil == 2)
            current = new cl_2(parent, child_name, class_affil);
        else if (class_affil == 3)
            current = new cl_3(parent, child_name, class_affil);
        else if (class_affil == 4)
            current = new cl_4(parent, child_name, class_affil);
        else if (class_affil == 5)
            current = new cl_5(parent, child_name, class_affil);
        else if (class_affil == 6)
            current = new cl_6(parent, child_name, class_affil);
    }
}

int cl_application::exec_app()
{
    std::cout << "Object tree\n";
    print_tree();
    std::cout << "The tree of objects and their readiness\n";

    std::string name;
    int state;

    while (std::cin >> name >> state)
    {
        cl_base* obj = find_object(name);

        if (obj != nullptr)
        {
            obj->set_ready(state);
        }
    }

    print_tree_ready();

    return 0;
}