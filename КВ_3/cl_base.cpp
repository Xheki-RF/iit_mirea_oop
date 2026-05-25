#include "cl_base.h"
#include <string>
#include <queue>
#include <iostream>
#include <functional>

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

cl_base* cl_base::get_subordinate_by_index(int index)
{
    if (index < 1 || index > (int)v_child_objects.size())
    {
        return nullptr;
    }

    return v_child_objects[index - 1];
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

void cl_base::setReady(int state)
{
    // выключение
    if (state == 0)
    {
        is_ready = 0;

        for (auto child : this->v_child_objects)
        {
            child->setReady(0);
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

cl_base* cl_base::findObjectFromBranch(std::string name)
{
    cl_base* result = nullptr;
    int count = 0;

    std::queue<cl_base*> q;
    q.push(this);

    while (!q.empty())
    {
        cl_base* current = q.front();
        q.pop();

        if (current->name == name)
        {
            result = current;
            count++;
        }

        for (auto child : current->v_child_objects)
        {
            q.push(child);
        }
    }

    if (count == 1)
        return result;

    return nullptr;
}

cl_base* cl_base::findObjectFromRoot(std::string name)
{
    cl_base* result = nullptr;
    int count = 0;

    // поднимаемся к корню дерева
    cl_base* root = this;

    while (root->p_head_object != nullptr)
    {
        root = root->p_head_object;
    }

    return root->findObjectFromBranch(name);
}

void cl_base::printTree(int level)
{
    // отступы
    for (int i = 0; i < level; i++)
    {
        std::cout << "    ";
    }

    std::cout << this->name << std::endl;

    for (auto child : this->v_child_objects)
    {
        child->printTree(level + 1);
    }
}

void cl_base::printTreeReady(int level)
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
        std::cout << " is ready" << std::endl;
    else
        std::cout << " is not ready" << std::endl;

    // рекурсия по детям
    for (auto child : v_child_objects)
    {
        child->printTreeReady(level + 1);
    }
}

bool cl_base::changePHeadObject(cl_base* object)
{
    // проверка, что настоящий объект - не корневой
    if (this->p_head_object == nullptr)
        return false;

    //  Недопустимо создать второй корневой объект
    if (object == nullptr)
        return false;

    // Недопустимо при переопределении, чтобы у нового 
    // головного появились два подчиненных объекта с одинаковым наименованием
    for (auto child : object->v_child_objects)
    {
        if (child->get_name() == this->get_name())
        {
            return false;
        }
    }

    // Новый головной объект не должен принадлежать к объектам из ветки текущего
    if (this->findObjectFromBranch(object->get_name()) != nullptr)
        return false;

    std::vector<cl_base*>& old_head = this->p_head_object->v_child_objects;

    // убрать указатель на текущий объект из списка старого головного
    this->p_head_object->deleteChildByName(this->get_name());

    object->v_child_objects.push_back(this);

    this->p_head_object = object;

    return true;
}

void cl_base::deleteChildByName(std::string name)
{
    for (auto it = v_child_objects.begin(); it != v_child_objects.end(); ++it)
    {
        if ((*it)->get_name() == name)
        {
            // delete *it;              // удаляем объект
            v_child_objects.erase(it); // убираем из списка
            return;
        }
    }
}

cl_base* cl_base::findObjectByPath(std::string path)
{
    if (path.empty())
        return nullptr;

    cl_base* current = nullptr;

    if (path == "/")
    {
        current = this;
        while (current->p_head_object != nullptr)
            current = current->p_head_object;
        return current;
    }

    if (path == ".")
        return this;

    if (path[0] == '.' && path.size() > 1 && path.find('/', 1) == std::string::npos)
    {
        current = this;
        std::string token = path.substr(1);
        if (token.empty())
            return current;
        return current->findObjectFromBranch(token);
    }

    size_t pos = 0;

    if (path[0] == '/')
    {
        current = this;
        while (current->p_head_object != nullptr)
            current = current->p_head_object;
        pos = 1;
    }
    else if (path[0] == '.')
    {
        current = this;
        pos = 1;
    }
    else
    {
        current = this;
    }

    while (pos < path.size())
    {
        size_t next = path.find('/', pos);

        std::string token;

        if (next == std::string::npos)
        {
            token = path.substr(pos);
            pos = path.size();
        }
        else
        {
            token = path.substr(pos, next - pos);
            pos = next + 1;
        }

        if (token.empty())
            continue;

        cl_base* found = nullptr;

        for (auto child : current->v_child_objects)
        {
            if (child->get_name() == token)
            {
                found = child;
                break;   // ❗ важно
            }
        }

        if (found == nullptr)
            return nullptr;

        current = found;
    }

    return current;
}

cl_base::~cl_base()
{
    for (int i = 0; i < v_child_objects.size(); i++)
    {
        delete v_child_objects[i];
    }
}