
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#define COLS 60
#define ROWS 30

int main()
{
	// a escape sequence in c to hide cursor
	printf("\e[?25l");

	// Switch to canonical mode, disable echo
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	int x[1000], y[1000];
	int quit = 0;
	while (!quit)
	{
		// Render table
		printf("┌");
		for (int i = 0; i < COLS; i++)
			printf("─");
		printf("┐\n");

		for (int j = 0; j < ROWS; j++)
		{
			printf("│");
			for (int i = 0; i < COLS; i++)
				printf("·");
			printf("│\n");
		}

		printf("└");
		for (int i = 0; i < COLS; i++)
			printf("─");
		printf("┘\n");

	/*
	
	*/
	}