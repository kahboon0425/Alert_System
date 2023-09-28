#include <iostream>
#include "../headerFile/DengueCases.h"
#include <iomanip> 
#include <sstream>

using namespace std;

Patient::Patient(const string &id, const string &name, const int &age, const string &residence, const int &phoneNo, const int &emergencyContactNo, const string &date, const string &doctor)
{
    patientId = id;
    patientName = name;
    patientAge = age;
    patientResidence = residence;
    patientPhoneNo = phoneNo;
    patientEmergencyContactNo = emergencyContactNo;
    dateReported = date;
    doctorReported = doctor;
}

string Patient::getPatientId() const
{
    return patientId;
}

string Patient::getPatientName() const
{
    return patientName;
}

int Patient::getPatientAge() const
{
    return patientAge;
}

int Patient::getPatientPhoneNo() const
{
    return patientPhoneNo;
}

int Patient::getPatientEmergencyContactNo() const
{
    return patientEmergencyContactNo;
}

string Patient::getPatientResidence() const
{
    return patientResidence;
}

string Patient::getDateReported() const
{
    return dateReported;
}

string Patient::getDoctorReported() const
{
    return doctorReported;
}

Node::Node(const Patient &reportedData)
{

    data = reportedData;
    next = nullptr;
    prev = nullptr;
}

DengueCasesLinkedList::DengueCasesLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DengueCasesLinkedList::insert(const Patient &reportedData)
{
    Node *newNode = new Node(reportedData);
    newNode->next = NULL;
    newNode->prev = tail;
    tail = newNode;

    if (head == NULL)
    { // Inserting to an empty list
        head = newNode;
    }
    else
    {
        newNode->prev->next = newNode;
    }

    size++;
}

void DengueCasesLinkedList::print()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << "\nPatient Id: " << current->data.getPatientId() << endl;
        cout << "Patient Name: " << current->data.getPatientName() << endl;
        cout << "Patient Age: " << current->data.getPatientAge() << endl;
        cout << "Patient Residence: " << current->data.getPatientResidence() << endl;
        cout << "Patient Phone No: " << current->data.getPatientPhoneNo() << endl;
        cout << "Patient Emergency Contact: " << current->data.getPatientEmergencyContactNo() << endl;
        cout << "Date Reported: " << current->data.getDateReported() << endl;
        cout << "Doctor Reported: " << current->data.getDoctorReported() << endl;
        current = current->next;
    }
}

bool DengueCasesLinkedList::isValidDate(const string &dateStr, const string &format) {
    tm tm = {};
    istringstream ss(dateStr);
    ss >> get_time(&tm, format.c_str());

    // If the date string is valid and parsed successfully, it's a valid date
    return !ss.fail();
}

void DengueCasesLinkedList::findLatestCaseByDoctor(const string &doctorUsername)
{
    // Initialize an array to store matching cases
    const int maxCases = 100; // Assuming a maximum of 100 matching cases, adjust as needed
    Patient *matchingCases[maxCases];
    int numMatchingCases = 0; // Initialize the count of matching cases to zero

    Node *current = head; // Initialize a pointer to traverse the linked list.

    while (current != nullptr)
    {
        const Patient &record = current->data; // Get the patient record at the current node.

        // Check if the patient's doctor matches the target doctor
        if (record.getDoctorReported() == doctorUsername)
        {
            string currentDateStr = record.getDateReported(); // Get the date string from the patient record.

            // Parse the date string into a tm struct
            tm currentDate = {}; // Create a tm struct to hold the parsed date.
            istringstream dateStream(currentDateStr); // Create a string stream for parsing.
            dateStream >> get_time(&currentDate, "%Y-%m-%d"); // Parse the date string.

            if (!dateStream.fail()) // Check if the date parsing was successful.
            {
                // Store the matching case in the array
                matchingCases[numMatchingCases++] = new Patient(record);
                // Ensure you don't exceed the maximum number of cases
                if (numMatchingCases >= maxCases)
                {
                    break;
                }
            }
        }

        current = current->next; // Move to the next node in the linked list.
    }

    // Check if any matching cases were found
    if (numMatchingCases > 0)
    {
        cout << ">>>>>> Matching Cases Found: >>>>>>\n" << endl;

        // Iterate through the matching cases array and print each case
        for (int i = 0; i < numMatchingCases; ++i)
        {

            const Patient &caseRecord = *matchingCases[i];
            cout << ">>>>>> Latest Case Found: >>>>>>\n" << endl;
            cout << "Patient Id: " << caseRecord.getPatientId() << endl;
            cout << "Patient Name: " << caseRecord.getPatientName() << endl;
            cout << "Patient Age: " << caseRecord.getPatientAge() << endl;
            cout << "Patient Residence: " << caseRecord.getPatientResidence() << endl;
            cout << "Patient Phone No: " << caseRecord.getPatientPhoneNo() << endl;
            cout << "Patient Emergency Contact: " << caseRecord.getPatientEmergencyContactNo() << endl;
            cout << "Date Reported: " << caseRecord.getDateReported() << endl;
            cout << "Doctor Reported: " << caseRecord.getDoctorReported() << endl;
            // Don't forget to deallocate memory for each case
            delete matchingCases[i];
        }
    }
    else
    {
        cout << "\nNo cases found for doctor: " << doctorUsername << endl;
    }
}

// void DengueCasesLinkedList::findLatestCaseByDoctor(const string &doctorUsername)
// {
//     Patient latestCase; // Initialize a variable to store the latest patient case.
//     bool found = false; // Initialize a boolean flag to track if a case is found.
//     Node *current = head; // Initialize a pointer to traverse the linked list.

//     while (current != nullptr)
//     {
//         const Patient &record = current->data; // Get the patient record at the current node.

//         // Check if the patient's doctor matches the target doctor
//         if (record.getDoctorReported() == doctorUsername)
//         {
//             string currentDateStr = record.getDateReported(); // Get the date string from the patient record.

//             // Parse the date string into a tm struct
//             tm currentDate = {}; // Create a tm struct to hold the parsed date.
//             istringstream dateStream(currentDateStr); // Create a string stream for parsing.
//             dateStream >> get_time(&currentDate, "%Y-%m-%d"); // Parse the date string.

//             if (!dateStream.fail()) // Check if the date parsing was successful.
//             {
//                 // Compare the current date with the latest date
//                 tm latestDate = {}; // Create a tm struct to hold the latest date.

//                 // Parse the date string from the latestCase 
//                 if (found) {
//                     istringstream latestDateStream(latestCase.getDateReported());
//                     latestDateStream >> get_time(&latestDate, "%Y-%m-%d");
//                 }

//                 // Compare the current date with the latest date using mktime
//                 if (!found || mktime(&currentDate) > mktime(&latestDate))
//                 {
//                     latestCase = record; // Update the latestCase variable with the current record.
//                     found = true; // Set the flag to indicate that a case was found.
//                 }
//             }
//         }

//         current = current->next; // Move to the next node in the linked list.
//     }

//     // Check if a latest case was found
//     if (found)
//     {
//         cout << ">>>>>> Latest Case Found: >>>>>>\n" << endl;
//         cout << "Patient Id: " << latestCase.getPatientId() << endl;
//         cout << "Patient Name: " << latestCase.getPatientName() << endl;
//         cout << "Patient Age: " << latestCase.getPatientAge() << endl;
//         cout << "Patient Residence: " << latestCase.getPatientResidence() << endl;
//         cout << "Patient Phone No: " << latestCase.getPatientPhoneNo() << endl;
//         cout << "Patient Emergency Contact: " << latestCase.getPatientEmergencyContactNo() << endl;
//         cout << "Date Reported: " << latestCase.getDateReported() << endl;
//         cout << "Doctor Reported: " << latestCase.getDoctorReported() << endl;
//     }
//     else
//     {
//         cout << "\nNo cases found for doctor: " << doctorUsername << endl;
//     }
// }



void DengueCasesLinkedList::findDengueCasesByPatientIdAndName(const string &patientID, const string &patientName){
    bool found = false;
    Node *current = head;
    Patient matchedPatient; // Variable to store the matched patient's data

    while(current != nullptr){
        const Patient &record = current->data;

        if(record.getPatientId() == patientID && record.getPatientName() == patientName){
            found = true;
            matchedPatient = record; // Store the matched patient's data
            break; // Exit the loop as you've found a match
        }
       
        current = current->next;
    }

    if (found)
    {
        cout << ">>>>>> Dengue Case Found: >>>>>>\n" << endl;
        cout << "Patient Id: " << matchedPatient.getPatientId() << endl;
        cout << "Patient Name: " << matchedPatient.getPatientName() << endl;
        cout << "Patient Age: " << matchedPatient.getPatientAge() << endl;
        cout << "Patient Residence: " << matchedPatient.getPatientResidence() << endl;
        cout << "Patient Phone No: " << matchedPatient.getPatientPhoneNo() << endl;
        cout << "Patient Emergency Contact: " << matchedPatient.getPatientEmergencyContactNo() << endl;
        cout << "Date Reported: " << matchedPatient.getDateReported() << endl;
        cout << "Doctor Reported: " << matchedPatient.getDoctorReported() << endl;
    }
    else
    {
        cout << "\nDengue Cases not found!: "  << endl;
    }
}


int DengueCasesLinkedList::countCasesByAgeAndState(int minAge, int maxAge, const string &minState, const string &maxState) {
        int caseCount = 0;
        Node *current = head;

        while (current!= nullptr) {
            const Patient &record = current->data;
            int age = record.getPatientAge();
            string state = record.getPatientResidence();

            if (age >= minAge && age <= maxAge && state >= minState && state <= maxState) {
                caseCount++;
            }

            current = current->next;
        }

        return caseCount;
    }
