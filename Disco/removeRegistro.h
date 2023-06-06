#ifndef REMOVE_REGISTRO
#define REMOVE_REGISTRO

#include"Disco.h"

void Disco::removeRegistro() {
    string a;
    cout<<"Id del registro a remover: ";
    cin>>a;

    ostringstream nullish;


    for(int i = 0; i < file->numberColumns; i++) {
        nullish<<setw(this->file->columnBytes[i])<<"-";
    }

    char * auxBuffer = new char[file->totalRegisterBytes];
    strcpy(auxBuffer, nullish.str().c_str());    
    findAndReplaceRegistro(a.c_str(),auxBuffer);

    delete auxBuffer;
}

#endif