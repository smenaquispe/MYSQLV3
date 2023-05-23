#ifndef PRINT_INFO_BLOQUE
#define PRINT_INFO_BLOQUE

#include"Disco.h"

void Disco::printInfoBloque(int numeroBloque) {
    ifstream directorio("./Disco/data/directorio");

    int countBloques = 0;
    bool band = false;
    bool isFirst = true;

    int capacidad = 0;

    if(directorio.is_open()) {
        int pos = 0;
        while(directorio.getline(buffer + pos, lenBuffer)) {

            char * token = myStrtok(buffer + pos, " ");

            if(!band) {
                if(!strcmp("#", token)) {
                    countBloques++;
                }
            }

            if(band) {

                if(!strcmp("#", token)) {
                    cout<<"Capacidad Bloque: "<<capacidad<<endl;
                    break;
                }

                if(isFirst) {
                    cout<<"Numero de bloque: "<<numeroBloque<<endl;
                    token = myStrtok(nullptr, " ");
                    cout<<"Numero de plato: "<<token<<endl;
                    token = myStrtok(nullptr, " ");
                    cout<<"Numero de superficie: "<<token<<endl;
                    token = myStrtok(nullptr, " ");
                    cout<<"Numero de pista: "<<token<<endl;

                    isFirst = false;
                }

                capacidad += tamanoSector;
            }

            if(countBloques == numeroBloque) {
                band = true;
            }

            if(pos >= sizeof(buffer)) {
                pos = 0;
            }
        }

        directorio.close();
    } else {
        cout<<"Problemas abriendo el directorio"<<endl;
    }
}

#endif