#ifndef SET_DIRECTORY
#define SET_DIRECTORY

#include"Disco.h"
#include<filesystem>

namespace fs = std::filesystem;

void Disco::setDirectory() {
    ofstream directorio("./Disco/data/directorio");

   /**
    * el directorio guardará bloques
    * los bloques tiene la informacion de que sector a que sector guarda
    * el bloque estará ubicado en un plato, una superficie y un track
    * 
    * 
    * 2 platos
    * 2 superficies por plato
    * 
    * 
    * 5 pistas por superficie
    * 10 sectores por pista
   */

    int contPlatos = 1;
    int contSuperficies = 1;
    int contPistas = 1;
    int contSectores = 1;
    
    for (const auto& archivo : fs::directory_iterator("./Disco/data")) {


        if(archivo.path().filename().string() != "directorio")
            directorio << archivo.path().filename().string() << " " << contPlatos << " " << contSuperficies << " " << contPistas <<endl;

        contSectores++;

        if(contSectores > this->numSectores) {
            contSectores = 1;
            contPistas++;
        }

        if(contPistas > this->numPistas) {
            contPistas = 1;
            contSuperficies++;
        } 
        
        if(contSuperficies > 2) {
            contSuperficies = 1;
            contPlatos++;
        } 

        if(contPlatos > this->numPlatos) {
            cout<<"El disco llegó a su maxima capacidad"<<endl;
            break;
        }

    }

}

#endif