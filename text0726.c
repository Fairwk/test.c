#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
void findDiffNum(int* arr, int size, int* px, int* py) {
	int num = 0;
	int i = 0;
	int pos = 0;
	for (i = 0; i < size; i++) {
		num ^= arr[i];
	}
	for (i = 0; i < 32; i++) {
		if (((num >> i) & 1) == 1) {
			pos = i;
			break;
		}
	}
	for (i = 0; i < size; i++) {
		if (((arr[i] >> pos) & 1 == 1)) {
			*px ^= arr[i];
		}
		else {
			*py ^= arr[i];
		}
	}
}
int main() {
	int arr[] = { 1,2,3,5,6,1,2,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int n1 = 0;
	int n2 = 0;
	findDiffNum(arr, size, &n1, &n2);
	printf("%d %d", n1, n2);
	return 0;
}
//enum {
//	INVALUE = 0,
//	VALUE
//};
//int num = INVALUE;
//int my_atoi(char* buff) {
//	int flag = 1;
//	assert(buff);
//	long long ret = 0;
//
//	if (*buff == '\0') {
//		return 0;
//	}
//	while (isspace(*buff)) {
//		buff++;
//	}
//	if (*buff == '-') {
//		buff++;
//		flag = -1;
//	}
//	while (isdigit(*buff)) {
//		ret = ret * 10 + flag * (*buff - '0');
//		buff++;
//		if ((ret > INT_MAX) || (ret < INT_MIN)) {
//			num = INVALUE;
//		}
//		else {
//			num = VALUE;
//		}
//	}
//	return ret;    
//}
//	
//int main() {
//	char buf[] = "12345";
//	int tmp = my_atoi("12@#$345");
//
//	if (num == 1) {
//		printf("VALUE:%d\n",tmp);
//	}
//	else if (num == 0) {
//		printf("INVALUE:%d\n",tmp);
//	}
//	//FILE* f = fopen("d:/test.txt", "w");
//	//int num = 100;
//
//	////fprintf(f, "num=%d\n", num);
//	//fclose(f);
//	return 0;
//}