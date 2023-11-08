#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <iomanip>
#include "headerFile/MOHAdmin.h"
#include "headerFile/User.h"
#include "headerFile/Doctor.h"
#include "headerFile/DengueCases.h"
#include "headerFile/AnnualDengueCases.h"
#include "headerFile/WeeklyDengueCases.h"
#include "headerFile/DailyCases.h"
#include "headerFile/Validation.h"
#include "cppFile/MOHAdmin.cpp"
#include "cppFile/User.cpp"
#include "cppFile/Doctor.cpp"
#include "cppFile/DengueCases.cpp"
#include "cppFile/AnnualDengueCases.cpp"
#include "cppFile/WeeklyDengueCases.cpp"
#include "cppFile/DailyCases.cpp"
#include "cppFile/Validation.cpp"

using namespace std;

// Function declarations
void displayMainMenu();
void loginAsUser(Admin &admin, User &user, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases, DailyCasesList &dailyCasesList, WeeklyDengueCasesLinkedList &weeklyDengueCases);
void loginAsDoctor(Admin &admin, Doctor &doctor, DengueCasesLinkedList &dengueCases);
void loginAsAdmin(Admin &admin, AnnualDengueCasesLinkedList &annualDengueCases, WeeklyDengueCasesLinkedList &weeklyDengueCases, DengueCasesLinkedList &dengueCases);

void userMenu(Admin &admin, User &user, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases, DailyCasesList &dailyCasesList, WeeklyDengueCasesLinkedList &weeklyDengueCases);
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
    DailyCasesList dailyCasesList;

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
            loginAsUser(admin, user, dengueCases, annualDengueCases, dailyCasesList, weeklyDengueCases);
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

void loginAsUser(Admin &admin, User &user, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases, DailyCasesList &dailyCasesList, WeeklyDengueCasesLinkedList &weeklyDengueCases)
{
    string user_username;
    string user_password;

    cout << "\n-------- Login As User --------\n";

    // Validation for username
    do
    {
        cout << "Enter user username: ";
        cin >> user_username;
    } while (user_username.length() < 4);

    // Validation for password
    do
    {
        cout << "Enter user password: ";
        cin >> user_password;
    } while (user_password.length() < 3);

    if (admin.userLogin(user_username, user_password))
    {
        cout << "\nLogin Successfully.\n"
             << endl;
        User userInfo = admin.getUserInfo(user_username);
        userMenu(admin, userInfo, dengueCases, annualDengueCases, dailyCasesList, weeklyDengueCases);
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
    // validation for username
    cout << "\n-------- Login As Doctor --------\n";
    do
    {
        cout << "Enter doctor username: ";
        cin >> doctor_username;
    } while (doctor_username.length() < 4);

    // Validation for password
    do
    {
        cout << "Enter doctor password: ";
        cin >> doctor_password;
    } while (doctor_password.length() < 3);

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

    do
    {
        cout << "\nEnter admin username: ";
        cin >> admin_username;
    } while (admin_username.length() < 4);

    do
    {
        cout << "Enter admin password: ";
        cin >> admin_password;
    } while (admin_password.length() < 3);

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

void userMenu(Admin &admin, User &userInfo, DengueCasesLinkedList &dengueCases, AnnualDengueCasesLinkedList &annualDengueCases, DailyCasesList &dailyCasesList, WeeklyDengueCasesLinkedList &weeklyDengueCases)
{
    int userMenu;
    string newUsername;
    string newName;
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
    int selectedState;
    string column;
    int state;
    string userState;

    string stateNames[] = {
        "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN",
        "PAHANG", "PERAK", "PERLIS", "PULAU PINANG", "SABAH",
        "SARAWAK", "SELANGOR", "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"};

    int dailyCases[] = {50, 30, 40, 20, 25, 35, 60, 10, 45, 55, 70, 65, 35, 30, 15};
    int maxAttempts = 1;

    while (true)
    {
        cout << "\n-------- User Menu --------\n"
             << endl;
        cout << "1. Manage Personal Information \n2. View Total Dengue Cases Based on Selected Years or Selected States \n3. View Daily Dengue Cases for All States In Descending Order \n4. View Dengue Alert Messages \n5. Search Personal Past Dengue Fever Status \n6. Logout \n\nEnter your choice: ";
        cin >> userMenu;

        switch (userMenu)
        {
        case 1: // Manage Personal Information
            cout << "\n<<<<< Welcome to your profile <<<<<" << endl;
            cout << ">>>>> User Profile >>>>>>\n";
            cout << "Username: " << userInfo.getUsername() << endl;
            cout << "Name: " << userInfo.getName() << endl;
            cout << "Password: " << userInfo.getPassword() << endl;
            cout << "Residence: " << userInfo.getResidence() << endl;
            cout << "Phone Number: " << userInfo.getPhoneNo() << endl;

            cout << "\n >>>> Options >>>>\n";
            cout << "\n1. Modify Username \n2. Modify Name\n3. Modify Password \n4. Modify Residence \n5. Modify Phone Number \n6. Logout\n\nEnter your choice: ";

            int modifyProfileInfo;
            cin >> modifyProfileInfo;

            if (modifyProfileInfo == 1)
            {
                string newUsername;
                cout << "Enter new username (Min 4 Characters): ";
                cin >> newUsername;
                if (isValidUsername(newUsername) && !admin.isUserUsernameTaken(newUsername))
                {
                    admin.updateUserInformation(userInfo.getUsername(), newUsername, userInfo.getName(), userInfo.getPassword(), userInfo.getResidence(), userInfo.getPhoneNo());
                    userInfo.setUsername(newUsername);
                    break;
                }
                else
                {
                    cout << "Invalid username or repeated username. Please try again." << endl;
                }
            }

            else if (modifyProfileInfo == 2)
            {
                cout << "Enter new name: ";
                cin >> newName;
                if (isValidName(newName))
                {
                    admin.updateUserInformation(userInfo.getUsername(), userInfo.getUsername(), newName, userInfo.getPassword(), userInfo.getResidence(), userInfo.getPhoneNo());
                    userInfo.setName(newName);
                    break;
                }
                else
                {
                    cout << "Invalid name. Please try again." << endl;
                }
            }

            else if (modifyProfileInfo == 3)
            {
                cout << "Enter new password (Min 3 Characters): ";
                cin >> newPassword;
                if (isValidPassword(newPassword))
                {
                    admin.updateUserInformation(userInfo.getUsername(), userInfo.getUsername(), userInfo.getName(), newPassword, userInfo.getResidence(), userInfo.getPhoneNo());
                    userInfo.setPassword(newPassword);
                    break;
                }
                else
                {
                    cout << "Invalid password. Please try again." << endl;
                }
            }
            else if (modifyProfileInfo == 4)
            {
                cout << "Enter new residence (Capitalize): ";
                cin >> newResidence;
                if (isValidResidence(newResidence))
                {
                    admin.updateUserInformation(userInfo.getUsername(), userInfo.getUsername(), userInfo.getName(), userInfo.getPassword(), newResidence, userInfo.getPhoneNo());
                    userInfo.setResidence(newResidence);
                    break;
                }
                else
                {
                    cout << "Invalid residence. Please try again." << endl;
                }
            }
            else if (modifyProfileInfo == 5)
            {
                cout << "Enter new phone number: ";
                cin >> newPhoneNo;
                if (isValidPhoneNumber(newPhoneNo))
                {

                    admin.updateUserInformation(userInfo.getUsername(), userInfo.getUsername(), userInfo.getName(), userInfo.getPassword(), userInfo.getResidence(), newPhoneNo);
                    userInfo.setPhoneNo(newPhoneNo);
                    break;
                }
                else
                {
                    cout << "Invalid phone number. Please try again." << endl;
                }
            }
            else if (modifyProfileInfo == 6)
            {
                continue;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            continue;

        case 2: // View Total Dengue Cases
            cout << "\n<<<<<<<< View Total Dengue Cases Based on Selected Years or Selected States >>>>>>>>" << endl;

            annualDengueCases.clear();
            fileName = "csvFile/AnnualDengueCasesByState.csv";

            // Read data from the CSV file and populate the linked list
            file.open(fileName);
            if (file.is_open())
            {
                getline(file, line); // Skip the header line

                while (getline(file, line))
                {
                    stringstream ss(line);
                    totalCases = 0;
                    columnCount = 0;
                    state = 0;

                    while (getline(ss, token, ','))
                    {
                        if (columnCount == 0)
                        {
                            year = token;
                        }
                        else if (columnCount >= 2)
                        {
                            totalCases += stoi(token); // Total cases for a specific state
                            state = columnCount - 1;   // Calculate the state index
                            annualDengueCases.readCsvFileAnnualCases(year, state, totalCases);
                        }
                        totalCases = 0;

                        columnCount++;
                    }
                }

                file.close();
            }
            else
            {
                cout << "Could not open the file\n"; // Display an error message if the file couldn't be opened
            }

            cout << "Enter Year: ";
            cin >> selectedYear;

            cout << "\n(1) Johor\n(2) Kedah\n(3) Kelantan\n(4) Melaka\n(5) Negeri Sembilan\n(6) Pahang\n(7) Perak\n(8) Perlis\n(9) Pulau Pinang\n(10) Sabah\n(11) Sarawak\n(12) Selangor\n(13) Terengganu\n(14) Kuala Lumpur\n(15) Labuan\nEnter State No: ";

            cin >> selectedState;

            annualDengueCases.displayTotalCasesBasedOnYearAndState(selectedYear, selectedState);
            continue;

        case 3: // View Daily Dengue Cases
            cout << "\n<<<<<<<< View Daily Dengue Cases for All States In Descending Order Based on State Name >>>>>>>>" << endl;
            // Populate the linked list with state data

            dailyCasesList.append("JOHOR", 50);
            dailyCasesList.append("KEDAH", 30);
            dailyCasesList.append("KELANTAN", 40);
            dailyCasesList.append("MELAKA", 20);
            dailyCasesList.append("NEGERI SEMBILAN", 25);
            dailyCasesList.append("PAHANG", 35);
            dailyCasesList.append("PERAK", 60);
            dailyCasesList.append("PERLIS", 10);
            dailyCasesList.append("PULAU PINANG", 45);
            dailyCasesList.append("SABAH", 55);
            dailyCasesList.append("SARAWAK", 70);
            dailyCasesList.append("SELANGOR", 65);
            dailyCasesList.append("TERENGGANU", 35);
            dailyCasesList.append("WP KUALA LUMPUR", 30);
            dailyCasesList.append("WP LABUAN", 15);

            // Sort the state data
            dailyCasesList.sort();
            cout << "\n--------Today's dengue cases for all states in descending order --------" << endl;
            // Display sorted state data
            dailyCasesList.displayDailyCases();

            continue;

        case 4: // View Dengue Alert Messages
            cout << "\n<<<<<<<< View Dengue Alert Messages >>>>>>>>" << endl;
            userState = userInfo.getResidence();
            for (char &c : userState)
            {
                c = std::toupper(c);
            }

            weeklyDengueCases.sendAlertToUsers(userState);

            continue;

        case 5: // Search Status
            cout << "\n<<<<<<<< Search Personal Past Dengue Fever Status >>>>>>>>" << endl;
            while (true)
            {
                cout << "Enter start date in YYYY-MM-DD format: ";
                cin >> startDate;
                if (isValidDateFormat(startDate))
                {
                    break; // Exit the loop when a valid date is provided
                }
                else
                {
                    cout << "Invalid start date. Please enter again in YYYY-MM-DD format." << endl;
                }
            }

            while (true)
            {
                cout << "Enter end date in YYYY-MM-DD format: ";
                cin >> endDate;
                if (isValidDateFormat(endDate))
                {
                    break; // Exit the loop when a valid date is provided
                }
                else
                {
                    cout << "Invalid end date. Please enter again in YYYY-MM-DD format." << endl;
                }
            }

            dengueCases.findPersonalDengueFeverStatusBasedOnDateRange(startDate, endDate, userInfo.getName(), userInfo.getPhoneNo());
            continue;

        case 6: // Logout
            cout << "Logging out. Goodbye!" << endl;
            return;
        }
    }
}

void doctorMenu(Doctor &doctorInfo, Admin &admin, DengueCasesLinkedList &dengueCases)
{
    int doctorChoice;
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
    string patientDiagnosisDetails;
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
        cout << "1. Manage Personal Information\n2. Report Cases\n3. View all dengue cases reported by current doctors in latest date \n4. Find cases based on Name and ID\n5. Find Number of Cases based on Age and State\n6. Logout\n\nEnter your choice: ";

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

            if (modifyProfileInfo == 1)
            {
                string newUsername;
                cout << "Enter new username (at least 4 characters): ";
                cin >> newUsername;
                if (isValidUsername(newUsername) && admin.isDocUsernameTaken(newUsername))
                {
                    admin.updateDoctorInformation(doctorInfo.getUsername(), newUsername, doctorInfo.getPassword(), doctorInfo.getResidence(), doctorInfo.getPhoneNo());
                    doctorInfo.setUsername(newUsername);
                    break;
                }
                else
                {
                    cout << "Invalid username or repeated username. Please try again." << endl;
                }
            }
            else if (modifyProfileInfo == 2)
            {
                cout << "Enter new password (at least 3 characters): ";
                cin >> newPassword;
                if (isValidPassword(newPassword))
                {
                    admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), newPassword, doctorInfo.getResidence(), doctorInfo.getPhoneNo());
                    doctorInfo.setPassword(newPassword);
                    break;
                }
                else
                {
                    cout << "Invalid password. Please try again." << endl;
                }
            }
            else if (modifyProfileInfo == 3)
            {
                cout << "Enter new residence (Capitalize): ";
                cin >> newResidence;
                if (isValidResidence(newResidence))
                {
                    admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), newResidence, doctorInfo.getPhoneNo());
                    doctorInfo.setResidence(newResidence);
                    break;
                }
                else
                {
                    cout << "Invalid Residence. Please try again." << endl;
                }
            }
            else if (modifyProfileInfo == 4)
            {
                cout << "Enter new phone number: ";
                cin >> newPhoneNo;
                if (isValidPhoneNumber(newPhoneNo))
                {
                    admin.updateDoctorInformation(doctorInfo.getUsername(), doctorInfo.getUsername(), doctorInfo.getPassword(), doctorInfo.getResidence(), newPhoneNo);
                    doctorInfo.setPhoneNo(newPhoneNo);
                    break;
                }
                else
                {
                    cout << "Invalid phone number. Please try again." << endl;
                }
            }
            else if (modifyProfileInfo == 5)
            {
                continue;
            }
            else
            {
                cout << "Invalid option. Please select an option between 1 and 5." << endl;
            }

            continue;

        case 2: // Report Cases
            cout << "\nHow many cases you want to report?: ";
            cin >> noOfCases;
            for (int i = 0; i < noOfCases; i++)
            {
                cout << "\n----- Case " << i + 1 << "------";

                while (true)
                {
                    cout << "\nEnter patient's name: ";
                    cin >> patientName;
                    if (isValidName(patientName))
                    {
                        break; // Exit the loop if the name is valid
                    }
                    cout << "Invalid patient name. Please enter a name with only alphabetic characters." << std::endl;
                }

                while (true)
                {
                    cout << "Enter patient's age: ";
                    cin >> patientAge;
                    if (isValidPatientAge(patientAge))
                    {
                        break; // Exit the loop if the age is valid
                    }
                    cout << "Invalid patient age. Please enter an age between 0 and 100." << std::endl;
                }

                while (true)
                {
                    cout << "Enter patient's residence (Capitalize): ";
                    cin >> patientResidence;
                    if (isValidResidence(patientResidence))
                    {
                        break; // Exit the loop if the residence is valid
                    }
                    cout << "Invalid patient residence" << endl;
                }

                while (true)
                {
                    cout << "Enter patient's phone number: ";
                    cin >> patientPhoneNo;
                    if (isValidPhoneNumber(patientPhoneNo))
                    {
                        break; // Exit the loop if the phone number is valid
                    }
                    cout << "Invalid phone number" << endl;
                }

                while (true)
                {
                    cout << "Enter patient's emergency contact number: ";
                    cin >> patientEmergencyContactNo;
                    if (isValidPhoneNumber(patientEmergencyContactNo))
                    {
                        if (patientEmergencyContactNo == patientPhoneNo)
                        {
                            cout << "Patient emergency phone number is the same as the patient number" << endl;
                        }
                        else
                        {
                            break; // Exit the loop if the emergency contact number is valid
                        }
                    }
                    else
                    {
                        cout << "Invalid phone number. Please try again" << endl;
                    }
                }

                while (true)
                {
                    cout << "Enter a date in YYYY-MM-DD format: ";
                    cin >> reportDate;
                    if (isValidDateFormat(reportDate))
                    {
                        break; // Exit the loop if the date is valid
                    }
                    cout << "Invalid date format. Please enter the date in YYYY-MM-DD format." << std::endl;
                }

                cin.ignore();
                cout << "Enter patient's diagnosis details: ";
                getline(cin, patientDiagnosisDetails);

                // Generate the patient ID and insert the patient data
                patientId = dengueCases.generatePatientID(patientName, patientAge);
                cout << "\nGenerated Patient ID: " << patientId << endl;
                dengueCases.insert(Patient(patientId, patientName, patientAge, patientResidence, patientPhoneNo, patientEmergencyContactNo, reportDate, patientDiagnosisDetails, doctorInfo.getUsername()));
                cout << "\nCase for patient ID " << patientId << " is reported and recorded in the database.\n"
                     << endl;
            }
            continue;

        case 3: // View Reported Cases
            // dengueCases.print();
            dengueCases.findLatestCaseByDoctor(doctorInfo.getUsername());
            continue;

        case 4: // Find Name And Id
            cout << "\n>>>>>>>> Find dengue fever cases based on patient name or patient id >>>>>>>" << endl;
            cout << "\nEnter Patient Id: ";
            cin >> searchPatientId;
            cout << "Enter Patient Name: ";
            cin >> searchPatientName;
            dengueCases.findDengueCasesByPatientIdAndName(searchPatientId, searchPatientName);
            continue;

        case 5: // Find Age And State
            cout << "\n<<<<<< Find the number of cases for any given age range and any given state range <<<<<<\n"
                 << endl;
            cout << "Enter Age Range >>" << endl;
            cout << "Min Age: ";
            cin >> minAge;
            if (!isValidPositiveInteger(std::to_string(minAge)))
            {
                std::cout << "Invalid input. Please enter a positive integer." << std::endl;
                break;
            }

            cout << "Max Age: ";
            cin >> maxAge;
            if (!isValidPositiveInteger(std::to_string(maxAge)))
            {
                std::cout << "Invalid input. Please enter a positive integer." << std::endl;
                break;
            }

            cout << "\nEnter State Range >>" << endl;
            cout << "State 1: ";
            cin >> state1;
            if (isValidState(state1))
            {
                cout << "State 2: ";
                cin >> state2;
                if (!isValidState(state2))
                {
                    std::cout << "Invalid state for State 2." << std::endl;
                }
            }
            else
            {
                std::cout << "Invalid state for State 1." << std::endl;
            }
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
    string user_name;
    string user_password;
    string user_residence;
    int user_phoneNo;

    string doctor_username;
    string doctor_password;
    string doctor_residence;
    int doctor_phoneNo;

    int adminChoice;
    ifstream file;
    string fileName;
    string line;
    string word;
    string rowData;

    string year;
    string token;
    int totalCases;
    int columnCount;
    int sendAlert;

    while (true)
    {
        cout << "------------------ Admin Menu ------------------\n"
             << endl;
        cout << "1. View total dengue cases reported in Malaysia between 2018 to 2023 \n2. View weekly dengue cases for all states in ascending order based on case number \n3. Send an alert message to users when dengue fever cases in their state reach 20 and persist for more than two weeks \n4. Create Doctor Account \n5. Create User Account \n6. Delete Inactive User Account \n7. Logout \n\nEnter your choice: ";
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
            cout << "\nSend Alert (0 for No, 1 for Yes): ";
            cin >> sendAlert;

            if (sendAlert == 1)
            {
                cout << "Successfully sent alert to the user.\n"
                     << std::endl;
            }
            else if (sendAlert == 0)
            {
                cout << "No alert was sent." << std::endl;
            }
            else
            {
                cout << "Invalid input. Please enter 0 or 1." << std::endl;
            }

            continue;
        }
        case 4:
        {
            cout << "\n>>>>> Create New Doctor >>>>\n"
                 << endl;
            while (true)
            {
                cout << "Username (Min 4 Characters): ";
                cin >> doctor_username;
                if (!isValidUsername(doctor_username))
                {
                    cout << "Invalid username. Please enter a valid username." << endl;
                }
                else if (admin.isDocUsernameTaken(doctor_username))
                {
                    cout << "Username repeated. Please enter a new username." << endl;
                }
                else
                {
                    break; // Exit the loop if the username is valid
                }
            }

            while (true)
            {
                cout << "Password (Min 3 Characters): ";
                cin >> doctor_password;
                if (!isValidPassword(doctor_password))
                {
                    cout << "Invalid password. Please enter a valid password." << endl;
                }
                else
                {
                    break; // Exit the loop if the password is valid
                }
            }

            while (true)
            {
                cout << "Residence (Capitalize): ";
                cin >> doctor_residence;
                if (!isValidResidence(doctor_residence))
                {
                    cout << "Invalid residence. Please enter a valid residence." << endl;
                }
                else
                {
                    break; // Exit the loop if the residence is valid
                }
            }

            while (true)
            {
                cout << "Phone Number: ";
                cin >> doctor_phoneNo;
                if (!isValidPhoneNumber(doctor_phoneNo))
                {
                    cout << "Invalid phone number. Please enter a valid phone number." << endl;
                }
                else
                {
                    break; // Exit the loop if the phone number is valid
                }
            }
            admin.createDoctor(doctor_username, doctor_password, doctor_residence, doctor_phoneNo);
            cout << "\nDoctor registered successfully!\n"
                 << endl;
            break;
        }
        case 5:
        {
            time_t loginTime;
            time(&loginTime);
            while (true)
            {
                cout << "Username (Min 4 Characters): ";
                cin >> user_username;
                if (!isValidUsername(user_username))
                {
                    cout << "Invalid username. Please enter a valid username." << endl;
                }
                else if (admin.isUserUsernameTaken(user_username))
                {
                    cout << "Username repeated. Please enter a new username." << endl;
                }
                else
                {
                    break; // Exit the loop if the username is valid and not taken
                }
            }

            while (true)
            {
                cout << "Password (Min 3 Characters): ";
                cin >> user_password;
                if (!isValidPassword(user_password))
                {
                    cout << "Invalid password. Please enter a valid password." << endl;
                }
                else
                {
                    break; // Exit the loop if the password is valid
                }
            }

            while (true)
            {
                cout << "Name: ";
                cin >> user_name;
                if (!isValidName(user_name))
                {
                    cout << "Invalid name. Please enter a valid name." << endl;
                }
                else
                {
                    break; // Exit the loop if the password is valid
                }
            }

            while (true)
            {
                cout << "Residence (Capitalize): ";
                cin >> user_residence;
                if (!isValidResidence(user_residence))
                {
                    cout << "Invalid residence. Please enter a valid residence." << endl;
                }
                else
                {
                    break; // Exit the loop if the residence is valid
                }
            }

            while (true)
            {
                cout << "Phone Number: ";
                cin >> user_phoneNo;
                if (!isValidPhoneNumber(user_phoneNo))
                {
                    cout << "Invalid phone number. Please enter a valid phone number." << endl;
                }
                else
                {
                    break; // Exit the loop if the phone number is valid
                }
            }

            admin.createUser(user_username, user_name, user_password, user_residence, user_phoneNo, loginTime);
            cout << "\nUser registered successfully!\n"
                 << endl;
            break;
        }
        case 6:
        {
            time_t fifteenDaysAgo = time(NULL) - (15 * 24 * 60 * 60); // 15 days in seconds
            admin.createUser("user1", "KahBoon", "password1", "residence1", 0123456777, fifteenDaysAgo);
            admin.createUser("user2", "Eunice", "password2", "residence2", 0162345666, fifteenDaysAgo);

            cout << "\nAll Registered Users:"
                 << endl;
            admin.printAllUsers();

            cout << "\nDo you want to delete inactive users more than 14 days? (yes/no): ";
            string confirmDelete;
            cin >> confirmDelete;

            if (confirmDelete == "yes" || confirmDelete == "Yes" || confirmDelete == "YES")
            {
                // Call the checkInactivity function to check for inactive users
                admin.checkInactivity();
                cout << "------------ All Current Users after removing the inactive ones:------------";
                admin.printAllUsers();
            }
            else
            {
                cout << "Inactive users were not deleted.\n";
                cout << endl;
            }
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