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
    int is_ready = 0;

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

    // метод установки готовности объекта
    void setReady(int is_ready);

    // метод вывода наименований объектов в дереве иерархии слева направо и сверху вниз
    void printTree(int level = 0);

    void printTreeReady(int level = 0);

    // метод получения адреса непосредственно подчиненного объект по его индексу
    cl_base* get_subordinate_by_index(int index);

    // метод получения адреса непосредственно подчиненного объект по его имени
    cl_base* get_subordinate_by_name(std::string name);

    // метод получения адреса (проходит по ветке от текущего рекурсивно)
    cl_base* findObjectFromBranch(std::string name);

    // Поиск объекта по всему дереву
    cl_base* findObjectFromRoot(std::string);

    // переопределение головного объекта
    bool changePHeadObject(cl_base *object);

    // метод удаления подчиненного объекта по наименованию
    void deleteChildByName(std::string name);

    // метод получения адреса любого объекта в составе дерева иерархии объектов согласно пути
    cl_base *findObjectByPath(std::string path);

    // метод деструктора
    ~cl_base();
};

#endif