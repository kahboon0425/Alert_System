#include "../headerFile/User.h"
#include "../headerFile/MOHAdmin.h"
#include <iostream>
#include <ctime>

User::User(const string &username, const string &name, const string &password, const string &residence, const int &phoneNo, time_t loginTime)
{
    userUsername = username;
    userName = name;
    userPassword = password;
    userResidence = residence;
    userPhoneNo = phoneNo;
    lastActivityTime = loginTime;
}

string User::getUsername()
{
    return userUsername;
}

string User::getName()
{
    return userName;
}

string User::getPassword()
{
    return userPassword;
}

string User::getResidence()
{
    return userResidence;
}

int User::getPhoneNo()
{
    return userPhoneNo;
}

string User::setUsername(const string &username)
{
    userUsername = username;
}

string User::setName(const string &name)
{
    userName = name;
}

string User::setPassword(const string &password)
{
    userPassword = password;
}

string User::setResidence(const string &residence)
{
    userResidence = residence;
}

int User::setPhoneNo(const int &phoneNo)
{
    userPhoneNo = phoneNo;
}

time_t User::getLastLoginTime() 
{
    return lastActivityTime;
}

bool User::login(const string &username, const string &password)
{
    return (username == userUsername && password == userPassword);
}

void User::modifyProfile(const string &newUsername,const string &newName, const string &newPassword, const string &newResidence, const int &newPhoneNo)
{
    userUsername = newUsername;
    userName = newName;
    userPassword = newPassword;
    userResidence = newResidence;
    userPhoneNo = newPhoneNo;
}

void User::setLoginTime()
{
    lastActivityTime = std::time(nullptr);
}

// Method to update the last activity time
// void User::updateLastActivityTime()
// {
//     lastActivityTime = time(nullptr);
// }
