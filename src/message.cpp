//
// Created by Carly Yuriko on 11/5/22.
//

#include <string>
#include <iostream>
#include "message.h"

Message::Message()
{

}

bool Message::PrintMessage(char *buff) {
    int i = 0;
    bool flag = true;
    int size_arr = std::strlen(buff);
    std::string str = std::string(buff, size_arr);
    std::cout << str << std::endl;

}