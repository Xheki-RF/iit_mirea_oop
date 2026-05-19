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

    // Новые поля
    int class_affil;
    int is_ready;

public:
    // параметризированный конструктор с параметрами
    cl_base(cl_base* p_head_object, std::string name = "Base_object", int is_ready = 0);

    // метод редактирования имени объекта
    bool set_name(std::string new_name);

    // метод получения имени объекта
    std::string get_name();

    // метод получения адреса головного объекта текущего объекта
    cl_base* get_head_object();

    // метод получения количества подчиненных объектов текущего объекта
    int get_subordinate_count();

    // метод установки готовности объекта
    void set_ready(int is_ready);

    // метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз
    void print_tree(int level = 0);

    void print_tree_ready(int level = 0);

    // метод получения адреса непосредственно подчиненного объект по его индексу
    cl_base* get_subordinate_by_index(int index);

    // метод получения адреса (проходит по ветке от текущего рекурсивно)
    cl_base* find_object_by_name(std::string name);

    // Поиск объекта по всему дереву
    cl_base* find_object(std::string);

    // метод деструктора
    ~cl_base();
};

#endif