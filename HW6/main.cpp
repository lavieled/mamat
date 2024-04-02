#include <iostream>
#include "input.h"
#include "string.h"
#include "port.h"
#include "ip.h"
#include "string-array.h"


int main(int argc, char **argv){
    //check input???
    String input(argv[1]);
    StringArray rule;
    //read rule
    rule = input.split("=");
    String name = (rule[0]).trim();
    String val = rule[1];
    if(name == "src-ip" || name == "dst-ip"){
        ip main_ip(name);
        main_ip.set_value(val);
        parse_input(main_ip);
    }

    if(name == "src-port" || name == "dst-port"){
        port main_port(name);
        main_port.set_value(val);
        parse_input(main_port);

    }
    return 0;
}//shahar didnt even see my last joke:(
