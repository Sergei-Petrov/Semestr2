#pragma once

/// Interface for sorter

class Sorter
{
public:
    /**
      * Interface functions sorter
      *
      *@ param matrix - array of array is passed to sort
      *@ param length - length of array is passed to sort
      */
    virtual int **sort(int **array, int length) = 0;
protected:
    /// Function that swap two values
    static void swap(int *&a, int *&b);
};
