#include "cl_application.h"
#include "cl_1.h"
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

    while (std::cin >> parent_name >> child_name)
    {
        // конец ввода
        if (parent_name == child_name)
        {
            break;
        }

        // search parent by tree
        cl_base* parent = nullptr;

        std::queue<cl_base*> q;
        q.push(this);

        while (!q.empty())
        {
            cl_base* current = q.front();
            q.pop();

            if (current->get_name() == parent_name)
            {
                parent = current;
                break;
            }

            for (int i = 1; i <= current->get_subordinate_count(); i++)
            {
                q.push(current->get_subordinate_by_index(i));
            }
        }

        // родитель не найден
        if (parent == nullptr)
        {
            continue;
        }

        // can object be parent
        bool valid_parent = false;

        // корень
        if (parent->get_head_object() == nullptr)
        {
            valid_parent = true;
        }
        // уже есть дети
        else if (parent->get_subordinate_count() > 0)
        {
            valid_parent = true;
        }
        else
        {
            cl_base* head = parent->get_head_object();

            int count = head->get_subordinate_count();

            // последний ребёнок у родителя
            if (count > 0 && head->get_subordinate_by_index(count) == parent)
            {
                valid_parent = true;
            }
        }

        if (!valid_parent)
        {
            continue;
        }

        // duplicate check
        if (parent->get_subordinate_by_name(child_name) != nullptr)
		{
			continue;
		}

        new cl_1(parent, child_name);
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