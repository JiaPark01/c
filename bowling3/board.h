#ifndef BOARD_H
#define BOARD_H

int board[11][3];
int board_tot[11];

int was_strike(int frame);
int was_spare(int frame);

int check_valid_new(int frame, int cast);
int check_valid_spare(int frame, int cast);

void setScore(int frame, int cast, int score);
void setBoardTot(int frame, int frameScore);
void printBoard(void);

#endif
