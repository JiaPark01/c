// ver1 : check for input validity (can't handle char) distinguish cases and only print when not stirke nor spare.
// ver2 : score calc. deal with spare
// ver3 : deal with strike - failed

#include <stdio.h>
#include <stdbool.h>

#define FRAME 9
#define CAST 2

void strike(int frame, int strike_in_row);
void spare(int frame);
int bowl(int frame, int cast, int score);	// 반환: strike/spare or not
void calc_frame(int frame, int cast, int strike_in_row);
void print_board(int frame);

int board[FRAME][CAST] = {0, };
int board_tot[FRAME] = {0, };
bool add_later = false;

int main(void)
{
	int frame = 0;
	//int cast = 0;
	bool was_strike = false;
	bool was_spare = false;
	int strike_in_row = 0;
	int score = 0;
	
	for (; frame < FRAME; ++frame) {
		for (int cast = 0; cast < CAST; ++cast) {
			// cast 1
			if (cast == 0) {
				// check input validity
				while (true) {
					printf("%d frame first cast : ", frame+1);
					scanf("%d", &score);
					
					if (score >= 0 && score <= 10) break;
					else printf("** Invalid score. Please try again (1~10) **\n\n");
				}
				// check for strike
				if (was_strike = bowl(frame, cast, score)) {
					// strike score handling
					++strike_in_row;
					add_later = true;
					//strike(frame, strike_in_row);
					calc_frame(frame, cast, strike_in_row);
					printf("strike\n");
					
				} else {
					// normal first throw
					strike_in_row = 0;
					if (was_strike || was_spare) {
						calc_frame(frame, cast, strike_in_row);
						
						print_board(frame-1);
					}
				}
				
			// cast2
			} else {
				if (was_strike) break;
				
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
				}
			}	
		}
		
		// calc frame
		//calc_frame(frame);
		
		
		
		
		
		// printing
		// when strike
		
		
		// when 3rd strike		
		// when spare
		
		// normal case
		if (was_strike == false && was_spare == false) print_board(frame);

	}
	


	return 0;
}


void strike(int frame, int strike_in_row)
{
	board_tot[frame] = board[frame][0];
	if (frame == 0) return;
	
	if (strike_in_row == 2) {
		board_tot[frame-1] += board_tot[frame];
	} else {
		for (int i = 1; i <= 3; ++i) {
			board_tot[frame-i] += board_tot[frame];
		}
	
	}

	return;
}

void spare(int frame)
{


	return;
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
			printf("strike\n");
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
	printf("frame : %d score : %d\n\n", frame+1, board_tot[frame]);

	return;
}
