#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	//������ʱ�����ķ���
	/*int i = 10;
	int j = 20;
	int tmp;
	tmp = i;
	i = j;
	j = tmp;
	printf("i = %d j = %d\n", i, j);*/
	////��������ʱ�����ķ���1.
	//int i = 10;
	//int j = 20;
	//int tmp;
	//i = i + j;
	//j = i - j;
	//i = i - j;
	//printf("i=%d j=%d\n", i, j);
	//��������ʱ����2.
	int i = 10;
	int j = 20;
	int tmp;
	i = i ^ j;
	j = i ^ j;
	i = i ^ j;
	printf("i=%d j=%d\n", i, j);
	return 0;
}
//int count_one_bit(unsigned int value) {
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; ++i) {
//		if (((value >> i) & 1) == 1) {
//			count++;
//		}
//	}
//	return count;
//}
//int main() {
//	int num;
//	int ret;
//	printf("������һ������:");
//	scanf("%d", &num);
//	ret = count_one_bit(num);
//	printf("ret=%d\n", ret);
//	return 0;
//}

//int main() {
//	int num = 7;
//	printf("����:");
//	for (int i = 31; i >= 1; i -= 2) {
//		printf("%d", (num >> i) & 1);
//	}
//	printf("ż��:");
//	for (int i = 30; i >= 0; i -= 2) {
//		printf("%d", (num >> i) & 1);
//	}
//	printf("\n");
//}
 
//int diff_bit(int n, int m) {
//	int tmp = m^n;//�����������������ͬλ,��ͬλΪ1
//	int count = 0;
//	while (tmp) {
//		tmp = tmp & (tmp - 1);//�ð�λ�������������ж���λ��1
//			count++;
//	}
//	return count;
//}
//int main() {
//	int m, n;
//	printf("��������������:");
//	scanf("%d %d", &m, &n);
//	int ret = diff_bit(m, n);
//	printf("ret=%d\n", ret);
//
//	return 0;
//}