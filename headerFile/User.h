#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User{
public:
    User(){};
    User(const string& username, const string& name,const string& password, const string& residence, const int& phoneNo, time_t loginTime);
    bool login(const string& username, const string& password);
    void modifyProfile(const string& newUsername,const string& name, const string& newPassword, const string& newResidence, const int& newPhoneNo);
    void setLoginTime();

    // setter
    string setUsername(const string &username);
    string setName(const string &name);
    string setPassword(const string &password);
    string setResidence(const string &residence);
    int setPhoneNo(const int &phoneNo);
    
    // void updateLastActivityTime();
    // bool isInactive(int inactivityThreshold) const;

    // Getter
    string getUsername();
    string getName();
    string getPassword();
    string getResidence();
    int getPhoneNo();
    time_t getLastLoginTime();

private:
    string userUsername;
    string userName;
    string userPassword;
    string userResidence;
    int userPhoneNo;
    time_t lastActivityTime;

};

#endif