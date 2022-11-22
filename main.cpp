#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"
#define BINGONUM_HOLE -1
#define BINGO_RES_UNFINISHED  -1
#define BINGO_RES_FINISHED  0
#define N_LINE 2


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int get_number(void)
{
	int selNum=0;
	
	do {
		printf("select a number: ");
		scanf("%d",&selNum);
		fflush(stdin);
		
		if (selNum <1 || selNum>N_SIZE*N_SIZE || bingo_checkNum(selNum)== BINGO_NUMSTATUS_ABSENT)
	    {
			printf("%i is not on the board! select other one.\n",selNum);
	    }
	} while (selNum <1 || selNum>N_SIZE*N_SIZE || bingo_checkNum(selNum)== BINGO_NUMSTATUS_ABSENT);
	return selNum;
} 

int check_gameEnd(void){
    int res= BINGO_RES_UNFINISHED;
    if(bingo_countCompletedLine()>=N_LINE)
       res=BINGO_RES_FINISHED;
    return res;
}

int main(int argc, char** argv) {
	srand(unsigned(time(NULL)));
	
	printf("=====================================================================\n");
	printf("                           BINGO GAME                                \n");
	printf("=====================================================================\n\n\n\n");
	
	
	bingo_init();
	

	while(check_gameEnd()==BINGO_RES_UNFINISHED){
		bingo_printBoard();
		printf("No. of completed line :%i\n",bingo_countCompletedLine());
        int selNum=get_number();
        printf("%i\n",selNum);
        bingo_inputNum(selNum);
	}

    
		
	
	

	
	
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
