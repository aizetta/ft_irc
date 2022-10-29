//
// Created by Abathur Izetta on 10/23/22.
//

#include "User.hpp"

User::User(){

}

bool User::parseUser(char *buff) {
    int i = 0;
    bool flag = true;
    int size_arr = std::strlen(buff);
    std::string str = std::string(buff);
    std::cout << str << std::endl;
    int start= str.find("USER");
    start += 5;
    int count = 0;
    while (str[start + count] != ' '){
        count++;
    }
    userName = str.substr(start,count);
    std::cout <<"user = "<< userName << std::endl;

    start= str.find("localhost :");
    count = 0;
    while (str[start + count] != ' ' || str[start + count] != '\n'){
        count++;
    }
    realName= str.substr(start,count);
    std::cout << realName << std::endl;

    start = str.find("NICK");
    start += 5;
    count = 0;
    while (str[start + count]){
        count++;
    }
    nickName = str.substr(start,count);
    std::cout <<"nick = "<< nickName << std::endl;
    return false;
}

