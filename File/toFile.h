#ifndef TO_FILE
#define TO_FILE

#include"File.h"
#include"../Utils/myStrtok.h"

void File::toFile() {

    // seteamos el array que guardará los espacios que alamacena cada columna
    this->columnBytes = new int[numberColumns];
    
    ifstream spacesSchema("./docs/spacesSchema");
    spacesSchema.getline(buffer, lenBuffer);

    int it = 0;
    char * token = myStrtok(buffer, " ");
    while (token != nullptr)
    {
        this->columnBytes[it++] = atoi(token);
        this->totalRegisterBytes += atoi(token);
        token = myStrtok(nullptr, " ");
    }

    // cree el file a partir del csv y los espacios que alamacena cada uno
    ifstream csvFile(this->csv);
    ofstream file("./docs/file");

    bool isHeader = true;
    if(csvFile.is_open()) {
        int pos = 0;
        while(csvFile.getline(buffer + pos, lenBuffer)) {
            
            if(!isHeader) {
                int column = 0;
                char * token = myStrtok(buffer + pos, ",");
                while (token != nullptr)
                {
                    if(strlen(token) != 0) 
                        file<<setw(this->columnBytes[column])<<token;
                    else 
                        file<<setw(this->columnBytes[column])<<"-";
                    column++;
                    token = myStrtok(nullptr, ",");
                }

            }
            
            if(isHeader) isHeader = false;
            if(pos >= sizeof(buffer)) {
                pos = 0;
            }
        }
    }

}

#endif