// lavie lederman 319046504
// shahar yankelovich 206159527


#include "string.h"
#include "string-array.h"
#include <cstring> // Include <cstring> for strcpy, strlen, and memmove
#include <cctype>  // Include <cctype> for isspace
#include <cstdlib> // Include <cstdlib> for atoi

// Constructor
String::String(const char* str) {
    length = strlen(str);
    data = new char[length + 1]; // Allocate memory
    strcpy(data, str); // Copy data
}

// Copy constructor
String::String(const String& other) {
    length = other.length;
    data = new char[length + 1]; // Allocate memory
    strcpy(data, other.data); // Copy data
}

// Destructor
String::~String() {
    if (data != nullptr) {
        delete[] data;
    }
}


// Implement methods from GenericString interface
StringArray String::split(const char* delimiters) const {
    // Implement split logic
    StringArray result;
    char* token = strtok(data, delimiters);
    while (token != nullptr) {
        result.add(make_string(token));
        token = strtok(nullptr, delimiters);
    }
    return result;
}

GenericString& String::operator=(const char* str) {
    // Calculate the length of the new string
    size_t newLength = strlen(str);

    // If the new string length is the same as the current one, just copy the data
    if (newLength == length) {
        strcpy(data, str);
    } else {
        // Allocate new memory for the new string
        char* newData = new char[newLength + 1];
        strcpy(newData, str);

        // If there was already allocated memory for data, delete it
        if (data != nullptr) {
            delete[] data;
        }

        // Update the data pointer and length
        data = newData;
        length = newLength;
    }

    return *this;
}

GenericString& String::trim() {
    int left = 0;
    int right = (int)length - 1;

    // Remove leading whitespace
    while (left <= right && (data[left] == ' ' || data[left] == '\t' || data[left] == '\n' || data[left] == '\r' || data[left] == '\f' || data[left] == '\v')) {
        left++;
    }

    // Check if the entire string is whitespace
    if (left > right) {
        length = 0;
        //delete[] data;
        data = new char[1];
        data[0] = '\0';
        return *this;
    }

    // Remove trailing whitespace
    while (right >= left && (data[right] == ' ' || data[right] == '\t' || data[right] == '\n' || data[right] == '\r' || data[right] == '\f' || data[right] == '\v')) {
        right--;
    }

    // Calculate new string length
    length = right - left + 1;

    // Shift content to the beginning of the string if needed
    if (left != 0) {
        memmove(data, data + left, length);
    }

    // Null-terminate the string
    data[length] = '\0';

    return *this;
}


bool String::operator==(const GenericString& other) const {
    const String& otherString = static_cast<const String&>(other);
    return strcmp(data, otherString.data) == 0;
}

bool String::operator==(const char* other) const {
    return strcmp(data, other) == 0;
}

int String::to_integer() const {
    return atoi(data);
}

String& String::as_string() {
    return *this;
}

const String& String::as_string() const {
    return *this;
}

// Global method implementation
GenericString* make_string(const char* str) {
    return new String(str);
}
