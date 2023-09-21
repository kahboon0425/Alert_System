#ifndef MOHADMIN_H
#define MOHADMIN_H

#include "User.h"
#include "Doctor.h"

#include <iostream>
using namespace std;


class Admin {
public:
    Admin(const string& username, const string& password);
    ~Admin(); 
    // Admin Login
    bool login(const string& username, const string& password);
    // Manage User Account
    void createUser(const string& uUsername, const string& uPassword, const string& uResidence, const int& uPhoneNo);
    bool userLogin(const string& username, const string& password);
    User getUserInfo(const string& username);
    void updateUserInformation(const string& username, const string& newUsername, const string& newPassword, const string& newResidence, const int newPhoneNo);

    // Manage Doctor Account
    void createDoctor(const string& dUsername, const string& dPassword, const string& dResidence, const int& dPhoneNo);
    bool doctorLogin(const string& dUsername, const string& dPassword);
    Doctor getDoctorInfo(const string& dUsername);
    void updateDoctorInformation(const string& dUsername, const string& dNewUsername, const string& dNNewPassword, const string& dNewResidence, const int dNewPhoneNo);
    

private:
    string adminUsername;
    string adminPassword;

    // User Dynamic Array
    User* userContainer; // Dynamic array to store user information
    int userCapacity; // Current capacity of the dynamic array
    int userSize; // Number of users currently stored

    // Doctor Dynamic Array
    Doctor* doctorContainer; 
    int doctorCapacity; 
    int doctorSize; 
};

#endif
