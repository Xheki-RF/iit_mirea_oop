#include "cl_base.h"
#include <string>
#include <queue>
#include <iostream>
#include <functional>

cl_base::cl_base(cl_base* p_head_object, std::string name, int class_affil, int is_ready)
{
    this->p_head_object = p_head_object;
    this->name = name;
    this->class_affil = class_affil;
    this->is_ready = is_ready;

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

cl_base* cl_base::get_subordinate_by_index(int index)
{
    if (index < 1 || index > (int)v_child_objects.size())
    {
        return nullptr;
    }

    return v_child_objects[index - 1];
}

void cl_base::set_ready(int state)
{
    // выключение
    if (state == 0)
    {
        is_ready = 0;

        for (auto child : this->v_child_objects)
        {
            child->set_ready(0);
        }

        return;
    }

    // проверка родителей
    cl_base* parent = p_head_object;

    while (parent != nullptr)
    {
        if (parent->is_ready == 0)
            return;

        parent = parent->p_head_object;
    }

    // включение (ЛЮБОЕ НЕ НУЛЕВОЕ ЗНАЧЕНИЕ)
    is_ready = state;
}

cl_base* cl_base::find_object_by_name(std::string name)
{
    cl_base* result = nullptr;
    int count = 0;

    std::function<void(cl_base*)> dfs = [&](cl_base* node)
    {
        if (node->name == name)
        {
            result = node;
            count++;
        }

        for (auto child : node->v_child_objects)
        {
            dfs(child);
        }
    };

    dfs(this);

    if (count == 1)
        return result;

    return nullptr;
}

cl_base* cl_base::find_object(std::string name)
{
    cl_base* result = nullptr;
    int count = 0;

    // поднимаемся к корню
    cl_base* root = this;
    while (root->p_head_object != nullptr)
    {
        root = root->p_head_object;
    }

    std::function<void(cl_base*)> dfs = [&](cl_base* node)
    {
        if (node->name == name)
        {
            result = node;
            count++;
        }

        for (auto child : node->v_child_objects)
        {
            dfs(child);
        }
    };

    dfs(root);

    if (count == 1)
        return result;

    return nullptr;
}

void cl_base::print_tree(int level)
{
    // отступы
    for (int i = 0; i < level; i++)
    {
        std::cout << "    ";
    }

    std::cout << this->name << std::endl;

    // for (int i = 0; i < get_subordinate_count(); i++)
    for (auto child : this->v_child_objects)
    {
        child->print_tree(level + 1);
    }
}

void cl_base::print_tree_ready(int level)
{
    // отступ
    for (int i = 0; i < level; i++)
    {
        std::cout << "    ";
    }

    // имя объекта
    std::cout << name;

    // состояние
    if (is_ready != 0)
        std::cout << " is ready";
    else
        std::cout << " is not ready";

    std::cout << std::endl;

    // рекурсия по детям
    // for (int i = 0; i < v_child_objects.size(); i++)
    for (auto child : v_child_objects)
    {
        child->print_tree_ready(level + 1);
    }
}

cl_base::~cl_base()
{
    for (int i = 0; i < v_child_objects.size(); i++)
    {
        delete v_child_objects[i];
    }
}