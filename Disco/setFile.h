#ifndef SET_FILE
#define SET_FILE

#include"Disco.h"

void Disco::setFile(File * file) {
    
    this->file = file;
    
    file->extractSchema();
    file->toFile();


    // el tamaño del sector es un multipo de los registros
    this->tamanoSector = file->totalRegisterBytes * NUMBER_REGISTER_PER_SECTOR;

    buffer = new char[file->totalRegisterBytes]; // el buffer tendra el tamaño para almacenar un registro
    
}

#endif