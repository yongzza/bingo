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
		printf("1. ���� ���� ����\n");
		printf("2. ���� ����\n");
		printf("3. ���α׷� ����\n");
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
						
		printf("����� : %d�� ����\n", userCount);
		printf("��ǻ�� : %d�� ����\n", comCount);

		if ((userCount >= 5 && isTurn) || (userCount >= 5 && comCount < 5))
		{
			printf("������� %d�� ����� �¸��߽��ϴ�.\n", userCount);
			record[0]++; 
			record[1]++; 
			break; 
		}

		else if (comCount >= 5)
		{
			printf("��ǻ���� %d�� ����� �й��߽��ϴ�.\n", comCount);
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