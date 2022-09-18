//
// Created by Abathur Izetta on 9/17/22.
//

#include "Json.hpp"
 Json::~Json() {
     //TODO: check if we alloced something and delete this shit if any
}
Json::Json(std::string nameFile) {
    std::string line;
    std::string buffer;
    std::ifstream jsonFile(nameFile);

    if (!jsonFile.is_open()) {
        std::cout << "ERROR OPEN CONFIG FILE" << std::endl;
    }
    while (getline(jsonFile, buffer)) {
        line += buffer;
    }
    int i = 0;
    while (line[i]){

        i++;
    }

    jsonFile.close();
    std::cout << line << std::endl;
    std::cout << "END PARSE"<< std::endl;
}