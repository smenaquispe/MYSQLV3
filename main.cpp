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

    cout<<"-----------------1------------------"<<endl;
    cout<<"Capacidad de bytes por registro: "<<f.totalRegisterBytes<<endl;
    cout<<"Capacidad de bytes del file: "<<f.totalRegisterBytes*f.numberRegisters<<endl;
    f.printFile(80);

    cout<<"-----------------2------------------"<<endl;
    d.calcCapacidad();

    cout<<"-----------------3------------------"<<endl;
    d.printSector("002");
    d.printInfoSector("002");

    cout<<"-----------------4------------------"<<endl;
    d.printBloque(4);
    d.printInfoBloque(4);

    return 0;
}