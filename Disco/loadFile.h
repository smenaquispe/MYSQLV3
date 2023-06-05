#ifndef LOAD_FILE
#define LOAD_FILE

#include"Disco.h"
#include<cmath>

void Disco::loadFile() {
    // abrimos el file
    ifstream f("./docs/file");

    numTotalSectores = file->numberRegisters * 1.0 / NUMBER_REGISTER_PER_SECTOR;
    
    // cuantos bytes alamcena cada registro
    if(f.is_open()) {
        int posicionInicio = 0;
        int contadorRegistros = 0;
        contadorSectores = 0;

        int digitos = floor(log10(numTotalSectores)) + 1;

        ofstream sector;

        ostringstream nombreArchivoStream;
        nombreArchivoStream<<"./Disco/data/sectores/"<<setfill('0')<<setw(digitos)<<to_string(contadorSectores);
        sector.open(nombreArchivoStream.str());

        while (true) {

            f.seekg(posicionInicio, std::ios::beg);  // Establecer la posición de lectura
            f.read(buffer, file->totalRegisterBytes);  // Leer el segmento en el buffer

            if(f.eof()) break;

            sector.write(buffer, file->totalRegisterBytes);

            contadorRegistros++;

            if(contadorRegistros == this->NUMBER_REGISTER_PER_SECTOR) {
                contadorRegistros = 0;
                sector.close();
                ostringstream nombreArchivoStream;
                nombreArchivoStream<<"./Disco/data/sectores/"<<setfill('0')<<setw(digitos)<<to_string(++contadorSectores);
                sector.open(nombreArchivoStream.str());
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