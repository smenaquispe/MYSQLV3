#ifndef SET_DIRECTORY
#define SET_DIRECTORY

#include"Disco.h"
#include<filesystem>

namespace fs = std::filesystem;

void Disco::setDirectory() {
    ofstream directorio("./Disco/data/directorio");

    this->tableName;
    this->numPlatos;
    this->numPistas;
    this->numSectores;

    unsigned int posicion[3];

    /*
    directorio<<"----------------------"<<endl;
    directorio<<"Table: "<<this->tableName<<endl;
    */

   
    for (const auto& archivo : fs::directory_iterator("./Disco/data")) {
        cout << archivo.path().filename().string() << endl;
    }

}

#endif