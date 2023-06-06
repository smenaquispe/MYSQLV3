#ifndef FIND_REGISTRO
#define FIND_REGISTRO

#include"Disco.h"

void Disco::findRegistro(const char * idRegistro, char *& auxBuffer) {
    int id = atoi(idRegistro);
    int sector = (id - 1) / NUMBER_REGISTER_PER_SECTOR;
    int row = (id - 1) % NUMBER_REGISTER_PER_SECTOR ;

    fstream sectorFile;

    int digitos = floor(log10(numTotalSectores)) + 1;
    ostringstream nombreArchivoStream;
    nombreArchivoStream<<"./Disco/data/sectores/"<<setfill('0')<<setw(digitos)<<to_string(sector);
    sectorFile.open(nombreArchivoStream.str());

    sectorFile.seekg(row * file->totalRegisterBytes + 1);
    sectorFile.read(buffer, file->totalRegisterBytes);

    strncpy(auxBuffer, buffer, file->totalRegisterBytes);
}


#endif