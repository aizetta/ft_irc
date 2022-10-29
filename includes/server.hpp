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

    void CreateSocket();
    void BindSocket();
    void ListenSocket();
    void Init();

    void ConnnectUser();

    bool LoadConfig();
//гетеры и сетеры

    int GetPort() const;

    const std::string &GetPassword() const;

    int GetSockfd() const;

    const sockaddr_in &GetMyAddr() const;

    int GetConnection() const;

    void SetPassword(const std::string &password);

    void SetSockfd(int sockfd);

    void SetMyAddr(const sockaddr_in &myAddr);

    void SetConnection(int connection);

    void SetPort(int port);

private:
    std::string         password;
    int                 sockfd;
    sockaddr_in         my_addr;
    int                 connection;
    int                 port;
    std::vector<User*>  userList;

};
