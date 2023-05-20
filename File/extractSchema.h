#ifndef EXTRACT_SCHEMA
#define EXTRACT_SCHEMA


#include"File.h"
const char * getValue(char * type) {
    if(!strcmp(type, "int")) {
        return "10";
    } else if(!strcmp(type, "str")) {
        return "100";
    } else if(!strcmp(type, "bool")) {
        return "1";
    } else if(!strcmp(type, "float")) {
        return "15";
    }

    return "";
}

void File::extractSchema() {
    ifstream csvFile(this->csv);
    ofstream schema("./docs/schema");
    ofstream spacesSchema("./docs/spacesSchema");

    if (csvFile.is_open()) {
        int pos = 0;
        char type[256];
        csvFile.getline(buffer + pos, lenBuffer);
        char *token = myStrtok(buffer + pos, ",");
        while (token != nullptr)
        {
            cout<<token<<": ";
            cin>>type;
            schema<<token<<" "<<type<<" "<<endl;
            spacesSchema<<getValue(type)<<" ";
            numberColumns++;
            token = myStrtok(nullptr, ",");
        }
        schema.close();
        spacesSchema.close();
        csvFile.close();
    } else {
        cout<<"No se puede abrir"<<endl;
    }
    
}

#endif