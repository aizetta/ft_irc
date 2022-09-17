#include "server.hpp"

Server::Server(int port, std::string pass): port(port), password(pass) {
    //TODO: init params here
}
Server::~Server(){
    std::string		line;
    std::ifstream	jsonFile(CONFIG);
    if (!jsonFile.is_open())
    {
        std::cout << "ERROR OPEN JSON FILE" << std::endl;
    }
    loadConfig("CONFIG");
    //TODO: check if we alloced something and delete this shit if any
}


//return false on failure
//returns true on success
//private bool read_config(std::string configAddress)
//exit with error on false
bool Server::loadConfig(std::string configAddress) {
    std::cout << "ZBS" << std::endl;
}