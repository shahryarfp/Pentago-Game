#include <string.h>
#include "win.h"

int win(char BOARD[][6])
{
	int w = 0,b=0; //for identifying if sb wone (w for white and b for black)
	for (int i = 0;i < 6;i++)//row
	{
		for (int j = 0;j < 6;j++)//column
		{
			/////////for L shapes and its horizental and vertical mirroring
			if (i < 3 & j < 5) 
			{
				if (BOARD[i][j] == BOARD[i + 1][j] & BOARD[i + 1][j] == BOARD[i + 2][j] & BOARD[i + 2][j] == BOARD[i + 3][j] & BOARD[i + 3][j] == BOARD[i + 3][j + 1])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i < 3 & j > 0)
			{
				if (BOARD[i][j] == BOARD[i + 1][j] & BOARD[i + 1][j] == BOARD[i + 2][j] & BOARD[i + 2][j] == BOARD[i + 3][j] & BOARD[i + 3][j] == BOARD[i + 3][j - 1])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 2 & j < 5)
			{
				if (BOARD[i][j] == BOARD[i - 1][j] & BOARD[i - 1][j] == BOARD[i - 2][j] & BOARD[i - 2][j] == BOARD[i - 3][j] & BOARD[i - 3][j] == BOARD[i - 3][j + 1])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 2 & j > 0)
			{
				if (BOARD[i][j] == BOARD[i - 1][j] & BOARD[i - 1][j] == BOARD[i - 2][j] & BOARD[i - 2][j] == BOARD[i - 3][j] & BOARD[i - 3][j] == BOARD[i - 3][j - 1])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}

			///////////////for +90 degree L clockwise rotated and its horizental and vertical mirroring
			if (i < 5 & j >2)
			{
				if (BOARD[i][j] == BOARD[i][j - 1] & BOARD[i][j - 1] == BOARD[i][j - 2] & BOARD[i][j - 2] == BOARD[i][j - 3] & BOARD[i][j - 3] == BOARD[i + 1][j - 3])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 0 & j > 2)
			{
				if (BOARD[i][j] == BOARD[i][j - 1] & BOARD[i][j - 1] == BOARD[i][j - 2] & BOARD[i][j - 2] == BOARD[i][j - 3] & BOARD[i][j - 3] == BOARD[i - 1][j - 3])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i < 5 & j < 2)
			{
				if (BOARD[i][j] == BOARD[i][j + 1] & BOARD[i][j + 1] == BOARD[i][j + 2] & BOARD[i][j + 2] == BOARD[i][j + 3] & BOARD[i][j + 3] == BOARD[i + 1][j + 3])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 0 & j < 2)
			{
				if (BOARD[i][j] == BOARD[i][j + 1] & BOARD[i][j + 1] == BOARD[i][j + 2] & BOARD[i][j + 2] == BOARD[i][j + 3] & BOARD[i][j + 3] == BOARD[i - 1][j + 3])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}


			///////////for orib(+45 L clockwise) shape and its horizental and vertical mirroring
			if (i < 2 & j >2)
			{
				if (BOARD[i][j] == BOARD[i + 1][j - 1] & BOARD[i + 1][j - 1] == BOARD[i + 2][j - 2] & BOARD[i + 2][j - 2] == BOARD[i + 3][j - 3] & BOARD[i + 3][j - 3] == BOARD[i + 4][j - 2])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i < 3 & j >3)
			{
				if (BOARD[i][j] == BOARD[i + 1][j - 1] & BOARD[i + 1][j - 1] == BOARD[i + 2][j - 2] & BOARD[i + 2][j - 2] == BOARD[i + 3][j - 3] & BOARD[i + 3][j - 3] == BOARD[i + 2][j - 4])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 2 & j < 2)
			{
				if (BOARD[i][j] == BOARD[i - 1][j + 1] & BOARD[i - 1][j + 1] == BOARD[i - 2][j + 2] & BOARD[i - 2][j + 2] == BOARD[i - 3][j + 3] & BOARD[i - 3][j + 3] == BOARD[i - 2][j + 4])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 3 & j < 3)
			{
				if (BOARD[i][j] == BOARD[i - 1][j + 1] & BOARD[i - 1][j + 1] == BOARD[i - 2][j + 2] & BOARD[i - 2][j + 2] == BOARD[i - 3][j + 3] & BOARD[i - 3][j + 3] == BOARD[i - 4][j + 3])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			//////////////for orib: (+45 L counterclockwise) and its horizental and vertical mirroring
			if (i < 3 & j < 2)
			{
				if (BOARD[i][j] == BOARD[i + 1][j + 1] & BOARD[i + 1][j + 1] == BOARD[i + 2][j + 2] & BOARD[i + 2][j + 2] == BOARD[i + 3][j + 3] & BOARD[i + 3][j + 3] == BOARD[i + 2][j + 4])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i < 2 & j < 3)
			{
				if (BOARD[i][j] == BOARD[i + 1][j + 1] & BOARD[i + 1][j + 1] == BOARD[i + 2][j + 2] & BOARD[i + 2][j + 2] == BOARD[i + 3][j + 3] & BOARD[i + 3][j + 3] == BOARD[i + 4][j + 2])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 3 & j >2)
			{
				if (BOARD[i][j] == BOARD[i - 1][j - 1] & BOARD[i - 1][j - 1] == BOARD[i - 2][j - 2] & BOARD[i - 2][j - 2] == BOARD[i - 3][j - 3] & BOARD[i - 3][j - 3] == BOARD[i - 4][j - 2])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
			if (i > 2 & j > 3)
			{
				if (BOARD[i][j] == BOARD[i - 1][j - 1] & BOARD[i - 1][j - 1] == BOARD[i - 2][j - 2] & BOARD[i - 2][j - 2] == BOARD[i - 3][j - 3] & BOARD[i - 3][j - 3] == BOARD[i - 2][j - 4])
				{
					if (BOARD[i][j] == 'w')
					{
						w = 1;
					}
					else if (BOARD[i][j] == 'b')
					{
						b = 1;
					}
				}
			}
		}
	}
	if (w == 1 & b == 1)//both win (draw)
		return 3;
	else if (w == 1)//white win
		return 1;
	else if (b == 1)//black win
		return 2;
}