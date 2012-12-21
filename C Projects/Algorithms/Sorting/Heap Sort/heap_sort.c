#include <utils.h>

static void heapify(void **array, int current, int length, compare_fn cmp){
	int first_child = 2 * current + 1;
	int second_child = 2 * current + 2;

	int largest = current;

	if(first_child < length && cmp(array[largest], array[first_child]) < 0)
		largest = first_child;

	if(second_child < length && cmp(array[largest], array[second_child]) < 0)
		largest = second_child;

	if(largest != current){
		void *temp = array[current];
		array[current] = array[largest];
		array[largest] = temp;

		heapify(array, largest, length, cmp);
	}
}

static void build_heap(void **array, int length, compare_fn cmp){
	int start = length/2 - 1;

	for(int i = start; i >= 0; i--)
		heapify(array, i, length, cmp);
}

void heap_sort(void **array, int length, compare_fn cmp){
	build_heap(array, length, cmp);

	for(int i = length - 1; i > 0; i--){
		void *temp = array[i];
		array[i] = array[0];
		array[0] = temp;

		build_heap(array, i, cmp);
	}
}

#ifdef TEST

#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y){
	int temp = *((int *)x) > *((int *)y);
	if(temp == 1) return 1;
	temp = *((int *)x) < *((int *)y);
	if(temp == 1) return -1;
	return 0;
}

int main(){

	int **test;
	int length = 30;

	test = malloc(length * sizeof(int *));

	srand(20);

	for(int i = 0; i < length; i++){
		test[i] = malloc(sizeof(int));
		*(test[i]) = rand() % 300;
		printf("%03d ", *(test[i]));
	}	
	printf("\n");

	heap_sort((void **)test, length, compare);

	for(int i = 0; i < length; i++){
		printf("%03d ", *(test[i]));
		free(test[i]);
	}	
	printf("\n");

	free(test);
}

#endif