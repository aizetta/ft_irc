#include <netdb.h>
#include "server.hpp"

Server::Server(int port, std::string pass): port(port), password(pass) {
    //TODO: init params here
//    loadConfig() == 1;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd  == -1) {
        std::cout << "Failed to create socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

//    ассициировать сокет с портом на машине
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(port);
    std::cout << sockfd<< std::endl;
    if (bind(sockfd,(struct sockaddr*)&my_addr, sizeof(my_addr)) == -1){
        std::cout << "Failed to bind to port "<< port << ". errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }


    std::cout << "!soked = port!"<< std::endl;
    int users = 10;
    if (listen(sockfd, users) < 0) {
        std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "!listen!"<< std::endl;

//    int addrlen = sizeof(sockaddr);
//    connection = accept(sockfd,(struct sockaddr*)&my_addr, (socklen_t*)&addrlen);
//    if (connection < 0) {
//        std::cout << "Failed to grab connection. errno: " << errno << std::endl;
//        exit(EXIT_FAILURE);
//    }
//    std::cout << "!connection!"<< std::endl;

//    char buffer[100];
//    bzero(&buffer, 100);
//    read(connection, buffer, 100);
//    std::cout << buffer << std::endl;
//    int bytes_sent = send(sockfd, "375", 3, 4130);
////    int bytes_sent;
//    bytes_sent = 0;
//
//    //SEND MESSAGE THO
//  //  if (msg.size() > 0)
//  //      send(sockfd, msg.c_str(), msg.size(), IRC_NOSIGNAL);
//
//    std::string message = ":IRCat 375 kekega :- IRCat Message of the day - \n";
//    while (strcmp(buffer,"QUIT") != 0) {
//        bytes_sent = read(connection, buffer, 100);
//        std::cout << buffer << std::endl;
//        bzero(&buffer, 100);
//        bytes_sent = 0;
//
//
//        bytes_sent = send(connection, message.c_str(), message.length(), 0x1022);
//        if (bytes_sent)
//            std::cout << bytes_sent << std::endl;
//        bytes_sent = 0;
//        message = ":IRCat 372 kekega :- ⠀⠀⠀⠀ ⣴⠉⡙⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⣚⡯⠴⢬⣱⡀⠀\n";
//        bytes_sent = send(connection, message.c_str(), message.length(), 0x1022);
//        if (bytes_sent)
//            std::cout << bytes_sent << std::endl;
//        bytes_sent = 0;
//        message = ":IRCat 376 kekega :End of /MOTD command\n";
//        bytes_sent = send(connection, message.c_str(), message.length(), 0x1022);
//        if (bytes_sent)
//            std::cout << bytes_sent << std::endl;
//        bytes_sent = 0;
//        std::cout << "while" << std::endl;
//    }
//
//    // Send a message to the connection
//    std::string response = "Good talking to you\n";
//    send(connection, response.c_str(), response.size(), 0);
//
////     Close the connections

}

void Server::connnectUser(){

    int addrlen = sizeof(sockaddr);
    connection = accept(sockfd,(struct sockaddr*)&my_addr, (socklen_t*)&addrlen);
    if (connection < 0) {
        std::cout << "Failed to grab connection. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "!connection!"<< std::endl;


    char buffer[100];
    bzero(&buffer, 100);
    int bytes_sent = 0;
    std::cout << "new" << std::endl;
    bytes_sent = read(connection, buffer, 100);
    std::cout << buffer << std::endl;
    bzero(&buffer, 100);

    std::cout << buffer << std::endl;
    bzero(&buffer, 100);
//    bytes_sent = 0;
//    std::string message = ":IRCat 371 kekega :\n";
//    bytes_sent = send(connection, message.c_str(), message.length(), 0x1022);
//    if (bytes_sent)
//        std::cout << bytes_sent << std::endl;
//    bytes_sent = 0;
////    message = ":IRCat 372 kekega :\n";
//    bytes_sent = send(connection, message.c_str(), message.length(), 0x1022);
//    if (bytes_sent)
//        std::cout << bytes_sent << std::endl;
    bytes_sent = 0;
    std::string message = ":IRCat 376 твой_ник_на_сервере\n";
    bytes_sent = send(connection, message.c_str(), message.length(), 0x1022);
    if (bytes_sent)
        std::cout << bytes_sent << std::endl;
    bytes_sent = 0;
    std::cout << "Good talking to you\n" << std::endl;
    std::cout << "выход из цикла" << std::endl;
//    // Send a message to the connection
//    std::string response = "Good talking to you\n";
//    send(connection, response.c_str(), response.size(), 0);
}
Server::~Server(){
    close(connection);
    close(sockfd);
    //TODO: check if we alloced something and delete this shit if any
}




//return false on failure
//returns true on success
//private bool read_config(std::string configAddress)
//exit with error on false
bool Server::loadConfig() {
    Config    file();
    std::cout << "ZBS" << std::endl;
    return 0;
}

//гетеры и сетеры

int Server::getPort() const {
    return port;
}

const std::string &Server::getPassword() const {
    return password;
}

int Server::getSockfd() const {
    return sockfd;
}

const sockaddr_in &Server::getMyAddr() const {
    return my_addr;
}

int Server::getConnection() const {
    return connection;
}

void Server::setPassword(const std::string &password) {
    Server::password = password;
}

void Server::setSockfd(int sockfd) {
    Server::sockfd = sockfd;
}

void Server::setMyAddr(const sockaddr_in &myAddr) {
    my_addr = myAddr;
}

void Server::setConnection(int connection) {
    Server::connection = connection;
}

void Server::setPort(int port) {
    Server::port = port;
}
