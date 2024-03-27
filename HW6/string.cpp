//Lavie Lederman 319046504
//Shahar Yankelovich 206159527
//
#include "generic-string.h"
#include "string.h"
#include "string_array.h"
#include <iostream>
#include <string.h>
#include <cstring>
using std::cout;
using std::endl;


//global function
GenericString* make_string(const char *str) {
    return new String(str); // Create a String object using the provided C-style string
}

//constructors and destructor
String::String() {
    data = new char [1];
    data[0] = '\0';
    length = 0;
}

String::String(const String &str){
   if(str.data == NULL){
        return;
    }
    data = new char[str.length + 1];// Allocate memory
    length = str.length;// Copy length
    strcpy(data, str.data);// Copy data
}

String::String(const char *str){
    length = strlen(str);// Copy length
    data = new char[length + 1];// Allocate memory
    strcpy(data, str);// Copy data
}

String::~String(){
        delete[] data;//free memory
}
//assigment operators
String& String::operator=(const String &rhs){
    if(this != &rhs){
        delete[] data; // Free memory
        length = rhs.length; // Copy length
        data = new char[length + 1]; // Allocate memory
        strcpy(data, rhs.data); // Copy data
    }
    return *this;
    }

String& String::operator=(const char *str){
    length = strlen(str);
    data = new char[length + 1];// Allocate memory
    strcpy(data, str);// Copy data
    return *this;
}
//equal operators
bool String::operator==(const GenericString &rhs) const{

    if(length == rhs.as_string().length){
        if( strcmp(data, rhs.as_string().data) ){
            return true;
        }
    }
    return false;
}

bool String::operator==(const char *str) const{
    if(length == strlen(str)){
        if( strcmp(data, str) ){
            return true;
        }
    }
    return false;
}
//split function turning string into array of substrings divided by delimiters
StringArray String::split(const char *delimiters) const {
    StringArray result;//create array
    char *token = strtok(data, delimiters);//use strtok to find delimiters
    while (token != nullptr) {
        result.push_back(String(token));//add new string to array
        token = strtok(nullptr, delimiters);//search for next string
    }
    //run until done, return string array
    return result;

}
//return number string as integer
int String::to_integer() const {
    return atoi(data);
}
//cut out empty spaced on the outside of strings
String& String::trim(){
    int left = 0;
    int right = length - 1;
    //left white spaces
    while(data[left] == ' '){
        left++;
    }

    if(left ==(int)length){
        return *this;
    }

    //right white spaces
    while(data[right] == ' ') {
        right--;
    }
    //calc new string length
    int new_length = right - left + 2;
    char *new_data = new char[new_length];
    int j = 0;
    //copy only relevant part of string
    for(int i = left; i<=right; i++){
        new_data[j] = data[i];
        j++;
    }
    new_data[j] = '\0';
    //update string to leaner version, delete temp memory
    delete[] data;
    length = new_length;
    data = new char[length + 1];// Allocate memory
    strcpy(data, new_data);// Copy data
    delete[] new_data;

    return *this;

}
//casts generic-string into string
String& String::as_string(){
    String& str = dynamic_cast<String&>(*this);
    return str;
}
String& String::as_string() const{
    String& str = const_cast<String&>(*this);
    return str;
}
