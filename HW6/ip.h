#ifndef IP_H
#define IP_H

//Maybe add libraries?
#include "generic-field.h"
//ip is a class inheriting from GenericField.
class ip : public GenericField {
  string ip_name;
  unsigned int mask_ip;
  int mask_num;

public :
  ip(): ip_name(nullptr), mask_ip(0), mask_nun(0){}
  ip(const string &ip);
  bool set_value(string value);
  bool match(string packet);
  ~ip()
};

#endif
