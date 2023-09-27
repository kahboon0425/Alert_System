#include <iostream>
#include "../headerFile/DengueCases.h"

using namespace std;


Patient::Patient(const string &id, const string &name, const int &age, const string &residence, const int &phoneNo, const int &emergencyContactNo, const string &date, const string &doctor){
    patientId = id;
    patientName = name;
    patientAge = age;
    patientResidence = residence;
    patientPhoneNo = phoneNo;
    patientEmergencyContactNo = emergencyContactNo;
    dateReported = date;
    doctorReported = doctor;
}

string Patient::getPatientId(){
    return patientId;
}

string Patient::getPatientName(){
    return patientName;
}

int Patient::getPatientAge(){
    return patientAge;
}

int Patient::getPatientPhoneNo(){
    return patientPhoneNo;
}

int Patient::getPatientEmergencyContactNo(){
    return patientEmergencyContactNo;
}

string Patient::getPatientResidence(){
    return patientResidence;
}

string Patient::getDateReported(){
    return dateReported;
}

string Patient::getDoctorReported(){
    return doctorReported;
}

Node::Node(const Patient& reportedData){

    data = reportedData;
    next = nullptr;
    prev = nullptr;
}


DengueCasesLinkedList::DengueCasesLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

    void DengueCasesLinkedList::insert(const Patient& reportedData) {
        Node* newNode = new Node(reportedData);
        newNode->next = NULL;
        newNode->prev = tail;
        tail = newNode;

        if (head == NULL) { // Inserting to an empty list
            head = newNode;
        } else {
            newNode->prev->next = newNode;
        }

        size++;
    }

    void DengueCasesLinkedList::print() {
        Node* current = head;
        while (current != nullptr) {
            cout << "Patient Id: " << current->data.getPatientId() << endl;
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
