#pragma once
#include "string"

using namespace std;

class Printer
{
public:
    /**
      * Interface functions print
      *
      *@ param int** - array of array is passed to print
      *@ param int - length of array is passed to print
      */
    void virtual print(int**, int) = 0;
protected:
    /// Function that goes in a spiral and writes in string
    string toString(int**, int);
};

