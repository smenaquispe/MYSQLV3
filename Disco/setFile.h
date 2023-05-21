#ifndef SET_FILE
#define SET_FILE

#include"Disco.h"

void Disco::setFile(File * file) {
    
    this->file = file;
    
    file->extractSchema();
    file->toFile();
    
}

#endif