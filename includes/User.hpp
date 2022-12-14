//
// Created by Abathur Izetta on 10/23/22.
//
#pragma once
#include "Server.hpp"

class User
{
private:
public:
    const std::string &GetNickName() const;

    const std::string &GetUserName() const;

    const std::string &GetRealName() const;

private:
    std::string nickName;
    std::string userName;
    std::string realName;
    int connection; //maybe useless, see later
    bool isOper; //am i an operator?
public:
    User();
    bool ParseUser(char *buff);
};
