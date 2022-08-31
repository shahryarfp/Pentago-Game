#include <stdio.h>
#include "graphics.h"
#include "rotate.h"//rotating plates
#include "win.h"//show the win or draw situation
#include "drawboard.h"//graphic board

int main()
{
	char BOARD[6][6];//the board

	while (1) //for playing game again and again
	{
		int counter = 0;//counter is times that players played (it can just reach to 36)
						//put dots in board
		for (int i = 0;i < 6;i++)
		{
			for (int j = 0;j < 6;j++)
			{
				BOARD[i][j] = '.';
			}
		}
		//Texts
		initwindow(1100, 680, "Pentagol");//Defining Window of Game
		setfillstyle(1, LIGHTBLUE);
		floodfill(30, 30, WHITE);
		drawboard(BOARD);
		settextstyle(8, 0, 6);
		outtextxy(670, 20, "PENTAGOL");
		settextstyle(8, 0, 1);
		outtextxy(670, 100, "We have two players (White and Black)");
		outtextxy(670, 140, "You should choose Coordinate, Plate");
		outtextxy(670, 160, "and Rotating Direction.");
		settextstyle(8, 0, 2);
		outtextxy(670, 200, "press 1 to Start...");
		outtextxy(670, 220, "press 0 to Exit");


		//Entering or Exiting Game
		while (1)
		{
			while (!kbhit())//waiting for user to press key
			{
				delay(1);
			}
			char c = getch();//get c from user
							 //Display error for pressing wrong button
			if (c != '0' & c != '1')
			{
				setcolor(RED);
				setlinestyle(0, 0, 5);
				rectangle(665, 625, 1080, 652);
				setcolor(WHITE);
				settextstyle(8, 0, 1);
				outtextxy(670, 630, "Warning: Enter Number between 1 and 0");
				continue;
			}
			if (c == '1')//entering game
				break;
			if (c == '0')//exiting game
				return 0;
		}

		//Before Starting Game
		settextstyle(8, 0, 6);
		setcolor(GREEN);
		outtextxy(670, 200, "Game Started");//display that game started
		setcolor(WHITE);
		settextstyle(8, 0, 1);
		outtextxy(720, 300, "players turn...");
		//Draw Rotating buttons
		setlinestyle(0, 0, 7);
		//counter clock wise
		arc(700, 575, 0, 90, 50);
		line(700, 525, 710, 518);
		line(700, 525, 710, 535);
		//clock wise
		arc(830, 575, 90, 180, 50);
		line(830, 525, 820, 518);
		line(830, 525, 820, 535);
		//rotating buttons border
		setlinestyle(0, 0, 2);
		rectangle(690, 510, 760, 585);
		rectangle(770, 510, 840, 585);

		//GAME STARTED
		while (1)//game's loop for each turn of it
		{

			//Variables
			int platenumber;//from 1 to 4 which is selectig by Graphic window
			char direction;//clock wise or counter clock wise




						   //////////////////End Game check for Winner or Draw!
			if (win(BOARD) == 1 || win(BOARD) == 2 || win(BOARD) == 3 || counter == 36) {
				if (win(BOARD) == 1)//white player wone
				{
					settextstyle(8, 0, 4.95);
					outtextxy(670, 350, "The 'White' Player");
					outtextxy(670, 380, "has wone!");
					settextstyle(8, 0, 2);
				}
				else if (win(BOARD) == 2)//black player wone
				{
					settextstyle(8, 0, 4.95);
					outtextxy(670, 350, "The 'Black' Player");
					outtextxy(670, 380, "has wone!");
					settextstyle(8, 0, 2);
				}
				else if (win(BOARD) == 3 || counter == 36)//both player wone at the same time or board is full so its Draw!
				{
					setcolor(YELLOW);
					settextstyle(8, 0, 4.95);
					outtextxy(670, 350, "Draw!");
				}
				setcolor(WHITE);
				outtextxy(670, 420, "to Restart the Game press 1 ...");//play the game again
				outtextxy(670, 440, "to Exit press 0 .");//exiting game
				while (1)
				{
					while (!kbhit())//waiting for user to press any key
					{
						delay(1);
					}
					char c = getch();//get c from user
									 //display error
					if (c != '0' & c != '1')
					{
						setcolor(RED);
						setlinestyle(0, 0, 5);
						rectangle(665, 625, 1080, 652);
						setcolor(WHITE);
						settextstyle(8, 0, 1);
						outtextxy(670, 630, "Warning: Enter Number between 1 and 0");
						continue;
					}
					if (c == '1')//play the game again
						break;
					if (c == '0')//exiting game
						return 0;
				}
				break;
			}




			////////////////Display circles to show players turn
			if (counter % 2 == 0) //white player turn
			{
				circle(690, 300, 20);
				setfillstyle(1, WHITE);
				floodfill(690, 300, WHITE);
			}
			else//black player turn
			{
				setcolor(BLACK);
				circle(690, 300, 20);
				setfillstyle(1, BLACK);
				floodfill(690, 300, BLACK);
			}





			///////////////Choose Coordinate
			int i = 1, j = 1;//for finding coordinate
			setlinestyle(0, 0, 1);
			//draw first up left rectangle
			rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
			//loop for user to move pointer and choose coordinate
			while (1)
			{
				setcolor(WHITE);
				setlinestyle(0, 0, 2);
				rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);


				while (!kbhit())//waiting for user to press any key
				{
					delay(1);
				}
				char c = getch();//get c from user
								 //first error for entering wrong wrong button
				if (c != 'w'&c != 's'&c != 'a'&c != 'd'&c != 'W'&c != 'S'&c != 'A'&c != 'D'&c != 'f'&c != 'F')
				{
					setcolor(RED);
					setlinestyle(0, 0, 5);
					rectangle(665, 625, 1080, 652);
					setcolor(WHITE);
					settextstyle(8, 0, 1);
					outtextxy(670, 630, "Warning: Enter between a,d,w,s and f ");
					continue;
				}
				if (c == 'f' || c == 'F')
				{
					//second error for entering wrong coordinate which was taken before
					if (BOARD[j - 1][i - 1] != '.')
					{
						//Display error!				
						setcolor(RED);
						setlinestyle(0, 0, 5);
						rectangle(665, 625, 1080, 652);
						setcolor(WHITE);
						settextstyle(8, 0, 1);
						outtextxy(670, 630, "Warning: Choose correct coordinate!  ");
						setcolor(GREEN);
						rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
						continue;//go to next loop and get another key from user
					}

					setcolor(GREEN);
					//cleaning previous rectangle
					rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
					setcolor(WHITE);
					//players turn
					if (counter % 2 == 0)
						BOARD[j - 1][i - 1] = 'w';//white player turn
					else
						BOARD[j - 1][i - 1] = 'b';//black player turn
					drawboard(BOARD);//show graphic board
					break;
				}
				if (c == 'd' || c == 'D')
				{
					if (i == 6)//the pointer is close to cross the board
						continue;
					//cleaning previous rectangle and draw new one
					setcolor(GREEN);
					rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
					setcolor(WHITE);
					rectangle(12 + (i + 1)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i + 1)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
					i++;
					continue;
				}
				if (c == 'a' || c == 'A')
				{
					if (i == 1)//the pointer is close to cross the board
						continue;
					//cleaning previous rectangle and draw new one
					setcolor(GREEN);
					rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
					setcolor(WHITE);
					rectangle(12 + (i - 1)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i - 1)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
					i--;
					continue;
				}
				if (c == 's' || c == 'S')
				{
					if (j == 6)//the pointer is close to cross the board
						continue;
					//cleaning previous rectangle and draw new one
					setcolor(GREEN);
					rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
					setcolor(WHITE);
					rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + (j + 1)*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + (j + 1)*(80 + 170 / 7) + 50 - 40);
					j++;
					continue;
				}
				if (c == 'w' || c == 'W');
				{
					if (j == 1)//the pointer is close to cross the board
						continue;
					//cleaning previous rectangle and draw new one
					setcolor(GREEN);
					rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + j*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + j*(80 + 170 / 7) + 50 - 40);
					setcolor(WHITE);
					rectangle(12 + (i)*(80 + 170 / 7) - 50 - 40, 12 + (j - 1)*(80 + 170 / 7) - 50 - 40, 8 + (i)*(80 + 170 / 7) + 50 - 40, 8 + (j - 1)*(80 + 170 / 7) + 50 - 40);
					j--;
					continue;
				}

			}




			///////////////Choose Plate
			i = 0;//for finding platenumber
			j = 0;//for finding platenumber
			setlinestyle(0, 0, 2);
			rectangle(25, 25, 330, 330);//first up left rectangle for pointing to plates
			setlinestyle(0, 0, 5);
			while (1)
			{
				while (!kbhit())//waiting for user to press any key
				{
					delay(1);
				}
				char c = getch();//get c from user
								 //error
				if (c != 'w'&c != 's'&c != 'a'&c != 'd'&c != 'W'&c != 'S'&c != 'A'&c != 'D'&c != 'f'&c != 'F')
				{
					setcolor(RED);
					setlinestyle(0, 0, 5);
					rectangle(665, 625, 1080, 652);
					setcolor(WHITE);
					settextstyle(8, 0, 1);
					outtextxy(670, 630, "Warning: Enter between a,d,w,s and f ");//displaying error
					continue;//going to next loop
				}
				if (c == 'f' || c == 'F')
				{
					setcolor(GREEN);
					rectangle(25 + i*(315), 25 + j*(315), 330 + i*(315), 330 + j*(315));//cleaning previous rectangle
					setcolor(WHITE);
					//finding plate number
					if (i == 0 & j == 0)
						platenumber = 2;
					else if (i == 1 & j == 0)
						platenumber = 1;
					else if (i == 0 & j == 1)
						platenumber = 3;
					else if (i == 1 & j == 1)
						platenumber = 4;
					break;
				}
				if (c == 'd' || c == 'D')
				{
					if (i == 1)//close to cross the border
						continue;
					setcolor(GREEN);
					//cleaning previous rectangle and draw new one
					rectangle(25 + i*(315), 25 + j*(315), 330 + i*(315), 330 + j*(315));
					setcolor(WHITE);
					rectangle(25 + (i + 1)*(315), 25 + j*(315), 330 + (i + 1)*(315), 330 + j*(315));
					i++;
					continue;
				}
				if (c == 'a' || c == 'A')
				{
					if (i == 0)//close to cross the border
						continue;
					setcolor(GREEN);
					//cleaning previous rectangle and draw new one
					rectangle(25 + i*(315), 25 + j*(315), 330 + i*(315), 330 + j*(315));
					setcolor(WHITE);
					rectangle(25 + (i - 1)*(315), 25 + j*(315), 330 + (i - 1)*(315), 330 + j*(315));
					i--;
					continue;
				}
				if (c == 's' || c == 'S')
				{
					if (j == 1)//close to cross the border
						continue;
					setcolor(GREEN);
					//cleaning previous rectangle and draw new one
					rectangle(25 + i*(315), 25 + j*(315), 330 + i*(315), 330 + j*(315));
					setcolor(WHITE);
					rectangle(25 + i*(315), 25 + (j + 1)*(315), 330 + i*(315), 330 + (j + 1)*(315));
					j++;
					continue;
				}
				if (c == 'w' || c == 'W');
				{
					if (j == 0)//close to cross the border
						continue;
					setcolor(GREEN);
					//cleaning previous rectangle and draw new one
					rectangle(25 + i*(315), 25 + j*(315), 330 + i*(315), 330 + j*(315));
					setcolor(WHITE);
					rectangle(25 + i*(315), 25 + (j - 1)*(315), 330 + i*(315), 330 + (j - 1)*(315));
					j--;
					continue;
				}

			}





			//Choose Direction of Rotation
			setfillstyle(1, BLUE);
			floodfill(695, 550, WHITE);//paint left direction at first in BLUE
			i = 0;//showing direction
			while (1)
			{
				while (!kbhit())//waiting for user to press any key
				{
					delay(1);
				}
				char c = getch();//get c from user

								 //error
				if (c != 'd'&c != 'D'&c != 'a'&c != 'A'&c != 'f'&c != 'F')
				{
					setcolor(RED);
					setlinestyle(0, 0, 5);
					rectangle(665, 625, 1080, 652);
					setcolor(WHITE);
					settextstyle(8, 0, 1);
					outtextxy(670, 630, "Warning: Enter between a,d and f     ");//displaying error
					continue;
				}
				if (c == 'f' || c == 'F')
				{
					//cleaning last paint
					setfillstyle(1, LIGHTBLUE);
					floodfill(695 + i * 80, 550, WHITE);
					//finding directions
					if (i == 1)//clock wise
						direction = '+';
					else//counter clock wise
						direction = '-';
					break;
				}
				if (c == 'd' || c == 'D')
				{
					if (i == 1)//close to cross the border
						continue;
					//clean previous color and paint new one
					setfillstyle(1, LIGHTBLUE);
					floodfill(695 + i * 80, 550, WHITE);
					setfillstyle(1, BLUE);
					floodfill(695 + (i + 1) * 80, 550, WHITE);
					i++;//chainging direction
					continue;
				}
				if (c == 'a' || c == 'A')
				{
					if (i == 0)//close to cross the border
						continue;
					//clean previous color and paint new one
					setfillstyle(1, LIGHTBLUE);
					floodfill(695 + i * 80, 550, WHITE);
					setfillstyle(1, BLUE);
					floodfill(695 + (i - 1) * 80, 550, WHITE);
					i--;//changing direction
					continue;
				}

			}

			rotate(platenumber, direction, BOARD);//Rotating Plate
			drawboard(BOARD);//Drawing Board
			counter++;//next player's turn
		}
	}
	return 0;
}