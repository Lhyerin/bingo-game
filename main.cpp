#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"
#define BINGONUM_HOLE -1

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	srand(unsigned(time(NULL)));
	
	printf("=====================================================================\n");
	printf("                           BINGO GAME                                \n");
	printf("=====================================================================\n\n\n\n");
	
	
	//GAME
	
	//INITIAL BINGO BOARD
	bingo_init();
	bingo_inputNum(5);
	bingo_printBoard();
	bingo_inputNum(12);
	bingo_printBoard();
	/*
	while (game is not end) // 홀수가 N_BINGO보다 작음
	{
	    //bingo board print
		//print no. of completed line
		//select a number
		//update the board status
    } 
	
	*/
	
	
	
	//ENDING
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("=====================================================================\n");
	printf("                        CONGRATULATION!!!!!!                         \n");
	printf("                              YOU WIN                                \n");
	printf("=====================================================================\n");
	return 0;
}
