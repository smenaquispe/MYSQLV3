#ifndef PRINT_FILE
#define PRINT_FILE

#include"File.h"

void File::printFile(int numeroRegistro) {
    ifstream file("./docs/file");
    if(file.is_open()) {
        file.seekg( (numeroRegistro * this->totalRegisterBytes) + 1);
        file.read(buffer, totalRegisterBytes);
        cout.write(buffer, totalRegisterBytes);
        cout<<endl;
        file.close();
    } else {
        cout<<"Problemas abriendo el file"<<endl;
    }

}

#endif