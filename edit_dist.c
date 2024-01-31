#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

int edit_dist(char word1[], char word2[]);
int get_min(int a, int b, int c);

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
	int ** str_mat = (int **)malloc((strlen(word1)) + 2)*sizeof(int*); //dynamically allocate a matrix
	if (matrix == NULL) { //check that allocation succeeded
		printf("error/n");
	}
	for (int i = 0; i < strlen(word1); i++) { //dynamically allocate an array
        matrix[i] = (int *)malloc((strlen(word2) + 2) * sizeof(int));
		if (matrix[i] == NULL) { //check that allocation succeeded
		printf("error/n");
		}
	}
	//initialize the matrix to zeros
	for ( int i = 0; i < (strlen(word1)) + 2); i++) { 
		for (int j = 0; i < (strlen(word2)) + 2); i++) {
			matirx[i][j] = {0};
		}
	}
	//set the upper row to be word1
	for ( int i = 2; i < strlen(word1); i++) { 
		matrix[0][i] = word1[i-2];
	}
	//set the left column to be word2
	for ( int i = 2; i < strlen(word2); i++) { 
		matrix[i][0] = word2[i-2];
	}
	//calculate the matrix
	for ( int i = 1; i < (strlen(word1)) + 2); i++) {
		for ( int j = 1; j < (strlen(word2)) + 2); j++) {
			//the distance between two empty strings is zero
			if (i == 1 && j == 1) {
				continue;
			}
			//the first calculated row
			else if (i == 1) {
				matrix[i][0] = matrix[0][j] ? matrix[i][j] = matirx[i][j-1];
			}
			else if (j == 1) {
				matrix[0][j] = matrix[i][0] ? matrix[i][k] = matrix[i-1][k];
			}
			else {
				matrix[i][j] = get_min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
			}
		}
	}
	for (int i = 0; i < strlen(word1); i++) { //free the arrays
		free (matrix[i]);
	}
	free (matrix); //free the main array of the matrix
}

int get_min(int a, int b, int c) {
	return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}
