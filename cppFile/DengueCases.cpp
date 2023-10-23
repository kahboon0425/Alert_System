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

bool DengueCasesLinkedList::isValidDate(const string &dateStr, const string &format)
{
    tm tm = {};
    istringstream ss(dateStr);
    ss >> get_time(&tm, format.c_str());

    // If the date string is valid and parsed successfully, it's a valid date
    return !ss.fail();
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

void DengueCasesLinkedList::findLatestCaseByDoctor(const string &doctorUsername)
{
    Patient latestCase;   // Initialize a variable to store the latest patient case.
    Node *current = head; // Initialize a pointer to traverse the linked list.
    bool found = false;   // Initialize a boolean flag to track if a case is found.

    while (current != nullptr)
    {
        const Patient &record = current->data; // Get the patient record at the current node.

        // Check if the patient's doctor matches the target doctor
        if (record.getDoctorReported() == doctorUsername)
        {
            string currentDateStr = record.getDateReported(); // Get the date string from the patient record.

            // Parse the date string into a tm struct
            tm currentDate = {};                              // Create a tm struct to hold the parsed date.
            istringstream dateStream(currentDateStr);         // Create a string stream for parsing.
            dateStream >> get_time(&currentDate, "%Y-%m-%d"); // Parse the date string.

            if (!dateStream.fail()) // Check if the date parsing was successful.
            {
                // Compare the current date with the latest date
                tm latestDate = {}; // Create a tm struct to hold the latest date.

                // Parse the date string from the latestCase
                if (found)
                {
                    istringstream latestDateStream(latestCase.getDateReported());
                    latestDateStream >> get_time(&latestDate, "%Y-%m-%d");
                }

                // Compare the current date with the latest date using mktime
                if (!found || mktime(&currentDate) > mktime(&latestDate))
                {
                    latestCase = record; // Update the latestCase variable with the current record.
                    found = true;        // Set the flag to indicate that a case was found.
                }
                else if (mktime(&currentDate) == mktime(&latestDate))
                {
                    // If the current case has the same latest date, print it
                    cout << ">>>>>> Latest Case Found: >>>>>>\n"
                         << endl;
                    cout << "Patient Id: " << record.getPatientId() << endl;
                    cout << "Patient Name: " << record.getPatientName() << endl;
                    cout << "Patient Age: " << record.getPatientAge() << endl;
                    cout << "Patient Residence: " << record.getPatientResidence() << endl;
                    cout << "Patient Phone No: " << record.getPatientPhoneNo() << endl;
                    cout << "Patient Emergency Contact: " << record.getPatientEmergencyContactNo() << endl;
                    cout << "Date Reported: " << record.getDateReported() << endl;
                    cout << "Doctor Reported: " << record.getDoctorReported() << endl;
                    cout << "-------------------" << endl;
                }
            }
        }

        current = current->next; // Move to the next node in the linked list.
    }

    if (!found)
    {
        cout << "\nNo cases found for doctor: " << doctorUsername << endl;
    }
}

void DengueCasesLinkedList::findDengueCasesByPatientIdAndName(const string &patientID, const string &patientName)
{
    bool found = false;
    Node *current = head;
    Patient matchedPatient; // Variable to store the matched patient's data

    while (current != nullptr)
    {
        const Patient &record = current->data;

        if (record.getPatientId() == patientID && record.getPatientName() == patientName)
        {
            found = true;
            matchedPatient = record; // Store the matched patient's data
            break;                   // Exit the loop as you've found a match
        }

        current = current->next;
    }

    if (found)
    {
        cout << ">>>>>> Dengue Case Found: >>>>>>\n"
             << endl;
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
        cout << "\nDengue Cases not found!: " << endl;
    }
}

void DengueCasesLinkedList::findPersonalDengueFeverStatusBasedOnDateRange(const string startDate, const string endDate, const string patientName)
{
    if (!isValidDate(startDate, "%Y-%m-%d") || !isValidDate(endDate, "%Y-%m-%d"))
    {
        cout << "Invalid date format. Please use YYYY-MM-DD format for dates." << endl;
        return;
    }

    if (startDate > endDate)
    {
        cout << "Invalid date range. Start date should be before or equal to end date." << endl;
        return;
    }

    Node *current = this->head; // Use 'this' to access the member variable 'head'
    bool found = false;

    cout << "\nPatients within the date range " << startDate << " to " << endDate << ":\n";

    while (current != nullptr)
    {
        const Patient &patient = current->data;
        if (patient.getPatientName() == patientName && patient.getDateReported() >= startDate && patient.getDateReported() <= endDate)
        {
            cout << "\nPatient Id: " << patient.getPatientId() << endl;
            cout << "Name: " << patient.getPatientName() << endl;
            cout << "Age: " << patient.getPatientAge() << endl;
            cout << "Residence: " << patient.getPatientResidence() << endl;
            cout << "Phone Number: " << patient.getPatientPhoneNo() << endl;
            cout << "Emergency Contact Number: " << patient.getPatientEmergencyContactNo() << endl;
            cout << "Report Date: " << patient.getDateReported() << endl;
            cout << "Reporting Doctor: " << patient.getDoctorReported() << endl;
            cout << "------------------------" << endl;
            found = true; // At least one patient found in the date range
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No patients found in the specified date range." << endl;
    }
}
