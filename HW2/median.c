#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int median(int *argv, int num_elements);
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

int median(int *argv, int num_elements){

    int *arr = argv;
    int median;
    arr = (int *)malloc(num_elements*sizeof(int));
    qsort(arr, num_elements, sizeof(int), compare);
    median = arr[(num_elements+1)/2];
    return median;

}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
