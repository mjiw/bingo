#include <stdio.h> 
#include "bingoboard.h" 
 
#define bingo_numhole	-1

static int bingoboard[N_SIZE][N_SIZE];	 //2���� �迭���� 
static int numberstatus[N_SIZE*N_SIZE];	// �� �ٸ� �迭�� ���� �迭 ��ġ(�ε���) ���� //5*5

void bingo_init(void){
	
	int i, j, k;
	int randNum; //���� ��ȣ (����� ���ڸ� ����) 
	int maxNum = N_SIZE*N_SIZE; //���� �����ִ� �� 
	
	for (i=0;i<N_SIZE*N_SIZE;i++)
		numberstatus[i] = bingo_numstatus_absent;
		
	for (i=0;i<N_SIZE;i++){
	
		for (j=0;j<N_SIZE;j++){
			randNum = rand()%maxNum; //���� ���� ����  
			
			for (k=0;k<N_SIZE*N_SIZE;k++){
				if (numberstatus[k] == bingo_numstatus_absent ){ //���� k+1�� ���� �Ҵ��� �ȵǾ� �ִٸ�  
					if (randNum == 0) //k+1 �� randNum��° �����̸�  
						break;
					else
						randNum--; //�׷��� ������ �ϳ� ����  
				}
			}
			//���� k+1�� �Ҵ� 
			numberstatus[k] = i*N_SIZE + j;
			bingoboard[i][j] = k+1;
			maxNum--;
		}
	}
}

int bingo_countcompletedline(void){ //�ϼ��� �� �� ��� �Է��� �ʿ���� return�� ������ 
	int i,j;
	int cnt=0;
	int checkbingo; //flag���� 
	

	
	//�밢�� Ȯ��(�ִ밢��) 
	for(i=0;i<N_SIZE;i++){
		if(bingoboard[i][i]>0){
			checkbingo=0;
		}
		else if(bingoboard[i][i]==bingo_numhole){
			checkbingo=1;
		}
	}
	//�밢�� Ȯ��(�δ밢��) 
	for(i=0;i<N_SIZE;i++){
		if(bingoboard[i][4-i]>0){
			checkbingo=0;
		}
		else if(bingoboard[i][4-i]==bingo_numhole){
			checkbingo=1;
		}
		
	}
	if(checkbingo==1){
		cnt++;
	}
	
	//�� Ȯ�� 
	for(j=0;j<N_SIZE;j++){
		checkbingo=1;
		for(i=0;i<N_SIZE;i++){
				if(bingoboard[i][j]>0){
					checkbingo=0; //���ڰ� �����ϸ� flag ���� 
					break;
				}	
		}
		
		if(checkbingo==1){
			cnt++;
		}
	}
	
	//�� Ȯ�� 
	for(i=0;i<N_SIZE;i++){
		checkbingo=1;
		for(j=0;j<N_SIZE;j++){
				if(bingoboard[i][j]>0){
					checkbingo=0; //���ڰ� �����ϸ� flag ���� 
					break;
				}	
		}
		
		if(checkbingo==1){
			cnt++;
		}
	}
	return cnt;
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

int bingo_checknum(int selnum){
	if(numberstatus[selnum-1]==bingo_numhole){
		return bingo_numstatus_absent;
	}
	else{
		return bingo_numstatus_present;
	}
	
}
