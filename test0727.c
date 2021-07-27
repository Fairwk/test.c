#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char findFristRepeat(char arr[], int len) {
	char a[256] = { 0 };
	int i = 0;
	if (len < 0) {
		return '\n';
	}
	for (i = 0; i < len; i++) {
		if (a[arr[i]] == 0) {
			a[arr[i]] = 1;
		}
		else {
			break;
		}
	}
	return arr[i];
}
int main() {
	char str[] = "kdbaaak";
	int len = strlen(str);
	printf("%c\n", findFristRepeat(str, len));
	return 0;
}
//int fun(char* s)
//{
//	char* p = s;
//	while (*p != '\0') {
//		p++;
//	}
//	return(p - s);
//}
//int main() {
//	const int i = 0;
//	int* j = (int*)&i;
//	*j = 1;
//	printf("%d,%d", i, *j);
//	//unsigned char a = 0xA5;
//	//unsigned char b = ~a >> 4 + 1;
//	//printf("%d\n", b);
//	//printf("%d\n", fun("goodbye!"));
//}
