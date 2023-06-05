#ifndef PRINT_SECTOR
#define PRINT_SECTOR

#include"Disco.h"

namespace fs = std::filesystem;

void Disco::printSector() {
    for (const auto& archivo : fs::directory_iterator("./Disco/data/sectores/")) {
        this->printSector(archivo.path().filename().string().c_str());
    }
}

void Disco::printSector(const char * nameSector) {

    const char rutaBase[] = "./Disco/data/sectores/";
    int longitud = std::strlen(rutaBase) + std::strlen(nameSector);

    // Crear un búfer para almacenar la ruta del archivo concatenada
    char *rutaArchivo = new char[longitud + 1];

    // Copiar la ruta base en el búfer
    std::strcpy(rutaArchivo, rutaBase);

    // Concatenar el nameSector al final del búfer
    std::strcat(rutaArchivo, nameSector);

    ifstream sector(rutaArchivo);

    if(sector.is_open()) {

        int numeroRegistro = 0;
        //for(int numeroRegistro = 0; numeroRegistro < NUMBER_REGISTER_PER_SECTOR; numeroRegistro++)  {
        while (!sector.eof()){

            //if(sector.eof()) break;
            
            // movemos hacia el siguiente registro
            sector.seekg((numeroRegistro * file->totalRegisterBytes) + 1);
            sector.read(buffer, file->totalRegisterBytes);

            int prevSize = 0;
            for(int i = 0; i < file->numberColumns; i++) {
                
                int columnLen = file->columnBytes[i];
                if(columnLen > 1) columnLen--; // si es uno, no se convertira en 0
                if(columnLen == 1) prevSize--; // si es uno, es necesario retroceder para que imprima como debe de ser

                // cuente desde que punto no hay espacios en blanco
                int startIndex = prevSize;
                while (buffer[startIndex] == ' ') {
                    startIndex++;
                }

                // mandamos a imprimir
                cout.write(buffer + startIndex, (columnLen + prevSize)  - startIndex);
                cout<<" ";

                prevSize += columnLen + 1;
            }

            cout<<endl;

            numeroRegistro++;
        }

        sector.close();
    } else {
        cout<<"Error abriendo el archvio sector"<<endl;
    }

}


#endif