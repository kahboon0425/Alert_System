#ifndef DENGUECASES_H
#define DENGUECASES_H

#include <iostream>

using namespace std;

class Patient
{
public:
    Patient(){};
    Patient(const string &id, const string &name, const int &age, const string &residence, const int &phoneNo, const int &emergencyContactNo, const string &date, const string &diagnosisDetails, const string &doctor);

    // Getter
    string getPatientId() const;
    string getPatientName() const;
    int getPatientAge() const;
    string getPatientResidence() const;
    int getPatientPhoneNo()const;
    int getPatientEmergencyContactNo() const;
    string getDateReported() const;
    string getDiagnosisDetails() const;
    string getDoctorReported() const;

private:
    string patientId;
    string patientName;
    int patientAge;
    string patientResidence;
    int patientPhoneNo;
    int patientEmergencyContactNo;
    string dateReported;
    string patientDiagnosisDetails;
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
    static std::string generatePatientID(const std::string& name, int age);
    void insert(const Patient &reportedData);
    void print();
    void findLatestCaseByDoctor(const string& doctorUsername);
    bool isValidDate(const string &dateStr, const string &format);
    void findDengueCasesByPatientIdAndName(const string &patientID, const string &patientName);
    int countCasesByAgeAndState(int minAge, int maxAge, const string &minState, const string &maxState);
    void findPersonalDengueFeverStatusBasedOnDateRange(const string startDate, const string endDate, const string userName, const int userPhoneNo);

public:
    Node *head;
    Node *tail;
    int size;
};


#endif