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

void Recordbingo(int *record)
{
	if (record[0])
	{
		printf("\n********** ���� ���� **********\n");
		printf("%d�� %d�� %d��\n", record[0], record[1], record[2]);
	}
	else
		printf("������ �����ϴ�...\n");
}

void initBingo(int *bingo)
{
	int i; 
	int sour, dest; 
	int temp; 
	for (i = 0; i < 25; i++) 
		bingo[i] = i + 1; 

	for (i = 0; i < 100; i++)
	{
		sour = rand() % 25; 
		dest = rand() % 25; 
		temp = bingo[sour]; 
		bingo[sour] = bingo[dest]; 
		bingo[dest] = temp; 
	}
}

void BingoBoard(int *bingo)
{
	system("cls"); 
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 1, 6, 6, 22, 6, 6, 22, 6, 6, 22, 6, 6, 22, 6, 6, 2);
	for (int i = 0; i < 5; i++)	
	{
		for (int j = 0; j < 5; j++)	
			if (bingo[(i * 5) + j] == 35)	
				printf("%c #", 5);	
			else	
				printf("%c%2d", 5, bingo[(i * 5) + j]);
		printf("%c\n", 5);	
		if (i != 4)	
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 25, 6, 6, 16, 6, 6, 16, 6, 6, 16, 6, 6, 16, 6, 6, 23);
	}
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 3, 6, 6, 21, 6, 6, 21, 6, 6, 21, 6, 6, 21, 6, 6, 4);

}
