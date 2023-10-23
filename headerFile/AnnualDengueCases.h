#ifndef ANNUALDENGUECASES_H
#define ANNUALDENGUECASES_H

#include <iostream>
using namespace std;

// define node
struct AnnualDengueCases
{
    std::string year;
    std::string state;
    int totalCases;
    AnnualDengueCases *next;
    AnnualDengueCases(){};
    AnnualDengueCases(const std::string &yearParam, const std::string &stateParam, int totalCasesParam);
    AnnualDengueCases(const std::string &yearParam, int totalCasesParam);
};

// define node
// struct AnnualDengueCases
// {

//     string year;
//     int totalCases;
//     AnnualDengueCases *next;
//     AnnualDengueCases(){};
//     AnnualDengueCases(const string &yearParam, int &totalCasesParam);

// };

// define linked list
class AnnualDengueCasesLinkedList
{
public:
    AnnualDengueCasesLinkedList();
    // ~AnnualDengueCasesLinkedList();

    // void readCsvFile(const string& rowData);
    void readCsvFileAnnualCases(const string &year, int &totalCases);
    void readCsvFileAnnualCases(const string &year, const string &state, int totalCases);
    void addNewDengueCases(const DengueCasesLinkedList &dengueCasesList);
    void displayTotalCasesBasedOnYearAndState(const string &year, const string &state);

    void displayTotalCases();
    void displayScaledBarChart(int scaleFactor);
    void clear();

public:
    AnnualDengueCases *head;
    int size;
    AnnualDengueCases *findNodeByYear(const string &year);
};

#endif
