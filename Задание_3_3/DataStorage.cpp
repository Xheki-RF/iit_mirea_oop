#include "DataStorage.h"

DataStorage::DataStorage(int size)
{
    data_size = size;
}

void DataStorage::setDS(int size)
{
    data_size = size;
}

int DataStorage::getDS()
{
    return data_size;
}