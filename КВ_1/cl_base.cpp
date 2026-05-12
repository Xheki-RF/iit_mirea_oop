#include "cl_base.h"
#include <string>
#include <queue>
#include <iostream>

cl_base::cl_base(cl_base* p_head_object, std::string name)
{
    this->p_head_object = p_head_object;
    this->name = name;

    if (p_head_object != nullptr)
    {
        p_head_object->v_child_objects.push_back(this);
    }
}

bool cl_base::set_name(std::string new_name)
{
    if (p_head_object == nullptr)
    {
        name = new_name;
        return true;
    }

    for (int i = 0; i < p_head_object->v_child_objects.size(); i++)
    {
        if (p_head_object->v_child_objects[i]->name == new_name)
        {
            return false;
        }
    }

    name = new_name;

    return true;
}

std::string cl_base::get_name()
{
    return name;
}

cl_base* cl_base::get_head_object()
{
    return p_head_object;
}

int cl_base::get_subordinate_count()
{
    return v_child_objects.size();
}

cl_base* cl_base::get_subordinate_by_name(std::string name)
{
    for (int i = 0; i < v_child_objects.size(); i++)
    {
        if (v_child_objects[i]->name == name)
        {
            return v_child_objects[i];
        }
    }

    return nullptr;
}

cl_base* cl_base::get_subordinate_by_index(int index)
{
    if (index < 1 || index > (int)v_child_objects.size())
    {
        return nullptr;
    }

    return v_child_objects[index - 1];
}

void cl_base::print_tree()
{
    // Выводим корневой объект
    std::cout << this->get_name() << std::endl;
    
    // Обходим дерево и выводим каждый объект с его подчинённых
    std::queue<cl_base*> q;
    q.push(this);
    
    while (!q.empty())
    {
        cl_base* current = q.front();
        q.pop();
        
        if (current->get_subordinate_count() > 0)
        {
            // Выводим имя родителя
            std::cout << current->get_name();
            
            // Выводим имена всех подчинённых
            for (int i = 1; i <= current->get_subordinate_count(); i++)
            {
                cl_base* child = current->get_subordinate_by_index(i);
                if (child != nullptr)
                {
                    std::cout << "  " << child->get_name();
                    q.push(child);
                }
            }
            std::cout << std::endl;
        }
    }
}

cl_base::~cl_base()
{
    for (int i = 0; i < v_child_objects.size(); i++)
    {
        delete v_child_objects[i];
    }
}