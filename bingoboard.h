#define N_SIZE 	5
#define bingo_numstatus_absent	-1
#define bingo_numstatus_present	0
#define bingo_res_unfinished	1
#define N_BINGO	2

void bingo_init(void);
int bingo_countcompletedline(void); //�ϼ��� �� �� ��� �Է��� �ʿ���� return�� ������ 
void bingo_printboard(void);
void bingo_inputnum(int sel); //�Է��� ���� �����ǿ� ������Ʈ
int bingo_checknum(int selnum); //���� �Է��� ���ڰ� �ִ��� ������ Ȯ�� 
 
