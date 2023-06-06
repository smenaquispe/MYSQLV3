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

    /*
    int opc, number;
    string name;
    
    do
    {
        cout<<"-------DISCO-------"<<endl;
        cout<<"1. Imprimir todo el file"<<endl;
        cout<<"2. Imprimir un registro"<<endl;
        cout<<"3. Calcular la capacidad del disco"<<endl;
        cout<<"4. Imprimir un sector"<<endl;
        cout<<"5. Informacion de un sector"<<endl;
        cout<<"6. Imprimir un bloque"<<endl;
        cout<<"7. Informcacion de un bloque"<<endl;
        cout<<"8. Agregar registro"<<endl;
        cout<<"9. Salir"<<endl;       
        cout<<"Digite su opcion: ";
        cin>>opc;


        switch (opc)
        {
        case 1: f.printFile(); break;
        case 2: {
            cout<<"Nunero de registro: "; 
            cin>>number;
            f.printFile(number);
        } break;
        case 3: d.calcCapacidad(); break;
        case 4: {
            cout<<"Nombre de sector: ";
            cin>>name;
            d.printSector(name.c_str());
        } break;
        case 5: {
            cout<<"Nombre de sector: ";
            cin>>name;
            d.printInfoSector(name.c_str());
        } break;
        case 6: {
            cout<<"Numero de bloque: ";
            cin>>number;
            d.printBloque(number);
        } break;
        case 7: {
            cout<<"Numero de bloque: ";
            cin>>number;
            d.printInfoBloque(number);
        }
        case 8: {
            d.addRegistro();
        } break;
        case 9: break;
        default:
            cout<<"No es una opcion valida"<<endl;
            break;
        }

    } while (opc != 9);
    
    */

    d.moveRegistro();
    d.printSector("000");
    return 0;
}