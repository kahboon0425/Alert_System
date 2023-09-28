#ifndef DENGUECASES_H
#define DENGUECASES_H

#include <iostream>

using namespace std;

class Patient
{
public:
    Patient(){};
    Patient(const string &id, const string &name, const int &age, const string &residence, const int &phoneNo, const int &emergencyContactNo, const string &date, const string &doctor);

    // Getter
    string getPatientId() const;
    string getPatientName() const;
    int getPatientAge() const;
    string getPatientResidence() const;
    int getPatientPhoneNo()const;
    int getPatientEmergencyContactNo() const;
    string getDateReported() const;
    string getDoctorReported() const;

private:
    string patientId;
    string patientName;
    int patientAge;
    string patientResidence;
    int patientPhoneNo;
    int patientEmergencyContactNo;
    string dateReported;
    string doctorReported;
};

struct Node
{
    Patient data;
    Node *next;
    Node *prev;

    Node(const Patient &reportedData);

};

class DengueCasesLinkedList
{
public:
    DengueCasesLinkedList();
    void insert(const Patient &reportedData);
    void print();
    void findLatestCaseByDoctor(const string& doctorUsername);
    bool isValidDate(const string &dateStr, const string &format);
    void findDengueCasesByPatientIdAndName(const string &patientID, const string &patientName);

private:
    Node *head;
    Node *tail;
    int size;
};


#endif