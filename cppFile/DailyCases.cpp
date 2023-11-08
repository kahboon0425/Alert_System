#include "../headerFile/DailyCases.h"
#include <iostream>

DailyCasesList::DailyCasesList() : head(nullptr) {}

DailyCasesList::~DailyCasesList() {
    while (head) {
        StateData* temp = head;
        head = head->next;
        delete temp;
    }
}

void DailyCasesList::append(const std::string& name, int cases) {
    if (!head) {
        head = new StateData(name, cases);
    } else {
        StateData* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new StateData(name, cases);
    }
}

void DailyCasesList::sort() {
    if (!head || !head->next) {
        return;
    }

    StateData* sortedList = nullptr;

    while (head) {
        StateData* current = head;
        head = head->next;
        current->next = nullptr;

        // If sortedList is empty or current should be the new head
        if (!sortedList || current->stateName >= sortedList->stateName) {
            current->next = sortedList;
            sortedList = current;
        } else {
            StateData* temp = sortedList;
            while (temp->next && current->stateName < temp->next->stateName) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    head = sortedList;
}


void DailyCasesList::displayDailyCases() {

    StateData* current = head;
    while (current) {
        std::cout << current->stateName << ": " << current->dailyDengueCases << std::endl;
        current = current->next;
    }
}

