#ifndef DAILY_CASES_H
#define DAILY_CASES_H

#include <string>

struct StateData {
    std::string stateName;
    int dailyDengueCases;
    StateData* next;

    StateData(const std::string& name, int cases) : stateName(name), dailyDengueCases(cases), next(nullptr) {}
};

class DailyCasesList {
public:
    DailyCasesList();
    ~DailyCasesList();

    void append(const std::string& name, int cases);
    void sort();
    void displayDailyCases();

private:
    StateData* head;
};

#endif
