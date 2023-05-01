#include <stdio.h>
#include <stdbool.h>

int was_strike(int frame);
int was_spare(int frame);

int check_valid_new(int frame, int cast);
int check_valid_spare(int frame, int cast);

void print_board(int frame);

int board[11][3];
int board_tot[11];

int main(void)
{
	
	int bonusCast;
	
	for (int frame = 1; frame <= 10; ++frame) {
		// first cast
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
		
		// second cast (10 frame || 1~9 frame no strike)
		
		if (frame == 10 || board[frame][1] != 10) {
			if (frame != 10 || frame == 10 && !was_strike(frame)) board[frame][2] = check_valid_spare(frame, 2);
			else board[frame][2] = check_valid_new(frame, 2);
			
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
		
		// 10 frame bonus cast ??
		if (frame == 10 && board[frame][1] + board[frame][2] >= 10) {
			if (board[frame][1] == 10) bonusCast = check_valid_spare(frame, 3);
			else {
				bonusCast = check_valid_new(frame, 3);
			}
			
			board_tot[frame] = board_tot[frame-1] + board[frame][1] + board[frame][2] + bonusCast;
			print_board(frame);
		}

	}
	
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

int check_valid_spare(int frame, int cast)
{
	int score = 0;
	int prev_cast_score = board[frame][cast-1];
	
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
