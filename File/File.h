#ifndef FILE_H
#define FILE_H

#include<cstring>
#include<fstream>
#include<iostream>
#include<cstdlib> 
#include<iomanip>

using namespace std;

class File
{
public:
    File() {
        this->buffer = new char[lenBuffer];
        numberColumns = 0;
        numberRegisters = 0;
    }

    ~File() {
        delete buffer;
    }

    // properties
    int numberColumns; // number of columns
    int totalRegisterBytes; // what is the total length of a register
    int * columnBytes;  // lenght of each column
    char * csv;

    int numberRegisters;

    int lenBuffer = 1024;
    char *buffer;

    // methods
    void setCsv(const char * csv) { strcpy(this->csv, csv); }
    void toFile();
    void extractSchema();

    // print one
    void printFile(int);
    // print all
    void printFile();
    // print range
    void printFile(int, int);
};

#include"toFile.h"
#include"extractSchema.h"
#include"printFile.h"

#endif