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
    AnnualDengueCases *next;
    AnnualDengueCases(){};
    AnnualDengueCases(const string& rowData);

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

public:
    AnnualDengueCases *head;
    int size;
};

#endif
