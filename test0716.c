#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
int fib(int n) {
	int a = 1;
	int b = 1;
	int c = 0;
	while (n >= 3) {
		c = a + b;
		a = b;
		b = c;
		n--;
		
	}
	return c;
}
int main() {
	int n = 5;
	int ret = 0;
	ret = fib(n);
	printf("%d\n", ret);
	return 0;
}
//void* myMemmove(void* dest, const void* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	char* cdest = (char*)dest;
//	const char* csrc = (const char*)src;
//		for (size_t i = num; i > 0; i--) {
//			cdest[i - 1] = csrc[i - 1];
//		}
//		return dest;
//}
//int myMemcmp(const void* ptr1, const void* ptr2, size_t num) {
//	assert(ptr1 != NULL);
//	assert(ptr2 != NULL);
//	assert(num != 0);
//	const char* cptr1 = (const char*)ptr1;
//	const char* cptr2 = (const char*)ptr2;
//	for (size_t i = 0; i < num; i++) {
//		if (cptr1[i] < cptr2[i]) {
//			return -1;
//		}
//		else if (cptr1[i] > cptr2[i]) {
//			return 1;
//		}
//		else {
//			continue;
//		}
//	}
//}
//void* myMemset(void* ptr, int value, size_t num) {
//	assert(ptr != NULL);
//	assert(num != 0);
//	char* cptr = (char*)ptr;
//	for (size_t i = 0; i < num; i++) {
//		cptr[i] = (char)value;
//	}
//	return ptr;
//}
//int main() {
//	char str[] = { 1,2,3,4 };
//	char str2[100] = { 3,4 };
//	myMemmove(str2, str, sizeof(str));
//	for (int i = 0; i < 4; i++) {
//		printf("%d\n", str2[i]);
//	}
//	return 0;
//}
//void* myMemcpy(void* dest, const void* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	//按照字节为单位进行拷贝
//	char* cdest = (char*)dest;
//	const char* csrc = (const char*)src;
//	for (size_t i = 0; i < num; i++) {
//		cdest[i] = csrc[i];
//	}
//	return dest;
//}
//void* myMemmove(void* dest, const void* src, size_t num) {
//	char* cdest = (char*)dest;
//	const char* csrc = (const char*)src;
//	if (csrc <= cdest && cdest <= csrc + num) {
//		//内存重叠,反着拷贝
//		for (size_t i = num; i > 0; i--) {
//			cdest[i - 1] = csrc[i - 1];
//		}
//		return dest;
//	}
//	else {
//		//不重叠就正着拷贝
//		for (size_t i = 0; i < num; i++) {
//			cdest[i] = csrc[i];
//		}
//		return dest;
//	}
//}
//
////typedef struct Student {
////	int id;
////	char name[1024];
////}Student;
////int main() {
//
//	/*char str[] = "hello";
//	char str2[1024] = { 0 };
//	myMemcpy(str2, str, sizeof(str));
//	printf("%s\n", str2);*/
//	/*Student s1 = { 1,"zhangsan" };
//	Student s2;
//	myMemcpy(&s2, &s1, sizeof(Student));
//	printf("%d,%s\n", s2.id, s2.name);*/
//	/*int arr[] = { 1,2,3,4 };
//	int arr2[100] = { 0 };
//	myMemcpy(arr2, arr, sizeof(arr));
//	for (int i = 0; i < 4; i++) {
//		printf("%d\n", arr2[i]);
//	}
//	return 0;*/
//	//return 0;
////}