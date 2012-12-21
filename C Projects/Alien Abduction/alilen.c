#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} pos;

int manhatten(pos p1, pos p2){
	return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

int main(){
	int ncases;
	scanf("%d", &ncases);

	int cc = 1;
	while(ncases-- > 0){
		int N, Q, W, H;

		scanf("%d %d %d %d", &N, &Q, &W, &H);

		pos positions[N];

		int i = 0;
		for(; i < N; i++)
			scanf("%d %d", &(positions[i].x), &(positions[i].y));

		int a, b, c, d, e, f, E;
		pos alien;

		int count = 0;

		while(Q-- > 0){
			scanf("%d %d", &(alien.x), &(alien.y));

			scanf("%d %d %d %d %d %d %d", &E, &a, &b, &c, &d, &e, &f);

			if(count >= 50000) continue;
			i = 0;
			for(; i < N; i++){

				if(manhatten(alien, positions[i]) <= E){
					int nx = (positions[i].x * a + positions[i].y * b + (i+1) * c) % W;
					int ny = (positions[i].x * d + positions[i].y * e + (i+1) * f) % H;
					positions[i].x = nx;
					positions[i].y = ny;
					count++;
				}
			}
		}

		printf("Case #%d:\n", cc++);

		i = 0;
		for(; i < N; i++)
			printf("%d %d\n", positions[i].x, positions[i].y);

	}
}