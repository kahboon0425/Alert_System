#include <iostream>
#include "../headerFile/DengueCases.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

Patient::Patient(const string &id, const string &name, const int &age, const string &residence, const int &phoneNo, const int &emergencyContactNo, const string &date, const string &diagnosisDetails, const string &doctor)
{
    patientId = id;
    patientName = name;
    patientAge = age;
    patientResidence = residence;
    patientPhoneNo = phoneNo;
    patientEmergencyContactNo = emergencyContactNo;
    dateReported = date;
    patientDiagnosisDetails = diagnosisDetails;
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

string Patient::getDiagnosisDetails() const{
    return patientDiagnosisDetails;
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

std::string DengueCasesLinkedList::generatePatientID(const std::string& name, int age) {
    // Get the current time in seconds
    std::time_t currentTime = std::time(nullptr);
    // Convert time to a string
    std::string timeString = std::to_string(currentTime);
    // Combine the name and age with the current time to create a unique ID
    std::string patientID = name.substr(0, 2) + std::to_string(age) + timeString.substr(timeString.size() - 5);
    return patientID;
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
    
    // Set the 'prev' pointer of the new node to nullptr, indicating the new node's position in an empty list.
    newNode->prev = nullptr;
    
    if (tail == nullptr)
    {
        // If the list is empty, set both head and tail to the new node.
        head = newNode;
        tail = newNode;
    }
    else
    {
        // If the list is not empty, update the links for a doubly linked list.
        newNode->prev = tail;    // Set the new node's 'prev' to the current tail.
        tail->next = newNode;    // Update the current tail's 'next' to point to the new node.
        tail = newNode;          // Update the tail to be the new node.
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
        cout << "Diagnosis Details" << current ->data.getDiagnosisDetails() << endl;
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
    Patient *latestCases = nullptr; // Dynamic array to store latest cases
    int latestCasesCount = 0;       // Number of latest cases
    Node *current = head;

    while (current != nullptr)
    {
        const Patient &record = current->data;

        if (record.getDoctorReported() == doctorUsername)
        {
            string currentDateStr = record.getDateReported();
            tm currentDate = {};
            istringstream dateStream(currentDateStr);
            dateStream >> get_time(&currentDate, "%Y-%m-%d");

            if (!dateStream.fail())
            {
                if (latestCasesCount == 0)
                {
                    latestCases = new Patient[1];
                    latestCases[0] = record;
                    latestCasesCount = 1;
                }
                else
                {
                    // Check if the current case has the same latest date as the latest case
                    tm latestDate = {};
                    istringstream latestDateStream(latestCases[0].getDateReported());
                    latestDateStream >> get_time(&latestDate, "%Y-%m-%d");

                    if (mktime(&currentDate) > mktime(&latestDate))
                    {
                        delete[] latestCases; // New latest date, clear the previous cases
                        latestCases = new Patient[1];
                        latestCases[0] = record;
                        latestCasesCount = 1;
                    }
                    else if (mktime(&currentDate) == mktime(&latestDate))
                    {
                        // Another case with the same latest date
                        Patient *temp = new Patient[latestCasesCount + 1];
                        for (int i = 0; i < latestCasesCount; ++i)
                        {
                            temp[i] = latestCases[i];
                        }
                        temp[latestCasesCount] = record;
                        delete[] latestCases;
                        latestCases = temp;
                        latestCasesCount += 1;
                    }
                }
            }
        }

        current = current->next;
    }

    if (latestCasesCount == 0)
    {
        cout << "No cases found for doctor: " << doctorUsername << endl;
    }
    else
    {
        cout << "\n>>>>>> Latest Cases Found: >>>>>>" << endl;

        for (int i = 0; i < latestCasesCount; ++i)
        {
            cout << "Patient Id: " << latestCases[i].getPatientId() << endl;
            cout << "Patient Name: " << latestCases[i].getPatientName() << endl;
            cout << "Patient Age: " << latestCases[i].getPatientAge() << endl;
            cout << "Patient Residence: " << latestCases[i].getPatientResidence() << endl;
            cout << "Patient Phone No: " << latestCases[i].getPatientPhoneNo() << endl;
            cout << "Patient Emergency Contact: " << latestCases[i].getPatientEmergencyContactNo() << endl;
            cout << "Date Reported: " << latestCases[i].getDateReported() << endl;
            cout << "DiagnosisDetails: "<< latestCases[i].getDiagnosisDetails() << endl;
            cout << "Doctor Reported: " << latestCases[i].getDoctorReported() << endl;
            cout << endl;
        }
    }

    // Clean up dynamic array
    if (latestCases != nullptr)
    {
        delete[] latestCases;
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
        cout << "\n---------- Dengue Case Found: -----------\n"
             << endl;
        cout << "Patient Id: " << matchedPatient.getPatientId() << endl;
        cout << "Patient Name: " << matchedPatient.getPatientName() << endl;
        cout << "Patient Age: " << matchedPatient.getPatientAge() << endl;
        cout << "Patient Residence: " << matchedPatient.getPatientResidence() << endl;
        cout << "Patient Phone No: " << matchedPatient.getPatientPhoneNo() << endl;
        cout << "Patient Emergency Contact: " << matchedPatient.getPatientEmergencyContactNo() << endl;
        cout << "Date Reported: " << matchedPatient.getDateReported() << endl;
        cout << "Diagnosis Details: "<< matchedPatient.getDiagnosisDetails() <<endl;
        cout << "Doctor Reported: " << matchedPatient.getDoctorReported() << endl;
    }
    else
    {
        cout << "\nDengue Cases not found!: " << endl;
    }
}

void DengueCasesLinkedList::findPersonalDengueFeverStatusBasedOnDateRange(const string startDate, const string endDate, const string userName, const int userPhoneNo)
{
    Node *current = this->head; // Use 'this' to access the member variable 'head'
    bool found = false;

    cout << "\nPatients within the date range " << startDate << " to " << endDate << ":\n";

    while (current != nullptr)
    {
        const Patient &patient = current->data;
        if (patient.getPatientName() == userName && patient.getPatientPhoneNo() == userPhoneNo && patient.getDateReported() >= startDate && patient.getDateReported() <= endDate)
        {
            cout << "\nPatient Id: " << patient.getPatientId() << endl;
            cout << "Name: " << patient.getPatientName() << endl;
            cout << "Age: " << patient.getPatientAge() << endl;
            cout << "Residence: " << patient.getPatientResidence() << endl;
            cout << "Phone Number: " << patient.getPatientPhoneNo() << endl;
            cout << "Emergency Contact Number: " << patient.getPatientEmergencyContactNo() << endl;
            cout << "Report Date: " << patient.getDateReported() << endl;
            cout << "Diagnosis Details: "<<patient.getDiagnosisDetails() << endl;
            cout << "Reporting Doctor: " << patient.getDoctorReported() << endl;
            cout << "------------------------" << endl;
            found = true; // At least one patient found in the date range
        }
        current = current->next;
    }   
    if (!found)
    {
        cout << "\nNo records found in the specified date range." << endl;
    }

}
