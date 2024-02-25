// 319046504 laviel@campus.technion.ac.il lavie lederman
// 206159527 shahary@campus.technion.ac.il shahar yankelovich

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
        if (!strcmp(argv[i], "-")) { //If the string is a "-"
            f = stdin;
        } //choose num of bins for hist
        else if (!strcmp(argv[i], "-n_bins")) {
            nbins = i<argc-1 ? atoi(argv[i+1]): NBINS;
            i++;
        }
         else {//open file and read from it
            f = fopen(argv[i], "r");
        }
    }
}

int main(int argc, char **argv) {
    parse_arg(argc, argv);
    if (!f) {//check for error
    fprintf(stderr, "File not found: \"%s\"\n", argv[1]);
    return 1;
}
/* Initiate histogram */
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
    int line = 1; //the first grade is at location 1 and not 0
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
//check if input is in the grades' range
    if(grade < MIN_GRADE || grade > MAX_GRADE){ //Not in range
        fprintf(stderr, "Error at line %d: grade %d invalid\n", line, grade);
        exit(1);
    } else{
        line++;
    }
        //*******************
        //Need to add a way to insert grades into the last bin. grade 100 doesnt appear in hist
        //*******************
    int n = grade / (MAX_GRADE / nbins);//calc to what bin the grade belongs
    bins [n]++;

}//print bins
    pace = MAX_GRADE /nbins;
    for (int i=0; i<nbins; ++i) {
        printf("%.0lf-%.0lf\t%d\n", i * pace,
            (i < nbins - 1)? ((i+1) * pace-1) : MAX_GRADE, bins[i]);
    }
}
