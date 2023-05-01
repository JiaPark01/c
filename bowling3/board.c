#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"

// char *board[7] = {}		// can't use pointer since the array needs to be altered, not making copies for simple printing

static char boardPic[7][44] = {
	"-------------------------------------------",
	"| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  |",
	"-------------------------------------------",
	"| | | | | | | | | | | | | | | | | | | | | |",
	"-------------------------------------------",
	"|   |   |   |   |   |   |   |   |   |     |",
	"-------------------------------------------",
};


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
	//printf("frame: %d, cast : %d, prev_score: %d\n\n");
	
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
			else printf("** Invalid score. The score can only sum up to 10 (%d + %d) **\n", prev_cast_score, score);
	}
}

void setScore(int frame, int cast, int score)
{
	// board[3][?] = [0-9] or '/' 'X'	// int score -> char
	// cast 1 : 1 5 9, cast 2 : 3 7 11
	int place = frame*4 - ((2-cast) * 2)-1;
	char score_c = score+'0';
	int cast1_score = boardPic[3][place-2] - '0';
	
	if (cast != 1 && cast1_score + score == 10) score_c = '/';
	else if (cast == 1 && score == 10 || frame == 10 && score == 10) score_c = 'X';
	
	boardPic[3][place] = score_c;
	
}

void setBoardTot(int frame, int frameScore)
{
	// board[5][?] "%3d"
	// 123 567
	int place = frame*4-3;
	char score_c[4] = {'\0', };
	sprintf(score_c, "%3d", frameScore);
	
	if (frame == 10) place += 1;
	
	for (int i = 0; i < 3; ++i) {
		if (score_c[i] == ' ') score_c[i] = '0';
	}
	
	strncpy(boardPic[5] + place, score_c, strlen(score_c));
	
}

void printBoard(void)
{
	system("clear");		// send "" message to console
	for (int i = 0; i < 7; ++i) {
		printf("%s\n", boardPic[i]);	// &board[i][0]
	}
	
}

