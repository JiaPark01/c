// ver1 : check for input validity (can't handle char) distinguish cases and only print when not stirke nor spare.
// ver2 : score calc. deal with spare
// ver3 : deal with strike - failed
// ver3-2: change way of index. split 10th frame (divide & conquor)

#include <stdio.h>
#include <stdbool.h>

#define FRAME 10
#define CAST 3

int was_strike(int frame);
int was_spare(int frame);
int bowl(int frame, int cast, int score);	// 반환: strike/spare or not
void calc_frame(int frame, int cast, int strike_in_row);
void print_board(int frame);

int board[FRAME][CAST] = {0, };	// 1~9
int board10[4];					// 10

int board_tot[11] = {0, };		// 1~10
bool add_later = false;

int main(void)
{
	int frame = 1;
	//int cast = 0;
	//bool was_strike = false;
	//bool was_spare = false;
	int strike_in_row = 0;
	int score = 0;
	
	for (; frame < FRAME; ++frame) {
		for (int cast = 1; cast < CAST; ++cast) {
			// cast 1
			if (cast == 1) {
				// check input validity
				while (true) {
					printf("%d frame first cast : ", frame+1);
					scanf("%d", &score);
					
					if (score >= 0 && score <= 10) break;
					else printf("** Invalid score. Please try again (1~10) **\n\n");
				}
				board[frame][cast] = score;
				// print if...
				// 1. i-1 frame spare --> i-1
				if (was_spare(frame-1)) {
					print_board(frame-1);
				} else if (was_strike(frame-2) && was_strike(frame-1)) {
					print_board(frame-2);
				}
				
				// 2. i-2 frame & i-1 frame strike --> i-2
				
				/*
				// check for strike
				if (was_strike = bowl(frame, cast, score)) {
					// strike score handling
					++strike_in_row;
					add_later = true;
					//strike(frame, strike_in_row);
					calc_frame(frame, cast, strike_in_row);
					//printf("strike\n");
					
				} else {
					// normal first throw
					strike_in_row = 0;
					if (was_strike || was_spare) {
						calc_frame(frame, cast, strike_in_row);
						
						print_board(frame-1);
					}
				} */
				
			// cast2
			} else {
				if (was_strike(frame)) break;
				
				// input validity
				while (true) {
					printf("%d frame second cast : ", frame+1);
					scanf("%d", &score);
					
					bool score_out_range = false;
					
					if (score >= 0 && score > 10) score_out_range = true;
					
					if (score_out_range == false && ((board[frame][cast-1] + score) <= 10)) {
						printf("================================\n");	
						break;
					}
					
					if (score_out_range) printf("** Invalid score. Please try again (1~10) **\n\n");
					else printf("** Invalid score. The score can only sum up to 10 **\n");

				}
				
				board[frame][cast] = score;
				board_tot[frame] = board[frame][1] + score;
				// print if not strike &&
				// 1. i-1 frame strike --> i-1 frame print
				if (was_strike(frame-1)) {
					print_board(frame-1);
				} else if (board_tot[frame] < 10) {
					print_board(frame);
				}
				
				// 2. i frame 1st + 2nd < 10 --> i frame print
				
				/*
				
				if (was_spare = bowl(frame, cast, score)) {
					// spare
					//printf("spare\n");
					calc_frame(frame, cast, strike_in_row);
					add_later = true;
					//printf("%d\n", add_later);
					
				} else {
					// normal second throw
					//print_board(frame);
					//printf("%d\n", add_later);
					add_later = false;
					calc_frame(frame, cast, strike_in_row);
				}*/
			}	
		}
		
		// calc frame
		//calc_frame(frame);
		
		
		
		
		
		// printing
		// when strike
		
		
		// when 3rd strike		
		// when spare
		
		// normal case
		//if (was_strike == false && was_spare == false) print_board(frame);

	}
	


	return 0;
}


int was_strike(int frame)
{
	return (board[frame][1] == 10);
}

int was_spare(int frame)
{
	return (board[frame][1] + board[frame][2] == 10);
}


int bowl(int frame, int cast, int score)
{
	board[frame][cast] = score;
}

void calc_frame(int frame, int cast, int strike_in_row)
{
	if (cast == 1) {
		int score = board[frame][0] + board[frame][1];
		board_tot[frame] = score;
	}
	
	if (frame == 0) return;
	//printf("%d\n", add_later);
	
	if (add_later == true) {
		//printf("add_later\n");
		
		// strike
		if (strike_in_row) {
			printf("\nstrike\n");
			for (int i = 1; i <= strike_in_row; ++i) {
				board_tot[frame-i] += board[frame][0];
				printf("frame-i: %d, score: %d\n", frame-i, board_tot[frame-i]);
			}
		// spare
		} else board_tot[frame-1] += board[frame][0];
	
	}
	
	board_tot[frame] += board_tot[frame-1];
	
	return;
}

void print_board(int frame)
{
	printf("frame : %d score : %d\n\n", frame, board_tot[frame]);

	return;
}
