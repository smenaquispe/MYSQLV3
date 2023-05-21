#ifndef EXTRACT_SCHEMA
#define EXTRACT_SCHEMA


#include"File.h"
const char * getValue(const char * type) {
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
    ifstream schema("./docs/schema");
    ofstream spacesSchema("./docs/spacesSchema");

    if (schema.is_open()) {
        int pos = 0;
        char type[256];

        while (schema.getline(buffer + pos, lenBuffer))
        {
            char *token = myStrtok(buffer + pos, " ");

            bool isType = false;
            while (token != nullptr)
            {
                if(isType) {
                    spacesSchema<<getValue(token)<<" ";
                    numberColumns++;
                }

                else isType = true;

                token = myStrtok(nullptr, ",");
            }
        }

        schema.close();
        spacesSchema.close();
    } else {
        cout<<"No se puede abrir"<<endl;
    }
    
}

#endif