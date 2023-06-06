#ifndef ADD_REGISTRO
#define ADD_REGISTRO

#include"Disco.h"



void Disco::addRegistro() {

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
            ifstream schema("./docs/schema");

            if(schema.is_open()) {

                string columnName, data;
                int column = 0;
                while (getline(schema,columnName))
                {
                    cout<<columnName<<": ";
                    cin>>data;
                    newSector<<setw(this->file->columnBytes[column++])<<data;
                }
                
            } else {
                cout<<"Error open schema file"<<endl;
            }

            schema.close();
            newSector.close();
        }
    } else {
        // agregamos el registro al final del ultimo sector
        ofstream newSector("./Disco/data/sectores/" + nombreArchivoStream.str(), ios::app);

        
        // guardamos en el nuevo sector
        if(newSector.is_open()) {
            ifstream schema("./docs/schema");

            if(schema.is_open()) {

                string columnName, data;
                int column = 0;
                while (getline(schema,columnName))
                {
                    cout<<columnName<<": ";
                    cin>>data;
                    newSector<<setw(this->file->columnBytes[column++])<<data;
                }
                
            } else {
                cout<<"Error open schema file"<<endl;
            }

            schema.close();
            newSector.close();
        }

    }

    // seteamos nuevamente el directorio de bloques
    this->setDirectory();
}

#endif