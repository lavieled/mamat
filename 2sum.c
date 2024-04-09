#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 10000

typedef struct {
    int value;
    int index;
} NumberWithIndex;

void twoSum(int nums[], int nums_size, int target);
int compare(const void *a, const void *b);//compare func for quick sort

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;

	scanf("%d", &target);//target num

	while (scanf("%d", &nums[array_size++]) == 1);//get array
	array_size--;

	twoSum(nums, array_size, target);

	return (0);
}

void twoSum(int nums[], int nums_size, int target) {
    NumberWithIndex numbers[MAX_ARRAY_SIZE];

    for (int i = 0; i < nums_size; i++) {
        numbers[i].value = nums[i];
        numbers[i].index = i;
    }
    qsort(numbers, nums_size, sizeof(NumberWithIndex), compare);
    //using built in qsort function
    int l_index = -1, r_index;

     for(int j = 0; j < nums_size; j++){
         int new_target = target - numbers[j].value;//calc new target for binary search on sorted array
         NumberWithIndex *second_in = bsearch(&new_target, numbers, nums_size
                                       , sizeof(NumberWithIndex), compare);
         //binary search on sorted array to find the other number
         /*if(second_in != NULL && second_in != j){//check if bin-search was successful
             /*for(int k = 0; k < nums_size; k++){
                 if((nums[k] == arr[j] || arr[*second_in] == nums[k]) && l_index == -1){//find the left index of the 2 numbers to return
                     l_index = k;
                 }
                 else if(nums[k] == arr[j] || arr[*second_in] == nums[k]){//find the right index of the numbers
                     r_index = k;
                     printf("(%d, %d)\n", l_index, r_index);//print result
                     return;
                 }
             }
         }
     }*/
if (second_in != NULL && second_in != &numbers[j]) {
             l_index = numbers[j].index;
             r_index = second_in->index;
             if (l_index > r_index) {
                 int temp = l_index;
                 l_index = r_index;
                 r_index = temp;
             }
             printf("(%d, %d)\n", l_index, r_index);
             return;
         }
     }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}