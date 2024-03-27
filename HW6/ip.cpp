//Lavie Lederman 319046504
//Shahar Yankelovich 206159527

//Maybe add a iostream or string library?
#include "ip.h"

#define MAXMASK 32
#define TOTBYTES 4
#define SHIFT 8

// Constructor definition
ip::ip(const string &ip) : GenericField(){
    ip_name = ip;
    mask_ip = 0;
    mask_num = 0;
}

// set_value function definition
bool ip::set_value(std::string value) {
    // Set the value of the IP (assuming value represents the IP address)
    size_t pos = value.find('/');
    //Check if the received position is valid.
    if(pos == std::string::npos) return false;
    ip_name = value.substr(0, pos);
    mask_num - std::stoi(value.substr(pos+1);
    return true; // Return true to indicate success
}

// match function definition
bool ip::match(std::string packet) {
   
    return (packet_ip_int == mask_ip);
}

// Destructor definition
ip::~ip() {
    // Destructor typically does not require explicit implementation
    // However, if there are resources to clean up, you can do so here
}
