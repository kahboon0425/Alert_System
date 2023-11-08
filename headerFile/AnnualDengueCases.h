#ifndef ANNUALDENGUECASES_H
#define ANNUALDENGUECASES_H

#include <iostream>
using namespace std;

// define node
struct AnnualDengueCases
{
    string year;
    int state;
    int totalCases;
    AnnualDengueCases *next;
    AnnualDengueCases(){};
    AnnualDengueCases(const string &yearParam, const int &stateParam, int totalCasesParam);
    AnnualDengueCases(const string &yearParam, int totalCasesParam);
};


// define linked list
class AnnualDengueCasesLinkedList
{
public:
    AnnualDengueCasesLinkedList();
    // ~AnnualDengueCasesLinkedList();

    void readCsvFileAnnualCases(const string &year, int &totalCases);
    void readCsvFileAnnualCases(const string &year, const int &state, int totalCases);
    void addNewDengueCases(const DengueCasesLinkedList &dengueCasesList);
    void displayTotalCasesBasedOnYearAndState(const string &year, const int &state);

    void displayTotalCases();
    void displayScaledBarChart(int scaleFactor);
    void clear();

public:
    AnnualDengueCases *head;
    int size;
    AnnualDengueCases *findNodeByYear(const string &year);
};

#endif
