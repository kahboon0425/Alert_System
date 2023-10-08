#include <iostream>
#include "headerFile/MOHAdmin.h"
#include "headerFile/User.h"
#include "headerFile/Doctor.h"
#include "headerFile/DengueCases.h"
#include "headerFile/AnnualDengueCases.h"
#include "headerFile/WeeklyDengueCases.h"
#include "cppFile/MOHAdmin.cpp"
#include "cppFile/User.cpp"
#include "cppFile/Doctor.cpp"
#include "cppFile/DengueCases.cpp"
#include "cppFile/AnnualDengueCases.cpp"
#include "cppFile/WeeklyDengueCases.cpp"

#include <string> // Add this line to include the <string> header
#include <fstream>
#include <sstream>
using namespace std;
#include <map>

void mainMenu(Admin &admin, Doctor &doctor, DengueCasesLinkedList &dengueCases, Patient &patient, AnnualDengueCasesLinkedList &annualDengueCases, WeeklyDengueCasesLinkedList &weeklyDengueCases)
{

    string admin_username;
    string admin_password;

    int choice;
    int mainMenuChoice;
    int userMenu;

    // Register
    string user_username;
    string user_password;
    string user_residence;
    int user_phoneNo;

    // Modify Account
    string newUsername;
    string newPassword;
    string newResidence;
    int newPhoneNo;

    // Dengue Cases
    int noOfCases;
    string patientId;
    string patientName;
    int patientAge;
    string patientResidence;
    int patientPhoneNo;
    int patientEmergencyContactNo;
    string reportDate;

    string searchPatientId;
    string searchPatientName;

    int minAge;
    int maxAge;
    string state1;
    string state2;
    int countCase;

    ifstream file;
    string fileName;
    string line;
    string word;
    string rowData;

    string year;
    string token;
    int totalCases;
    int columnCount;
    map<string, int> totalCasesByYear;

    bool returnToAdminMenu = false;

    cout << "\n----------- DENGUE FEVER SURVEILLANCE AND ALERT SYSTEM -----------\n"
         << endl;
    cout << "1. Login As User \n2. Login As Doctor \n3. Login As Admin\n\nEnter your choice: ";

    cin >> mainMenuChoice;

    switch (mainMenuChoice)
    {
    case 1: // Login As User
        cout << "\n-------- Login As User --------\n";
        cout << "\nEnter user username: ";
        cin >> user_username;
        cout << "Enter user password: ";
        cin >> user_password;

        if (admin.userLogin(user_username, user_password))
        {
            cout << "\nLogin Successfully.\n"
                 << endl;
            User userInfo = admin.getUserInfo(user_username);

            while (true)
            {
                cout << "1. Manage Personal Information \n2. View Total Dengue Cases \n3. View Daily Dengue Cases \n4. View Dengue Alert Messages \n5. Search Status \n6. Logout \n\nEnter your choice: ";
                cin >> userMenu;

                switch (userMenu)
                {
                case 1: // Manage Personal Information
                    cout << "\n<<<<< Welcome to your profile <<<<<" << endl;
                    cout << ">>>>> User Profile >>>>>>\n";
                    cout << "Username: " << userInfo.getUsername() << endl;
                    cout << "Password: " << userInfo.getPassword() << endl;
                    cout << "Residence: " << userInfo.getResidence() << endl;
                    cout << "Phone Number: " << userInfo.getPhoneNo() << endl;

                    while (true)
                    {
                        cout << "\n >>>> Options >>>>\n";
                        cout << "\n1. Modify Username \n2. Modify Password \n3. Modify Residence \n4. Modify Phone Number \n5. Logout\n\nEnter your choice: ";

                        int modifyProfileInfo;
                        cin >> modifyProfileInfo;

                        switch (modifyProfileInfo)
                        {
                        case 1:
                            cout << "Enter new username: ";
                            cin >> newUsername;
                            admin.updateUserInformation(userInfo.getUsername(), newUsername, userInfo.getPassword(), userInfo.getResidence(), userInfo.getPhoneNo());
                            break;
                        case 2:
                            cout << "Enter new password: ";
                            cin >> newPassword;
                            admin.updateUserInformation(userInfo.getUsername(), userInfo.getUsername(), newPassword, userInfo.getResidence(), userInfo.getPhoneNo());
                            break;
                        case 3:
                            cout << "Enter new residence: ";
                            cin >> newResidence;
                            admin.updateUserInformation(userInfo.getUsername(), userInfo.getUsername(), userInfo.getPassword(), newResidence, userInfo.getPhoneNo());
                            break;
                        case 4:
                            cout << "Enter new phone number: ";
                            cin >> newPhoneNo;
                            admin.updateUserInformation(userInfo.getUsername(), userInfo.getUsername(), userInfo.getPassword(), userInfo.getResidence(), newPhoneNo);
                            break;
                        case 5:
                            returnToAdminMenu = true;
                            break;
                        }
                        if (returnToAdminMenu)
                        {
                            break;
                        }
                    }
                    break;

                case 2: // View Total Dengue Cases
                    // code
                    break;
                case 3: // View Daily Dengue Cases
                    // code
                    break;
                case 4: // View Dengue Alert Messages
                    // code
                    break;
                case 5: // Search Status
                    // code
                    break;
                case 6: // Logout
                    return;
                }
            }
        }
        else
        {
            cout << "User login failed. Try again." << endl;
        }
        break;

    case 2: // Login As Doctor
        cout << "\n-------- Login As Doctor --------\n";
        cout << "\nEnter doctor username: ";
        cin >> user_username;
        cout << "Enter doctor password: ";
        cin >> user_password;

        if (admin.doctorLogin(user_username, user_password))
        {
            cout << "\nLogin Successfully.\n"
                 << endl;
            Doctor doctorInfo = admin.getDoctorInfo(user_username);

            while (true)
            {
                cout << "\n >>>>> Doctor Menu >>>>>\n";
                cout << "\n1. Manage Personal Information \n2. Report Cases \n3. View Reported Cases \n4. Find Name And Id \n5. Find Age And State \n6. Logout \n\nEnter your choice: ";
                cin >> userMenu;

                switch (userMenu)
                {
                case 1: // Manage Personal Information
                    cout << "\n<<<<< Welcome to your profile <<<<<" << endl;
                    cout << ">>>>> Doctor Profile >>>>>>\n";
                    cout << "Username: " << doctorInfo.getUsername() << endl;
                    cout << "Password: " << doctorInfo.getPassword() << endl;
                    cout << "Residence: " << doctorInfo.getResidence() << endl;
                    cout << "Phone Number: " << doctorInfo.getPhoneNo() << endl;

                    while (!returnToAdminMenu)
                    {
                        cout << "\n >>>> Options >>>>\n";
                        cout << "\n1. Modify Username \n2. Modify Password \n3. Modify Residence \n4. Modify Phone Number \n5. Logout\n\nEnter your choice: ";

                        int modifyProfileInfo;
                        cin >> modifyProfileInfo;

                        switch (modifyProfileInfo)
                        {
                        case 1:
                            cout << "Enter new username: ";
                            cin >> newUsername;
                            admin.updateDoctorInformation(doctorInfo.getUsername(), newUsername, doctorInfo.getPassword(), doctorInfo.getResidence(), doctorInfo.getPhoneNo());
                            break;
                        case 2:
                            cout << "Enter new password: ";
                            cin >> newPassword;
                            admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), newPassword, doctorInfo.getResidence(), doctorInfo.getPhoneNo());
                            break;
                        case 3:
                            cout << "Enter new residence: ";
                            cin >> newResidence;
                            admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), newResidence, doctorInfo.getPhoneNo());
                            break;
                        case 4:
                            cout << "Enter new phone number: ";
                            cin >> newPhoneNo;
                            admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), doctorInfo.getResidence(), newPhoneNo);
                            break;
                        case 5:
                            returnToAdminMenu = true;
                            break;
                        }
                    }
                    continue;

                case 2: // Report Cases

                    cout << "How many cases you want to report?: ";
                    cin >> noOfCases;
                    for (int i = 0; i < noOfCases; i++)
                    {
                        cout << "Enter patient's Id: ";
                        cin >> patientId;
                        cout << "Enter patient's name: ";
                        cin >> patientName;
                        cout << "Enter patient's age: ";
                        cin >> patientAge;
                        cout << "Enter patient's residence: ";
                        cin >> patientResidence;
                        cout << "Enter patient's phone number: ";
                        cin >> patientPhoneNo;
                        cout << "Enter patient's emergency contact number: ";
                        cin >> patientEmergencyContactNo;
                        cout << "Enter a date in YYYY-MM-DD format: ";
                        cin >> reportDate;

                        if (dengueCases.isValidDate(reportDate, "%Y-%m-%d"))
                        {
                            cout << "Valid date: " << reportDate << endl;
                        }
                        else
                        {
                            cout << "Invalid date format. Please enter the date in YYYY-MM-DD format." << std::endl;
                        }

                        dengueCases.insert(Patient(patientId, patientName, patientAge, patientResidence, patientPhoneNo, patientEmergencyContactNo, reportDate, doctorInfo.getUsername()));
                    };
                    

                    continue;

                case 3: // View Reported Cases
                    dengueCases.findLatestCaseByDoctor(doctorInfo.getUsername());
                    continue;

                case 4: // Find Name And Id
                    cout << ">>>>>>>> Find dengue fever cases based on patient name or patient id >>>>>>>" << endl;
                    cout << "Enter Patient Id: ";
                    cin >> searchPatientId;
                    cout << "Enter Patient Name: ";
                    cin >> searchPatientName;
                    dengueCases.findDengueCasesByPatientIdAndName(searchPatientId, searchPatientName);
                    continue;
                case 5: // Find Age And State
                    cout << "<<<<<< Find the number of cases for any given age range and any given state range <<<<<<\n"
                         << endl;
                    cout << "Enter Age Range >>" << endl;
                    cout << "Min Age: ";
                    cin >> minAge;
                    cout << "Max Age: ";
                    cin >> maxAge;
                    cout << "\nEnter State Range >>" << endl;
                    cout << "State 1: ";
                    cin >> state1;
                    cout << "State 2: ";
                    cin >> state2;
                    countCase = dengueCases.countCasesByAgeAndState(minAge, maxAge, state1, state2);
                    cout << "\nNumber of cases within the age range " << minAge << " to " << maxAge
                         << " and state range " << state1 << " to " << state2 << ": " << countCase << endl;
                    continue;
                case 6: // Logout
                    return;
                }
                return;
            }
        }
        else
        {
            cout << "Doctor login failed. Try again." << endl;
        }
        break;

    case 3: // Login As Admin
        cout << "\nEnter admin username: ";
        cin >> admin_username;
        cout << "Enter admin password: ";
        cin >> admin_password;

        if (admin.login(admin_username, admin_password))
        {
            cout << "Login Successfully." << endl;

            while (true)
            {
                cout << "------------------ Admin Menu ------------------\n"
                     << endl;
                cout << "1. View Total Dengue Cases \n2. View Weekly Dengue Cases \n3. Send Alert Message \n4. Manage Doctor Account \n5. Manage User Account \n6. Logout \n\nEnter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    annualDengueCases.clear();
                    annualDengueCases.addNewDengueCases(dengueCases);
                    fileName = "csvFile/AnnualDengueCasesByState.csv";

                    // Read data from the CSV file and populate the linked list
                    file.open(fileName);
                    if (file.is_open())
                    {
                        // Skip the header line
                        getline(file, line);

                        while (getline(file, line))
                        {
                            stringstream ss(line);
                            totalCases = 0;
                            columnCount = 0;

                            while (getline(ss, token, ','))
                            {
                                if (columnCount == 0)
                                { // Year is in the first column
                                    year = token;
                                }
                                else if (columnCount >= 2) // Starting from the third column
                                {
                                    totalCases += stoi(token); // Convert token to integer and add to totalCases
                                }
                                columnCount++;
                            }

                            annualDengueCases.readCsvFileAnnualCases(year, totalCases);
                        }

                        file.close();
                        cout << "\n";
                        cout << ">>>>>>>> Total Dengue Cses by Year >>>>>>>>>>>>\n"
                             << endl;
                        annualDengueCases.displayTotalCases();
                        cout << "\n";
                    }
                    else
                    {
                        cout << "Could not open the file\n"; // Display an error message if the file couldn't be opened
                    }

                    cout << ">>>>>>>> Bar Chart(scaled by 1000) >>>>>>>>>>>>\n"
                         << endl;
                    annualDengueCases.displayScaledBarChart(1000);
                    cout << "\n";

                    continue;
                case 2:
                    fileName = "csvFile/NumberOfDengueFeverCasesWeeklyByState.csv";

                    // Read data from the CSV file and populate the linked list
                    file.open(fileName);
                    if (file.is_open())
                    {

                        // Skip the header line
                        getline(file, line);

                        cout << "\nYear\tWeek\tJHR\tKDH\tKTN\tMLK\tN.S\tPHG\tPRK\tPLS\tP.P\tSBH\tSWK\tSGR\tTRG\tKL\tLBN" << endl;
                        cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;

                        while (getline(file, line))
                        {
                            stringstream str(line);
                            string rowData;

                            while (getline(str, word, ',')) // Split the line into fields separated by commas
                            {
                                if (!rowData.empty())
                                {
                                    rowData += "\t"; // Add a comma if it's not the first field in the row
                                }
                                rowData += word; // Append the current field to the row data
                            }

                            weeklyDengueCases.readCsvFile(rowData); // Add the complete row data to the linked list
                            cout << rowData << endl;                // Print each row
                        }

                        file.close();
                    }

                   
                    continue;
                case 3:
                    // code
                    break;
                case 4:
                    cout << "\n>>>>> Create New Doctor >>>>\n"
                         << endl;
                    cout << "Username: ";
                    cin >> user_username;
                    cout << "Password: ";
                    cin >> user_password;
                    cout << "Residence: ";
                    cin >> user_residence;
                    cout << "Phone Number: ";
                    cin >> user_phoneNo;
                    admin.createDoctor(user_username, user_password, user_residence, user_phoneNo);
                    break;

                case 5:
                    cout << "\n>>>>> Create New User >>>>\n"
                         << endl;
                    cout << "Username: ";
                    cin >> user_username;
                    cout << "Password: ";
                    cin >> user_password;
                    cout << "Residence: ";
                    cin >> user_residence;
                    cout << "Phone Number: ";
                    cin >> user_phoneNo;
                    admin.createUser(user_username, user_password, user_residence, user_phoneNo);
                    break;
                case 6:
                    return;
                }
            }
        }
        else
        {
            cout << "Wrong admin username or password. Try again." << endl;
        }
        break;
    }
}

int main()
{
    Admin admin("admin", "admin123");
    Doctor doctor;
    DengueCasesLinkedList dengueCases;
    Patient patient;
    AnnualDengueCasesLinkedList annualDengueCases;
    WeeklyDengueCasesLinkedList weeklyDengueCases;

    while (true)
    {
        mainMenu(admin, doctor, dengueCases, patient, annualDengueCases, weeklyDengueCases);
    }

    return 0;
}
