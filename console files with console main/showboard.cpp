#include <stdio.h>
#include "showboard.h"
char BOARD[6][6];

void showboard(char BOARD[][6])
{
	printf("  1 2 3   4 5 6\n");
	printf("1 %c %c %c | %c %c %c\n", BOARD[0][0], BOARD[0][1], BOARD[0][2], BOARD[0][3], BOARD[0][4], BOARD[0][5]);
	printf("2 %c %c %c | %c %c %c\n", BOARD[1][0], BOARD[1][1], BOARD[1][2], BOARD[1][3], BOARD[1][4], BOARD[1][5]);
	printf("3 %c %c %c | %c %c %c\n", BOARD[2][0], BOARD[2][1], BOARD[2][2], BOARD[2][3], BOARD[2][4], BOARD[2][5]);
	printf("  -- --- --- --\n");
	printf("4 %c %c %c | %c %c %c\n", BOARD[3][0], BOARD[3][1], BOARD[3][2], BOARD[3][3], BOARD[3][4], BOARD[3][5]);
	printf("5 %c %c %c | %c %c %c\n", BOARD[4][0], BOARD[4][1], BOARD[4][2], BOARD[4][3], BOARD[4][4], BOARD[4][5]);
	printf("6 %c %c %c | %c %c %c\n\n", BOARD[5][0], BOARD[5][1], BOARD[5][2], BOARD[5][3], BOARD[5][4], BOARD[5][5]);
}