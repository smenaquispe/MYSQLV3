#include<iostream>
#include"File/File.h"
#include"Disco/Disco.h"
using namespace std;

int main() {

    File f;
    f.setCsv("./docs/titanic.csv");

    Disco d(2,5,3, 500);
    //d.calcCapacidad();
    d.setFile(&f);
    d.loadFile();

    return 0;
}