//
// Created by Abathur Izetta on 10/23/22.
//
#pragma once
#include "Server.hpp"

class User {
private:
public:
    const std::string &getNickName() const;

    const std::string &getUserName() const;

    const std::string &getRealName() const;

private:
    std::string nickName;
    std::string userName;
    std::string realName;
public:
    User();
    bool parseUser(char *buff);

};
