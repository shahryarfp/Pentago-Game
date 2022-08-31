#include "graphics.h"
#include "drawboard.h"
void drawboard(char BOARD[][6])
{
	GetActiveWindow();
	//////////Drawing board
	setlinestyle(0, 0, 5);
	rectangle(18, 18, 652, 652);
	//painting board with Green
	setfillstyle(1, GREEN);
	floodfill(30, 30, WHITE);

	setcolor(WHITE);
	setlinestyle(0, 0, 2);
	line(20, 335, 650, 335);
	line(335, 20, 335, 650);
	setcolor(BLACK);
	rectangle(16, 16, 654, 654);
	setcolor(WHITE);

	/////////Drawing inside circles
	for (int i = 10+40+170/7;i < 660;i += 80+170/7)
	{
		for (int j = 10 + 40 + 170 / 7;j < 660;j += 80 + 170 / 7)
		{
			setcolor(LIGHTGREEN);
			setlinestyle(0, 0,3);
			circle(i, j, 40);
		}
	}
	/////////Drawing outside circles
	for (int i = 10 + 40 + 170 / 7;i < 660;i += 80 + 170 / 7)
	{
		for (int j = 10 + 40 + 170 / 7;j < 660;j += 80 + 170 / 7)
		{
			setcolor(BLACK);
			setlinestyle(0, 0, 2);
			circle(i, j, 44);
		}
	}
	setcolor(WHITE);
	//paint circles
	for (int i =0;i < 6;i ++)
	{
		for (int j =0 ;j < 6;j ++)
		{
			if (BOARD[i][j] == 'w')//paint white
			{
				setfillstyle(1, WHITE);
				floodfill((j + 1) * 80 + j*170/7 + 10 - 40,(i+1)*80+ i * 170 / 7 +10-40, LIGHTGREEN);
			}
			else if (BOARD[i][j] == 'b')//paint black
			{
				setfillstyle(1, BLACK);
				floodfill((j + 1) * 80 + j * 170 / 7 + 10 - 40, (i + 1) * 80 + i* 170 / 7 + 10 - 40, LIGHTGREEN);
			}
			else if (BOARD[i][j] == '.')//No paint
			{
				setfillstyle(1, GREEN);
				floodfill((j + 1) * 80 + j * 170 / 7 + 10 - 40, (i + 1) * 80 + i * 170 / 7 + 10 - 40, LIGHTGREEN);
			}
		}
	}
}