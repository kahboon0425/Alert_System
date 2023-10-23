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


struct WeeklyDengueCases {
    int year;         
    int week;         
    int cases[15];
    WeeklyDengueCases* next;   
    WeeklyDengueCases(int year, int week);
};

// Define the WeeklyDengueCasesLinkedList class
class WeeklyDengueCasesLinkedList
{
public:
    WeeklyDengueCasesLinkedList();

    void merge(pair<string, int> stateCases[], int left, int middle, int right);
    void mergeSort(pair<string, int> stateCases[], int left, int right);
    void insert(int year, int week, int* caseData);
    void sortCasesByState(int year, int week);
    string getStateName(int index);
    


    // void readCsvFile(const string& rowData);
    // void viewWeeklyCasesSortByCaseNumber(const string& year, const int &week);
    // void addWeeklyCases();
    // void sendAlert();


private:
    WeeklyDengueCases *head;
    int size;
};

#endif
