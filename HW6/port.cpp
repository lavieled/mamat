//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
//

#include "port.h"
#include <iostream>

// Constructor definition
port::port(const String &Port) : port_name(Port), min_val(MINPORT), max_val(MAXPORT) {}

// set_value function definition
bool port::set_value(String value) {
    //split to range
    StringArray port_range = value.split("-");
    unsigned short min = port_range[0].trim().to_integer();
    unsigned short max = port_range[1].trim().to_integer();
    if (min < MINPORT || max > MAXPORT) {
        std::cerr << "Error: Port value out of range" << std::endl;
        return false;
    }
    //update params
    min_val = min;
    max_val = max;
    port_name = value;
    return true;
}

// match function definition
bool port::match(const GenericString& packet) const {
    String const &packet_str = packet.as_string();
    StringArray packet_split = packet_str.split(",");//4 fields
    for (unsigned int i = 0; i < packet_split.getSize(); i++) {
        StringArray ports = packet_split[i].split("=");//name & value
        if (ports.getSize() == 2) {
            String port = ports[0].trim();
            String Value = ports[1].trim();
            if (port == port_name) {
                int curr_port = Value.to_integer();
                return (curr_port >= min_val && curr_port <= max_val);
            }
        }
    }
    return false; // Port not found in packet
}

// Destructor definition
port::~port() {
    // Destructor typically does not require explicit implementation
}

