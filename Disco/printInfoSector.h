#ifndef PRINT_INFO_SECTOR
#define PRINT_INFO_SECTOR

#include"Disco.h"

void Disco::printInfoSector(const char * nameSector) {
    ifstream directorio("./Disco/data/directorio");

    if(directorio.is_open()) {
        int pos = 0;
        while(directorio.getline(buffer + pos, lenBuffer)) {

            char * token = myStrtok(buffer + pos, " ");
            if(!strcmp(nameSector, token)) {

                cout<<"Nombre del sector: "<<nameSector<<endl;
                token = myStrtok(nullptr, " ");
                cout<<"Numero de plato: "<<token<<endl;
                token = myStrtok(nullptr, " ");
                cout<<"Numero de superficie: "<<token<<endl;
                token = myStrtok(nullptr, " ");
                cout<<"Numero de pista: "<<token<<endl;


                break;
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