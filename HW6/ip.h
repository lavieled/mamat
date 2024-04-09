#ifndef IP_H
#define IP_H

#include <stddef.h>
#include <iostream>
#include "generic-string.h"
#include "generic-field.h"
#include "string-array.h"
#include "string.h"

//ip is a class inheriting from GenericField.
class ip : public GenericField {
    String ip_name;
    unsigned int mask_ip;
    int mask_num;

public :

    ip(): ip_name(nullptr), mask_ip(0), mask_num(0){}
    ip(const String& ip);
    bool set_value(String value);
    bool match(const GenericString& packet) const;
    ~ip();
};

#endif
