#include <iostream>

using namespace std;

class Patient
{
public:
    Patient(){};
    Patient(const string &id, const string &name, const int &age, const string &residence, const int &phoneNo, const int &emergencyContactNo, const string &date, const string &doctor);
    
    // Getter
    string getPatientId();
    string getPatientName();
    int getPatientAge();
    string getPatientResidence();
    int getPatientPhoneNo();
    int getPatientEmergencyContactNo();
    string getDateReported();
    string getDoctorReported();

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

private:
    Node *head;
    Node *tail;
    int size;
};