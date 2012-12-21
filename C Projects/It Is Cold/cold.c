#include <stdio.h>

int main(){
	int Teams;
	scanf("%d", &Teams);

	while(Teams-- > 0){
		int N;
		int i;
		scanf("%d", &N);

		long fans[N];

		for(i = 0; i < N; i++)
			scanf("%ld", &fans[i]);

		char temp[2];
		long long int total = 0;

		for(i = 0; i < N; i++){
			scanf("%s", temp);
			temp[1] = '\0';

			if(!strcmp("A", temp))
				fans[i] *= -1;
		}

		for(i = N-1; i >= 0; i--){
			total += fans[i];
			if(total < 0) total = 0;
		}

		printf("%lld\n", total);			
	}
}