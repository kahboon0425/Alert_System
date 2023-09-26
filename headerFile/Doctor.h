#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
using namespace std;

#include "DengueReport.h"
#include "LinkedList.h"

class Doctor
{
public:
    Doctor(){};
    Doctor(const string &username, const string &password, const string &residence, const int &phoneNo);
    bool login(const string &username, const string &password);
    void modifyProfile(const string &newUsername, const string &newPassword, const string &newResidence, const int &newPhoneNo);
    // ~Doctor();
  

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