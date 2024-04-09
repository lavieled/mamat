#include "ip.h"
#include <iostream>

#define IPBYTES 4
#define SHIFT 8
#define MAXMASK 32

unsigned int ip_to_int(const String& ip);


// Constructor definition
ip::ip(const String &ip) : GenericField(), ip_name(ip) {
    mask_ip = 0;
    mask_num = 0;
}

// Destructor definition
ip::~ip() {}

// Function to convert IP string to integer representation


unsigned int ip_to_int(const String& ip){
    StringArray ip_bytes = ip.split(".");
    unsigned int ip_int = 0;
    for (unsigned int i = 0; i < IPBYTES; i++) {
        String temp = ip_bytes[i].as_string();
        int curr = temp.to_integer();
        if (curr < 0 || curr > 255) {
            // Invalid byte value
            return 0;
        }
        ip_int += (curr << ((3 - i) * SHIFT));
    }
    return ip_int;
}

bool ip::set_value(String value) {
    StringArray ip_mask = value.split("/"); // Split values
    if (ip_mask.getSize() != 2) {
        std::cerr << "Invalid format: IP/mask expected." << std::endl;
        return false;
    }
    
    String ip_string = ip_mask[0].as_string(); // Convert GenericString to String

    unsigned int int_ip = ip_to_int(ip_string);
  
    String mask_string = ip_mask[1].as_string(); // Convert GenericString to String
    int mask = mask_string.to_integer();
    if (mask < 0 || mask > MAXMASK) {
        //std::cerr << "Invalid mask value: " << mask << std::endl;
        return false;
    }

    // Calculate the mask IP by shifting the IP address to the left by (MAXMASK - mask) bits
    mask_num = mask;
    mask_ip = int_ip >> (MAXMASK - mask_num);
    return true;
}




// Match IP address with packet
bool ip::match(const GenericString& packet) const {
    String packet_str = packet.as_string();
    StringArray packet_split = packet_str.split(",");
    for (unsigned int i = 0; i < packet_split.getSize(); i++) {
        String packet_split_str = packet_split[i].as_string();
        StringArray ip_addrs = packet_split_str.split("=");
        if (ip_addrs.getSize() != 2) {
            continue; // Skip this field if it doesn't match the expected format
        }

        String ip_n = ip_addrs[0].as_string();
        String ip_v = ip_addrs[1].as_string();
        // Trim spaces from the name and value
        ip_n.trim();
        ip_v.trim();

        if (ip_n == ip_name) {
            unsigned int curr_ip = ip_to_int(ip_v); // Convert GenericString to String
            // Apply the mask to the current IP address
            unsigned int masked_curr_ip = curr_ip >> (MAXMASK - mask_num);
            // Check if the masked IP matches the masked rule IP
            if (masked_curr_ip == mask_ip) {
                return true;
            }
        }
    }
    return false;
}
