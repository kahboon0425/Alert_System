#include "../headerFile/MOHAdmin.h"
#include "../headerFile/User.h"
#include "../headerFile/Doctor.h"

#include <ctime>
#include <iostream>

Admin::Admin(const string &username, const string &password)
{
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

bool Admin::login(const string &username, const string &password)
{
    return (username == adminUsername && password == adminPassword);
}

void Admin::createUser(const string &uUsername,const string &uName ,const string &uPassword, const string &uResidence, const int &uPhoneNo, time_t loginTime)
{
    // Check if the dynamic array is full, and if so, resize it.
    if (userSize == userCapacity)
    {
        userCapacity *= 2;
        User *temp = new User[userCapacity];

        // Copy existing users to the new array
        for (int i = 0; i < userSize; i++)
        {
            temp[i] = userContainer[i];
        }

        // Delete the old array and update the pointer
        delete[] userContainer;
        userContainer = temp;
    }

    // Create a new User object with the provided login time and add it to the dynamic array
    userContainer[userSize] = User(uUsername, uName, uPassword, uResidence, uPhoneNo, loginTime);
    userSize++;
}

bool Admin::isUserUsernameTaken(const std::string &usernameToCheck) {
    for (int i = 0; i < userSize; i++) {
        if (userContainer[i].getUsername() == usernameToCheck) {
            return true; // Username is already taken
        }
    }
    return false; // Username is not taken
}

bool Admin::userLogin(const string &username, const string &password)
{
    for (int i = 0; i < userSize; i++)
    {
        if (userContainer[i].login(username, password))
        {
            userContainer[i].setLoginTime();
            return true;
        }
    }
    return false;
}

User Admin::getUserInfo(const string &username)
{
    for (int i = 0; i < userSize; i++)
    {
        if (userContainer[i].getUsername() == username)
        {
            return userContainer[i];
        }
    }
    return User();
}

void Admin::updateUserInformation(const string &username, const string &newUsername,const string &newName,const string &newPassword, const string &newResidence, const int newPhoneNo)
{
    for (int i = 0; i < userSize; i++)
    {
        if (userContainer[i].getUsername() == username)
        {
            // Update the user's information
            userContainer[i].modifyProfile(newUsername, newName, newPassword, newResidence, newPhoneNo);
            cout << "Profile information updated successfully." << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

void Admin::createDoctor(const string &dUsername, const string &dPassword, const string &dResidence, const int &dPhoneNo)
{
    if (doctorSize == doctorCapacity)
    {
        doctorCapacity *= 2;
        Doctor *temp = new Doctor[doctorCapacity];

        // Copy existing users to the new array
        for (int i = 0; i < doctorSize; i++)
        {
            temp[i] = doctorContainer[i];
        }

        // Delete the old array and update the pointer
        delete[] doctorContainer;
        doctorContainer = temp;
    }

    // Create a new Doctor object and add it to the dynamic array
    doctorContainer[doctorSize] = Doctor(dUsername, dPassword, dResidence, dPhoneNo);
    doctorSize++;
}

bool Admin::isDocUsernameTaken(const std::string &usernameToCheck) {
    for (int i = 0; i < userSize; i++) {
        if (userContainer[i].getUsername() == usernameToCheck) {
            return true; // Username is already taken
        }
    }
    return false; // Username is not taken
}
bool Admin::doctorLogin(const string &dUsername, const string &dPassword)
{
    for (int i = 0; i < doctorSize; i++)
    {
        if (doctorContainer[i].login(dUsername, dPassword))
        {
            return true;
        }
    }
    return false;
}

Doctor Admin::getDoctorInfo(const string &dUsername)
{
    for (int i = 0; i < doctorSize; i++)
    {
        if (doctorContainer[i].getUsername() == dUsername)
        {
            return doctorContainer[i];
        }
    }
    return Doctor();
}

void Admin::updateDoctorInformation(const string &dUsername, const string &dNewUsername, const string &dNewPassword, const string &dNewResidence, const int dNewPhoneNo)
{
    for (int i = 0; i < doctorSize; i++)
    {
        if (doctorContainer[i].getUsername() == dUsername)
        {
            // Update the user's information
            doctorContainer[i].modifyProfile(dNewUsername, dNewPassword, dNewResidence, dNewPhoneNo);
            cout << "Profile information updated successfully.\n"
                 << endl;
            return;
        }
    }
    cout << "User not found." << endl;
}

// // Method to check and handle inactivity
// void Admin::checkInactivity()
// {
//     cout << "User to be deleted:" << endl;
//     int inactivityThreshold = 15 * 24 * 60 * 60;
//     for (int i = 0; i < userSize; i++)
//     {
//         User &user = userContainer[i];
//         if (user.getLastLoginTime()>=inactivityThreshold)
//         {
//             cout << "Username: " << user.getUsername() << endl;
//             cout << "Password: " << user.getPassword() << endl;
//             cout << "Last Activity Time: " << user.getLastLoginTime() << endl;

//             // Take appropriate action, e.g., deleting the user or disabling the account
//             // deleteUserAtIndex(i);
//             // i--; // Decrement the loop counter since the array size has reduced
//         }
//     }
// }

void Admin::checkInactivity()
{
    cout << "\n-----------User deleted (more than 14 days not login):--------------\n"
         << endl;
    int inactivityThreshold = time(NULL) - (15 * 24 * 60 * 60);
    for (int i = 0; i < userSize; i++)
    {
        User &user = userContainer[i];
        time_t lastLoginTime = user.getLastLoginTime();
        if (lastLoginTime <= inactivityThreshold)
        {
            cout << "Username: " << user.getUsername() << endl;
            cout << "Password: " << user.getPassword() << endl;
            cout << "Residence: " << user.getResidence() << endl;
            cout << "Phone No: " << user.getPhoneNo() << endl;

            // Format and print the Last Activity Time
            struct tm *timeinfo;
            timeinfo = localtime(&lastLoginTime);
            char buffer[11]; // To hold the formatted date (YYYY-MM-DD)
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
            cout << "Last Activity Time: " << buffer << endl;
            cout << "\n"
                 << endl;

            // Take appropriate action, e.g., deleting the user or disabling the account
            deleteUserAtIndex(i);
            i--; // Decrement the loop counter since the array size has reduced
        }
    }
}

void Admin::deleteUserAtIndex(int index)
{
    if (index < 0 || index >= userSize)
    {
        cout << "Invalid index for user deletion." << endl;
        return;
    }

    // Shift elements to fill the gap
    for (int i = index; i < userSize - 1; i++)
    {
        userContainer[i] = userContainer[i + 1];
    }

    // Decrease the userSize to reflect the removal
    userSize--;
}

void Admin::printAllUsers()
{
    for (int i = 0; i < userSize; i++)
    {
        User &user = userContainer[i];
        cout << "\nUsername: " << user.getUsername() << endl;
        cout << "Password: " << user.getPassword() << endl;
        cout << "Residence: " << user.getResidence() << endl;
        cout << "Phone No: " << user.getPhoneNo() << endl;

        // Get the Last Activity Time from the user
        time_t lastLoginTime = user.getLastLoginTime();

        // Format and print the Last Activity Time
        struct tm *timeinfo = localtime(&lastLoginTime);
        char buffer[11]; // To hold the formatted date (YYYY-MM-DD)
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
        cout << "Last Activity Date: " << buffer << endl;
    }
}

Admin::~Admin()
{
    // Free the dynamic array memory
    delete[] userContainer;
    delete[] doctorContainer;
}


