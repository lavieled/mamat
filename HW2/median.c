// 319046504 laviel@campus.technion.ac.il lavie lederman
// 206159527 shahary@campus.technion.ac.il shahar yankelovich

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define grade range
#define MAX_GRADE 100
#define MIN_GRADE 0

static FILE *f;

int median(char *argv, int argc);
int compare(const void *a, const void *b);

int main(int argc, char **argv) {
    //decide input method
    if (argc == 1 || !strcmp("-", argv[1])) {
        f = stdin;
    } else {
        f = fopen(argv[1], "r");
    }

    // Check for errors
    if (!f) {
        fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
        return 1;
    }

    int result = median(argv[1], argc);
    printf("%d\n", result);//print median

    fclose(f);
    return 0;
}

int median(char *argv, int argc) {
    int *arr = (int *)malloc(argc * sizeof(int));//init array to sort grades
    int grade;
    int retval;
    int line = 0;

   /* for(int i=0;i < argc; ++i){
        retval = fscanf(f, "%d", &grade);
        if (retval != 1) { // Error 
            fprintf(stderr, "Error: not a number\n");
            free(arr);
            exit(1);
        }
        else if (grade < MIN_GRADE || grade > MAX_GRADE) {//check in range
            fprintf(stderr, "Error at line %d: grade %d invalid\n", (line + 1), grade);
            free(arr);
            exit(1);
        }
        else {
            arr[line] = grade;//add grade to array
            line++;
            //printf("%d\n",grade);
        }
    } */
    while (line <= argc) {
        retval = fscanf(f, "%d", &grade);
        if (retval != 1) { // Error 
            fprintf(stderr, "Error: not a number\n");
            free(arr);
            exit(1);
        }
        else if (grade < MIN_GRADE || grade > MAX_GRADE) {//check in range
            fprintf(stderr, "Error at line %d: grade %d invalid\n", (line + 1), grade);
            free(arr);
            exit(1);
        }
        else {
            arr[line] = grade;//add grade to array
            line++;
        }
        
    } 

    int median;
    qsort(arr, line, sizeof(int), compare);//sort array to easily find median
    median = arr[(line) / 2];//choose median from sorted array
    free(arr);
    return median;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}//cmp func for qsort
