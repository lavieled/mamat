//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
//

#ifndef STRING_H
#define STRING_H


#include <cstring> // Include necessary header files

class String {
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
    String& operator=(const char *str);

    // Comparison functions
    bool equals(const String &rhs) const;
    bool equals(const char *rhs) const;

    // Utility functions
    void split(const char *delimiters, String **output, size_t *size) const;
    int to_integer() const;
    String trim() const;
};

#endif // STRING_H
