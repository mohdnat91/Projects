#include <stdio.h>
#include <stdlib.h>

int **x;
int W;
int H;
int num;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

void count(int r, int c, int depth){
	int found = 0;

	int val = x[r][c];

	int i = 0, j = 0;
	for(; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
		if(val > x[nr][nc]) {
			count(nr, nc, depth+1);
			found = 1;
		}
	}

	if(!found) num++;
}

int main(){
	int n_cases;
	scanf("%d", &n_cases);

	int c = 1;

	while(n_cases-- > 0){
		int N;
		int M;

		num = 0;

		scanf("%d %d", &N, &M);
		int **board;

		int i = 0, j = 0;

		board = calloc(N, sizeof(int *));

		for(i = 0; i < N; i++){
			board[i] = calloc(M, sizeof(int));
			for(j = 0; j < M; j++)
				scanf("%d", &board[i][j]);
		}

		W = M;
		H = N;
		x = board;

		i = 0;
		j = 0;

		for(; i < N; i++)
			for(j = 0; j < M; j++){
				int val = board[i][j];
				int largest = 1;
				int k = 0;
				for(; k < 4; k++){
					int nr = i + dr[k];
					int nc = j + dc[k];
					if(nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
					if(board[nr][nc] > val){
						largest = 0;
						break;
					}
				}
				if(largest) count(i, j, 1);
			}

		printf("Case #%d: %d\n", c++, num);
	}
}