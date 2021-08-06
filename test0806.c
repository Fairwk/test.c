#include<stdio.h>
int IsEchoNum(int num) {
	int n;
	int tmp, sum = 0;
	for (n = num; n; n /= 10) {
		tmp = n % 10;
		sum = sum * 10 + tmp;
	}
	if (num == sum) {
		printf("%d是回文数", num);
	}
	else {
		printf("%d不是回文数", num);
	}
}
int fun(char* s1, char* s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}
int main() {
	int x = 1, y = 012;
	printf("%d", y * x++);
	//int j = 4;
	//int i = j;
	//for (; i <= 2 * j; i++)
	//{
	//	switch (i / j)
	//	{
	//	case 0:
	//	case 1:
	//		printf("*");
	//		break;
	//	case 2:
	//		printf("#");
	//	}
	//}
	//unsigned int a = 0xFFFFFFF7;
	//unsigned char i = (unsigned char)a;
	//char* b = (char*)&a;
	//printf("%08x,%08x", i, *b);
	//char str1[] = "ABCDEFG";
	//char str2[] = "ABCDEFG";
	//int ret = fun(str1, str2);
	//printf("%d\n", ret);
	//char* p1, * p2;
	//p1 = "abcd"; p2 = "efgh";
	//strcpy(str + 1, p2 + 1);
	//strcpy(str + 3, p1 + 3);
	//printf("%s\n", str);
	//char a[] = "123456789", * p = a;
	//int i = 0;
	//while (*p)
	//{
	//	if (i % 2 == 0) *p = '!';
	//	i++; p++;
	//} 
	//puts(a);
	//int num = 121;
	//IsEchoNum(num);
	return 0;
}
//int main(void)
//{
//	int arr[] = { 6,7,8,9,10 };
//	int* ptr = arr;
//	*(ptr++) += 123;
//	printf("%d,%d", *ptr, *(++ptr));
//	//int k, j, s;
//	//for (k = 2; k < 6; k++, k++)
//	//{
//	//	s = 1;
//	//	for (j = k; j < 6; j++)
//	//		s += j;
//	//} 
//	//printf("%d\n", s);
//	//int a = 2, * p1, ** p2;
//	//p2 = &p1;
//	//p1 = &a;
//	//a++;
//	//printf("%d,%d,%d\n", a, *p1, **p2);
//	return 0;
//}