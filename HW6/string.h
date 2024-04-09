//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
//

#ifndef STRING_H
#define STRING_H

#include "generic-string.h"
#include "string-array.h"
#include <cstring> // Include necessary header files

class String : public GenericString {
private:
    char* data;
    size_t length;

public:
    // Constructor
    String(const char* str);
    String(const String& other);

    // Destructor
    ~String();

    // Implement methods from GenericString interface
    StringArray split(const char* delimiters) const override;
    GenericString& operator=(const char* str) override;
    GenericString& trim() override;
    bool operator==(const GenericString& other) const override;
    bool operator==(const char* other) const override;
    int to_integer() const override;
    String& as_string() override;
    const String& as_string() const override;
};

#endif /* STRING_H */
