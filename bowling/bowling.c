// ver1 : check for input validity (can't handle char) distinguish cases and only print when not stirke nor spare.

#include <stdio.h>
#include <stdbool.h>

#define FRAME 13
#define CAST 2

// 반환: strike or not
int strike(int frame, int strike_in_row);
int spare(int frame);
int bowl(int frame, int cast, int score);
void calc_frame(int frame);
void print_board(int frame);

int board[FRAME][CAST] = {0, };
int board_tot[FRAME] = {0, };

int main(void)
{
	int frame = 0;
	//int cast = 0;
	bool was_strike = 0;
	bool was_spare = 0;
	int strike_in_row = 0;
	int score = 0;
	
	for (; frame < FRAME; ++frame) {
		for (int cast = 0; cast < CAST; ++cast) {
			if (cast == 0) {
				while (true) {
					printf("%d frame first cast : ", frame+1);
					scanf("%d", &score);
					
					if (score >= 0 && score <= 10) break;
					else printf("** Invalid score. Please try again (1~10) **\n\n");
				}
				
				if (was_strike = bowl(frame, cast, score)) {
					// strike
					++strike_in_row;
					strike(frame, strike_in_row);
					printf("strike\n");
					
				} else {
					// normal first throw
					strike_in_row = 0;
				}
			} else {
				if (was_strike) break;
				
				while (true) {
					printf("%d frame second cast : ", frame+1);
					scanf("%d", &score);
					
					bool score_out_range = false;
					
					if (score >= 0 && score > 10) score_out_range = true;
					
					if (score_out_range == false && ((board[frame][cast-1] + score) <= 10)) break;
					
					if (score_out_range) printf("** Invalid score. Please try again (1~10) **\n\n");
					else printf("** Invalid score. The score can only sum up to 10 **\n");

				}
				
				if (was_spare = bowl(frame, cast, score)) {
					// spare
					printf("spare\n");
				} else {
					// normal second throw
					print_board(frame);
				}
			}
			
			
			
		}

	}
	


	return 0;
}


int strike(int frame, int strike_in_row)
{
	

	return 1;
}

int spare(int frame)
{


	return 1;
}


int bowl(int frame, int cast, int score)
{
	board[frame][cast] = score;
	
	if (score == 10) return 1;	// strike
	
	if (cast == 0) return 0;	// first cast and not strike
	else {
		if ((board[frame][cast-1] + score) == 10) return 1;	// spare
		else return 0;			// second cast and not spare
	}
}

void calc_frame(int frame)
{

	return;
}

void print_board(int frame)
{
	int score = board[frame][0] + board[frame][1];
	printf("\nframe : %d score : %d\n", frame+1, score);

	return;
}
