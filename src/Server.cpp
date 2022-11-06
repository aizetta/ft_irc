#include <netdb.h>
#include "Server.hpp"
#include "message.h"

void Server::CreateSocket()
{
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd  == -1)
    {
        std::cout << "Failed to create socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::BindSocket()
{
    //    ассициировать сокет с портом на машине
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(port);
    std::cout << sockfd<< std::endl;
    if (bind(sockfd,(struct sockaddr*)&my_addr, sizeof(my_addr)) == -1)
    {
        std::cout << "Failed to bind to port "<< port << ". errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::ListenSocket()
{
    std::cout << "!soked = port!"<< std::endl;
    int users = 10;
    if (listen(sockfd, users) < 0)
    {
        std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "!listen!"<< std::endl;
}

void Server::HandleConnectUser()
{
    int addrlen = sizeof(sockaddr);

    //Поцоны тут брейкпоинт если поставите оно умрет, ета нормально
    connection = accept(sockfd,(struct sockaddr*)&my_addr, (socklen_t*)&addrlen);
    if (connection < 0)
    {
        std::cout << "Failed to grab connection. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "!connection!"<< std::endl;
    Message* message_handler = new Message();
    User* new_user = new User();
    char buffer[100];
    bzero(&buffer, 100);
    int bytes_sent = 0;
    std::cout << "new user1" << std::endl;
    bytes_sent = read(connection, &buffer, 100);
    message_handler->PrintMessage(buffer);
    new_user->ParseUser(buffer);
    std::cout << "new user2" << std::endl;
    bzero(&buffer, 100);
    bytes_sent = 0;
    std::string message = ":IRCat 376 ";
    message.append(new_user->GetNickName());
    message.append("\n");
    bytes_sent = send(connection, message.c_str(), message.length(), 0x1022);
    bytes_sent = 0;
    userList.push_back(new_user);
    std::cout << "выход из цикла" << std::endl;
}

void Server::HandleMessages()
{

}

Server::~Server()
{
    close(connection);
    std::cout << "close(connection)" << std::endl;
    close(sockfd);
    std::cout << "close(sockfd)" << std::endl;
    //TODO: check if we alloced something and delete this shit if any
}
//return false on failure
//returns true on success
//private bool read_config(std::string configAddress)
//exit with error on false
bool Server::LoadConfig()
{
    Config    file();
    std::cout << "ZBS" << std::endl;
    return 0;
}

//гетеры и сетеры

int Server::GetPort() const
{
    return port;
}

const std::string &Server::GetPassword() const
{
    return password;
}

int Server::GetSockfd() const
{
    return sockfd;
}

const sockaddr_in &Server::GetMyAddr() const
{
    return my_addr;
}

int Server::GetConnection() const
{
    return connection;
}

void Server::SetPassword(const std::string &password)
{
    this->password = password;
}

void Server::SetSockfd(int sockfd)
{
    this->sockfd = sockfd;
}

void Server::SetMyAddr(const sockaddr_in &myAddr)
{
    my_addr = myAddr;
}

void Server::SetConnection(int connection)
{
    this->connection = connection;
}

void Server::SetPort(int port)
{
    this->port = port;
}

void Server::Init()
{
    //TODO: Init params here
//    LoadConfig() == 1;


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
