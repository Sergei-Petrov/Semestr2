#pragma once
#include "Printer.h"

class FilePrinter : public Printer
{
public:
    void print(int **, int);
private:
    FILE *file;
};
