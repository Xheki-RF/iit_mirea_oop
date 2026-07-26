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
    std::string root_name, parent_path, child_name;
    std::cin >> root_name;
    set_name(root_name);

    int class_affil;

    while (std::cin >> parent_path)
    {
        if (parent_path == "endtree")
            break;

        std::cin >> child_name >> class_affil;

        if (child_name.find('/') != std::string::npos || 
        child_name.find('.') != std::string::npos)
        {
            continue;
        }

        if (class_affil < 2 || class_affil > 6)
            continue;

        cl_base* parent = this->findObjectByPath(parent_path);

        if (parent == nullptr)
        {
            std::cout << "The head object " << parent_path << " is not found\n";
            exit(1);
        }

        if (parent->get_subordinate_by_name(child_name) != nullptr)
        {
            std::cout << parent_path << "     Dubbing the names of subordinate objects\n";
            continue;
        }

        switch (class_affil)
        {
        case 2:
            new cl_2(parent, child_name);
            break;
        case 3:
            new cl_3(parent, child_name);
            break;
        case 4:
            new cl_4(parent, child_name);
            break;
        case 5:
            new cl_5(parent, child_name);
            break;
        case 6:
            new cl_6(parent, child_name);
            break;
        }
    }
}

int cl_application::exec_app()
{
    std::cout << "Object tree\n";
    printTree();

    cl_base* current = this;

    std::string cmd;

    while (std::cin >> cmd)
    {
        if (cmd == "END")
            break;

        if (cmd == "SET")
        {
            std::string path;
            std::cin >> path;

            cl_base* obj = current->findObjectByPath(path);

            if (obj)
            {
                current = obj;
                std::cout << "Object is set: " << obj->get_name() << "\n";
            }
            else
            {
                std::cout << "The object was not found at the specified coordinate: " << path << "\n";
            }
        }

        else if (cmd == "FIND")
        {
            std::string path;
            std::cin >> path;

            cl_base* obj = current->findObjectByPath(path);

            if (obj)
            {
                std::cout << path << "     Object name: " << obj->get_name() << "\n";
            }
            else
            {
                std::cout << path << "     Object is not found\n";
            }
        }

        else if (cmd == "MOVE")
        {
            std::string path;
            std::cin >> path;

            cl_base* new_head = current->findObjectByPath(path);

            if (new_head == nullptr)
            {
                std::cout << path << "     Head object is not found\n";
                continue;
            }

            if (new_head->get_subordinate_by_name(current->get_name()) != nullptr)
            {
                std::cout << path << "     Dubbing the names of subordinate objects\n";
                continue;
            }

            if (!current->changePHeadObject(new_head))
            {
                std::cout << path << "     Redefining the head object failed\n";
                continue;
            }

            std::cout << "New head object: " << new_head->get_name() << "\n";
        }

        else if (cmd == "DELETE")
        {
            std::string name;
            std::cin >> name;

            cl_base* child = current->get_subordinate_by_name(name);

            if (child)
            {
                std::string full_path = current->get_name() + "/" + name;
                // удалить указатель из списка родителя, затем освободить память
                current->deleteChildByName(name);
                delete child;
                std::cout << "The object " << full_path << " has been deleted\n";
            }
        }
    }

    std::cout << "Current object hierarchy tree\n";
    printTree();

    return 0;
}