#include<iostream>
#include"File/File.h"
#include"Disco/Disco.h"
using namespace std;

int main() {

    File f;
    f.setCsv("./docs/titanic.csv");

    Disco d(2,5,10, 500);
    d.setFile(&f, "titanic");
    d.loadFile();
    d.setDirectory();

    d.printSector();

    return 0;
}