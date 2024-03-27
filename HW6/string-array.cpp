//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
//
#include "string_array.h"

// Default constructor
StringArray::StringArray() : array(nullptr), elements(0) {}

// Constructor with initial size
StringArray::StringArray(size_t initialSize) : elements(initialSize) {
    array = new String[initialSize];
}

// Copy constructor
StringArray::StringArray(const StringArray& other) : elements(other.elements) {
    array = new String[elements];
    for (size_t i = 0; i < elements; ++i) {
        array[i] = other.array[i];
    }
}

// Destructor
StringArray::~StringArray() {
    delete[] array;
}

// Accessor for the size of the array
size_t StringArray::getSize() const {
    return elements;
}

// Element access operator for non-const objects
String& StringArray::operator[](size_t index) {
    return array[index];
}

// Element access operator for const objects
const String& StringArray::operator[](size_t index) const {
    return array[index];
}
//add element to array
void StringArray::push_back(const String& str) {
    // Create a new array with increased size
    String* newArray = new String[elements + 1];

    // Copy existing elements to the new array
    for (size_t i = 0; i < elements; ++i) {
        newArray[i] = array[i];
    }

    // Add the new string at the end of the new array
    newArray[elements] = str;

    // Delete the old array and update to the new array
    delete[] array;
    array = newArray;

    // Increment the number of elements
    elements++;
}
