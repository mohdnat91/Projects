#include "../Utilities/utils.h"
#include <stdlib.h>

void quick_sort(void **array, compare_fn cmp, int left, int right){
	if(right <= left) return;

	int pivot_index = (rand() % (right - left + 1)) + left;
	pivot_index = partition(array, cmp, left, right, pivot_index);

	quick_sort(array, cmp, left, pivot_index-1);
	quick_sort(array, cmp, pivot_index+1, right);
}


#ifdef TEST

#include <stdio.h>

int compare(const void *x, const void *y){
	return *((int *)x) > *((int *)y);
}

int main(){

	int **test;
	int length = 10;

	test = malloc(length * sizeof(int));

	srand(20);

	for(int i = 0; i < length; i++){
		test[i] = malloc(sizeof(int));
		*(test[i]) = rand() % 300;
		printf("%03d ", *(test[i]));
	}	
	printf("\n");

	quick_sort((void **)test, compare, 0, length-1);

	for(int i = 0; i < length; i++){
		printf("%03d ", *(test[i]));
	}	
	printf("\n=======\n");

	// int fourth = select_kth((void **)test, compare, 0, length-1, 7);

	// printf("The 7th element is %d\n", *(test[fourth]));

	free(test);
}

#endif