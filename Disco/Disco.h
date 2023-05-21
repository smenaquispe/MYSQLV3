#ifndef DISCO_H
#define DISCO_H

#include<iostream>
#include<fstream>
#include"../File/File.h"
using namespace std;

class Disco
{
public:
    Disco(int numPlatos, int numPistas, int numSectores, int tamanoSector) : 
        numPlatos(numPlatos) ,  
        numPistas(numPistas), 
        numSectores(numSectores) ,
        tamanoSector(tamanoSector)
        {}
    ~Disco(){}

    unsigned int numPlatos;
    unsigned int numPistas;
    unsigned int numSectores;
    unsigned int tamanoSector;

    int NUMBER_REGISTER_PER_SECTOR = 5;
    File * file;

    unsigned int capacidad; // capacidad total

    char * buffer;

    void calcCapacidad();
    void setFile(File * file);
    void loadFile();
};

#include"getCapacidad.h"
#include"setFile.h"
#include"loadFile.h"

#endif