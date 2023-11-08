#include "../headerFile/Validation.h"
#include "../headerFile/MOHAdmin.h"
#include <iostream>
#include <cctype>
#include <ctime>

bool isValidUsername(const std::string &username) {
    int length = 0;
    
    // Check minimum length requirement.
    while (username[length] != '\0') {
        length++;
    }
    if (length < 4) {
        return false;
    }

    // Check allowed characters (e.g., only letters and digits).
    for (int i = 0; i < length; i++) {
        if (!std::isalnum(username[i])) {
            return false;
        }
    }

    return true;
}


bool isValidPassword(const std::string &password) {
    int length = 0;
    
    // Check minimum length requirement for the password.
    while (password[length] != '\0') {
        length++;
    }
    if (length < 3) { // Adjust the minimum length as needed
        return false;
    }

 
    bool hasDigit = false;
    for (char c : password) {
        if (std::isdigit(c)) {
            hasDigit = true;
            break;
        }
    }

    return hasDigit;
}

bool isValidResidence(const std::string &residence) {
    // Predefined list of valid residence options.
    const std::string validResidences[] = {
        "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN",
        "PAHANG", "PERAK", "PERLIS", "PULAU PINANG", "SABAH",
        "SARAWAK", "SELANGOR", "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"
    };

    // Check if the provided residence matches any of the valid options.
    for (const std::string &validResidence : validResidences) {
        if (residence == validResidence) {
            return true; // The provided residence is valid.
        }
    }

    // If the provided residence doesn't match any valid option, return false.
    return false;
}

bool isValidPhoneNumber(int phoneNumber) {
    // Define the minimum number of digits required for a valid phone number.
    const int requiredDigits = 6; // Change to the desired minimum number of digits.

    // Check if the phone number contains at least the required number of digits.
    int numDigits = 0;
    int tempPhoneNumber = phoneNumber;
    while (tempPhoneNumber > 0) {
        tempPhoneNumber /= 10;
        numDigits++;
    }

    return numDigits >= requiredDigits;
}


bool isValidName(const std::string &name) {
    // Check if the name contains only alphabetic characters.
    for (char c : name) {
        if (!std::isalpha(c)) {
            return false;
        }
    }

    return true;
}

bool isValidPatientAge(int age) {
    // Check if the age is within the range of 0 to 100.
    return (age >= 0 && age <= 100);
}

bool isValidDateFormat(const std::string &date) {
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;  // Not in the expected format.
    }

    if (year < 2017 || year > 2023) {
        return false;  // Year out of range.
    }

    if (month < 1 || month > 12) {
        return false;  // Month out of range.
    }

    if (day < 1 || day > 31) {
        return false;  // Day out of range.
    }

    return true;  // Valid date format.
}

bool isValidPositiveInteger(const std::string &input) {
    // Check if the input is not empty.
    if (input.empty()) {
        return false;
    }

    // Check if all characters in the input are digits.
    for (char c : input) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    // Convert the input to an integer and check if it's greater than 0.
    int value = std::stoi(input);
    return value > 0;
}

bool isValidState(const std::string &state) {
    // Check if the input state is within the specified range of valid states.
    return state == "JOHOR" || state == "KEDAH" || state == "KELANTAN" || state == "MELAKA" ||
           state == "NEGERI SEMBILAN" || state == "PAHANG" || state == "PERAK" || state == "PERLIS" ||
           state == "PULAU PINANG" || state == "SABAH" || state == "SARAWAK" || state == "SELANGOR" ||
           state == "TERENGGANU" || state == "WP KUALA LUMPUR" || state == "WP LABUAN";
}