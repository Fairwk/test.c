#include <stdio.h>
#include <string.h>


void myqsort(void* base, size_t nitems, size_t size, int(*Comper)(void*, void*)) {
	int bound, cur;
	char* st = (char*)base;//将void*强制转换成char*,有利于加减
	char tmp[1024];//临时空间设立
	for (bound = 0; bound < nitems - 1; bound++) {
		for (cur = nitems-1; cur > bound; cur--) {
			char* p1 = st + (cur - 1) * size;
			char* p2 = st + cur * size;
			if (Comper(p1, p2)) {
				memcpy(tmp, p1, size);
				memcpy(p1, p2, size);
				memcpy(p2, tmp, size);
			}
		}
	}
}
int Comper(void* x, void* y) {
	int* ix = (int*)x;
	int* iy = (int*)y;
	return *ix < *iy ? 1 : 0;
}
int main() {
	int arr[] = { 9,5,7,8,2,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	myqsort(arr, len, sizeof(arr[0]),Comper);
	for (int i = 0; i < len; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}
//typedef int(*Cmp)(void*, void*);
//void myqsort(void* arr, int len, int unitlen,Cmp cmp){
//	for (int bound = 0; bound < len; bound++) {
//		for (int cur = len - 1; cur > bound; cur--) {
//			//为了使arr这个void*能够解引用,就需要强制类型转换
//			//统一转成char*
//			char* carr = (char*)arr;
//			//取cur和cur-1
//			char* p1 = carr + (cur - 1) * unitlen;
//			char* p2 = carr + cur * unitlen;
//			if (cmp(p1, p2) != 1) {
//				//交换需要一个临时空间
//				char tmp[1024] = { 0 };
//				//把p1的内存拷贝到tmp上
//				memcpy(tmp, p1, unitlen);
//				//把p2的内存拷贝到p1上
//				memcpy(p1, p2, unitlen);
//				//把tmp的内存拷贝回p1上
//				memcpy(p2, tmp, unitlen);
//			}
//		}
//	}
//}
//
//int Comper(void* x, void* y) {
//	int* ix = (int*)x;
//	int* iy = (int*)y;
//	return *ix < *iy ? 1 : 0;
//}
//int main() {
//	int arr[] = { 9,5,7,8,2,6 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	myqsort(arr, len, sizeof(arr[0]),Comper);
//	for (int i = 0; i < len; i++) {
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
//int findNum(int a[][3], int x, int y, int f) {
//	int i = 0, j = x - 1;
//	while (j >= 0 && i < y) {
//		if (a[i][j] < f) {//输入的数据和左上方的比大就往下走
//			i++;
//		}
//		else if (a[i][j] > f) {//输入的数据比他小就往左走
//			j--;
//		}
//		else {
//			return 1;
//		}
//	}
//	return 0;
//}
//int main() {
//	int a[][3] = { {2,4,6},{3,5,7},{4,8,9} };
//	if (findNum(a, 3, 3, 2)) {
//		printf("It has been found!\n");
//	}
//	else {
//		printf("It hasn't been found!\n");
//	}
//	return 0;
//}