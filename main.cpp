#include<iostream>
#include"File/File.h"
using namespace std;

int main() {

    File f;
    f.setCsv("./docs/titanic.csv");

    f.extractSchema();
    f.toFile();
    f.printFile(0);

    return 0;
}