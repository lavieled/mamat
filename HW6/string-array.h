#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include "string.h"
#include "generic-string.h"
#include <cstring>

class StringArray {
private:
    String* array; // Array of String objects
    size_t elements;   // Number of elements in the array

public:
    //constructors and destructor
    StringArray();
    StringArray(size_t initialSize);
    StringArray(const StringArray& other);
    ~StringArray();

    //getter
    size_t getSize() const;

    //element access
    String& operator[](size_t index);
    const String& operator[](size_t index) const;
    //adds elements
    void push_back(const String& str);
    /*
    // Modifiers
    void resize(size_t newSize);
    void clear();

    // Utility functions
    void print() const;
     */
};

#endif // STRINGARRAY_H
