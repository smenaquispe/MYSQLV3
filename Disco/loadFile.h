#ifndef LOAD_FILE
#define LOAD_FILE

#include"Disco.h"
#include<cmath>

void Disco::loadFile() {
    // abrimos el file
    ifstream f("./docs/file");

    unsigned int numTotalSectores = file->numberRegisters * 1.0 / NUMBER_REGISTER_PER_SECTOR;
    
    // cuantos bytes alamcena cada registro
    if(f.is_open()) {
        int posicionInicio = 0;
        int contadorRegistros = 0;
        int contadorSectores = 0;

        ofstream sector("./Disco/data/0");
        while (true) {

            f.seekg(posicionInicio, std::ios::beg);  // Establecer la posición de lectura
            f.read(buffer, file->totalRegisterBytes);  // Leer el segmento en el buffer
        
            sector<<buffer;

            ++contadorRegistros;
            if(contadorRegistros == 5) {
                contadorRegistros = 0;
                sector.close();
                sector.open("./Disco/data/" + to_string(contadorSectores++));
                
            }

            int caracteresLeidos = f.gcount();  // Obtener la cantidad de caracteres leídos

            if (caracteresLeidos < file->totalRegisterBytes) {
                break;  // Si se leen menos caracteres que el tamaño del segmento, es el final del archivo o de la línea
            }

            posicionInicio += caracteresLeidos;  // Actualizar la posición de inicio para el siguiente segmento
        }

        f.close();
    } else {
        cout<<"No se pudo abrir el archivo file"<<endl;
    }

}

#endif