#include <stdio.h>
#include <time.h> 
#include <Windows.h> 

void StartbingoGame(int*);
void Recordbingo(int*); 
void initBingo(int*); 
int CheckBingo(int*); 
void BingoBoard(int*); 
void inputNum(int*, int*); 
void randNum(int*, int*); 
						  
int main() 
{
	int menu; 
	int record[3] = { 0 };
	while (1)
	{
		printf("1. 빙고 게임 시작\n");
		printf("2. 전적 보기\n");
		printf("3. 프로그램 종료\n");
		scanf_s("%d", &menu); 
		switch (menu) 
		{
		case 1:
			StartbingoGame(record);
			break;
		case 2:
			Recordbingo(record);
			break;
		case 3:
			return 0;
		default:
			break;
		}
		system("pause"); 
		system("cls"); 
	}
	return 0;
}