#ifndef ANNUALDENGUECASES_H
#define ANNUALDENGUECASES_H

#include <iostream>
using namespace std;

// define node
struct AnnualDengueCases
{
    // int year;
    // string ageGroup;
    // string Johorstate;
    // string KedahState;
    // string KelantanState;
    // string MelakaState;
    // string NegeriSembilanState;
    // string PahangState;
    // string PerakState;
    // string PerlisState;
    // string PulauPinangState;
    // string SabahState;
    // string SarawakState;
    // string SelangorState;
    // string TerengganuState;
    // string KLState;
    // string LabuanState;
    
    string data;
    string year;
    int totalCases;
    AnnualDengueCases *next;
    AnnualDengueCases(){};
    // AnnualDengueCases(const string& rowData);
    AnnualDengueCases(const string &yearParam, int &totalCasesParam);

    // AnnualDengueCases(int &year, string &ageGroup,
    //                   string &Johorstate,
    //                   string &KedahState,
    //                   string &KelantanState,
    //                   string &MelakaState,
    //                   string &NegeriSembilanState,
    //                   string &PahangState,
    //                   string &PerakState,
    //                   string &PerlisState,
    //                   string &PulauPinangState,
    //                   string &SabahState,
    //                   string &SarawakState,
    //                   string &SelangorState,
    //                   string &TerengganuState,
    //                   string &KLState,
    //                   string &LabuanState);

};

// define linked list
class AnnualDengueCasesLinkedList
{
public:
    AnnualDengueCasesLinkedList();
    // ~AnnualDengueCasesLinkedList();

    void readCsvFile(const string& rowData);
    void readCsvFileAnnualCases(const string &year, int &totalCases);
    void displayTotalCases();
    void displayScaledBarChart(int scaleFactor);

public:
    AnnualDengueCases *head;
    int size;
};



#endif
