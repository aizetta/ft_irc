#include "server.hpp"

Server::Server(int port, std::string pass): port(port), password(pass) {
    //TODO: init params here
    loadConfig(CONFIG);
}
Server::~Server(){
    //TODO: check if we alloced something and delete this shit if any
}


//return false on failure
//returns true on success
//private bool read_config(std::string configAddress)
//exit with error on false
bool Server::loadConfig(std::string configAddress) {
    Json    file(configAddress);
    std::cout << "ZBS" << std::endl;
}