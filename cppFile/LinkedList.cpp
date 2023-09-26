#include <iostream>
#include <string>
struct Patient {
    int id;
    std::string name;
    int age;
    std::string phoneNumber;

    Patient(int _id, const std::string& _name, int _age, const std::string& _phoneNumber)
        : id(_id), name(_name), age(_age), phoneNumber(_phoneNumber) {}
};
struct Node {
    Patient data;
    Node* next;

    Node(const Patient& val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(const Patient& val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "ID: " << current->data.id << ", Name: " << current->data.name
                      << ", Age: " << current->data.age << ", Phone: " << current->data.phoneNumber << std::endl;
            current = current->next;
        }
    }
};