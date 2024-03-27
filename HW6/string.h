//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
//

#ifndef STRING_H
#define STRING_H

#include "generic-string.h"
#include <cstring>




class String : public GenericString{
private:
    char *data; // Pointer to character array holding the string data
    size_t length; // Length of the string

public:
    // Constructors and destructor
    String(); // Default constructor
    String(const String &str); // Copy constructor
    String(const char *str); // Constructor from C-style string
    ~String(); // Destructor

    // Overloaded assignment operators
    String& operator=(const String &rhs);
    String& operator=(const char *str) override;

    // Comparison operators
    bool operator==(const GenericString &rhs) const;
    bool operator==(const char *rhs) const override;

    // Utility functions
    StringArray split(const char *delimiters, String **output, size_t *size) const;
    int to_integer() const;
    String& trim();

    // casting functions
    String& as_string();
    String& as_string() const;
};

#endif // STRING_H
