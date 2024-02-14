#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mean(FILE *f);

int main(int argc, char **argv) {
    FILE *f;

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
    int line_n = 0;
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
        avg += grade;
        line_n++;
    }
    printf("%.2lf\n", (avg / line_n));
}
