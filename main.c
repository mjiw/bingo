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
