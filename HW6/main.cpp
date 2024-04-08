#include <iostream>
#include "input.h"
#include "generic-field.h"
#include "generic-string.h"
#include "string.h"
#include "port.h"
#include "ip.h"
#include "string-array.h"


int main(int argc, char **argv) {
 
    if(argc != 2){
        return 1;
    }
    String input(argv[1]);
    
    //String input("src-ip=241.1.205.106/32");
    StringArray rule = input.split("=");

    if (rule.getSize() < 2) {
        std::cerr << "Invalid input format: " << std::endl;
        return 1;
    }

    String name = rule[0].trim();
    String val = rule[1].trim();

    if (name == "src-ip" || name == "dst-ip") {
        ip main_ip(name);
        main_ip.set_value(val);
        parse_input(main_ip);
    }

    if (name == "src-port" || name == "dst-port") {
        port main_port(name);
        main_port.set_value(val);
        parse_input(main_port);
    }

    return 0;
}
