#include <stdio.h>
#include <string.h>


void myqsort(void* base, size_t nitems, size_t size, int(*Comper)(void*, void*)) {
	int bound, cur;
	char* st = (char*)base;//��void*ǿ��ת����char*,�����ڼӼ�
	char tmp[1024];//��ʱ�ռ�����
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
//			//Ϊ��ʹarr���void*�ܹ�������,����Ҫǿ������ת��
//			//ͳһת��char*
//			char* carr = (char*)arr;
//			//ȡcur��cur-1
//			char* p1 = carr + (cur - 1) * unitlen;
//			char* p2 = carr + cur * unitlen;
//			if (cmp(p1, p2) != 1) {
//				//������Ҫһ����ʱ�ռ�
//				char tmp[1024] = { 0 };
//				//��p1���ڴ濽����tmp��
//				memcpy(tmp, p1, unitlen);
//				//��p2���ڴ濽����p1��
//				memcpy(p1, p2, unitlen);
//				//��tmp���ڴ濽����p1��
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
//		if (a[i][j] < f) {//��������ݺ����Ϸ��ıȴ��������
//			i++;
//		}
//		else if (a[i][j] > f) {//��������ݱ���С��������
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