#ifndef PRINT_BLOQUE
#define PRINT_BLOQUE

#include"Disco.h"

void Disco::printBloque(int numeroBloque) {
    ifstream directorio("./Disco/data/directorio");

    int countBloques = 0;
    bool band = false;
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
                    break;
                }

                printSector(token);

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