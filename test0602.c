////дһ���������ж�һ���ַ����Ƿ�Ϊ��һ���ַ�����ת֮����ַ�����
////���磺����s1 = AABCD��s2 = BCDAA������1
////����s1 = abcd��s2 = ACBD������0.
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

//���Ͼ���
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�
//������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
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
