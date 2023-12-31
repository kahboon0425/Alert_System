#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
using namespace std;

class Doctor
{
public:
    Doctor() {};
    Doctor(const string &username, const string &password, const string &residence, const int &phoneNo);
    bool login(const string &username, const string &password);
    void modifyProfile(const string &newUsername, const string &newPassword, const string &newResidence, const int &newPhoneNo);
  
    // Getter
    string getUsername();
    string getPassword();
    string getResidence();
    int getPhoneNo();

    // Setter
    string setUsername(const string &username);
    string setPassword(const string &password);
    string setResidence(const string &residence);
    int setPhoneNo(const int &phoneNo);

private:
    string userUsername;
    string userPassword;
    string userResidence;
    int userPhoneNo;

};

#endif
