#include "Printer.h"

string Printer::toString(int **matrix, int length)
{
    string str;
    for (int level = 0; level < length / 2 + 1; level++)
    {
        int middle = length / 2;
        for (int i = middle - level + 1; i < middle + level; ++i)
        {
            str.push_back(matrix[i][middle + level] + '0');
            str.push_back(' ');
        }
        for (int i = middle + level; i > middle - level; --i)
        {
            str.push_back(matrix[middle + level][i] + '0');
            str.push_back(' ');
        }
        for (int i = middle + level; i > middle - level; --i)
        {
            str.push_back(matrix[i][middle - level] + '0');
            str.push_back(' ');
        }
        for (int i = middle - level; i <= middle + level; ++i)
        {
            str.push_back(matrix[middle - level][i] + '0');
            str.push_back(' ');
        }
    }
    return str;
}
