#include<iostream>
#include"File/File.h"
using namespace std;

int main() {

    File f;
    f.setCsv("./docs/titanic.csv");

    

    // extraemos columnas, tambien setea el numero de columnas
    //f.extractSchema();

    f.numberColumns = 4;

    f.toFile();

    //f.printFile(0);
    //f.printFile(1);
    f.printFile(0);
    f.printFile(1);
    f.printFile(2);


    return 0;
}