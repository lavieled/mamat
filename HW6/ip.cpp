//Lavie Lederman 319046504
//Shahar Yankelovich 206159527


#include "ip.h"

#define IPBYTES 4
#define SHIFT 8
#define MASKMAX 32

// Constructor definition
ip::ip(const String &ip) : GenericField(){
    ip_name = ip;
    mask_ip = 0;
    mask_num = 0;
}

ip::~ip(){}

// set_value function definition
unsigned int ip::ip_to_int(String &ip){
    StringArray ip_bytes;
    ip = ip.trim();
    ip_bytes = ip.split(".");
    unsigned int ip_int = 0;
    int curr;
    for (int i = 0; i < IPBYTES ; i++ ) {
        curr = ip_bytes[i].to_integer();
        ip_int += (curr << ((3 - i) * SHIFT));
        //ip_int |= (curr << ((3 - i) * SHIFT));
    }
    return ip_int;
}

bool ip::set_value(String value) {
    StringArray ip_mask;
    ip_mask = value.split("/");//split values
    unsigned int int_ip = ip_to_int(ip_mask[0]);//the ip
    unsigned int mask = ip_mask[1].to_integer();//mask num
    //checks that we got a valid mask number
    if(mask < 0 || mask > MASKMAX){
        return false;
    }
    //update ip according to mask
    mask_num = mask;
    mask_ip = int_ip >> (MASKMAX - mask_num);
    return true;

}
bool ip::match(const GenericString& packet) const {
    String const &packet_str = packet.as_string();
    StringArray packet_split, ip_addrs;
    if(packet == ""){
        return false;
    }//check for empty string
    //split to fields
    packet_split = packet_str.split(",");
    for(unsigned int i=0; i < packet_split.getSize(); i++){
        packet_split[i] = packet_split[i].trim();
        //split to name & value
        ip_addrs = packet_split[i].split("=");
        ip_addrs[0] = ip_addrs[0].trim();
        if(ip_addrs[0] == ip_name){
            unsigned int curr_ip = ip_to_int(ip_addrs[1]);
            //remove the unwanted number of bits
            curr_ip = curr_ip >> (MASKMAX - mask_num);
            //returns true if the ip number meets the rule
            return (curr_ip == mask_ip);
        }
    }
    return false;
}
