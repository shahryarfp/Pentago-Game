#include "rotate.h"
char HELPBOARD[3][3];


void rot(char);//declare rot function which is defined under rotate function
void rotate(int i, char k,char BOARD[][6])//i is for plate number and k for direction
{
	//here first we send plate data to the help board; then rotate it and send it back again.
	switch (i)
	{
	case 1:
		for (int i = 0;i<3;i++)//send plate to help board
		{
			for (int j = 3;j < 6;j++)
			{
				HELPBOARD[i][j - 3] = BOARD[i][j];
			}
		}
		rot(k);//rotate it
		for (int i = 0;i<3;i++)//send it back to plate from helpboard
		{
			for (int j = 3;j < 6;j++)
			{
				BOARD[i][j] = HELPBOARD[i][j - 3];
			}
		}
		break;


	case 2:
		for (int i = 0;i<3;i++)//send plate to help board
		{
			for (int j = 0;j < 3;j++)
			{
				HELPBOARD[i][j] = BOARD[i][j];
			}
		}
		rot(k);//rotate it
		for (int i = 0;i<3;i++)//send it back to plate from helpboard
		{
			for (int j = 0;j < 3;j++)
			{
				BOARD[i][j] = HELPBOARD[i][j];
			}
		}
		break;


	case 3:
		for (int i = 3;i<6;i++)//send plate to help board
		{
			for (int j = 0;j < 3;j++)
			{
				HELPBOARD[i - 3][j] = BOARD[i][j];
			}
		}
		rot(k);//rotate it
		for (int i = 3;i<6;i++)//send it back to plate from helpboard
		{
			for (int j = 0;j < 3;j++)
			{
				BOARD[i][j] = HELPBOARD[i - 3][j];
			}
		}
		break;


	case 4:
		for (int i = 3;i<6;i++)//send plate to help board
		{
			for (int j = 3;j < 6;j++)
			{
				HELPBOARD[i - 3][j - 3] = BOARD[i][j];
			}
		}
		rot(k);//rotate it
		for (int i = 3;i<6;i++)//send it back to plate from helpboard
		{
			for (int j = 3;j < 6;j++)
			{
				BOARD[i][j] = HELPBOARD[i - 3][j - 3];
			}
		}
		break;
	}
}

void rot(char k)
{
	char x, y;
	if (k == '+')
	{
		//rotate clockwise
		x = HELPBOARD[0][0];
		y = HELPBOARD[0][1];
		HELPBOARD[0][1] = HELPBOARD[1][0];
		HELPBOARD[0][0] = HELPBOARD[2][0];
		HELPBOARD[1][0] = HELPBOARD[2][1];
		HELPBOARD[2][0] = HELPBOARD[2][2];
		HELPBOARD[2][1] = HELPBOARD[1][2];
		HELPBOARD[2][2] = HELPBOARD[0][2];
		HELPBOARD[1][2] = y;
		HELPBOARD[0][2] = x;
	}
	else
	{
		for (int i = 0;i < 3;i++)
		{
			//rotate counter clockwise
			x = HELPBOARD[0][0];
			y = HELPBOARD[0][1];
			HELPBOARD[0][1] = HELPBOARD[1][0];
			HELPBOARD[0][0] = HELPBOARD[2][0];
			HELPBOARD[1][0] = HELPBOARD[2][1];
			HELPBOARD[2][0] = HELPBOARD[2][2];
			HELPBOARD[2][1] = HELPBOARD[1][2];
			HELPBOARD[2][2] = HELPBOARD[0][2];
			HELPBOARD[1][2] = y;
			HELPBOARD[0][2] = x;
		}
	}
}