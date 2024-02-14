#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRADE 100
#define MIN_GRADE 0

static FILE *f;

int median(char *argv, int num_elements);
int compare(const void *a, const void *b);

int main(int argc, char **argv) {
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
    printf("Median: %d\n", result);

    fclose(f);
    return 0;
}

int median(char *argv, int num_elements) {
    int *arr = (int *)malloc(num_elements * sizeof(int));
    int grade;
    int retval;
    int line = 0;

    while (1) {
        retval = fscanf(f, "%d", &grade);
        if (retval == EOF) {
            break; /* Finished */
        } else if (retval != 1) { /* Error */
            fprintf(stderr, "Error: not a number\n");
            exit(1);
        }

        /* Find bin */
        if (grade < MIN_GRADE || grade > MAX_GRADE) {
            fprintf(stderr, "Error at line %d: grade %d invalid\n", line, grade);
            exit(1);
        } else {
            arr[line++] = grade;
        }
    }

    int median;
    qsort(arr, line, sizeof(int), compare);
    median = arr[(line + 1) / 2];
    free(arr);
    return median;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
