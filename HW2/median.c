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
    int retval =0;

    // Decide input method
    if (argc == 1 || !strcmp("-", argv[1])) {
        f = stdin;
    } else {
        f = fopen(argv[1], "r");
    }

    // Check for errors opening the file
    if (f == NULL) {
        fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
        return 1;
    }

    // Count grades in a loop
    while (retval != EOF) {
        retval = fscanf(f, "%d", &grade);
        num_grades++;
    }
    num_grades--;
    if (num_grades == 0) {
        fprintf(stderr, "Error: Empty file\n");
        fclose(f);
        return 1;
    }

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
        if (fscanf(f, "%d", &grades[i]) != 1) {
            // Handle potential error reading a grade (e.g., non-numeric input)
            fprintf(stderr, "Error reading grade\n");
            // ... (consider handling or skipping the invalid input)
        }
    }

    // Sort the array
    qsort(grades, num_grades, sizeof(int), compare);

    // Calculate and print the median
    int median = grades[(num_grades + 1) / 2];
    printf("%d\n", median);

    // Free memory and close the file
    free(grades);
    fclose(f);

    return 0;
}
