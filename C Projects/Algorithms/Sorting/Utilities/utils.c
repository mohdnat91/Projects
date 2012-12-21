#include <stdlib.h>
#include "utils.h"

int partition(void **array, compare_fn cmp, int left, int right, int pivot_idx){
	void *pivot = array[pivot_idx];

	void *temp 		 = array[right];
	array[right] 	 = array[pivot_idx];
	array[pivot_idx] = temp;

	int store = left;

	for(int i = left; i < right; i++){
		if(cmp(array[i], pivot) <= 0){
			temp = array[i];
			array[i] = array[store];
			array[store] = temp;
			++store;
		}
	}

	temp = array[right];
	array[right] = array[store];
	array[store] = temp;
	return store;
}

int select_kth(void **array, compare_fn cmp, int left, int right, int k){
	int random = (rand() % (right - left + 1)) + left;

	int pivot_index = partition(array, cmp, left, right, random);

	if (left+k-1 == pivot_index) { return pivot_index; }

	if (left+k-1 < pivot_index) {
		return select_kth (array, cmp, left, pivot_index-1, k);
	} else {
		return select_kth (array, cmp, pivot_index+1, right, k - (pivot_index-left+1));
	}
}