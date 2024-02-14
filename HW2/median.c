#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRADE 100
#define MIN_GRADE 0

static FILE *f;

int median(char *argv, int num_elements);
int compare(const void *a, const void *b);

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

    return median(argv[1], argc);
}

int median(char *argv, int num_elements){
    int *arr = (int *)malloc(num_elements*sizeof(int));
    int grade;
    int retval;
    int line = 1; 
    while (1) {
        retval = fscanf(f, "%d", &grade);
        if (retval == EOF) {
            break; /* Finished */
        } 
        else if (retval != 1) { /* Error */
        fprintf(stderr, "Error: not a number\n");
        exit(1);
    }
/* Find bin */
    if(grade < MIN_GRADE || grade > MAX_GRADE){
        fprintf(stderr, "Error at line %d: grade %d invalid\n", line, grade);
        exit(1);
    }
     else{
        arr[line-1] = grade;
    }
}
    int median;
    qsort(arr, num_elements, sizeof(int), compare);
    median = arr[((num_elements+1)/2)];
    return median;

}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
