#include <iostream>
#include <string>
#include <ctime>
#include <map> 
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

using namespace std;

// Function declarations
void displayMainMenu();
void loginAsUser(Admin &admin, User &user, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases);
void loginAsDoctor(Admin &admin, Doctor &doctor, DengueCasesLinkedList &dengueCases);
void loginAsAdmin(Admin &admin, AnnualDengueCasesLinkedList &annualDengueCases, WeeklyDengueCasesLinkedList &weeklyDengueCases, DengueCasesLinkedList &dengueCases);

void userMenu(Admin &admin, User &user, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases);
void doctorMenu(Doctor &doctor, Admin &admin, DengueCasesLinkedList &dengueCases);
void adminMenu(Admin &admin, AnnualDengueCasesLinkedList &annualDengueCases, WeeklyDengueCasesLinkedList &weeklyDengueCases, DengueCasesLinkedList &dengueCases);

int main()
{
    Admin admin("admin", "admin123");
    Doctor doctor;
    DengueCasesLinkedList dengueCases;
    User user;
    AnnualDengueCasesLinkedList annualDengueCases;
    WeeklyDengueCasesLinkedList weeklyDengueCases;

    while (true)
    {
        displayMainMenu();

        int mainMenuChoice;
        cin >> mainMenuChoice;

        switch (mainMenuChoice)
        {
        case 1:
        {
            // calling the function
            loginAsUser(admin, user, dengueCases, annualDengueCases);
            break;
        }
        case 2:
        {
            loginAsDoctor(admin, doctor, dengueCases);

            break;
        }
        case 3:
        {
            loginAsAdmin(admin, annualDengueCases, weeklyDengueCases, dengueCases);

            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    }

    return 0;
}

void displayMainMenu()
{
    cout << "\n----------- DENGUE FEVER SURVEILLANCE AND ALERT SYSTEM -----------\n"
         << endl;
    cout << "1. Login As User \n2. Login As Doctor \n3. Login As Admin\n\nEnter your choice: ";
}

void loginAsUser(Admin &admin, User &user, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases)
{
    string user_username;
    string user_password;

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
        userMenu(admin, userInfo, dengueCases, annualDengueCases);
    }
    else
    {
        cout << "User login failed. Try again." << endl;
    }
}

void loginAsDoctor(Admin &admin, Doctor &doctor, DengueCasesLinkedList &dengueCases)
{
    string doctor_username;
    string doctor_password;

    cout << "\n-------- Login As Doctor --------\n";
    cout << "\nEnter doctor username: ";
    cin >> doctor_username;
    cout << "Enter doctor password: ";
    cin >> doctor_password;

    if (admin.doctorLogin(doctor_username, doctor_password))
    {
        cout << "\nLogin Successfully.\n"
             << endl;
        Doctor doctorInfo = admin.getDoctorInfo(doctor_username);
        doctorMenu(doctorInfo, admin, dengueCases);
    }
    else
    {
        cout << "Doctor login failed. Try again." << endl;
    }
}

void loginAsAdmin(Admin &admin, AnnualDengueCasesLinkedList &annualDengueCases, WeeklyDengueCasesLinkedList &weeklyDengueCases, DengueCasesLinkedList &dengueCases)
{
    string admin_username;
    string admin_password;

    cout << "\nEnter admin username: ";
    cin >> admin_username;
    cout << "Enter admin password: ";
    cin >> admin_password;

    if (admin.login(admin_username, admin_password))
    {
        cout << "Login Successfully." << endl;
        adminMenu(admin, annualDengueCases, weeklyDengueCases, dengueCases);
    }
    else
    {
        cout << "Wrong admin username or password. Try again." << endl;
    }
}

void userMenu(Admin &admin, User &userInfo, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases)
{
    int userMenu;
    string newUsername;
    string newPassword;
    string newResidence;
    int newPhoneNo;

    string startDate;
    string endDate;

    string year;
    int totalCases;

    ifstream file;
    string fileName;
    string line;
    string word;
    string rowData;

    string token;
    int columnCount;
    string selectedYear;
    string selectedState;
    map<int, string> stateColumns; // Declare the map here
    string column;

    while (true)
    {
        cout << "\n-------- User Menu --------\n"
             << endl;
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
                break;
            }
            continue;

        case 2: // View Total Dengue Cases
            annualDengueCases.clear();
            annualDengueCases.addNewDengueCases(dengueCases);
            fileName = "csvFile/AnnualDengueCasesByState.csv";

            // Read data from the CSV file and populate the linked list
            file.open(fileName);
            if (file.is_open())
            {
                // map<int, string> stateColumns; // Declare the map here

                getline(file, line); // Skip the header line

                // Parse the header to get the state names
                stringstream headerStream(line);
                // Map column index to state name
                int columnIndex = 0;

                while (getline(headerStream, column, ','))
                {
                    if (columnIndex >= 2)
                    {
                        stateColumns[columnIndex] = column;
                    }
                    columnIndex++;
                }

                // Get user input for the year and state
                string selectedYear;
                string selectedState;

                cout << "Enter Year: ";
                cin >> selectedYear;

                cout << "Enter State: ";
                cin >> selectedState;

                bool yearFound = false;

                // Process data rows
                while (getline(file, line))
                {
                    stringstream ss(line);
                    int columnCount = 0;
                    string token;
                    string year;
                    int totalCases = 0;

                    while (getline(ss, token, ','))
                    {
                        if (columnCount == 0)
                        {
                            year = token;
                        }
                        else if (columnCount >= 2)
                        {
                            totalCases += stoi(token);
                        }
                        columnCount++;
                    }

                    // Check if the year matches the selected year
                    if (year == selectedYear)
                    {
                        yearFound = true;
                        string state = stateColumns[columnCount - 1]; // Get the state name from the map
                        if (state == selectedState)
                        {
                            annualDengueCases.readCsvFileAnnualCases(year, state, totalCases);
                        }
                    }
                }

                if (!yearFound)
                {
                    cout << "Selected year not found in the data" << endl;
                }
                else
                {
                    annualDengueCases.displayTotalCasesBasedOnYearAndState(selectedYear, selectedState);
                }
            }
            file.close();
            continue;

        case 3: // View Daily Dengue Cases
            // code
            break;
        case 4: // View Dengue Alert Messages
            // code
            break;
        case 5: // Search Status
            cout << "Enter start date in YYYY-MM-DD format: ";
            cin >> startDate;

            cout << "Enter end date in YYYY-MM-DD format: ";
            cin >> endDate;

            dengueCases.findPersonalDengueFeverStatusBasedOnDateRange(startDate, endDate, userInfo.getUsername());
            continue;

        case 6: // Logout
            return;
        }
    }
}

void doctorMenu(Doctor &doctorInfo, Admin &admin, DengueCasesLinkedList &dengueCases)
{
    string newUsername;
    string newPassword;
    string newResidence;
    int newPhoneNo;

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

    while (true)
    {
        cout << "-------- Doctor Menu --------\n"
             << endl;
        cout << "1. Manage Personal Information\n2. Report Cases\n3. View Reported Cases\n4. Find Name and ID\n5. Find Age and State\n6. Logout\n\nEnter your choice: ";

        int doctorChoice;
        cin >> doctorChoice;

        switch (doctorChoice)
        {
        case 1:
            // Manage Personal Information
            cout << "\n<<<<< Welcome to your profile <<<<<" << endl;
            cout << ">>>>> Doctor Profile >>>>>>\n";
            cout << "Username: " << doctorInfo.getUsername() << endl;
            cout << "Password: " << doctorInfo.getPassword() << endl;
            cout << "Residence: " << doctorInfo.getResidence() << endl;
            cout << "Phone Number: " << doctorInfo.getPhoneNo() << endl;

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
                doctorInfo.setUsername(newUsername);
                break;
            case 2:
                cout << "Enter new password: ";
                cin >> newPassword;
                admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), newPassword, doctorInfo.getResidence(), doctorInfo.getPhoneNo());
                doctorInfo.setPassword(newPassword);

                break;
            case 3:
                cout << "Enter new residence: ";
                cin >> newResidence;
                admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), newResidence, doctorInfo.getPhoneNo());
                doctorInfo.setResidence(newResidence);
                break;
            case 4:
                cout << "Enter new phone number: ";
                cin >> newPhoneNo;
                admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), doctorInfo.getResidence(), newPhoneNo);
                doctorInfo.setPhoneNo(newPhoneNo);
                break;
            case 5:
                break;
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
            dengueCases.print();
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
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void adminMenu(Admin &admin, AnnualDengueCasesLinkedList &annualDengueCases, WeeklyDengueCasesLinkedList &weeklyDengueCases, DengueCasesLinkedList &dengueCases)
{
    string user_username;
    string user_password;
    string user_residence;
    int user_phoneNo;

    ifstream file;
    string fileName;
    string line;
    string word;
    string rowData;

    string year;
    string token;
    int totalCases;
    int columnCount;

    while (true)
    {
        cout << "------------------ Admin Menu ------------------\n"
             << endl;
        cout << "1. View Total Dengue Cases \n2. View Weekly Dengue Cases \n3. Send Alert Message \n4. Manage Doctor Account \n5. Manage User Account \n6. Delete Inactive User Account \n7. Logout \n\nEnter your choice: ";

        int adminChoice;
        cin >> adminChoice;

        switch (adminChoice)
        {
        case 1:
        {
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
                cout << ">>>>>>>> Total Dengue Cases by Year >>>>>>>>>>>>\n"
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
        }
        case 2:
        {

            fileName = "csvFile/NumberOfDengueFeverCasesWeeklyByState.csv";

            // Read data from the CSV file and populate the linked list
            file.open(fileName);
            if (file.is_open())
            {

                // Skip the header line
                getline(file, line);

                string line;
                while (getline(file, line))
                {
                    istringstream ss(line);
                    string token;
                    int data[15];
                    int year, week, i = 0;

                    while (getline(ss, token, ','))
                    {
                        if (i == 0)
                        {
                            year = stoi(token);
                        }
                        else if (i == 1)
                        {
                            week = stoi(token);
                        }
                        else
                        {
                            data[i - 2] = stoi(token);
                        }
                        i++;
                    }

                    weeklyDengueCases.insert(year, week, data);
                }

                file.close();
            }
            else
            {
                cout << "Could not open the file." << endl;
            }
            int year, week;
            cout << "Enter the year: ";
            cin >> year;
            cout << "Enter the week: ";
            cin >> week;

            weeklyDengueCases.sortCasesByState(year, week);

            continue;
        }
        case 3:
        {
            weeklyDengueCases.clear();
            // Add data to the linked list using the insertNewCases function
            int data2023Week1[15] = {20, 10, 15, 5, 8, 25, 18, 0, 5, 12, 10, 22, 14, 2, 0};
            int data2023Week2[15] = {22, 12, 18, 6, 9, 27, 20, 0, 6, 15, 12, 24, 16, 3, 0};
            int data2023Week3[15] = {23, 15, 19, 7, 10, 30, 22, 0, 7, 18, 14, 26, 18, 4, 0};

            weeklyDengueCases.insertNewCases(2023, 1, data2023Week1);
            weeklyDengueCases.insertNewCases(2023, 2, data2023Week2);
            weeklyDengueCases.insertNewCases(2023, 3, data2023Week3);

            // Check for alerts in specific states
            for (int stateIndexToCheck = 0; stateIndexToCheck < 15; stateIndexToCheck++)
            {
                weeklyDengueCases.checkAlerts(stateIndexToCheck);
            }

            continue;
        }
        case 4:
        {
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
        }
        case 5:
        {
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
            admin.createUser(user_username, user_password, user_residence, user_phoneNo, 0);
            break;
        }
        case 6:
        {

            time_t fifteenDaysAgo = time(NULL) - (15 * 24 * 60 * 60); // 15 days in seconds
            admin.createUser("user1", "password1", "residence1", 012, fifteenDaysAgo);
            admin.createUser("user2", "password2", "residence2", 016, fifteenDaysAgo);

            cout << "\nAll Registered Users:\n"
                 << endl;
            admin.printAllUsers();
            // Call the checkInactivity function to check for inactive users
            admin.checkInactivity();
            cout << "\nAll Registered Users after removing the inactive one:\n"
                 << endl;
            admin.printAllUsers();
            break;
        }
        case 7:
        {
            return;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    }
}
