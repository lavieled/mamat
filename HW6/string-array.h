#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include "string.h"
#include <cstddef> // Include <cstddef> for size_t

class StringArray {
private:
    GenericString** strings;
    size_t size;

public:
    // Constructor
    StringArray();

    // Destructor
    ~StringArray();

    // Add a string to the array
    void add(GenericString* str);

    // Operator to access individual strings
    GenericString& operator[](size_t index); // Correct syntax for operator overloading

    // Method to get the size of the array
    size_t getSize() const;

};

#endif /* STRING_ARRAY_H */
