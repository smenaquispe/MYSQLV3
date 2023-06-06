#ifndef DISCO_H
#define DISCO_H

#include<iostream>
#include<fstream>
#include<cmath>
#include<filesystem>

#include<map>

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

    char *tableName;

    int NUMBER_SECTORS_PER_CLUSTER = 3;
    
    int NUMBER_REGISTER_PER_SECTOR = 5;
    File * file;

    unsigned int capacidad; // capacidad total en bytes

    int lenBuffer;
    char * buffer;


    int contadorSectores;  
    unsigned int numTotalSectores;

    void calcCapacidad();
    void setFile(File * file, const char * tableName);
    void loadFile();
    void setDirectory();
    void printSector(const char * nameSector);
    void printSector();
    void printInfoSector(const char * nameSector);


    void printBloque(int numeroBloque);
    void printInfoBloque(int numeroBloque);


    void addRegistro();
    void moveRegistro();

    void findRegistro(const char * idRegistro, char *& auxBuffer);
    void findAndReplaceRegistro(const char * idRegistro, char * auxBuffer);
};

#include"getCapacidad.h"
#include"setFile.h"
#include"loadFile.h"
#include"setDirectory.h"
#include"printSector.h"
#include"printInfoSector.h"
#include"printBloque.h"
#include"printInfoBloque.h"
#include"addRegistro.h"
#include"moveRegistro.h"
#include"findRegistro.h"
#include"findAndReplaceRegistro.h"

#endif