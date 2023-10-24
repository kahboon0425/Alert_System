#ifndef WEEKLYDENGUECASES_H
#define WEEKLYDENGUECASES_H

#include <iostream>
using namespace std;

// // Define the WeeklyDengueCases class (not a struct)
// class WeeklyDengueCases
// {
// public:
//     // string data;
//     // WeeklyDengueCases *next;
//     // WeeklyDengueCases(){};
//     // WeeklyDengueCases(const string& rowData);
// };

struct WeeklyDengueCases
{
    int year;
    int week;
    int cases[15];
    int consecutiveWeeks[15];
    WeeklyDengueCases *next;
    WeeklyDengueCases(int year, int week);
};

// Define the WeeklyDengueCasesLinkedList class
class WeeklyDengueCasesLinkedList
{
public:
    WeeklyDengueCasesLinkedList();

    void merge(pair<string, int> stateCases[], int left, int middle, int right);
    void mergeSort(pair<string, int> stateCases[], int left, int right);
    void insert(int year, int week, int *caseData);
    void sortCasesByState(int year, int week);
    string getStateName(int index);
    // void initializeCasesFor2023()
    void insertNewCases(int year, int week, int *caseData);
    // void checkAlerts(int year, int week);
    void checkAlerts(int stateIndex);
    // void sendAlertToUsers(string stateFound);
    // void sendAlertToUsers(string alertedStates[], int alertedCount, string userState);
    void sendAlertToUsers(string userState);

    void clear();

    // void readCsvFile(const string& rowData);
    // void viewWeeklyCasesSortByCaseNumber(const string& year, const int &week);
    // void addWeeklyCases();
    // void sendAlert();

public:
    WeeklyDengueCases *head;
    int size;
    // string alertedStates[50]; // Adjust the size as needed
    // int alertedCount;
};

#endif
