//
// Created by llede on 25/03/2024.
//
#include "generic-string.h"
#include "string.h"
#include <iostream>
#include <string.h>
#include <cstring>
using std::cout;
using std::endl;


//global functions
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
StringArray String::split(
        const char *delimiters, String **output, size_t *size) const {

}
int String::to_integer() const {
    return atoi(data);
}
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

    //trailing white spaces
    while(data[right] == ' ') {
        right--;
    }

    int new_size = right - left + 2;
    char *new_data = new char[new_size];
    int j = 0;
    for(int i = left; i<=right; i++){
        new_data[j] = data[i];
        j++;
    }
    new_data[j] = '\0';
    delete[] data;
    length = new_size;
    data = new char[length + 1];// Allocate memory
    strcpy(data, new_data);// Copy data
    delete[] new_data;

    return *this;

}

String& String::as_string(){

}
String& String::as_string() const{

}

