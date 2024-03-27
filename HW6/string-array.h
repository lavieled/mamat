
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
    // Constructors and destructor
    StringArray();
    StringArray(size_t initialSize);
    StringArray(const StringArray& other);
    ~StringArray();

    // Accessors
    size_t getSize() const;

    // Element access
    String& operator[](size_t index);
    const String& operator[](size_t index) const;
    /*
    // Modifiers
    void resize(size_t newSize);
    void push_back(const String& str);
    void clear();

    // Utility functions
    void print() const;
     */
};

#endif // STRINGARRAY_H
