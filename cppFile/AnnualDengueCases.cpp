#include <iostream>
#include "fstream"
using namespace std;
#include "../headerFile/AnnualDengueCases.h"

AnnualDengueCases::AnnualDengueCases(const string &yearParam, int &totalCasesParam)
{
    year = yearParam;
    totalCases = totalCasesParam;
    next = nullptr;
}

AnnualDengueCasesLinkedList::AnnualDengueCasesLinkedList()
{
    head = nullptr;
    size = 0;
}

void AnnualDengueCasesLinkedList::readCsvFile(const string& rowData)

{

    AnnualDengueCases *newNode = new AnnualDengueCases;
    newNode->data = rowData;
    newNode->next = nullptr;

    if (head == nullptr)
        head = newNode; // if list is empty, set head to the new node
    else
    {
        AnnualDengueCases *last = head; // a new pointer is decleared and initialized with value of the head pointer
        while (last->next != nullptr)   // if next pointer is not nullptr, continue travel
            last = last->next;
        last->next = newNode;
    }
    size++;
}

void AnnualDengueCasesLinkedList::readCsvFileAnnualCases(const string &year, int &totalCases)

{

    AnnualDengueCases *newNode = new AnnualDengueCases;
    newNode->year = year;
    newNode->totalCases = totalCases;
    newNode->next = nullptr;

    if (head == nullptr)
        head = newNode; // if list is empty, set head to the new node
    else
    {
        AnnualDengueCases *last = head; // a new pointer is decleared and initialized with value of the head pointer
        while (last->next != nullptr)   // if next pointer is not nullptr, continue travel
            last = last->next;
        last->next = newNode;
    }
    size++;
}


void AnnualDengueCasesLinkedList::display()
{
    AnnualDengueCases *current = head;
    string currentYear = "";
    int totalCasesForYear = 0;

    while (current)
    {
        if (current->year != currentYear)
        {
            // We've encountered a new year, so display the total cases for the previous year
            if (!currentYear.empty())
            {
                cout << "Year: " << currentYear << ", Total Cases: " << totalCasesForYear << endl;
            }

            // Reset the total cases and update the current year
            totalCasesForYear = 0;
            currentYear = current->year;
        }

        // Accumulate the total cases for the current year
        totalCasesForYear += current->totalCases;

        // Move to the next node
        current = current->next;
    }

    // Display the total cases for the last year
    if (!currentYear.empty())
    {
        cout << "Year: " << currentYear << ", Total Cases: " << totalCasesForYear << endl;
    }
}
