#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void JudgeIs2(int num) {
	int num2 = num - 1;
	//因为2的次方数用二进制表示时，
	//只有一个1，所以将num-1与num做&，这样可以消除1
	if ((num & num2) == 0) {
		printf("这个数是2的次方！\n");
	}
	else {
		printf("这个数不是2的次方！\n");
	}
}
int main() {
	int num;
	printf("请输入一个数:");
	scanf("%d", &num);
	JudgeIs2(num);
	return 0;
}
//#define N 3
//#define Y(n) ((N+1)*n)
//void sumk(int* arr, int len, int* num1, int* num2, int key) {
//	int i = 0;
//	int j = len - 1;
//	while (i < j) {
//		if (arr[i] + arr[j] > key) {
//			j--;
//		}
//		else if (arr[i] + arr[j] < key) {
//			i++;
//		}
//		else {
//			*num1 = i;
//			*num2 = j;
//			break;
//		}
//	}
//}
//int main() {
//	int i, x, y;
//	i = x = y = 0;
//	do {
//		++i;
//		if (i % 2)
//			x += i,
//			i++;
//		y += i++;
//	} while (i <= 7);
//	printf("%d %d %d", i, x, y);
//	//double ret = (double)(10 / 4 * 4);
//	//printf("%f", ret);
//	//char ch = -1;
//	//printf("%d\n", ch);
//	//int i = 6;
//	//if (i <= 6)
//	//	printf("hello\n");
//	//else
//	//	printf("bye-bye\n");
//	//int z;
//	//z = 2 * (N + Y(5 + 1));
//	//printf("%d\n", z);
//
//	//int arr[] = { 1,3,5,8,9,10,13,17 };
//	//int len = sizeof(arr) / sizeof(arr[0]);
//	//int i = 0;
//	//int j = 0;
//	//sumk(arr, len, &i, &j, 17);
//	//printf("%d,%d\n", i, j);
//	//return 0;
//}
//int myPow(int x, int y) {
//	if (y == 0) {
//		return 1;
//	}
//	if (y == 1) {
//		return x;
//	}
//	int ret = 0;
//	int tmp = myPow(x, y / 2);
//	if ((y & 1) != 0) {
//		ret = x * tmp * tmp;
//	}
//	else {
//		ret = tmp * tmp;
//	}
//	return ret;
//}
//void foo(int b[][3])
//{
//	++b;
//	b[1][1] = 9;
//}
////void main()
////{
////	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
////	foo(a);
////	printf("%d", a[2][1]);
////	//char* szStr = "abcde";
////	//szStr += 2;
////	//printf("%lu\n", szStr);
////	return;
////}
//int main() {
//	int i = 10;
//	long long t = sizeof(i++);
//	printf("%d", i);
//	//int x = 0, y = 0, z = 0;
//	//z = (x == 1) && (y = 2);
//	//printf("%d ", y);
//	//	unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
//	//	unsigned long* pulPtr;
//	//	pulPtr = pulArray;
//	//	*(pulPtr + 2) += 2;
//	//	printf("%d,%d\n", *pulPtr, *(pulPtr + 2));
//	//	//printf("%d\n", myPow(2, 4));
//	return 0;
//}
//int main() {
//	char ch;
//	ch = 'B ' + '8' - '3';
//	printf("%c", ch);
//	//unsigned short sht = 0;
//	//sht--;
//	//printf("%d", sht);
//	//int arr[] = { 1,2,3,4,5 };
//	//int* ptr = (int*)(&arr + 1);
//	//printf("%d %d\n", *(arr + 1), *(ptr - 1));
//	return 0;
//}