// 319046504 laviel@campus.technion.ac.il lavie lederman
// 206159527 shahary@campus.technion.ac.il shahar yankelovich

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define grade range
#define MAX_GRADE 100
#define MIN_GRADE 0

void mean(FILE *f);

int main(int argc, char **argv) {
    FILE *f;
    //decide input method
    if(argc == 1 || !strcmp("-", argv[1])){
        f = stdin;
    }
    else{
        fopen(argv[1], "r");
    }
    //check for errors
    if(!f){
        fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
        return 1;
    }
    mean(f);
    return 0;
}
void mean(FILE *f){
    int grade;
    int retval;
    double avg = 0;
    double line = 1;
    while(1){
        retval = fscanf(f, "%d", &grade);
        if(retval == EOF){
            break;//finished
        }
        else if(retval != 1){
            //error
            fprintf(stderr, "Error: not a number\n");
            exit(1);
        }
        //Check grade's validity
        if (grade > MAX_GRADE || grade < MIN_GRADE) {
            fprintf(stderr, "Error in line %.0f: grade %d invalid\n", line, grade);
            exit(1);
        }
        else {
        avg += grade;
        line++;
        }
    }
    //print the average
    printf("%.2lf\n", (avg / (line-1)));
}
