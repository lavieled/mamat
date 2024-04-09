// 319046504, 206159527 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define HISTOGRAM_SIZE 10


int main() {

    int histogram[10] = {0};

    while(1){
        char x = getchar();
        if(x == EOF){
            break;
        }
        if((int)x < (int)'0' || (int)x > (int)'9'){//check if the current char is a number on ASCII
            continue;
        }
        histogram[(int)x - (int)'0']++;//increase the histogram accordingly
    }

    for(int i = 0; i < HISTOGRAM_SIZE; i++){
        printf("%d%s",histogram[i], i < 9 ? " " : "");//print result
    }
    printf("\n");
}
