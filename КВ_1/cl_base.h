#ifndef __CL_BASE_H__
#define __CL_BASE_H__

#include <string>
#include <vector>

class cl_base
{
protected:
    std::string name;
    cl_base *p_head_object;
    std::vector<cl_base*> v_child_objects;

public:
    // параметризированный конструктор с параметрами
    cl_base(cl_base* p_head_object, std::string name = "Base_object");

    // метод редактирования имени объекта
    bool set_name(std::string new_name);

    // метод получения имени объекта
    std::string get_name();

    // метод получения адреса головного объекта текущего объекта
    cl_base* get_head_object();

    // метод получения количества подчиненных объектов текущего объекта
    int get_subordinate_count();

    // метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз
    void print_tree();

    // метод получения адреса непосредственно подчиненного объекта по его имени
    cl_base* get_subordinate_by_name(std::string name);

    // метод получения адреса непосредственно подчиненного объект по его индексу
    cl_base* get_subordinate_by_index(int index);

    // метод деструктора
    ~cl_base();
};

#endif