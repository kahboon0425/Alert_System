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
        "\nJOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN", "PAHANG", "PERAK", "PERLIS",
        "PULAU PINANG", "SABAH", "SARAWAK", "SELANGOR", "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"
    };

    if (index >= 0 && index < 15) {
        return stateNames[index];
    } else {
        return "Unknown";
    }
}





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
