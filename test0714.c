#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int myChange(char* str1, char* str2) {
	while (*str1) {
		if (*str1 != ' ') {
			*str2 = *str1;
			str2++;
		}
		else {
			strcpy(str2,"%20");
			str2 = str2 + 3;
		}
		str1++;
	}
	*str2 = '\0';
	return 0;
}
int main() {
	char str1[] = "abc defgx yz";
	char str2[1024];
	myChange(str1, str2);
	printf("%s", str2);
	return 0;
}
//char* myStrstr(const char* str1, const char* str2) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	assert(*str1 != '\0');
//	assert(*str2 != '\0');
//	const char* black = str1;
//	//外层循环是从black从str1的哪个位置开始找子串
//	while (*black != '\0') {
//		char* red = black;
//		char* sub = str2;
//		//里层循环就是从black开始判定当前这个子串是否和str2相等
//		while (*red!='\0'&&*sub!='\0'
//			&&*red == *sub) {
//			red++;
//			sub++;
//		}
//		//循环结束有三种可能
//		//1.*red==\0
//		//2.*sub==\0
//		//3.*red!=*sub
//		/*if (*red == '\0' || *red == *sub) {
//			black++;
//			continue;
//		}*/
//		if (*sub == '\0') {
//			return black;
//		}
//		black++;
//	}
//	return NULL;
// }
//int main() {
//	int a = 10;
//	printf("%d\n", a += a *= a -= a / 3);
//	/*const char* p = "hello";
//	printf("%c\n", *p);
//	return 0;*/
//	/*char* str1 = "helloworld";
//	char* str2 = "llo";
//	const char* result = myStrstr(str1, str2);
//	printf("%c\n", *result);
//	return 0;*/
//}
//char* myStrncpy(char* dest, const char* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	int i = 0;
//	while (src[i] != '\0' && i < num) {
//		dest[i] = src[i];
//		i++;
//	}
//	//有两种情况导致循环结束
//	//1)src遇到\0,后续把dest剩余部分都设成\0
//	//2)i=nmu,函数直接结束即可(这种情况会被下面的while给包含)
//	/*if (i == num) {
//		return dest;
//	}*/
//	while (i < num) {
//		dest[i] = '\0';
//		i++;
//	}
//	return dest;
//}
//char* myStrncat(char* dest, char* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	//先找dest末尾
//	size_t destTail = 0;
//	while (dest[destTail] != '\0') {
//		destTail++;
//	}
//	size_t i = 0;
//	while (src[i] != '\0' && i < num) {
//		dest[destTail + i] = src[i];
//		i++;
//	}
//	//循环结束有两种情况
//	//1)src[i]=>\0,需要给dest末尾(dest[destTail+i])设为\0
//	//2)i==num,也需要给dest末尾加\0
//	dest[destTail + i] = '\0';
//	return dest;
//}
////返回规则和strcmp一样
//int myStrncmp(const char* str1, const char* str2, size_t num) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	assert(num != 0);
//	size_t i = 0;
//	while (str1[i] != '\0' && str2[i] != '\0' && i < num) {
//		if (str1[i] < str2[i]) {
//			return -1;
//		}
//		else if (str1[i] > str2[i]) {
//			return 1;
//		}
//		else {
//			i++;
//		}
//	}
//	//循环结束有三种情况
//	//1)str1[i]=='\0'
//	//2)str2[i]=='\0'
//	// 	   这两种情况视为一种,谁先结束,谁就更小
//	//3)i==num
//	if (i == num) {
//		return 0;
//	}
//	return str1[i] - str2[i];
//}
//int main() {
//	char str1[1024] = "hello";
//	char str2[1024] = "hella";
//	int a = myStrncmp(str1, str2, 10);
//	printf("%d\n", a);
//	/*char str1[1024] = {0};
//	char str2[] = "hello";
//	myStrncpy(str1, str2, sizeof(str1)-1);
//	printf("%s", str1);
//	return 0;*/
//	return 0;
//}