////写一个函数，判断一个字符串是否为另一个字符串旋转之后的字符串。
////例如：给定s1 = AABCD和s2 = BCDAA，返回1
////给定s1 = abcd和s2 = ACBD，返回0.
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//int findRound(const char* str, char* find) {
//	char tmp[256] = { 0 };
//	strcpy(tmp, str);
//	strcat(tmp, str);
//	return strstr(tmp, find) != NULL;
//}
//	
//int main() {
//		printf("%d\n", findRound("AABCD", "BCDAB"));
//		return 0;
//	}

//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，
//矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
#include<stdio.h>
int findNum(int a[][3], int x, int y, int f) {
	int i = 0, j = x - 1;
	while (j >= 0 && i < y) {
		if (a[i][j] < f) {
			i++;
		}
		else if (a[i][j] > f) {
			j--;
		}
		else {
			return 1;
		}
	}
	return 0;
}

int main() {
	int a[][3] = { {2,4,6},{3,5,7},{4,8,9} };
	if (findNum(a, 3, 3, 2)) {
		printf("It has been found!\n");
	}
	else {
		printf("It hasn't been found!\n");
	}
	return 0;
}
