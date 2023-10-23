#include <iostream>
#include "fstream"
using namespace std;
#include "../headerFile/WeeklyDengueCases.h"

// Constructor for WeeklyDengueCases struct
WeeklyDengueCases::WeeklyDengueCases(int year, int week)
{
    this->year = year;
    this->week = week;
    next = nullptr;
    for (int i = 0; i < 15; i++) {
        cases[i] = 0;
        consecutiveWeeks[i] = 0;
    }
}

// Constructor for WeeklyDengueCasesLinkedList class
WeeklyDengueCasesLinkedList::WeeklyDengueCasesLinkedList()
{
    head = nullptr;
    size = 0;
}



// Merge two sorted halves of the stateCases array
void WeeklyDengueCasesLinkedList::merge(pair<string, int> stateCases[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    pair<string, int> leftHalf[n1];
    pair<string, int> rightHalf[n2];

    for (int i = 0; i < n1; i++) {
        leftHalf[i] = stateCases[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightHalf[i] = stateCases[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftHalf[i].second <= rightHalf[j].second) {
            stateCases[k] = leftHalf[i];
            i++;
        } else {
            stateCases[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        stateCases[k] = leftHalf[i];
        i++;
        k++;
    }

    while (j < n2) {
        stateCases[k] = rightHalf[j];
        j++;
        k++;
    }
}

// Implement Merge Sort
void WeeklyDengueCasesLinkedList::mergeSort(pair<string, int> stateCases[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(stateCases, left, middle);
        mergeSort(stateCases, middle + 1, right);
        merge(stateCases, left, middle, right);
    }
}


void WeeklyDengueCasesLinkedList::insert(int year, int week, int *caseData)
{
    WeeklyDengueCases *newNode = new WeeklyDengueCases(year, week);

    for (int i = 0; i < 15; i++) {
        newNode->cases[i] = caseData[i];
    }

    if (!head || (year < head->year) || (year == head->year && week < head->week)) {
        newNode->next = head;
        head = newNode;
        return;
    }

    WeeklyDengueCases *current = head;
    while (current->next && (year > current->next->year || (year == current->next->year && week > current->next->week))) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void WeeklyDengueCasesLinkedList::sortCasesByState(int year, int week)
{
   WeeklyDengueCases *current = head;
    while (current && (current->year != year || current->week != week)) {
        current = current->next;
    }

    if (!current) {
        cout << "Data not found for the specified year and week." << endl;
        return;
    }

    // Create a key-value pair for state and case number
    pair<string, int> stateCases[15];
    for (int i = 0; i < 15; i++) {
        stateCases[i].first = getStateName(i);
        stateCases[i].second = current->cases[i];
    }

    // Start Merge Sort to sort the stateCases array
    mergeSort(stateCases, 0, 14);

    // Display the sorted data
    cout << "\nStates with Dengue Cases in Ascending Order for Year " << year << ", Week " << week << ":" << endl;
    for (int i = 0; i < 15; i++) {
        cout << stateCases[i].first << ": " << stateCases[i].second << endl;
    }
}

string WeeklyDengueCasesLinkedList::getStateName(int index)
{
    const string stateNames[] = {
        "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN", "PAHANG", "PERAK", "PERLIS",
        "PULAU PINANG", "SABAH", "SARAWAK", "SELANGOR", "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"
    };

    if (index >= 0 && index < 15) {
        return stateNames[index];
    } else {
        return "Unknown";
    }
}

void WeeklyDengueCasesLinkedList::insertNewCases(int year, int week, int *caseData) {
   WeeklyDengueCases* newNode = new WeeklyDengueCases{year, week};
        for (int i = 0; i < 15; i++) {
            newNode->cases[i] = caseData[i];
        }

        newNode->next = head;
        head = newNode;
    }



void WeeklyDengueCasesLinkedList::checkAlerts(int stateIndex) {
    WeeklyDengueCases* current = head;
        int latestYear = 0;
        int latestWeeks[3] = {0};

        while (current) {
            std::cout << "State: " << getStateName(stateIndex) << " Week: " << current->week << " Cases: " << current->cases[stateIndex] << std::endl;
            if (current->cases[stateIndex] >= 20) {
                latestYear = current->year;
                latestWeeks[2] = latestWeeks[1];
                latestWeeks[1] = latestWeeks[0];
                latestWeeks[0] = current->week;
            }
            current = current->next;
        }

        if (latestYear == 0) {
            std::cout << "No alerts for state " << getStateName(stateIndex) << " at this time." << std::endl;
            return;
        }

        std::string alertMessage = "ALERT: Dengue cases in " + getStateName(stateIndex) + " have reached 20 or more in the last 3 weeks.";
        std::cout << alertMessage << std::endl;
        // sendAlertToUsers(alertMessage);
    }



void WeeklyDengueCasesLinkedList::clear() {
    // Remove all nodes from the list and reset the head to nullptr
    while (head) {
        WeeklyDengueCases* current = head;
        head = head->next;
        delete current;
    }
}



// void WeeklyDengueCasesLinkedList::initializeCasesFor2023() {
//         // Find the nodes for the specified year (2023) and week (1)
//         int year = 2023;
//         int week = 1;
//         WeeklyDengueCases* current = head;

//         while (current && (current->year != year || current->week != week)) {
//             current = current->next;
//         }

//         if (!current) {
//             cout << "Data not found for the specified year and week." << endl;
//             return;
//         }

//         // Set the cases for Johor (index 0) and Kuala Lumpur (index 13) to 20 for the consecutive weeks (1, 2, and 3)
//         int johorIndex = 0;
//         int klIndex = 13;
//         for (int i = 0; i < 3; i++) {
//             current->cases[johorIndex] = 20;
//             current->cases[klIndex] = 20;

//             // If you want to set the cases for the next consecutive week, create a new node
//             week++;
//             WeeklyDengueCases* newNode = new WeeklyDengueCases(year, week);
//             newNode->cases[johorIndex] = 20;
//             newNode->cases[klIndex] = 20;
//             newNode->next = current->next;
//             current->next = newNode;

//             current = newNode; // Move to the next node for the next week
//         }
//     }
// };



// // Member function to read CSV data and populate the linked list
// void WeeklyDengueCasesLinkedList::readCsvFile(const std::string& rowData) {
//     WeeklyDengueCases* newNode = new WeeklyDengueCases(rowData);

//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         WeeklyDengueCases* last = head;
//         while (last->next != nullptr) {
//             last = last->next;
//         }
//         last->next = newNode;
//     }
//     size++;
// }
// // View Weekly dengue cases in all state sort by case number
// void WeeklyDengueCasesLinkedList::viewWeeklyCasesSortByCaseNumber(const string &year, const int &week){

// }
