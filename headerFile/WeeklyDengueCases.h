#ifndef WEEKLYDENGUECASES_H
#define WEEKLYDENGUECASES_H

#include <iostream>
using namespace std;


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
    void insertNewCases(int year, int week, int *caseData);
    void checkAlerts(int stateIndex);
    void sendAlertToUsers(string userState);
    void navigateAlertMessages(string alertMessages[], int alertCount);

    void clear();


public:
    WeeklyDengueCases *head;
    int size;
   
};

#endif
