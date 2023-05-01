// ver1 : check for input validity (can't handle char) distinguish cases and only print when not stirke nor spare.
// ver2 : score calc. deal with spare
// ver3 : deal with strike - failed
// ver4 : fixed spare, change index, printing algorithm, complete strike
// ver5 : completed 10th frame

#include <stdio.h>
#include <stdbool.h>

#define FRAME 10
#define CAST 3

int was_strike(int frame);
int was_spare(int frame);
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
		while (true) {
			printf("%d frame first cast : ", frame);
			scanf("%d", &score);
			
			if (score >= 0 && score <= 10) {
				board[frame][1] = score;
				break;
			}
			else printf("** Invalid score. Please try again (1~10) **\n\n");
		}
		
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
			while (true) {
				printf("%d frame second cast : ", frame);
				scanf("%d", &score);
				
				bool score_out_range = false;
				
				if (score >= 0 && score > 10) score_out_range = true;
				
				if (score_out_range == false && ((board[frame][1] + score) <= 10)) {
					//printf("================================\n");
					board[frame][2] = score;
					break;
				}
				
				if (score_out_range) printf("** Invalid score. Please try again (1~10) **\n\n");
				else printf("** Invalid score. The score can only sum up to 10 **\n");

			}
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
	while (true) {
		printf("%d frame first cast : ", FRAME);
		scanf("%d", &score);
		
		if (score >= 0 && score <= 10) {
			board10[1] = score;
			break;
		}
		else printf("** Invalid score. Please try again (1~10) **\n\n");
	}
	
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
	
	
	// if strike
	if (board10[1] == 10) {
		// cast 2 new
		
		while (true) {
			printf("%d frame second cast : ", FRAME);
			scanf("%d", &score);
			
			if (score >= 0 && score <= 10) {
				board10[2] = score;
				break;
			}
			else printf("** Invalid score. Please try again (1~10) **\n\n");
		}
		
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
		
		// if strike
		if (board10[2] == 10) {
			// cast 3 new
			
			while (true) {
				printf("%d frame third cast : ", FRAME);
				scanf("%d", &score);
				
				if (score >= 0 && score <= 10) {
					board10[3] = score;
					break;
				}
				else printf("** Invalid score. Please try again (1~10) **\n\n");
			}
		// cast 3 continue
		} else {
			// input validity
			while (true) {
				printf("%d frame third cast : ", FRAME);
				scanf("%d", &score);
				
				bool score_out_range = false;
				
				if (score >= 0 && score > 10) score_out_range = true;
				
				if (score_out_range == false && ((board10[2] + score) <= 10)) {
					//printf("================================\n");
					board10[3] = score;
					break;
				}
				
				if (score_out_range) printf("** Invalid score. Please try again (1~10) **\n\n");
				else printf("** Invalid score. The score can only sum up to 10 **\n");

			}
		
		}
	// cast 2 continue (try spare)
	} else {
		while (true) {
			printf("%d frame second cast : ", FRAME);
			scanf("%d", &score);
			
			bool score_out_range = false;
			
			if (score >= 0 && score > 10) score_out_range = true;
				
				if (score_out_range == false && ((board10[1] + score) <= 10)) {
					//printf("================================\n");
					board10[2] = score;
					break;
				}
				
				if (score_out_range) printf("** Invalid score. Please try again (1~10) **\n\n");
				else printf("** Invalid score. The score can only sum up to 10 **\n");
		}
		
		// if spare
		if (board10[1] + board10[2] == 10 && board10[1] != 10) {
			// cast 3 new
			while (true) {
				printf("%d frame third cast : ", FRAME);
				scanf("%d", &score);
				
				if (score >= 0 && score <= 10) {
					board10[3] = score;
					break;
				}
				else printf("** Invalid score. Please try again (1~10) **\n\n");
			}
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

void print_board(int frame)
{
	printf("frame : %d score : %d\n", frame, board_tot[frame]);

	return;
}
