// 319046504 laviel@campus.technion.ac.il lavie lederman
// 206159527 shahary@campus.technion.ac.il shahar yankelovich

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRADE 100
#define MIN_GRADE 0

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char **argv) {
    FILE *f;
    int num_grades = 0;
    int *grades;
    int grade;
    int retval = 0;

    // Decide input method
    if (argc == 1 || !strcmp("-", argv[1])) {
        f = stdin;
    } else {
        f = fopen(argv[1], "r");
    }
    // Check for errors opening the file
    if (f == NULL) {
        fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
        fclose(f);
        return 1;
    }
    // Count grades in a loop
    while (retval != EOF) {
        retval = fscanf(f, "%d", &grade);
        num_grades++;
    }
    num_grades--;
    // Allocate memory for grades
    grades = (int *)malloc(num_grades*sizeof(int));
    if (grades == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(f);
        return 1;
    }
    // Rewind the file pointer
    fseek(f, 0, SEEK_SET);
    // Read grades into the array
    for (int i = 0; i < num_grades; i++) {
        fscanf(f, "%d", &grades[i]);
    }
    // Sort the array
    qsort(grades, num_grades, sizeof(int), compare);
    int median;
    //check if even or odd array to choose correct median
    if(num_grades % 2){
        median = grades[num_grades / 2];
    }
    else{
        median = grades[(num_grades / 2) - 1];
    }
    //print median
    printf("%d\t", median);
    // Free memory and close the file
    free(grades);
    fclose(f);

    return 0;
}
