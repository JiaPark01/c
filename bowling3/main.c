// ver1 : check for input validity (can't handle char) distinguish cases and only print when not stirke nor spare.
// ver2 : score calc. deal with spare
// ver3 : deal with strike - failed
// ver4 : fixed spare, change index, printing algorithm, complete strike
// ver5 : completed 10th frame
// ver6 : cleanup codes by modifying func
// ver7 : print with board looks
// ver8 : will try printing 0 as '-'

#include <stdio.h>
#include "board.h"

int board[11][3] = {0, };
int board_tot[11] = {0, };

int main(void)
{
	
	int bonusCast;
	
	for (int frame = 1; frame <= 10; ++frame) {
		// first cast
		board[frame][1] = check_valid_new(frame, 1);
		setScore(frame, 1, board[frame][1]);
		
		// print if...
		// 1. i-1 frame spare --> i-1
		if (frame >= 2 && was_spare(frame-1)) {
			int bonus = board[frame][1];
			board_tot[frame-1] = board_tot[frame-2] + 10 + bonus;
			//print_board(frame-1);
			setBoardTot(frame-1, board_tot[frame-1]);
			
		// 2. i-2 frame strike && i-1 frame strike --> i-2 frame print
		} else if (frame >= 3 && was_strike(frame-2) && was_strike(frame-1)) {
			int bonus = 10 + board[frame][1];	// 10 == board[frame-1][1]
			board_tot[frame-2] = board_tot[frame-3] + 10 + bonus;
			//print_board(frame-2);
			setBoardTot(frame-2, board_tot[frame-2]);
		}
		printBoard();
		
		// second cast (10 frame || 1~9 frame no strike)
		
		if (frame == 10 || board[frame][1] != 10) {
			if (frame != 10 || frame == 10 && !was_strike(frame)) board[frame][2] = check_valid_spare(frame, 2);
			else board[frame][2] = check_valid_new(frame, 2);
			setScore(frame, 2, board[frame][2]);
			
			// print if not strike &&
			// 1. i-1 frame strike --> i-1 frame print
			if (frame >= 2 && was_strike(frame-1)) {
				int bonus = board[frame][1] + board[frame][2];
				board_tot[frame-1] = board_tot[frame-2] + 10 + bonus;
				//print_board(frame-1);
				setBoardTot(frame-1, board_tot[frame-1]);
			}
			// 2. normal case
			if (board[frame][1] + board[frame][2] < 10) {
				int bonus = 0;
				board_tot[frame] = board_tot[frame-1] + board[frame][1] + board[frame][2];
				//print_board(frame);
				setBoardTot(frame, board_tot[frame]);
			}
		}
		
		printBoard();
		
		// 10 frame bonus cast
		if (frame == 10 && board[frame][1] + board[frame][2] >= 10) {
			if (board[frame][1] == 10 && board[frame][2] != 10) bonusCast = check_valid_spare(frame, 3);
			else {
				bonusCast = check_valid_new(frame, 3);
			}
			
			setScore(frame, 3, bonusCast);
			board_tot[frame] = board_tot[frame-1] + board[frame][1] + board[frame][2] + bonusCast;
			//print_board(frame);
			setBoardTot(frame, board_tot[frame]);
		}
		
		printBoard();

	}
	
	return 0;
}
