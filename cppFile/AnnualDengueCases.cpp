#include <iostream>
#include "fstream"
using namespace std;
#include "../headerFile/AnnualDengueCases.h"

AnnualDengueCases::AnnualDengueCases(const string &yearParam, const int &stateParam, int totalCasesParam)
    : year(yearParam), state(stateParam), totalCases(totalCasesParam), next(nullptr)
{
}

AnnualDengueCases::AnnualDengueCases(const std::string &yearParam, int totalCasesParam)
{
    // Initialize the fields of the AnnualDengueCases object here
    year = yearParam;
    totalCases = totalCasesParam;
}

AnnualDengueCasesLinkedList::AnnualDengueCasesLinkedList()
{
    head = nullptr;
    size = 0;
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

void AnnualDengueCasesLinkedList::readCsvFileAnnualCases(const string &year, const int &state, int totalCases)
{
    // Create a new node to store the data
    // AnnualDengueCases *newNode = new AnnualDengueCases(year, state, totalCases);
    AnnualDengueCases *newNode = new AnnualDengueCases;
    newNode->year = year;
    newNode->state = state;
    newNode->totalCases = totalCases;
    newNode->next = nullptr;

    // Add the new node to the linked list
    if (head == nullptr)
        head = newNode; // If the list is empty, set the head to the new node
    else
    {
        AnnualDengueCases *last = head;
        while (last->next != nullptr)
            last = last->next;
        last->next = newNode;
    }

    size++;
}

void AnnualDengueCasesLinkedList::displayTotalCasesBasedOnYearAndState(const string &year, const int &state)
{
    AnnualDengueCases *current = head;
    int totalCasesForYearAndState = 0;
    while (current)
    {

        if (current->year == year && current->state == state)
        {
            totalCasesForYearAndState += current->totalCases;
        }

        current = current->next;
    }
    string stateNames[] = {
        "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN",
        "PAHANG", "PERAK", "PERLIS", "PULAU PINANG", "SABAH",
        "SARAWAK", "SELANGOR", "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"};

    if (state >= 1 && state <= 15)
    {
        string stateName = stateNames[state - 1];
        cout << "\nYear: " << year << ", State: " << stateName << ", Total Cases: " << totalCasesForYearAndState << endl;
    }
    totalCasesForYearAndState = 0;
}

void AnnualDengueCasesLinkedList::displayTotalCases()
{
    AnnualDengueCases *current = head;
    string currentYear = "";
    int totalCasesForYear = 0;

    // while current not equal nullptr
    while (current)
    {
        // checks if the year in the current node is different from the previously encountered year = indication it has moved to a new year's data
        if (current->year != currentYear)
        {

            if (!currentYear.empty())
            {
                cout << "Year: " << currentYear << ", Total Cases: " << totalCasesForYear << endl;
            }

            // Reset the total cases and update the current year
            totalCasesForYear = 0;
            // updates the currentYear to the year from the current node
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

void AnnualDengueCasesLinkedList::displayScaledBarChart(int scaleFactor)
{
    AnnualDengueCases *current = head;
    string currentYear = "";
    int totalCasesForYear = 0;

    while (current)
    {
        if (current->year != currentYear)
        {
            //  if encountered a new year, so display the total cases for the previous year
            if (!currentYear.empty())
            {
                int scaledTotalCases = totalCasesForYear / scaleFactor;

                // Display the bar chart
                cout << "Year " << currentYear << ": ";
                for (int i = 0; i < scaledTotalCases; i++)
                {
                    cout << "*";
                }
                cout << endl;
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
        int scaledTotalCases = totalCasesForYear / scaleFactor;

        // Display the bar chart
        cout << "Year " << currentYear << ": ";
        for (int i = 0; i < scaledTotalCases; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// Implement member functions for the AnnualDengueCasesLinkedList class
void AnnualDengueCasesLinkedList::addNewDengueCases(const DengueCasesLinkedList &dengueCasesList)
{
    Node *current = dengueCasesList.head;
    int tempTotalCases = 1;

    while (current != nullptr)
    {
        const Patient &dengueCase = current->data;

        // Extract relevant information from the dengue case to add to the annual list
        string year = dengueCase.getDateReported().substr(0, 4); // Extract the year

        // Check if a node with the same year already exists in the annual list
        AnnualDengueCases *existingNode = findNodeByYear(year);

        if (existingNode != nullptr)
        {
            // If a node for the year exists, increment the totalCases by tempTotalCases
            existingNode->totalCases += tempTotalCases; // Accumulate the total cases for the current year
        }
        else
        {
            // If no node for the year exists, create a new node
            AnnualDengueCases *newNode = new AnnualDengueCases(year, tempTotalCases); // Initialize with tempTotalCases cases
            newNode->next = nullptr;

            if (head == nullptr)
                head = newNode; // if list is empty, set head to the new node
            else
            {
                AnnualDengueCases *last = head;
                while (last->next != nullptr)
                    last = last->next;
                last->next = newNode;
            }
            size++;
        }

        // Move to the next Dengue case in the list
        current = current->next;
    }
}

AnnualDengueCases *AnnualDengueCasesLinkedList::findNodeByYear(const string &year)
{
    AnnualDengueCases *current = head;
    while (current != nullptr)
    {
        if (current->year == year)
        {
            return current; // Return the node if found
        }
        current = current->next;
    }
    return nullptr; // Year not found
}

void AnnualDengueCasesLinkedList::clear()
{
    AnnualDengueCases *current = head;
    while (current != nullptr)
    {
        AnnualDengueCases *next = current->next;
        delete current; // Delete the current node
        current = next;
    }
    head = nullptr; // Set head to nullptr to indicate an empty list
    size = 0;       // Reset the size to 0
}