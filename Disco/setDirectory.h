#ifndef SET_DIRECTORY
#define SET_DIRECTORY

#include"Disco.h"

namespace fs = std::filesystem;

void Disco::setDirectory() {
    ofstream directorio("./Disco/data/directorio");
    
    int contPlatos = 1;
    int contSuperficies = 1;
    int contPistas = 1;
    int contSectores = 1;

    int contBloques = 1;
    
    for (const auto& archivo : fs::directory_iterator("./Disco/data/sectores/")) {

        if(contBloques == 1) directorio << "#" << endl;

        directorio << archivo.path().filename().string() << " " << contPlatos << " " << contSuperficies << " " << contPistas <<endl;

        contBloques++;
        contSectores++;

        if(contBloques > NUMBER_SECTORS_PER_CLUSTER) {
            contBloques = 1;
        }

        if(contSectores > this->numSectores) {
            contSectores = 1;
            contPistas++;
            contBloques = 1; // los bloques solo se encuentran contiguos en una pista

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