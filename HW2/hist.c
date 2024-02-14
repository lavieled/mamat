#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBINS 10
#define MAX_GRADE 100
#define MIN_GRADE 0

static FILE *f;
static int nbins = NBINS;

void operate(int *bins);


void parse_arg(int argc, char **argv) {
    f = stdin;
    for (int i=1; i<argc; ++i) {
        if (!strcmp(argv[i], "-")) {
            f = stdin;
        } else if (!strcmp(argv[i], "-n_bins")) {
            nbins = i<argc-1 ? atoi(argv[i+1]): NBINS;
            i++;
        } else {
            f = fopen(argv[i], "r");
        }
    }
}
int main(int argc, char **argv) {
    parse_arg(argc, argv);
/* Must check for errors... */
    if (!f) {
    fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
    return 1;
}
/* Initiate array */
    int *bins = (int *)malloc(sizeof(int)*nbins);
    for (int i=0; i<nbins; ++i) {
        bins[i] = 0;
    }
    operate (bins);
    free (bins);
}

void operate (int *bins) {
    int grade;
    int retval;
    int line = 1; 
    double pace;
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
    } else{
        line++;
    }
    int n = grade / (MAX_GRADE / nbins);
    bins [n]++;
/* Print bins */
}
    pace = MAX_GRADE /nbins;
    for (int i=0; i<nbins; ++i) {
        printf("%.0lf-%.0lf\t%d\n", i * pace,
            (i < nbins - 1)? ((i+1) * pace-1) : MAX_GRADE, bins[i]);
    }
}
