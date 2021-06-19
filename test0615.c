#include<stdio.h>
#include<assert.h>
char* myStrstr(const char* str1,const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(*str1 != '\0');
	assert(*str2 != '\0');
	const char* black = str1;
	//外层循环通过black控制从str1的哪个位置开始找子串
	while (*black != '\0') {
		const char* red = black;
		const char* sub = str2;
		//里层循环就是从black开始,判定当前这个子串和str2是否相等
		while (*red != '\0' && *sub != '\0'
			&& *red == *sub) {
			red++;
			sub++;
		}
		//以上循环结束,有三种可能
		//1. *red == \0, 可以直接结束循环,直接进入下次循环
		//2. *sub == \0,找到了,直接返回black
		//3. *red != *sub, 直接进入下次循环
		if (*red == '\0' || *red == *sub) {
			continue;
		}
		if (*sub == '\0') {
			return black;
		}
		black++; 
	}
	return NULL;
}
int main() {
	char* str1 = "hello world";
	char* str2 = "llo";
	const char* result = myStrstr(str1, str2);
	printf("%s\n", result);
	return 0;
}