#include <stdio.h> //표준 입출력 함수 사용을 위한 헤더
#include <time.h> //시간 함수 사용을 위한 헤더
#include <Windows.h> //windows 함수 사용을 위한 헤더

void StartbingoGame(int*); //빙고게임 시작 함수 선언
void Recordbingo(int*); //게임 전적을 출력하는 함수 선언
void initBingo(int*); //빙고판을 초기화하는 함수 선언
int CheckBingo(int*); //빙고를 체크하는 함수 선언
void BingoBoard(int*); //빙고판을 출력하는 함수 선언
void inputNum(int*, int*); //숫자 입력하는 함수 선언
void randNum(int*, int*); //랜덤 숫자 지정하는 함수 선언
						  
int main() 
{
	int menu; //menu= 1,2,3번 메뉴를 입력 받아줄 변수
	int record[3] = { 0 }; //전적을 보관할 배열
	while (1)  //프로그램 종료 메뉴를 입력하기 전까지 무한 반복
	{
		printf("▶① 빙고 게임 시작\n");
		printf("▶② 전적 보기\n");
		printf("▶③ 프로그램 종료\n");
		scanf_s("%d", &menu); //메뉴 선택
		switch (menu) //입력에 따른 처리
		{
		case 1:
			//게임 시작 전적을 보관할 배열의 이름을 적는다.
			StartbingoGame(record);
			break;
		case 2:
			Recordbingo(record);
			break;
		case 3:
			//프로그램 종료
			return 0;
		default:
			//메뉴 외 입력은 아무것도 하지 않도록 한다.
			break;
		}
		system("pause"); //계속하려면 아무 키나 누르십시오 ... 라는 메세지가 나오며 일시 정지한다. 
		system("cls"); //화면을 깨끗하게 지워준다.
					   //이 두 함수를 통해서 매번 화면이 깔끔하게 갱신되도록 한다.
	}
	return 0;
}

void StartbingoGame(int *record)
{
	int userBingo[25]; //유저의 빙고판
	int comBingo[25]; //컴퓨터의 빙고판
	int userCount; //유저의 빙고수
	int comCount; //컴퓨터의 빙고수
	int isTurn = 0; //현재 사용자의 턴인지, 컴퓨터의 턴인지 구분하기 위한 스위치 변수, 이 값이 1일때 유저의 턴이다.
	srand((unsigned int)time(NULL)); // rand 랜덤 함수의 시드값을 현재 시간으로 지정.

	initBingo(userBingo); //유저 빙고 초기화 
	initBingo(comBingo); //컴퓨터 빙고 초기화
						 //두 배열 다 1~25가 채워진 후 뒤섞인 상태가 된다.
	while (1) //승패가 갈리기 전까지 무한반복
	{
		userCount = checkBingo(userBingo); //유저의 빙고수를 체크하여 변수에 대입한다.
		comCount = checkBingo(comBingo); //컴퓨터의 빙고수를 체크하여 변수에 대입한다.
		BingoBoard(userBingo); //유저의 빙고판을 보여준다.
						
		printf("사용자 : %d줄 빙고\n", userCount); //각각 빙고수를 출력해준다.
		printf("컴퓨터 : %d줄 빙고\n", comCount);

		if ((userCount >= 5 && isTurn) || (userCount >= 5 && comCount < 5))//현재 유저의 빙고수가 5를 넘고 유저의 턴인 경우
																	//유저의 빙고수가 5를 넘으며 컴퓨터의 빙고수가 5를 넘지 못한 경우 유저의 승리
		{
			printf("사용자의 %d줄 빙고로 승리했습니다.\n", userCount); //사용자 승리 출력, 전적을 증가시킨다
			record[0]++; //전적 증가
			record[1]++; //승리 증가
			break; 
		}

		else if (comCount >= 5)//컴퓨터의 빙고수가 5를 넘으면 사용자 패배
		{
			printf("컴퓨터의 %d줄 빙고로 패배했습니다.\n", comCount); //사용자 패배 출력, 전적을 증가시킨다
			record[0]++; //전적 증가
			record[2]++; //패배 증가
			break;
		}
		isTurn = !isTurn; //항상 한 번씩 돌아가기 때문에 현재 턴을 바꿈

		if (isTurn) //isturn 값이 1이면 유저에게 입력을 받음
			inputNum(userBingo, comBingo);
		else //0인 경우 컴퓨터가 랜덤한 수를 지정함
			randNum(userBingo, comBingo);

	}
}

void Recordbingo(int *record)//전적을 출력한다
{
	if (record[0]) 
	{
		printf("\n********** 현재 전적 **********\n");
		printf("%d전 %d승 %d패\n", record[0], record[1], record[2]);
	}
	else
		printf("전적이 없습니다...\n");
}

void initBingo(int *bingo)
{
	int i; //반복을 위한 index 변수
	int sour, dest; //맞교환할 두 개의 index를 담아놓을 변수
	int temp; //맞교환을 위해 임시로 값을 보관할 변수
	for (i = 0; i < 25; i++) // i는 0부터 24까지 증가하며
		bingo[i] = i + 1; //배열의 값을 1 ~ 25로 대입

	for (i = 0; i < 100; i++) //100번 동안 랜덤한 숫자들의 위치를 맞교환해서 뒤섞는다.
	{
		sour = rand() % 25; //맞 바꿀 위치 각각 2개 지정 rand 함수의 결과를 25로 나눈 나머지를 저장
		dest = rand() % 25; //0 ~ 24라는 값이 들어가게 된다.
		temp = bingo[sour]; //맞바꿀 값을 우선 temp 변수에 저장해둔다.
		bingo[sour] = bingo[dest]; //sour에 dest 값을 저장하고
		bingo[dest] = temp; //dest에는 처음에 빼놓은 temp값을 저장한다.
	}
}

void BingoBoard(int *bingo)
{
	system("cls"); //화면을 깨끗하게 지워준다.
				   //빙고판을 그리기 위해 아스키 코드 문자들(맨 윗줄┌ ─ ┬ ┐ 이런 모양)을 찍어준다.
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 1, 6, 6, 22, 6, 6, 22, 6, 6, 22, 6, 6, 22, 6, 6, 2);
	for (int i = 0; i < 5; i++)	//5X5 행열을 출력하기 위한 행 반복
	{
		for (int j = 0; j < 5; j++)	//5X5 행열을 출력하기 위한 열 반복
			if (bingo[(i * 5) + j] == 35) //만약 현재 출력할 숫자가 체크된 것이면
				printf("%c #", 5); //칸 모양과 #을 출력한다. (│ # 이러한 모양)	
			else //아닌 경우 칸 모양과 해당 숫자를 출력한다.(│ 3 이러한 모양)	
				printf("%c%2d", 5, bingo[(i * 5) + j]); 
		printf("%c\n", 5);	//한 줄의 끝 문자를 출력 한 뒤에 개행한다.(│)
		if (i != 4)	//마지막 행이 아닌 동안에는 계속 중간 줄을 출력한다. (├ ─ ┼ ┤ )
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 25, 6, 6, 16, 6, 6, 16, 6, 6, 16, 6, 6, 16, 6, 6, 23);
	}
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 3, 6, 6, 21, 6, 6, 21, 6, 6, 21, 6, 6, 21, 6, 6, 4); //맨 밑줄 칸을 그려준다.

}

int checkBingo(int *bingo)
{
	int bingoCheck[12] = { 0 }; //최대 12개의 빙고 체크판을 0으로 초기화한다.
	int count = 0;	//빙고 수를 저장할 변수이며 함수의 끝에서 이 변수를 반환한다.
	int i, j; //반복을 위한 Index 변수: 가로, 세로, 대각선 총 5줄 빙고를 확인한다.

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{

			if (bingo[i * 5 + j] == 35) //가로 확인(행이 같고 열이 다른 즉, 첫줄 왼쪽부터 오른쪽까지, 두번째줄~다섯번째줄)
				bingoCheck[i]++;

			if (bingo[j * 5 + i] == 35)//세로 확인(열이 같고 행이 다른 즉 첫열 위부터 아래까지, 두번째줄~다섯번째줄)
				bingoCheck[i + 5]++;
		}
		for (j = i; j <= i; j++) //대각선 확인(행과 열이 같아서 왼쪽 위에서부터 오른쪽 아래쪽으로 가는 대각선을 확인한다.)
			if (bingo[i * 5 + j] == 35)
				bingoCheck[10]++;
	}
	for (i = 4; i >= 0; i--) //왼쪽 아래에서 오른쪽 위로 가는 대각선 빙고를 확인한다.
		for (j = 4 - i; j >= 4 - i; j--)
			if (bingo[i * 5 + j] == 35)
				bingoCheck[11]++;

	for (i = 0; i < 12; i++)//위에서 확인한 빙고의 수를 센다.
		if (bingoCheck[i] == 5)	//해당 변수의 값이 5이면 빙고이므로 count 변수의 값을 증가한다.
			count++;
	return count;
}

void inputNum(int *userBingo, int *comBingo)
{
	int num; //유저에게 입력받은 수를 저장할 변수	
	int isCheck; //이미 입력되어 체크된 것인지 확인할 변수	
	while (1) //정상적인 수가 입력될 때까지 무한 반복	
	{
		isCheck = 0; //체크되지 않았다고 초기화하고 시작한다.	
		printf("입력 : ");
		scanf_s("%d", &num);
		if (num < 1 || num > 25) //입력받은 수가 1~25 범위를 벗어난 경우 	
			printf("1 ~ 25 사이의 숫자를 입력해주세요\n"); //출력 후 다시 입력받는다.	
		else //정상적인 범위 내의 숫자인 경우	
		{
			for (int i = 0; i < 25; i++) //빙고 배열 25개를 모두 검사해서	
			{=
				if (userBingo[i] == num) //입력받은 수와 같은 수가 저장되어 있다면	
				{
					userBingo[i] = 35;	//그 값을 35라는 값으로 바꾸고(#의 아스키코드 값=35)
					isCheck = 1; //체크가 되었음을 저장한다.	
				}
				if (comBingo[i] == num)	//컴퓨터의 빙고판에도 동일하게 적용한다.
				{
					comBingo[i] = 35; //isCheck 값은 이미 변경했으니 컴퓨터 빙고의 숫자값만 바꿔준다.	
				}
			}
			if (isCheck) //위 반복이 종료되고 체크가 되었으면	
				break;	//정상적인 입력으로 인한 체크로 반복을 종료하고
			else 	    //체크가 안되었으면 정상적인 입력이나 해당 수를 찾지 못한 것이므로
				printf("이미 입력한 숫자입니다.\n"); //해당 문자열을 출력하고 반복한다.	
		}
	}
}

void randNum(int *userBingo, int *comBingo)
{
	int num; //컴퓨터가 랜덤으로 정한 수를 저장할 변수	
	int isCheck; //이미 입력되어 체크된 것인지 확인할 변수	
	printf("컴퓨터 차례입니다.\n");	//유저에게 컴퓨터의 차례임을 알린다.
	Sleep(1000); //1초 멈추는 함수를 실행	
	while (1) //이미 입력되지 않은 수가 입력될 때까지 무한 반복한다.	
	{
		isCheck = 0; //체크되지 않았다고 초기화하고 시작한다	
		num = rand() % 25 + 1;	//랜덤 수를 지정한다. rand 함수로 나오는 결과에
								//% 25 연산을 해서 0 ~ 24 라는 결과를 얻고 + 1 연산을 통해 1 ~ 25 라는 결과값을 얻어낸다.
		for (int i = 0; i < 25; i++) //빙고 배열 25개를 모두 검사해서	
		{
			if (userBingo[i] == num) //입력받은 수와 같은 수가 저장되어 있다면	
			{
				userBingo[i] = 35; //그 값을 35라는 값으로 바꾸고(#의 아스키코드 값)	
				isCheck = 1; //체크가 되었음을 저장한다.	
			}
			if (comBingo[i] == num)	//컴퓨터의 빙고판에도 동일하게 적용한다.	
			{
				comBingo[i] = 35; //isCheck 값은 이미 변경했으니 컴퓨터 빙고의 숫자값만 바꿔준다.	
			}
		}
		if (isCheck) //위 반복이 종료되고 체크가 되었으면	
			break;	//정상적인 입력으로 인한 체크로 반복을 종료한다.
	}
	printf("컴퓨터가 입력한 숫자 : %d\n", num);	//컴퓨터가 입력한 숫자를 유저에게 알려준다.
	Sleep(1500); //1.5초 멈춰서 사용자가 충분히 반응할 수 있도록 해준다.	
}