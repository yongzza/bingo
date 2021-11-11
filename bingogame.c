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

void StartbingoGame(int *record)
{
	int userBingo[25]; 
	int comBingo[25]; 
	int userCount; 
	int comCount; 
	int isTurn = 0; 
	srand((unsigned int)time(NULL)); 

	initBingo(userBingo); 
	initBingo(comBingo); 
	while (1) 
	{
		userCount = checkBingo(userBingo); 
		comCount = checkBingo(comBingo); 
		BingoBoard(userBingo); 
						
		printf("사용자 : %d줄 빙고\n", userCount);
		printf("컴퓨터 : %d줄 빙고\n", comCount);

		if ((userCount >= 5 && isTurn) || (userCount >= 5 && comCount < 5))
		{
			printf("사용자의 %d줄 빙고로 승리했습니다.\n", userCount);
			record[0]++; 
			record[1]++; 
			break; 
		}

		else if (comCount >= 5)
		{
			printf("컴퓨터의 %d줄 빙고로 패배했습니다.\n", comCount);
			record[0]++; 
			record[2]++; 
			break;
		}
		isTurn = !isTurn;

		if (isTurn) 
			inputNum(userBingo, comBingo);
		else 
			randNum(userBingo, comBingo);

	}
}