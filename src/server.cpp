#include <netdb.h>
#include "server.hpp"

Server::Server(int port, std::string pass): port(port), password(pass) {
    //TODO: init params here
//    loadConfig(CONFIG);
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd  == -1) {
        std::cout << "Failed to create socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
//    sockaddr_in  my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(9999);
    std::cout << sockfd<< std::endl;
    if (bind(sockfd,(struct sockaddr*)&my_addr, sizeof(my_addr)) == -1){
        std::cout << "Failed to bind to port "<< port << ". errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "!soked!"<< std::endl;
    if (listen(sockfd, 2) < 0) {
        std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "!listen!"<< std::endl;

    int addrlen = sizeof(sockaddr);
    connection = accept(sockfd,(struct sockaddr*)&my_addr, (socklen_t*)&addrlen);
    if (connection < 0) {
        std::cout << "Failed to grab connection. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "!connection!"<< std::endl;

    char buffer[100];
    auto bytesRead = read(connection, buffer, 100);
    std::cout << "The message was: " << buffer;

    // Send a message to the connection
    std::string response = "Good talking to you\n";
    send(connection, response.c_str(), response.size(), 0);

//     Close the connections
    close(connection);
    close(sockfd);
}
Server::~Server(){
    //TODO: check if we alloced something and delete this shit if any
}

int Server::getconnection() {
    return connection;
}

int Server::getfd() {
    return sockfd;
}



//return false on failure
//returns true on success
//private bool read_config(std::string configAddress)
//exit with error on false
bool Server::loadConfig(std::string configAddress) {
    Json    file(configAddress);
    std::cout << "ZBS" << std::endl;
}