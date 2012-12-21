#include <stdio.h>
#include <string.h>

int best;
int d[4] = {-2, -1, 1, 2};

void process(char *tiles, int length, int prev_move, int frog, int current_moves);
int is_correct(char *tiles, int length);

int main(){
	int c = 1;
	while(1){
		char tiles[101];
		scanf("%s", tiles);
		int length = strlen(tiles);
		int frog = 0;

		if(tiles[0] == '-') break;

		for(; frog < length; frog++)
			if(tiles[frog] == 'F') break;

		best = 999999999;

		process(tiles, length, 0, frog, 0);

		if(best == 999999999) best = -1;

		printf("%d. %d\n", c++, best);
	}
}

void process(char *tiles, int length, int prev_move, int frog, int current_moves){
	if(is_correct(tiles, length)) {
		best = best < current_moves ? best : current_moves;
		return;
	}

	if(current_moves == 9) return;

	int i = 0;
	for(; i < 4; i++){
		int c = d[i];
		if(c + prev_move == 0) continue;
		int idx = c + frog;
		if(idx < 0 || idx >= length) continue;
		char temp = tiles[idx];
		tiles[idx] = 'F';
		if(c == 1 || c == -1){
			tiles[frog] = temp;
		} else {
			tiles[frog] = temp == 'B' ? 'W' : 'B';
		}
		process(tiles, length, c, idx, current_moves+1);
		tiles[frog] = 'F';
		tiles[idx] = temp;
	}
}

int is_correct(char *tiles, int length){
	int i = 0;

	for(; i < length; i++)
		if(tiles[i] == 'B') break;

	for(; i < length; i++)
		if(tiles[i] == 'W') break;

	for(; i < length; i++)
		if(tiles[i] == 'B') break;

	return i == length;
}