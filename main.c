#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoboard.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int get_number(void){ //사용자에게 숫자 입력받기 
	int selnum=0;
	do{
		printf("select a number:");
		scanf("%d",&selnum);
		fflush(stdin);
		
		if(selnum<1||selnum>N_SIZE*N_SIZE||bingo_checknum(selnum)==bingo_numstatus_absent)
		{
			printf("%i is not on the board! select other one./n",selnum);
		}
			
	}while(selnum<1||selnum>N_SIZE*N_SIZE||bingo_checknum(selnum)==bingo_numstatus_absent);
	
	return selnum;
}

int check_gameend(void){

	if(bingo_countcompletedline()>=N_BINGO){
		//ending
		printf("\n\n\n\n\n\n\n\n\n\n");
		printf("******************************\n");
		printf("*****CONGRATULATION!!!!!******\n");
		printf("*********You win!!!!!*********\n");
		printf("******************************\n");	
	}

}

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL)); //***
	//opening 
	printf("=================\n");
	printf("******BINGO******\n");
	printf("=================\n");
	
	//game
	
	//빙고보드 만들기=>랜덤하게 for문 2번 돌려서 2차원 배열 만들기  
	//while문 사용해서 반복으로 초기화
	
	/*while(게임이 끝날때까지 반복=>게임이 안끝나는 조건)줄수가 N_BINGO 보다 작음{
		bingo 보드가매번출력
		완성된 줄수 출력
		숫자입력 //main에서 코딩 
		보드에 입력한 숫자 지우기 
		 
	*/
	
	bingo_init();
	bingo_printboard();
	int	selnum=get_number();
	bingo_inputnum(selnum);
	printf("completed lines:%i\n",bingo_countcompletedline());
	bingo_printboard();
	
	while(bingo_countcompletedline()<=bingo_res_unfinished){
		int	selnum=get_number();
		bingo_inputnum(selnum);
		printf("completed lines:%i\n",bingo_countcompletedline());
		bingo_printboard();
	} 
	
	check_gameend();

	return 0;
}
