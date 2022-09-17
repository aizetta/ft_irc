#include <iostream>

class Server
{
private:
    /* data */
    int port;
    std::string password;
public:
    Server(int port, std::string pass);
    ~Server();

    //private bool read_config(std::string configAddress)
    //returns true on success
    //return false on failure
    //exit with error on false
};


Server::~Server()
{
    //TODO: check if we alloced something and delete this shit if any
}
