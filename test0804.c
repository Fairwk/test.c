#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void DeleteStr(char* str1, char* str2) {
	char* pFast = str1;
	char* pSlow = str2;
	int a[256] = { 0 };
	int i;
	int n = strlen(str2);
	for (i = 0; i < n; i++) {
		a[str2[i]] = 1;
	}
	while(*pFast) {
		if (a[*pFast] == 1) {
			*pFast++;
		}
		*pSlow++ = *pFast++;
	}
	*pSlow = '\0';
}
int main() {
	char str1[] = "They are students.";
	char str2[] = "aeiou";
	DeleteStr(str1, str2);
	printf("%s\n", str2);
	return 0;
}
//#define sum(a,b,c) a+b+c
//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//}
//int func()
//{
//	int i, j, k = 0;
//	for (i = 0, j = -1; j = 0; i++, j++) {
//		k++;
//	}
//	return k;
//}
//int main()
//{
//	//int i = 3;
//	//int j = 2;
//	//printf("%d\n", i * sum(i, (i + j), j));
//	//printf("%d\n", f(1));
//	printf("%d\n", (func()));
//	return 0;
//}