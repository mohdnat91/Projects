typedef int(*compare_fn)(const void *,const void *);

int partition(void **array, compare_fn cmp, int left, int right, int pivot_idx);
int select_kth(void **array, compare_fn cmp, int left, int right, int k);