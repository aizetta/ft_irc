//
// Created by Abathur Izetta on 10/23/22.
//
#pragma once
#include "server.hpp"
#ifndef FT_IRC_USER_HPP
#define FT_IRC_USER_HPP


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


#endif //FT_IRC_USER_HPP
