#include <stdio.h>

int main(){
	int c = 1;
	int n0;
	
	while(1){
		scanf("%d", &n0);
		if(n0 == 0) break;

		if(n0 & 1)
			printf("%d. odd %d\n", c++, (n0-1)/2);
		else
			printf("%d. even %d\n", c++, n0/2);
	}

	return 0;
}