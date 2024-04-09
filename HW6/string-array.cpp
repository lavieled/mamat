#include "string-array.h"

// Constructor
StringArray::StringArray() : strings(nullptr), size(0) {}

// Destructor
StringArray::~StringArray() {
    // Deallocate memory for each GenericString object in the array
    for (size_t i = 0; i < size; ++i) {
        delete strings[i];
    }
    // Deallocate memory for the array itself
    if (strings != nullptr) {
            delete[] strings;
        }
}

// Add a string to the array
void StringArray::add(GenericString* str) {
    // Increase size of array
    GenericString** temp = new GenericString*[size + 1]; // Allocate memory for new array

    for (size_t i = 0; i < size; ++i) {
        temp[i] = strings[i]; // Copy old pointers to the new array
    }

    temp[size++] = str; // Add the new string pointer to the new array

    // Deallocate memory for the old array
    delete[] strings;

    // Update array pointer to point to the new array
    strings = temp;
}


// Operator to access individual strings
GenericString& StringArray::operator[](size_t index) {
    return *strings[index];
}

// Method to get the size of the array
size_t StringArray::getSize() const {
    return size;
}
