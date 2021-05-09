#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int init(int arr[]) {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
}
int reverse(int arr[]) {
	for (int i = 9; i >=0; i--) {
		printf("%d\n", arr[i]);
	}
}
int main() {
	int arr[10];
	init(arr);
	reverse(arr);
	return 0;
}
//int main() {
//	int arr[] = { 1,2,3,4,5,6 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//	for (int* p = arr; p < arr + size; p++) {
//		printf("%d\n", *p);
//	}
//	return 0;
//}