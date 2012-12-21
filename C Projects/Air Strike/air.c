#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141

typedef struct dist{
	double dist1;
	double dist2;
} dist; 

typedef struct point{
	double x;
	double y;
} point ;

int cmp_1(const void *dv, const void *dv2){
	const dist *d = (const dist *)dv;
	const dist *d2 = (const dist *)dv2;
	return d2->dist1 - d->dist1;
}

int cmp_2(const void * dv, const void *dv2){
	const dist *d = (const dist *)dv;
	const dist *d2 = (const dist *)dv2;
	return d->dist2 - d2->dist2;
}

double calc(point p1, point p2){
	return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

int main(){
	int N;
	double E;
	point tower1;
	point tower2;
	point current;

	int c = 1;

	while(1){
		scanf("%d", &N);
		if(N == 0) break;
		scanf("%lf %lf %lf %lf %lf", &(tower1.x), &(tower1.y), &(tower2.x), &(tower2.y), &E);

		dist array[N];

		int i = 0;
		for(; i < N; i++){
			scanf("%lf %lf", &(current.x), &(current.y));
			array[i].dist1 = calc(current, tower1);
			array[i].dist2 = calc(current, tower2);
		}

		qsort(array, N, sizeof(dist), cmp_1);

		i = 0;

		int best = 0;

		for(; i < N; i++){
			double r = array[i].dist1;
			double area1 = PI * r * r;
			if(area1 > E) continue;
			double area2 = E - area1;
			double r2 = sqrt(area2/PI);
			int j = 0;
			int count = 0;
			for(; j < N; j++){
				if(array[j].dist1 <= r || array[j].dist2 <= r2) count++;
			}

			best = count > best ? count : best;
		}

		qsort(array, N, sizeof(dist), cmp_2);

		i = 0;

		for(; i < N; i++){
			double r = array[i].dist2;
			double area1 = PI * r * r;
			if(area1 > E) continue;
			double area2 = E - area1;
			double r2 = sqrt(area2/PI);
			int j = 0;
			int count = 0;
			for(; j < N; j++){
				if(array[j].dist2 <= r || array[j].dist <= r2) count++;
			}

			best = count > best ? count : best;
		}

		printf("%d. %d\n", c++, N - best);
	}
}