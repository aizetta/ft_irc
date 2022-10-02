#pragma once
#include <iostream>
#include "Json.hpp"
#include <fstream>
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <unistd.h> // For read

#define CONFIG "../config/conf.json"

class Server
{
private:
    /* data */
    int port;
    std::string password;
    int         sockfd;
    sockaddr_in my_addr;
    int connection;
public:
    Server(int port, std::string pass);
    ~Server();
    bool loadConfig(std::string configAddress);
    int getfd();
    int getconnection();
};