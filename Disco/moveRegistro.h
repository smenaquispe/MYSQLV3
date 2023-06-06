#ifndef MOVE_REGISTRO
#define MOVE_REGISTRO

#include"Disco.h"

void Disco::moveRegistro() {
    
    string a, b;
    cout<<"Id del registro a mover: ";
    cin>>a;
    cout<<"Id del segundo registro: ";
    cin>>b;

    // guardamos un registro como auxiliar
    char * auxBuffer = new char[file->totalRegisterBytes];
    this->findRegistro(a.c_str(), auxBuffer);
    //cout.write(auxBuffer,file->totalRegisterBytes);

    // guardamo el otro registro
    char * auxBuffer2 = new char[file->totalRegisterBytes];
    this->findRegistro(b.c_str(), auxBuffer2);
    //cout.write(auxBuffer2, file->totalRegisterBytes);

    // escribimo lo del 001 en 000
    findAndReplaceRegistro(a.c_str(), auxBuffer2);
    findAndReplaceRegistro(b.c_str(), auxBuffer);

    delete auxBuffer;
    delete auxBuffer2;
}

#endif