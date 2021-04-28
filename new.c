#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_ROW 3
#define MAX_COL 3

 

void init(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chessBoard[row][col] = ' ';
		}
	}
	//设置随机种子
	srand((unsigned int)time(0));
}


void print(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("+--+--+--+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|");
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c |", chessBoard[row][col]);
		}
		printf("\n+--+--+--+\n");
	}
}
void playerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("玩家落子....\n");
	while (1) {
		printf("请输入坐标(row,col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//进行合法性校验,判定用户输入内容是否合法
		//如果不合法,让用户重新输入
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			continue;
		}
		if (chessBoard[row][col] !=' ') {
			printf("您输入的位置有子了,请重新输入!\n");
			continue;
		}
		//进行落子
		chessBoard[row][col] = 'x';
		break;
	}
}
void computerMove(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBoard[row][col] != ' ') {
			//这个位置已经有子了
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
	
	
}

int isFull(char chessBoard[MAX_ROW][MAX_COL]) {
	//遍历棋盘,看看有没有空格,有空格就是没满
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
//此处约定 如果返回 x 表示玩家获胜 返回 o 表示电脑获胜
//如果返回' ',表示胜负未分,还要继续下棋
//如果返回 q ,表示和棋
char isGameover(char chessBoard[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]) {
			return chessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			return chessBoard[0][col];
		}
	}
	if (chessBoard[0][0] != ' '
		&& chessBoard[0][0] == chessBoard[1][1]
		&& chessBoard[0][0] == chessBoard[2][2]) {
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '
		&& chessBoard[0][2] == chessBoard[1][1]
		&& chessBoard[0][2] == chessBoard[2][0]) {
		return chessBoard[0][2];
	}
	//判定是否和棋
	if (isFull(chessBoard) ){
		return 'q';
	}
	//胜负未分
	return ' ';
}
int main() {
	
	char chessBoard[MAX_ROW][MAX_COL];
		//1.对棋盘进行初始化
		init(chessBoard);
		char winner = ' ';
	while (1) {
		//打印棋盘之前先清屏
		system("cls");
		//2.打印棋盘 
		print(chessBoard);
		//3.玩家落子
		playerMove(chessBoard);
		//4.判定胜负(TODO)
		winner = isGameover(chessBoard);
		if (winner != ' ') {
			break;
		}
		//5.电脑落子
		computerMove(chessBoard);
        //6.判定胜负
	    winner = isGameover(chessBoard);
		if (winner != ' ') {
			break;
		}
	}
	print(chessBoard);
	if (winner == 'x') {
		printf("恭喜你赢了!\n");
	}
	else if (winner == 'o') {
		printf("你咋连人工智障都下不过!\n");
	}
	else {
		printf("你和人工智障五五开!\n");
	}
	return 0;
}