#include "string-array.h"

// Constructor
StringArray::StringArray() : strings(nullptr), size(0) {}

// Destructor
StringArray::~StringArray() {
    // Deallocate memory for each GenericString object in the array
    /*for (size_t i = 0; i < size; ++i) {
        delete strings[i];
    }
    // Deallocate memory for the array itself
    delete[] strings;
    */
    if (strings != nullptr) {
            delete[] strings;
        }
}

// Add a string to the array
void StringArray::add(GenericString* str) {
    // Increase size of array
    GenericString** temp = new GenericString*[size + 1];
    for (size_t i = 0; i < size; ++i) {
        temp[i] = strings[i];
    }
    temp[size++] = str;
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
