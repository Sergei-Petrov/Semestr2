#include "FilePrinter.h"
#include <stdio.h>
#include "iostream"

void FilePrinter::print(int **matrix, int length)
{
    file = fopen("file.txt", "w");
    fprintf(file, toString(matrix, length).c_str());
    fclose(file);
}
