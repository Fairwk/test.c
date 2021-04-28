#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h >
#include <windows.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]){
    //men => memory �ڴ�
	//set:����,����
	//memset �Ĺ��ܾ��ǰ�һ���ڴ��ϵ�ÿ���ֽڶ����ó�һ�������ֵ
    //��ά�����ÿ��Ԫ�ض�����һ���������ڴ�ռ��ϲ��ֵ�
	memset(showMap, '*', MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	//�������ʮ��λ����Ϊ����
	//�������������
	srand((unsigned int)time(0));
	int mineCount = 0;
	while (mineCount < MINE_COUNT) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			continue;
		}
		mineMap[row][col] = '1';
		mineCount++;
	}
	
}

//ϣ����һ������ͬʱ�߱���ӡ���ֵ�ͼ�Ĺ���
//ȡ����ʵ����ɶ
void print(char theMap[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			printf("%c ",theMap[row][col]);
		}
		printf("\n");
	}
}

void update(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL], int row, int col) {
	//��ʾ��Χ���׵ĸ���
	int count = 0;
	for (int r = row - 1; r < row + 1; r++) {
		for (int c = col - 1; c < col + 1; c++) {
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL) {
				//��ʱr,c�������̵ķ�Χ,ֱ������
				continue;
			}
			if (r == row && c == col) {
				//����Ҫ�ж�,ֱ���´�ѭ��
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	//���ֱ�Ӹ�ֵ,��ʱ����count��2,
	//��ǰrow,col λ�õ�Ԫ�ر����ó� ASCIIֵΪ2���ַ�
	//�������ַ�'2'
	//������������ת��,ֻ��C��������ôд
	//�����������������,һ�㲻�����ַ����ͺ��������ͽ���ת��
	showMap[row][col] = '0' + count;
}
int main() {
	//������ͼ����ʼ��
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedCount = 0;
	while (1) {
		//��������
		system("cls");
		//2.��ӡ��ͼ
		print(showMap);
		//print(mineMap);
		int row = 0;
		int col = 0;
		printf("����������(row,col):");
		scanf("%d %d", &row, &col);
		//���кϷ����ж�
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("���������������!����������!\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("�������λ���Ѿ�����!����������!\n");
			continue;
		}
		//4.�ж��Ƿ����
		if (mineMap[row][col] == '1') {
			printf("��������!!��Ϸ����!\n");
			break;
		}
		//����showMap,��ʾ��ǰ��Χ�ж��ٸ���
		update(showMap, mineMap, row, col);
		//6.������Ϸʤ�����ж�,ͳ�Ƶ�ǰһ�������˶��ٸ�����
		openedCount++;
		if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("��ϲ��,��ʤ��!\n");
			break;
		}
	}

	//print(mineMap);
	return 0;
}
//���������еĽϴ�ֵ
//int main() {
//	int a, b, c;
//	scanf("%d %d", &a, &b);
//	c = Max(a, b);
//	printf("%d", c);
//	return 0;
//}
////дmax����
//int Max(int x, int y){
//	int z;
//	if (x > y) {
//		z = x;
//	}
//	z = y;
//	return(z);
//}
//����������֮��
//int main() {
//	int a, b, sum;
//	a = 123;
//	b = 456;
//	sum = a + b;
//	printf("sum=%d", sum);
//	return 0;
//}