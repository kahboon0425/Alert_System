#ifndef WEEKLYDENGUECASES_H
#define WEEKLYDENGUECASES_H

#include <iostream>
using namespace std;

// Define the WeeklyDengueCases class (not a struct)
class WeeklyDengueCases
{
public:
    string data;
    WeeklyDengueCases *next;
    WeeklyDengueCases(){};
    WeeklyDengueCases(const string& rowData);
};

// Define the WeeklyDengueCasesLinkedList class
class WeeklyDengueCasesLinkedList
{
public:
    WeeklyDengueCasesLinkedList();

    void readCsvFile(const string& rowData);

public:
    WeeklyDengueCases *head;
    int size;
};

#endif
