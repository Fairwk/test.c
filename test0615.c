#include<stdio.h>
#include<assert.h>
char* myStrstr(const char* str1,const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(*str1 != '\0');
	assert(*str2 != '\0');
	const char* black = str1;
	//���ѭ��ͨ��black���ƴ�str1���ĸ�λ�ÿ�ʼ���Ӵ�
	while (*black != '\0') {
		const char* red = black;
		const char* sub = str2;
		//���ѭ�����Ǵ�black��ʼ,�ж���ǰ����Ӵ���str2�Ƿ����
		while (*red != '\0' && *sub != '\0'
			&& *red == *sub) {
			red++;
			sub++;
		}
		//����ѭ������,�����ֿ���
		//1. *red == \0, ����ֱ�ӽ���ѭ��,ֱ�ӽ����´�ѭ��
		//2. *sub == \0,�ҵ���,ֱ�ӷ���black
		//3. *red != *sub, ֱ�ӽ����´�ѭ��
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