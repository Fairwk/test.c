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
//	//���ѭ���Ǵ�black��str1���ĸ�λ�ÿ�ʼ���Ӵ�
//	while (*black != '\0') {
//		char* red = black;
//		char* sub = str2;
//		//���ѭ�����Ǵ�black��ʼ�ж���ǰ����Ӵ��Ƿ��str2���
//		while (*red!='\0'&&*sub!='\0'
//			&&*red == *sub) {
//			red++;
//			sub++;
//		}
//		//ѭ�����������ֿ���
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
//	//�������������ѭ������
//	//1)src����\0,������destʣ�ಿ�ֶ����\0
//	//2)i=nmu,����ֱ�ӽ�������(��������ᱻ�����while������)
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
//	//����destĩβ
//	size_t destTail = 0;
//	while (dest[destTail] != '\0') {
//		destTail++;
//	}
//	size_t i = 0;
//	while (src[i] != '\0' && i < num) {
//		dest[destTail + i] = src[i];
//		i++;
//	}
//	//ѭ���������������
//	//1)src[i]=>\0,��Ҫ��destĩβ(dest[destTail+i])��Ϊ\0
//	//2)i==num,Ҳ��Ҫ��destĩβ��\0
//	dest[destTail + i] = '\0';
//	return dest;
//}
////���ع����strcmpһ��
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
//	//ѭ���������������
//	//1)str1[i]=='\0'
//	//2)str2[i]=='\0'
//	// 	   �����������Ϊһ��,˭�Ƚ���,˭�͸�С
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