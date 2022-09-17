#include "server.hpp"

Server::Server(int port, std::string pass): port(port), password(pass) {
    //TODO: init params here
}
Server::~Server(){
    loadConfig("CONFIG");
    //TODO: check if we alloced something and delete this shit if any
}


//return false on failure
//returns true on success
//private bool read_config(std::string configAddress)
//exit with error on false
void Server::loadConfig(std::string configAddress) {

}