## Bingo game

5 X 5 빙고판으로 숫자는 1 ~ 25로 설정합니다.
각각의 숫자는 배열에 저장해서 셔플을 통해 섞습니다.

**EX)**
1|5|9|22|25
---|---|---|---|---|
3|6|8|21|24
2|4|10|16|15
7|11|13|18|23
12|14|19|17|20

user와 컴퓨터는 한 번씩 턴을 돌아가면서 
user는 입력을 컴퓨터는 랜덤한 숫자를 생성합니다.

그 숫자가 있는 위치를 체크하고 새롭게 빙고가 된 줄이 있는지 체크합니다.


5줄 빙고가 완성되면 승리하며 게임이 종료됩니다.
동시에 5줄 빙고가 되면 그 때 턴을 갖는 user 혹은 컴퓨터가 승리하게 됩니다.