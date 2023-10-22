#include "../headerFile/Doctor.h"
#include "../headerFile/MOHAdmin.h"
#include "../headerFile/Doctor.h"
// #include "../headerFile/DengueReport.h"
// #include "../headerFile/LinkedList.h"
#include <iostream>

Doctor::Doctor(const string &username, const string &password, const string &residence, const int &phoneNo)
{
    userUsername = username;
    userPassword = password;
    userResidence = residence;
    userPhoneNo = phoneNo;
}

string Doctor::getUsername()
{
    return userUsername;
}

string Doctor::getPassword()
{
    return userPassword;
}

string Doctor::getResidence()
{
    return userResidence;
}

int Doctor::getPhoneNo()
{
    return userPhoneNo;
}

string Doctor::setUsername(const string &username)
{
    userUsername = username;
}

string Doctor::setPassword(const string &password)
{
    userPassword = password;
}

string Doctor::setResidence(const string &residence)
{
    userResidence = residence;
}

int Doctor::setPhoneNo(const int &phoneNo)
{
    userPhoneNo = phoneNo;
}

bool Doctor::login(const string &username, const string &password)
{
    return (username == userUsername && password == userPassword);
}

void Doctor::modifyProfile(const string &newUsername, const string &newPassword, const string &newResidence, const int &newPhoneNo)
{
    userUsername = newUsername;
    userPassword = newPassword;
    userResidence = newResidence;
    userPhoneNo = newPhoneNo;
}
