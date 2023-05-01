// ver1 : check for input validity (can't handle char) distinguish cases and only print when not stirke nor spare.
// ver2 : score calc. deal with spare
// ver3 : deal with strike - failed
// ver4 : fixed spare, change index, printing algorithm, complete strike
// ver5 : completed 10th frame
// ver6 : cleanup codes by modifying func

#include <stdio.h>
#include <stdbool.h>

#define FRAME 10
#define CAST 3

int was_strike(int frame);
int was_spare(int frame);
int check_valid_new(int frame, int cast);
int check_valid_spare(int frame, int cast, int dim);
void print_board(int frame);

int board[FRAME][CAST] = {0, };	// 1~9
int board10[4];					// 10

int board_tot[11] = {0, };		// 1~10

int main(void)
{
	int frame = 1;
	int strike_in_row = 0;
	int score = 0;
	
	// 1~9 frames
	for (; frame < FRAME; ++frame) {
		// cast 1
		// check input validity
		board[frame][1] = check_valid_new(frame, 1);
		
		// print if...
		// 1. i-1 frame spare --> i-1
		if (frame >= 2 && was_spare(frame-1)) {
			int bonus = board[frame][1];
			board_tot[frame-1] = board_tot[frame-2] + 10 + bonus;
			print_board(frame-1);
			
		// 2. i-2 frame strike && i-1 frame strike --> i-2 frame print
		} else if (frame >= 3 && was_strike(frame-2) && was_strike(frame-1)) {
			int bonus = 10 + board[frame][1];	// 10 == board[frame-1][1]
			board_tot[frame-2] = board_tot[frame-3] + 10 + bonus;
			print_board(frame-2);
		}
		
		
		// cast2
		if (was_strike(frame) == false) {
			// input validity
			board[frame][2] = check_valid_spare(frame, 2, 2);
			
			// print if not strike &&
			// 1. i-1 frame strike --> i-1 frame print
			if (frame >= 2 && was_strike(frame-1)) {
				int bonus = board[frame][1] + board[frame][2];
				board_tot[frame-1] = board_tot[frame-2] + 10 + bonus;
				print_board(frame-1);
			}
			// 2. normal case
			if (board[frame][1] + board[frame][2] < 10) {
				int bonus = 0;
				board_tot[frame] = board_tot[frame-1] + board[frame][1] + board[frame][2];
				print_board(frame);
			}
		}
		
		
		
	}
	
	// 10th frame
	
	// cast 1
	// check input validity
	board10[1] = check_valid_new(FRAME, 1);
	
	// print if...
	// 1. i-1 frame spare --> i-1
	if (was_spare(FRAME-1)) {
		int bonus = board10[1];
		board_tot[FRAME-1] = board_tot[FRAME-2] + 10 + bonus;
		print_board(FRAME-1);
		
	// 2. i-2 frame strike && i-1 frame strike --> i-2 frame print
	} else if (was_strike(FRAME-2) && was_strike(FRAME-1)) {
		int bonus = 10 + board10[1];	// 10 == board[frame-1][1]
		board_tot[FRAME-2] = board_tot[FRAME-3] + 10 + bonus;
		print_board(FRAME-2);
	}
	
	
	// if strike 1
	if (board10[1] == 10) {
		// cast 2 new
		
		board10[2] = check_valid_new(FRAME, 2);
		
		// print if not strike &&
		// 1. i-1 frame strike --> i-1 frame print
		if (was_strike(FRAME-1)) {
			int bonus = board10[1] + board10[2];
			board_tot[FRAME-1] = board_tot[FRAME-2] + 10 + bonus;
			print_board(FRAME-1);
		}
		// 2. normal case
		if (board10[1] + board10[2] < 10) {
			int bonus = 0;
			board_tot[FRAME] = board_tot[FRAME-1] + board10[1] + board10[2];
			print_board(frame);
		}
		
		// if strike 2
		if (board10[2] == 10) {
			// cast 3 new
			board10[3] = check_valid_new(FRAME, 3);
			
		// cast 3 continue
		} else {
			// input validity
			board10[3] = check_valid_spare(FRAME, 3, 1);
		
		}
	// cast 2 continue (try spare)
	} else {
		// print if not strike &&
		// 1. i-1 frame strike --> i-1 frame print
		if (was_strike(FRAME-1)) {
			int bonus = board10[1] + board10[2];
			board_tot[FRAME-1] = board_tot[FRAME-2] + 10 + bonus;
			//print_board(FRAME-1);
		}
		// 2. normal case
		if (board10[1] + board10[2] < 10) {
			int bonus = 0;
			board_tot[FRAME] = board_tot[FRAME-1] + board10[1] + board10[2];
			//print_board(frame);
		}
		
		board10[2] = check_valid_spare(FRAME, 2, 1);
		
		// if spare
		if (board10[1] + board10[2] == 10 && board10[1] != 10) {
			// cast 3 new
			board10[3] = check_valid_new(FRAME, 3);
		}
		// print
		
	}
	
	board_tot[FRAME] = board_tot[FRAME-1] + board10[1] + board10[2] + board10[3];
	
	print_board(FRAME);

	return 0;
}


int was_strike(int frame)
{
	return (board[frame][1] == 10);
}

int was_spare(int frame)
{
	return ((board[frame][1] + board[frame][2] == 10) && (board[frame][1] != 10));
}

int check_valid_new(int frame, int cast)
{
	int score = 0;
	while (true) {
		switch (cast) {
			case 1:
				printf("%d frame first cast : ", frame);
				break;
			case 2:
				printf("%d frame second cast : ", frame);
				break;
			case 3:
				printf("%d frame third cast : ", frame);
				break;
		}
		scanf("%d", &score);
		
		if (score >= 0 && score <= 10) {
			return score;
		}
		else printf("** Invalid score. Please try again (1~10) **\n\n");
	}
}

int check_valid_spare(int frame, int cast, int dim)
{
	int score = 0;
	int prev_cast_score = 0;
	
	if (dim == 2) prev_cast_score = board[frame][cast-1];
	else prev_cast_score = board10[cast-1];
	
	while (true) {
		switch (cast) {
			case 2:
				printf("%d frame second cast : ", frame);
				break;
			case 3:
				printf("%d frame third cast : ", frame);
				break;
		}
		scanf("%d", &score);
		
		bool score_out_range = false;
			
		if (score >= 0 && score > 10) score_out_range = true;
			
			if (score_out_range == false && ((prev_cast_score + score) <= 10)) {
				//printf("================================\n");
				return score;
			}
			
			if (score_out_range) printf("** Invalid score. Please try again (1~10) **\n\n");
			else printf("** Invalid score. The score can only sum up to 10 **\n");
	}
}

void print_board(int frame)
{
	printf("frame : %d score : %d\n", frame, board_tot[frame]);

	return;
}
