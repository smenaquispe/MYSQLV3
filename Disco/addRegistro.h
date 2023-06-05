#ifndef ADD_REGISTRO
#define ADD_REGISTRO

#include"Disco.h"

void Disco::addRegistro() {

    cout<<this->numTotalSectores<<endl;
    int digitos = floor(log10(numTotalSectores)) + 1;
    
    ostringstream nombreArchivoStream;
    nombreArchivoStream<<setfill('0')<<setw(digitos)<<to_string(numTotalSectores);
    
    // abrimos el ultimo sector que esta activo en el disco
    fstream lastSector("./Disco/data/sectores/" + nombreArchivoStream.str());

    int numeroRegistro = 0;
    if(lastSector.is_open()) {
        while (!lastSector.eof())
        {
            lastSector.seekg((numeroRegistro * file->totalRegisterBytes) + 1);
            lastSector.read(buffer, file->totalRegisterBytes);

            numeroRegistro++;   
        }
    } else {
        cout<<"Error open last sector file"<<endl;
    }
    
    lastSector.close();
    // comprobamos si podemos guardar en el ultimo sector
    if(numeroRegistro == NUMBER_REGISTER_PER_SECTOR) {
        // creamos nuevo sector y guardamos
        
        ostringstream nombreArchivoStream;
        nombreArchivoStream<<setfill('0')<<setw(digitos)<<to_string(numTotalSectores + 1);
        
        ofstream newSector;
        newSector.open("./Disco/data/sectores/" + nombreArchivoStream.str());

        // guardamos en el nuevo sector
        if(newSector.is_open()) {
            newSector.close();
        }
    } else {
        // agregamos el registro al final del ultimo sector
        ofstream newSector("./Disco/data/sectores/" + nombreArchivoStream.str(), ios::app);

        if(newSector.is_open()) {
            newSector.close();
        }

    }
}

#endif