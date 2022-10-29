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
    std::string str = "";
    for (int x = 0; x < size_arr; x++) {
        str = str + buff[x];
    }
    int start= str.find("USER");
    start += 5;
    int count = 0;
    while (str[start + count] != ' '){
        count++;
    }
    nickName = str.substr(start,count);
    std::cout << size_arr << std::endl;
    std::cout << nickName << std::endl;
    return false;
}

