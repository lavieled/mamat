// Lavie Lederman 319046504
// Shahar Yankelovich 206159527

#ifndef PORT_H
#define PORT_H

#define MINPORT 0
#define MAXPORT 65535

#include "generic-string.h"
#include "generic-field.h"
#include "string-array.h"
#include "string.h"


class port : public GenericField {
public:
    String port_name;
    unsigned short min_val;
    unsigned short max_val;

    port() : port_name(nullptr), min_val(MINPORT), max_val(MAXPORT) {}
    port(const String& Port);
    bool set_value(String value);
    bool match(const GenericString& packet) const;
    
    ~port();
};

#endif // PORT_H
