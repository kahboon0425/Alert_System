#include "../headerFile/User.h"
#include "../headerFile/MOHAdmin.h"
#include <iostream>

User::User(const string& username, const string& password, const string& residence, const int& phoneNo) {
    userUsername = username;
    userPassword = password;
    userResidence = residence;
    userPhoneNo = phoneNo;
}

string User::getUsername(){
    return userUsername;
}

string User::getPassword(){
    return userPassword;
}

string User::getResidence(){
    return userResidence;
}

int User::getPhoneNo(){
    return userPhoneNo;
}

bool User::login(const string& username, const string& password) {
    return (username == userUsername && password == userPassword);
}

void User::modifyProfile(const string& newUsername, const string& newPassword, const string& newResidence, const int& newPhoneNo) {
    userUsername = newUsername;
    userPassword = newPassword;
    userResidence = newResidence;
    userPhoneNo = newPhoneNo;
}

