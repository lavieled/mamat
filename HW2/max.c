// 319046504 laviel@campus.technion.ac.il lavie lederman
// 206159527 shahary@campus.technion.ac.il shahar yankelovich

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRADE 100
#define MIN_GRADE 0
//definitions for grade range
void max(FILE *f);

int main(int argc, char **argv) {
    FILE *f;
    //check input method
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
    max(f);//prints max
    return 0;
}
void max(FILE *f){
    int grade;
    int retval;
    int max = -1;
    int line = 1;
    while(1){
        retval = fscanf(f, "%d", &grade);
        if(retval == EOF){
            break;//finished
        }
        else if(retval != 1){//error
            
            fprintf(stderr, "Error: not a number\n");
            exit(1);
        }
        if (grade < MIN_GRADE || grade > MAX_GRADE) {//not in grade range
            fprintf(stderr, "Error at line %d: grade %d invalid\n", line, grade);
            exit(1);
        }
        if(grade > max){//update max
            max = grade;
        }
        line++;

    }
    printf("%.d\n", max);
}
