#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoboard.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int get_number(void){ //����ڿ��� ���� �Է¹ޱ� 
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
	
	//������ �����=>�����ϰ� for�� 2�� ������ 2���� �迭 �����  
	//while�� ����ؼ� �ݺ����� �ʱ�ȭ
	
	/*while(������ ���������� �ݺ�=>������ �ȳ����� ����)�ټ��� N_BINGO ���� ����{
		bingo ���尡�Ź����
		�ϼ��� �ټ� ���
		�����Է� //main���� �ڵ� 
		���忡 �Է��� ���� ����� 
		 
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
