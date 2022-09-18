//
// Created by Abathur Izetta on 9/17/22.
//

#include "Json.hpp"
 Json::~Json() {
     //TODO: check if we alloced something and delete this shit if any
}
Json::Json(std::string nameFile) {
    std::string line;
    std::ifstream	jsonFile(nameFile);
    if (!jsonFile.is_open()){
        std::cout << "ERROR OPEN CONFIG FILE" << std::endl;
    }
    while (getline(jsonFile, line)){
        std::cout << line << std::endl;
    }
    std::cout << "END PARSE"<< std::endl;
    jsonFile.close();
}