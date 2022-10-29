//
// Created by Abathur Izetta on 9/17/22.
//
#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>

class Config{
private:
public:
    Config(){
        sinFamily = "AF_INET";
        sAddr = "INADDR_ANY";

        // max_user;
        userCountMax = 10;
    }

    ~Config(){
        //TODO: check if we alloced something and delete this shit if any
    }
public:
    const std::string &getSinFamily() const {
        return sinFamily;
    }

    const std::string &getSAddr() const {
        return sAddr;
    }

    const std::string &getPasswordToServer() const {
        return passwordToServer;
    }

    int getUserCountMax() const {
        return userCountMax;
    }

private:
    std::string                        sinFamily;
    std::string                        sAddr;
    std::string                        passwordToServer;
    int                                userCountMax;
};
