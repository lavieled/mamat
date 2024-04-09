#include "port.h"
#include <iostream>

port::port(const String& Port) : GenericField(), port_name(Port) {
    min_val = MINPORT;
    max_val = MAXPORT;
}
port::~port() {
    // Destructor implementation (if needed)
}

bool port::set_value(String value) {
    // Split the value into port range
    StringArray port_range = value.split("-");
    
    if (port_range.getSize() != 2) {
        return false;
    }
    
    unsigned short min = port_range[0].to_integer();
    unsigned short max = port_range[1].to_integer();

    // Update parameters
    min_val = min;
    max_val = max;
    // Assigning the value to port_name directly instead of using the assignment operator
    return true;
}


bool port::match(const GenericString& packet) const {
    String packet_str = packet.as_string();

    StringArray packet_split = packet_str.split(",");
    for(unsigned int i = 0; i < packet_split.getSize(); i++) {
        String packet_split_str = packet_split[i].as_string();
        StringArray ports = packet_split_str.split("=");
        if(ports.getSize() != 2) {
            continue; // Skip this field if it doesn't match the expected format
        }
        String port_n = ports[0].as_string();
        String port_v = ports[1].as_string();
        // Trim spaces from the name and value
        port_n.trim();
        port_v.trim();
        
        if(port_n == port_name) {
            int curr_port = port_v.to_integer();
            // Check if the port number meets the rule
            if((curr_port >= min_val) && (curr_port <= max_val)) {

                return true;
            }
        }
    }
    return false;
}
