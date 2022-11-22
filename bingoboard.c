#include <stdio.h> 
#include "bingoboard.h" 
 
#define bingo_numhole	-1

static int bingoboard[N_SIZE][N_SIZE];	 //2차원 배열선언 
static int numberstatus[N_SIZE*N_SIZE];	// 또 다른 배열을 만들어서 배열 위치(인덱스) 저장 //5*5

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

int bingo_countcompletedline(void){ //완성된 줄 수 계산 입력은 필요없음 return은 정수형 
	int i,j;
	int cnt=0;
	int checkbingo; //flag변수 
	
	int s=1;
	//대각선 확인(주대각선) 
	for(i=0;i<N_SIZE;i++){
		if(bingoboard[i][i]>0){
			checkbingo=0;
		}
		else if(bingoboard[i][i]==bingo_numhole){
			checkbingo=1;
		}
	}
	for(i=0;i<N_SIZE;i++){
		if(bingoboard[4-i][i]>0){
			checkbingo=0;
		}
		else if(bingoboard[4-i][i]==bingo_numhole){
			checkbingo=1;
		}
		
	}
	if(checkbingo==1){
		cnt++;
	}
	
	//열 확인 
	for(j=0;j<N_SIZE;j++){
		checkbingo=1;
		for(i=0;i<N_SIZE;i++){
				if(bingoboard[i][j]>0){
					checkbingo=0; //숫자가 존재하면 flag 내림 
					break;
				}	
		}
		
		if(checkbingo==1){
			cnt++;
		}
	}
	
	//행 확인 
	for(i=0;i<N_SIZE;i++){
		checkbingo=1;
		for(j=0;j<N_SIZE;j++){
				if(bingoboard[i][j]>0){
					checkbingo=0; //숫자가 존재하면 flag 내림 
					break;
				}	
		}
		
		if(checkbingo==1){
			cnt++;
		}
	}
	printf("\n");
	printf("completed lines:%i\n",cnt);
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
			} //\t 줄맞추기 
		}
		printf("\n");
	}
	printf("=========================================\n");
}

void bingo_inputnum(int sel){//입력한 숫자 빙고판에 업데이트
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
