#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoboard.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
	bingo_inputnum(5);
	bingo_printboard();
	bingo_inputnum(12);	
	
	//ending
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("******************************\n");
	printf("*****CONGRATULATION!!!!!******\n");
	printf("*********You win!!!!!*********\n");
	printf("******************************\n");
	
	return 0;
}
