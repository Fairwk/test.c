#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int myStrcmp(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	const char* p1 = str1;
	const char* p2 = str2;
	while (*p1 != '\0' && *p2 != '\0') {
		if (*p1 < *p2) {
			return -1;
		}
		else if (*p1 > *p2) {
			return 1;
		}
		else {//相等就是比较下一个字符
			p1++;
			p2++;
		}
	}
	//两个字符串不一样长
	if (*p1 < *p2) {
		return -1;
	}
	else if (*p1 > *p2) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	char str1[] = "hallo";
	char str2[] = "hello";
	int n = myStrcmp(str1, str2);
	printf("%d\n", n);
	return 0;
}
//char* myStrcat(char* dest , const char* src ) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	//先找dest的结束位置
//	int destTail = 0;
//	while (dest[destTail] != '\0') {
//		destTail++;
//	}
//	//当循环结束的时候,destTail就指向\0的位置
//	//mystrcpy(dest + destTail, src);
//	int i = 0;
//	while (src[i] != '\0') {
//		dest[destTail + i] = src[i];
//		i++;
//	}
//	//最后把dest最后的位置设为\0
//	dest[destTail + i] = '\0';
//	return dest;
//}
//int main() {
//	char dest[1024] = "world";
//	char src[] = "hello";
//	myStrcat(dest, src);
//	printf("%s\n", dest);
//	return 0;
//}

//char* myStrcpy(char* dest, const char* src) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	int i = 0;
//	while (src[i] != '\0') {
//		dest[i] = src[i];
//		i++;
//	}
//	dest[i] = '\0';
//	return dest;
//}
//int main() {
	/*char dest[1024] = { 0 };
	char src[1024] = "hello";
	myStrcpy(dest, src);
	printf("%s\n", dest);*/
//}
//int findNum(int(*arr)[4], int to_find) {
//	int row = 0;
//	int col = 3;//选择右上角的数字作为出发点
//	while (row <= 3 && col >= 0) {
//		if (to_find > arr[row][col]) {
//			row++;
//		}
//		else if (to_find < arr[row][col]) {
//			col--;
//		}
//		else {
//			return 1;
//		}
//	}
//	return 0;
//}
//int main() {
//	int arr[4][4] = { 1,2,8,9,
//					 2,4,9,12,
//					 4,7,10,13,
//					 6,8,11,15 };
//	int n;
//	printf("请输入您要查找的数:");
//	scanf("%d", &n);
//	if (findNum(arr, n)) {
//		printf("找到了!\n");
//	}
//	else {
//		printf("没找到!\n");
//	}
//	return 0;
//}