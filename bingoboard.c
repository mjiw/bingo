#include <stdio.h> 
#include "bingoboard.h" 
 
#define bingo_numhole	-1

static int bingoboard[N_SIZE][N_SIZE];	 //2���� �迭���� 
static int numberstatus[N_SIZE*N_SIZE];	// �� �ٸ� �迭�� ���� �迭 ��ġ(�ε���) ���� //5*5

void bingo_init(void){
	int i,j;
	int cnt=1;
	
	for(i=0;i<N_SIZE;i++){
		for(j=0;j<N_SIZE;j++){
			if(cnt==15){
				bingoboard[i][j]=bingo_numhole;
				numberstatus[cnt-1]=i*N_SIZE+j;
				cnt++;
			}
			else{
				numberstatus[cnt-1]=i*N_SIZE+j;
				bingoboard[i][j]=cnt++;
			
			}
		}
	}
}

int bingo_countcompletedline(void){ //�ϼ��� �� �� ��� �Է��� �ʿ���� return�� ������ 

}

void bingo_printboard(void){
	int i,j;
	printf("========================================\n");
	for(i=0;i<N_SIZE;i++){
		for(j=0;j<N_SIZE;j++){
			if(bingoboard[i][j]==bingo_numhole){
				printf("X\t");
			}
			else{
				printf("%i\t",bingoboard[i][j]);
			} //\t �ٸ��߱� 
		}
		printf("\n");
	}
	printf("=========================================\n");
}

void bingo_inputnum(int sel){//�Է��� ���� �����ǿ� ������Ʈ
	int rowindex=numberstatus[sel-1]/N_SIZE;
	int columnindex=numberstatus[sel-1]%N_SIZE;
	
 	int i,j;
	int cnt=1;
	
	for(i=0;i<N_SIZE;i++){
		for(j=0;j<N_SIZE;j++){
			if(bingoboard[i][j]==bingoboard[rowindex][columnindex]){
				bingoboard[i][j]=bingo_numhole;
			}
		}
	}
	
}
