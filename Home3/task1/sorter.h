#pragma once

class Sorter
{
public:
    //virtual ~Sort()
    //{}
    virtual int *sort(int *array, int length) = 0;
    static void swap(int &a, int &b);
};
