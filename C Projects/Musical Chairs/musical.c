#include <stdio.h>

int main(){
	while(1){
		int N;
		int D;
		scanf("%d %d", &N, &D);
		if(N == 0 && D == 0) break;
		int chairs[N];
		int i = 0;

		int X = N;

		for(; i < N; i++)
			chairs[i] = 0;

		D = D % N;

		int CD = D;

		for(i = 0; i < N && X != 1; i++){
			if(chairs[i])
				goto q;
			CD--;
			if(CD == 0){
				chairs[i] = 1;
				CD = D;
				X--;
			}
q:			if(i == N-1) i = -1;
		}

		for(i = 0; i < N; i++)
			if(!chairs[i]){
				printf("%d %d %d\n", N, D, i+1);
				break;
			}
	}
}