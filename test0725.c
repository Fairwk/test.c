#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char firstsingle(char* arr) {
	char asc[255] = { 0 };
	int i = 0;
	for (; arr[i] != '\0'; i++) {
		asc[arr[i]]++;
	}
	for (i = 0; arr[i] != '\0'; i++) {
		if (asc[arr[i]] == 1) {
			return arr[i];
			return '\0';
		}
	}
}
int main() {
	FILE* fopen("", "");
	//char arr[10];
	//char ret;
	//scanf("%s", arr);
	//ret = firstsingle(arr);
	//printf("%c\n", ret);
	//return 0;
}
//char* myString()
//{
//	char buffer[6] = { 0 };
//	char* s = "Hello World!";
//	for (int i = 0; i < sizeof(buffer) - 1; i++)
//	{
//		buffer[i] = *(s + i);
//	}
//	return buffer;
//}
//int main(){
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = (char)(-1 - i);
//	} 
//	printf("%d\n", strlen(a));
	//int i = 1;
	//printf("%d, %d\n", sizeof(i++), i);
	//printf("%s\n", myString());
	//int x[] = { 1,2,3,4,5,6 }, * p = x;
	//p += 3, * p;
	//printf("%d\n",  * p);
	//char* str[3] = { "stra","strb","strc" };
	//char* p = str[0];
	//int i = 0;
	//while (i < 3)
	//{
	//	printf("%s ", p++);
	//	i++;
	//} 
//	return 0;
//}