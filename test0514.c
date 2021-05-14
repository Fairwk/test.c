#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main() {
	int line = 0;
	int i = 0;
	scanf("%d", &line);//此时要打印的line是7行,这是打印图形上半部分
	for (i = 0; i < line; i++) {
		int j = 0;
		for (j = 0; j < line - i - 1; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < line - 1; i++) {
		//这个循环打印图形下半部分
		//因为上半部分打印过第7行,所以i<line-1(6)
		int j = 0;
		for (j = 0; j <= i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
//int main() {
//	int i = 0;
//	for (i = 0; i <= 99999; i++) {
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//我们首先要算数字的个数
//		while (tmp/10) {
//			count++;
//			tmp = tmp / 10;
//		}
//		//接下来我们要计算每一位的次方和
//		tmp = i;
//		while (tmp) {
//			//pow是一个函数计算数字的次方
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//		if (sum == i) {
//			printf("%d\n", sum);
//		}
//	}
//	return 0;
//}
//int main() {
//	int i = 0;
//	int a = 0;
//	int n = 0;
//	int tmp = 0;
//	int sum = 0;
//	scanf("%d %d", &a, &n);
//	for ( i = 0; i < n; i++) {
//		tmp = tmp * 10 + a;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//	return 0;
//}