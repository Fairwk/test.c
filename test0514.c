#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main() {
	int line = 0;
	int i = 0;
	scanf("%d", &line);//��ʱҪ��ӡ��line��7��,���Ǵ�ӡͼ���ϰ벿��
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
		//���ѭ����ӡͼ���°벿��
		//��Ϊ�ϰ벿�ִ�ӡ����7��,����i<line-1(6)
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
//		//��������Ҫ�����ֵĸ���
//		while (tmp/10) {
//			count++;
//			tmp = tmp / 10;
//		}
//		//����������Ҫ����ÿһλ�Ĵη���
//		tmp = i;
//		while (tmp) {
//			//pow��һ�������������ֵĴη�
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