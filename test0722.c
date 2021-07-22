#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void bubble_sort(int* arr, int len) {
	int bound = 0;
	for (bound = 0; bound < len; bound++) {
		for (int cur = len - 1; cur > bound; cur--) {
			if (arr[cur - 1] > arr[cur]) {
				swap(&arr[cur - 1], &arr[cur]);
			}
		}
	}
}
void Find_Num(int* arr, int len) {
	bubble_sort(arr, len);
	int mid_num = arr[len / 2];
	printf("超过数组长度一半的数字是:%d\n", mid_num);
}
int main() {
	int arr[] = { 1,2,3,2,2,2,5,4,2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Find_Num(arr, len);
	return 0;
}
//	unsigned long ulA = 0x11000000;
//	printf("%x\n", *(unsigned char*)&ulA);
//	/*int s = 0, n;
//	for (n = 0; n < 4; n++)
//	{
//		switch (n)
//		{
//		default:s += 4;
//		case 1:s += 1;
//		case 2:s += 2;
//		case 3:s += 3;
//		}
//	} */
//	
//    //char* pcColor = "bluee";
//	//char acColor[] = "blue1";
//		//printf("%d\n", sizeof(pcColor));
//	/*return 0;
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));*/
//	/*int* p = (int*)malloc(1024 * 1024);
//	for (int i = 0; i < 4; i++) {
//		p[i] = i;
//	}
//	for (int i = 0; i < 4; i++) {
//		printf("%d\n", p[i]);
//	}*/
//	return 0;
//}