#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int findRound(const char* str, char* find) {
	char tmp[256] = { 0 };//用辅助空间将原字符串做成两倍原字符串
	strcpy(tmp, str);//先拷贝一遍
	strcat(tmp, str);//在连接一遍
	return strstr(tmp, find) != NULL;
}
int main() {
	printf("%d\n", findRound("AABCD", "BCDAB"));
	return 0;
}

//void leftRound(char* src, int time) {
//	int i, j, tmp;
//	int len = strlen(src);
//	time %= len;
//	for (i = 0; i < time; i++) {
//		tmp = src[0];
//		for (j = 0; j < len - 1; j++) {
//			src[j] = src[j + 1];
//		}
//		src[j] = tmp;
//	}
//}
//int main() {
//	char src[] = "ABCD";
//	int k = 2;
//	printf("左旋前:%s\n", src);
//	leftRound(src, k);
//	printf("左旋后:%s\n", src);
//	return 0;
//}
//int checkData(int* p) {
//	int tmp[7] = { 0 };
//	int i;
//	for (i = 0; i < 5; i++) {
//		if (tmp[p[i]] == 1) {//如果这个位置是1,就说明重复就返回0
//			return 0;
//		}
//		tmp[p[i]] = 1;//不重复就赋值1
//	}
//	return 1;
//}
//int main() {
//	int p[5];
//	for (p[0] = 1; p[0] <= 5; p[0]++) {
//		for (p[1] = 1; p[1] <= 5; p[1]++) {
//			for (p[2] = 1; p[2] <= 5; p[2]++) {
//				for (p[3] = 1; p[3] <= 5; p[3]++) {
//					for (p[4] = 1; p[4] <= 5; p[4]++) {
//						if ((p[1] == 2) + (p[0] == 3) == 1 &&
//							(p[1] == 2) + (p[4] == 4) == 1 &&
//							(p[2] == 1) + (p[3] == 2) == 1 &&
//							(p[2] == 5) + (p[3] == 3) == 1 &&
//							(p[4] == 4) + (p[0] == 1) == 1 &&
//							checkData(p)
//							) {
//							for (int i = 0; i < 5; i++) {
//								printf("%d", p[i]);
//							}
//							putchar('\n');
//						}
//						
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//int main() {
//	int murder[4] = { 0 };
//	int i;
//	
//	for (i = 0; i < 4; i++) {
//		murder[i] = 1;
//		if ((murder[0] != 1) + (murder[2] == 1) + (murder[3] == 1) + (murder[3] != 1) == 3) {
//			break;
//		}
//		murder[i] = 0;
//	}
//	putchar('A' + i);
//	return 0;
//}

//void yanghuiTriangle(int n) {
//	int data[30][30] = { 1 };
//	int i, j;
//	for (i = 1; i < n; i++) {
//		data[i][0] = 1;
//		for (j = 1; j <= i; j++) {
//			data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
//		}
//	}
//	for (i = 0; i < n; i++) {
//		for (j = 0; j <= i; j++) {
//			printf("%d", data[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main() {
//
//	yanghuiTriangle(20);
//	return 0;
//}