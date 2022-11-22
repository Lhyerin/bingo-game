#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"
#define BINGONUM_HOLE -1
#define BINGO_NUMSTATUS_ABSENT    -1
#define BINGO_NUMSTATUS_PRESENT    0


static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

void bingo_init(void){
	int i,j, cnt=1;
	for(i=0;i<N_SIZE;i++)
	   for (j=0;j<N_SIZE;j++)
	   {
	   	bingoBoard[i][j]=cnt;
	   	numberStatus[cnt-1]=N_SIZE*i+j;
	   	cnt++;
	   }
	
}

void bingo_printBoard(void){
	int i,j;
	
	printf("=====================================\n");
	for(i=0;i<N_SIZE;i++){
		for(j=0;j<N_SIZE;j++){
			if (bingoBoard[i][j]>0)
			    printf("%i\t", bingoBoard[i][j]);
			else
			    printf("X\t");
		}
		printf("\n");
	}
	printf("=====================================\n\n");
}
void bingo_inputNum(int sel){
	int i,j;
	i = numberStatus[sel-1]/N_SIZE;
	j =numberStatus[sel-1]%N_SIZE; 
	
	bingoBoard[i][j]=BINGONUM_HOLE;
}
int bingo_countCompletedLine(void){
	int i,j;
	int cnt=0;
	int checkBingo;
	for(i=0; i<N_SIZE; i++){
		checkBingo =1;
		for (j=0;j<N_SIZE;j++){
			if (bingoBoard[i][j]> 0){
				checkBingo=0;
				break;
			}
		}
		if (checkBingo ==1){
			cnt++;
		}
	}
	
	for(j=0;j<N_SIZE;j++){
		checkBingo=1;
		for(i=0;i<N_SIZE;i++){
			if(bingoBoard[i][j]>0){
			    checkBingo=0;
			    break;
		    }
    	}
		if(checkBingo==1){
		   cnt++;
	    }
	}
	for(i=0;i<N_SIZE;i++){
		checkBingo=1;
		if(bingoBoard[i][i]>0){
			checkBingo=0;
			break;
		}
   }
	if(checkBingo==1){
   	    cnt++;
    }
	
	for(i=0;i<N_SIZE;i++){
		checkBingo=1;
		if(bingoBoard[i][N_SIZE-1-i]>0){
			checkBingo=0;
			break;
		}
   }
	if(checkBingo==1){
   	    cnt++;
    }				
   return cnt;
}

int bingo_checkNum(int selNum)
{
	if(numberStatus[selNum-1]==BINGONUM_HOLE)
	  return BINGO_NUMSTATUS_ABSENT;
	  
	return BINGO_NUMSTATUS_PRESENT;
}
