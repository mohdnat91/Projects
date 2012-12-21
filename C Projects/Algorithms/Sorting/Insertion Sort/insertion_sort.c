#include "insertion_sort.h"
#include <string.h>
#include <stdlib.h>

void inversion_sort_pointers(void **array, int length, compare_fn cmp){
	for (int j = 1; j < length; j++) {
		int i = j-1;
		void *value = array[j];
		while (i >= 0 && cmp(array[i], value)> 0) {
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = value;
	}
}

void inversion_sort_values(void* first, int length, int element_size, compare_fn cmp){
	void *saved = malloc(element_size);
	for (int j = 1; j < length; j++) {
	/* start at end, work backward until smaller element or i < 0. */
		int i = j-1;
		void *value = first + j * element_size;
		while (i >= 0 && cmp(first+i*element_size, value) > 0) { i--; }
		if(++i == j) continue;
		memmove (saved, value, element_size);
		memmove (first+(i+1)*element_size, first+i*element_size, element_size*(j-i));
		memmove (first+i*element_size, saved, element_size);
	}
	free (saved);
}

#ifdef TEST

#include <stdio.h>

int compare(const void *x, const void *y){
	return *((int *)x) > *((int *)y);
}

// int main(){

// 	int **test;
// 	int length = 30;

// 	test = malloc(length * sizeof(int));

// 	srand(20);

// 	for(int i = 0; i < length; i++){
// 		test[i] = malloc(sizeof(int));
// 		*(test[i]) = rand() % 300;
// 		printf("%03d ", *(test[i]));
// 	}	
// 	printf("\n");

// 	inversion_sort((void **)test, length, compare);

// 	for(int i = 0; i < length; i++){
// 		printf("%03d ", *(test[i]));
// 		free(test[i]);
// 	}	
// 	printf("\n");

// 	free(test);
// }

int main(){

	int *test;
	int length = 30;

	test = malloc(length * sizeof(int));

	srand(20);

	for(int i = 0; i < length; i++){
		test[i] = rand() % 300;
		printf("%03d ", test[i]);
	}	
	printf("\n");

	inversion_sort_values((void *)test, length, sizeof(int), compare);

	for(int i = 0; i < length; i++){
		printf("%03d ", test[i]);
	}	
	printf("\n");

	free(test);
}

#endif