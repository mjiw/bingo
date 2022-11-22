#define N_SIZE 	5
#define bingo_numstatus_absent	-1
#define bingo_numstatus_present	0
#define bingo_res_unfinished	1
#define N_BINGO	2

void bingo_init(void);
int bingo_countcompletedline(void); //완성된 줄 수 계산 입력은 필요없음 return은 정수형 
void bingo_printboard(void);
void bingo_inputnum(int sel); //입력한 숫자 빙고판에 업데이트
int bingo_checknum(int selnum); //빙고에 입력한 숫자가 있는지 없는지 확인 
 
