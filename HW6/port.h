//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
//

#ifndef PORT_H
#define PORT_H

#define MINPORT 0
#define MAXPORT 65535

#include "string-array.h"
#include "string.h"
#include "generic-field.h"

class port : public GenericField{
    unsigned short min_val;
    unsigned short max_val;
    String port_name;

public:
    port(): port_name(nullptr), min_val(MINPORT), max_val(MAXPORT){}
    port(const String &Port);
    bool match(const GenericString& packet) const;
    bool set_value(String value);
    ~port();


};
#endif //PORT_H
