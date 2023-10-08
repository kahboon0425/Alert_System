#include <iostream>
#include "fstream"
using namespace std;
#include "../headerFile/WeeklyDengueCases.h"



// Constructor for WeeklyDengueCases class
WeeklyDengueCases::WeeklyDengueCases(const std::string& rowData) {
    data = rowData;
    next = nullptr;
}

// Constructor for WeeklyDengueCasesLinkedList class
WeeklyDengueCasesLinkedList::WeeklyDengueCasesLinkedList() {
    head = nullptr;
    size = 0;
}

// Member function to read CSV data and populate the linked list
void WeeklyDengueCasesLinkedList::readCsvFile(const std::string& rowData) {
    WeeklyDengueCases* newNode = new WeeklyDengueCases(rowData);

    if (head == nullptr) {
        head = newNode;
    } else {
        WeeklyDengueCases* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }
    size++;
}

