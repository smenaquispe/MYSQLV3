#ifndef GET_CAPACIDAD
#define GET_CAPACIDAD

#include"Disco.h"

void Disco::calcCapacidad() {
    capacidad = numPlatos * 2 * numPistas * numSectores * tamanoSector;
    cout<<"Capacidad en bytes: "<<capacidad<<endl;
    cout<<"Capacidad en bits: "<<capacidad * 8<<endl;
}

#endif