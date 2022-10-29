//
// Created by Abathur Izetta on 10/23/22.
//

#include "User.hpp"

User::User()
{

}

bool User::ParseUser(char *buff)
{
    int i = 0;
    bool flag = true;
    int size_arr = std::strlen(buff);
    std::string str = std::string(buff, size_arr);
    int start= str.find("USER");
    start += 5;
    int count = 0;
    while (str[start + count] != ' ')
    {
        count++;
    }
    userName = str.substr(start,count);
    std::cout <<"user = "<< userName << std::endl;

    start= str.find("localhost :");
    start += 11;
    count = 0;
    while (str[start + count] != '\r')
    {
        count++;
    }
    realName= str.substr(start,count);
    std::cout << "realName = "<< realName << std::endl;

    start = str.find("NICK");
    start += 5;
    count = 0;
    while (str[start + count] != '\r')
    {
        count++;
    }
    nickName = str.substr(start,count);
    std::cout <<"nick = "<< nickName << std::endl;
    return false;
}

const std::string &User::GetNickName() const
{
    return nickName;
}

const std::string &User::GetUserName() const
{
    return userName;
}

const std::string &User::GetRealName() const
{
    return realName;
}

