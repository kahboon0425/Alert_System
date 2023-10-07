#include <iostream>
#include "fstream"
using namespace std;
#include "../headerFile/AnnualDengueCases.h"


AnnualDengueCases::AnnualDengueCases(const string &rowData)
{
    data = rowData;
    next = nullptr;
}

AnnualDengueCasesLinkedList::AnnualDengueCasesLinkedList(){
    head = nullptr;
    size = 0;
}


void AnnualDengueCasesLinkedList::readCsvFile(const string &rowData) 

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

