#include "cl_application.h"
#include "cl_1.h"
#include "cl_2.h"
#include <iostream>
#include <queue>
#include <vector>

cl_application::cl_application(cl_base* p_head_object): cl_base(p_head_object)
{
}

void cl_application::build_tree_objects()
{
    std::string root_name;
    std::cin >> root_name;
    set_name(root_name);

    std::string parent_name, child_name;
    int count = 0;

    while (std::cin >> parent_name >> child_name)
    {
        if (parent_name == child_name)
        {
            break;
        }

        cl_base* parent = find_object(parent_name);

        if (parent == nullptr)
        {
            continue;
        }
            
        // проверка, может ли объект быть родителем
        if (!parent->is_valid_parent())
        {
            continue;
        }

        // проверка дубля имени
        if (parent->get_subordinate_by_name(child_name) != nullptr)
        {
            continue;
        }

        // чередование классов
        if (count % 2 == 0)
        {
            new cl_1(parent, child_name);
        }
        else
        {
            new cl_2(parent, child_name);
        }

        count++;
    }
}

int cl_application::exec_app()
{
    print_tree();

    int level, index;
    std::string new_name;

    while (std::cin >> level)
    {
        if (level == 0)
        {
            break;
        }

        std::cin >> index >> new_name;

        int count_lvl = 1;
        cl_base *current = this;
        bool is_valid = true;

        while (count_lvl < level - 1)
        {
            current = current->get_subordinate_by_index(current->get_subordinate_count());

            if (current == nullptr)
            {
                is_valid = false;
                break;
            }
            
            count_lvl++;
        }

        if (is_valid == false)
            continue;

        if (level == 1 && index == 1)
        {
            current->set_name(new_name);
            continue;
        }

        current = current->get_subordinate_by_index(index);
        if (current == nullptr)
            continue;

        current->set_name(new_name);
    }

    print_tree();

    return 0;
}