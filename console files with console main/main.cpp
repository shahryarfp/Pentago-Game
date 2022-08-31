#include <stdio.h>
#include "showboard.h"
#include "rotate.h"
#include "win.h"

int main()
{
	char BOARD[6][6];

	int n, counter = 0;
	while (1)
	{

		//put dots in board
		for (int i = 0;i < 6;i++) 
		{
			for (int j = 0;j < 6;j++)
			{
				BOARD[i][j] = '.';
			}
		}

		printf("welcome to PENTAGOL\n\n(b) is for Black and (w) for White player\n\n");
		
		
		/////////entering game
		while (1)
		{
			printf("if you wanna play press 1\nand if you wanna exit press 2\n");
			int checker = scanf("%d", &n);//for checking that user enterd correct number
			while (getchar() != '\n'); //clearing buffer
			//error
			if (n != 1 & n != 2 || checker != 1)
			{
				printf("warning: enter number between 1 and 2\n");//display error
				continue;//get number again
			}
			else
				break;//entering game
		}

		if (n == 2) //exiting game
			return 0;

		printf("you should enter coordinates at first;\nthen choose the plate and its rotation direction.\n\n"); /*a little description*/
		showboard(BOARD);

		///////////////GAME STARTED
		while (1)
		{
			//entered data
			int row;
			int column;
			int platenumber;
			char direction;


			////////End Game check with Win or Draw
			if (win(BOARD)==1) //white wone
			{
				printf("The White player has wone!\n\n\n");
				break;
			}
			else if (win(BOARD) == 2)//black wone
			{
				printf("The Black player has wone!\n\n\n");
				break;
			}
			else if (win(BOARD) == 3 || counter == 36)//draw!
			{
				printf("Draw!\n\n\n");
				break;
			}

			///////////entering coordinate
			while (1) 
			{
				if (counter % 2 == 0) //players turn
					printf("White player's turn:\nplease enter the coordinate:\n");
				else
					printf("Black player's turn:\nplease enter the coordinate:\n");

				int n;//2-digits number which shows coordinate!
				int checker = scanf("%d", &n);
				while (getchar() != '\n'); //clearing buffer
				//error 1
				if (n > 99 || n < 11 || checker != 1)
				{
					printf("warning: please enter correct coordinate!\n");//display error
					continue;
				}
				column = n % 10;//finding column
				row = (n - column) / 10;//finding row
				//error 2
				if (row<1 || row>6 || column<1 || column>6 || BOARD[row - 1][column - 1] != '.')
					printf("warning: please enter corect coordinate!\n");//display error
				else
					break;
			}


			////////Put w or b in BOARD
			if (counter % 2 == 0)
				BOARD[row - 1][column - 1] = 'w';
			else
				BOARD[row - 1][column - 1] = 'b';

			showboard(BOARD);//display board right after entering coordinate

			////////plate number
			while (1)
			{
				printf("please enter the number of plate you wanna rotate:\n");
				int checker = scanf("%d", &platenumber);//check if user enterd correct platenumber
				while (getchar() != '\n'); //clearing buffer
				if (0 < platenumber & platenumber < 5 & checker == 1)
					break;
				else//error
					printf("warning: enter correct plate number!\n");//display error
			}



			///////////////rotation direction
			while (1)
			{
				printf("please enter the direction of rotation:\n");
				scanf("%s", &direction);//get char + or -
				if (direction == '+' || direction == '-')
					break;//right input
				else//error
					printf("warning: enter direction with + or - !\n");//display error
			}

			

			rotate(platenumber, direction, BOARD);//rotate
			showboard(BOARD);//display board
			counter++; //next player's turn
		}
	}
	return 0;
}