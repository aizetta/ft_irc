//all sorts of includes go here
#include "Server.hpp"
#include <cstdlib>

int main (int arc, char **argv){

    //check args here
    if (arc != 3 ){
        std::cout << "ERROR ARGV" << std::endl;
        exit(0);
    }
    int port = atoi(argv[1]);
    if (port > 49151 || port < 1024){
        std::cout << "ERROR PORT" << std::endl;
    }
    //Init shit her
    //TODO: create server class here
    Server server(port, argv[2]);
    server.CreateSocket();
    server.BindSocket();
    server.ListenSocket();
    while (1)
    {
        server.ConnnectUser();
    }
    //Init it with params from config >>  Server(int port, std::string pass);
    //event listener here
    //event writer here
    //run server
    //main loop goes here
    //main loop listens to events and acts accordingly
    return 0;
}
