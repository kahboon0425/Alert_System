#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

//for user and doctor
bool isValidUsername(const std::string &username);
bool isValidPassword(const std::string &password);
bool isValidResidence(const std::string &residence);
bool isValidPhoneNumber(int phoneNumber);
bool isValidPatientName(const std::string &name);
bool isValidPatientAge(int age);
bool isValidPatientID(const std::string &patientId);
bool isValidDateFormat(const std::string &date);
bool isValidPositiveInteger(const std::string &input);
bool isValidState(const std::string &state);
#endif
