#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

int edit_dist(char word1[], char word2[]);
int min3(int a, int b, int c);

int main() {
    char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];

    fgets(word1, MAX_WORD_LEN, stdin);
    word1[strlen(word1) - 1] = '\0';
    fgets(word2, MAX_WORD_LEN, stdin);
    word2[strlen(word2) - 1] = '\0';

    printf("%d\n", edit_dist(word1, word2));

    return (0);
} 

int edit_dist(char word1[], char word2[]) {
    /* YOUR CODE HERE */
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
    if(word1_len == 0 && word2_len == 0){
        return 0;
    }//check if finished both strings
    else if(word1_len == 0) {
        return word2_len;
    }
    else if(word2_len == 0) {
        return word1_len;
    }
    //checking if done with one of the strings
    else if(word1[0] == word2[0]) {
        return edit_dist(word1 + 1, word2 + 1);
    }
    else{
        return 1 + min3(edit_dist(word1 + 1, word2),
                    edit_dist(word1, word2 + 1),
                    edit_dist(word1 + 1, word2 + 1));//checking best possible edit_dist
    }
}
int min3(int a, int b, int c){
        int minimum = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
        return minimum;
    }
