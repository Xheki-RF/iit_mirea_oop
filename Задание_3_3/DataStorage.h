#ifndef __DATASTORAGE_H
#define __DATASTORAGE_H

class DataStorage
{
private:
    int data_size;

public:
    DataStorage(int size);
    void setDS(int size);
    int getDS();
};


#endif