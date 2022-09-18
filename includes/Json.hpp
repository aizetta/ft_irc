//
// Created by Abathur Izetta on 9/17/22.
//

#ifndef FT_IRC_JSON_HPP
#define FT_IRC_JSON_HPP
#include <map>
#include <iostream>
#include <string>
#include <fstream>

class Json{
private:
    std::map<std::string, std::string> jsonBase;

    Json (const Json &other);
    Json& operator=(const Json &other);
public:
   explicit Json(std::string nameFile);
    ~Json();
};


#endif //FT_IRC_JSON_HPP
