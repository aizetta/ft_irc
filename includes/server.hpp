#pragma once
#include <iostream>
#include "Config.hpp"
#include <fstream>
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <unistd.h> // For read
#include "User.hpp"
#include <map>
#include <vector>

#define CONFIG "../config/conf.json"
class User;
class Server
{
public:

    Server(int port, std::string pass)
    : port(port)
    , password(pass)
    {}

    ~Server();

    void createSocket();
    void bindSocket();
    void listenSocket();
    void init();

    void connnectUser();

    bool loadConfig();
//гетеры и сетеры

    int getPort() const;

    const std::string &getPassword() const;

    int getSockfd() const;

    const sockaddr_in &getMyAddr() const;

    int getConnection() const;

    void setPassword(const std::string &password);

    void setSockfd(int sockfd);

    void setMyAddr(const sockaddr_in &myAddr);

    void setConnection(int connection);

    void setPort(int port);

private:
    std::string         password;
    int                 sockfd;
    sockaddr_in         my_addr;
    int                 connection;
    int                 port;
    std::vector<User*>  userList;

};
