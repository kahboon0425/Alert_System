#include "../headerFile/MOHAdmin.h"
#include "../headerFile/User.h" 
#include "../headerFile/Doctor.h"

Admin::Admin(const string& username, const string& password) {
    adminUsername = username;
    adminPassword = password;
    
    // User Dynamic Array
    userCapacity = 10; 
    userSize = 0; 
    userContainer = new User[userCapacity];

    // Doctor Dynamic Array
    doctorCapacity = 10; 
    doctorSize = 0; 
    doctorContainer = new Doctor[doctorCapacity]; 
    
}

bool Admin::login(const string& username, const string& password) {
    return (username == adminUsername && password == adminPassword);
}

void Admin::createUser(const string& uUsername, const string& uPassword, const string& uResidence, const int& uPhoneNo) {
    // Check if the dynamic array is full, and if so, resize it.
    if (userSize == userCapacity) {
        userCapacity *= 2; 
        User* temp = new User[userCapacity];
        
        // Copy existing users to the new array
        for (int i = 0; i < userSize; i++) {
            temp[i] = userContainer[i];
        }
        
        // Delete the old array and update the pointer
        delete[] userContainer;
        userContainer = temp;
    }
    

    // Create a new User object and add it to the dynamic array
    userContainer[userSize] = User(uUsername, uPassword, uResidence, uPhoneNo);
    userSize++;

    cout << "\nUser registered successfully!\n" << endl;
}

bool Admin::userLogin(const string& username, const string& password) {
    for (int i = 0; i < userSize; i++) {
        if (userContainer[i].login(username, password)) {
            return true;
        }
    }
    return false;
}


User Admin::getUserInfo(const string& username) {
    for (int i = 0; i < userSize; i++) {
        if (userContainer[i].getUsername() == username) {
            return userContainer[i];
        }
    }
    return User(); 
}


void Admin::updateUserInformation(const string& username, const string& newUsername, const string& newPassword, const string& newResidence, const int newPhoneNo) {
    for (int i = 0; i < userSize; i++) {
        if (userContainer[i].getUsername() == username) {
            // Update the user's information
            userContainer[i].modifyProfile(newUsername, newPassword, newResidence, newPhoneNo);
            cout << "Profile information updated successfully." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

void Admin::createDoctor(const string& dUsername, const string& dPassword, const string& dResidence, const int& dPhoneNo){
    if (doctorSize == doctorCapacity) {
        doctorCapacity *= 2; 
        Doctor* temp = new Doctor[doctorCapacity];
        
        // Copy existing users to the new array
        for (int i = 0; i < doctorSize; i++) {
            temp[i] = doctorContainer[i];
        }
        
        // Delete the old array and update the pointer
        delete[] doctorContainer;
        doctorContainer = temp;
    }
    

    // Create a new Doctor object and add it to the dynamic array
    doctorContainer[doctorSize] = Doctor(dUsername, dPassword, dResidence, dPhoneNo);
    doctorSize++;

    cout << "\nDoctor registered successfully!\n" << endl;
}

bool Admin::doctorLogin(const string& dUsername, const string& dPassword){
    for (int i = 0; i < doctorSize; i++) {
        if (doctorContainer[i].login(dUsername, dPassword)) {
            return true;
        }
    }
    return false;
}

Doctor Admin::getDoctorInfo(const string& dUsername){
    for (int i = 0; i < doctorSize; i++) {
        if (doctorContainer[i].getUsername() == dUsername) {
            return doctorContainer[i];
        }
    }
    return Doctor(); 
}

void Admin::updateDoctorInformation(const string& dUsername, const string& dNewUsername, const string& dNewPassword, const string& dNewResidence, const int dNewPhoneNo){
    for (int i = 0; i < doctorSize; i++) {
        if (doctorContainer[i].getUsername() == dUsername) {
            // Update the user's information
            doctorContainer[i].modifyProfile(dNewUsername, dNewPassword, dNewResidence, dNewPhoneNo);
            cout << "Profile information updated successfully.\n" << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}


Admin::~Admin() {
    // Free the dynamic array memory
    delete[] userContainer;
    delete[] doctorContainer;
}
