#pragma once
#include <iostream>
#include "Json.hpp"
#include <fstream>

#define CONFIG "../config/conf.json"

class Server
{
private:
    /* data */
    int port;
    std::string password;
public:
    Server(int port, std::string pass);
    ~Server();
    bool loadConfig(std::string configAddress);
};