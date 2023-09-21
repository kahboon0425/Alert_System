#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User{
public:
    User(){};
    User(const string& username, const string& password, const string& residence, const int& phoneNo);
    bool login(const string& username, const string& password);
    void modifyProfile(const string& newUsername, const string& newPassword, const string& newResidence, const int& newPhoneNo);

    // Getter
    string getUsername();
    string getPassword();
    string getResidence();
    int getPhoneNo();


private:
    string userUsername;
    string userPassword;
    string userResidence;
    int userPhoneNo;

};

#endif