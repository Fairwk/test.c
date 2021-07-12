#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
struct imag {
	char name[1024];
	double grade;
	int age;
};
int comparNum(const void* p, const void* q) {
	//比较两个数大小
	return*((int*)p) - *((int*)q);
}
int structIntCompar(const void* p, const void* q) {
	//结构体中年龄比较
	return((struct imag*)p)->age - ((struct imag*)q)->age;
}
int structStrCompar(const void* p, const void* q) {
	//结构体中字符串比较
	return(strcmp((*(struct imag*)p).name, (*(struct imag*)q).name));
}
int structDoubleCompar(const void* p, const void* q) {
	//结构体中浮点型比较
	return((*(struct imag*)p).grade > ((struct imag*)q)->grade);
}
void swapNum(void* p, void* q, int size) {
	for (int i = 0; i < size; i++) {
		char tmp = *((char*)p + i);
		*((char*)p + i) = *((char*)q + i);
		*((char*)q + i) = tmp;
	}
}
void bubbleSort(void* arr,//要排序的数组
	int num,//数组元素的个数
	int size,//每个元素所占的字节个数
	int (*comper)(const void*, const void*)) {//比较两个元素大小
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (comper((char*)arr + j * size, (char*)arr + (j + 1) * size) > 0) {
				swapNum((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
			}
		}
	}
}
void printNum(int* arr, int size) {//打印整型数组
	for(int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void printStruct(struct imag arr[], int size) {
	printf("姓名\t      成绩\t     年龄\t");
	for (int i = 0; i < size; i++) {
		printf("%s\t     %.2f\t     %d\n", arr[i].name, arr[i].grade, arr[i].age);
	}
	printf("\n");
}
int main() {
	int i = 0;
	int arrInt[10] = { 2,5,8,15,23,25,30,35,38,40 };
	char* arrStr[] = { "efghi","abcde","bcdef","cdefg","defgh" };
	struct imag arrStu[3] = { {"xiaohong",97,19},{"xiaoming",95,20},{"xiaozhang",85,21} };
	printf("给整型数组排序\n");
	bubbleSort(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), sizeof(arrInt[0]), comparNum);
	printNum(arrInt, sizeof(arrInt) / sizeof(arrInt[0]));
	printf("\n");
	printf("按结构体中的年龄进行排序\n");
	bubbleSort(arrStu, sizeof(arrStu) / sizeof(arrStu[0]), sizeof(arrStu[0]), structStrCompar);
	printStruct(arrStu, sizeof(arrStu) / sizeof(arrStu[0]));
	printf("\n");
	printf("按结构体中的成绩进行排序\n");
	bubbleSort(arrStu, sizeof(arrStu) / sizeof(arrStu[0]), sizeof(arrStu[0]), structDoubleCompar);
	printStruct(arrStu, sizeof(arrStu) / sizeof(arrStu[0]));
	printf("pause");
	return 0;
}
//void myQsort(void* base, size_t nitems, size_t size, int(*comper)(const void*, const void*)) {
//	int i = 0;
//	char* st = (char*)base;//利用char*更方便加减,且字符跳转为1
//	int tmp[1024];//临时空间设置1024防止不够用
//	for (int i = 0; i < nitems - 1; i++) {
//		for (int j = 0; j < nitems - i - 1; j++) {
//			if (comper(st + j * size, st + (j + 1) * size)) {
//				memcpy(tmp, st + j * size, size);
//				memcpy(st + j * size, st + (j + 1) * size, size);
//				memcpy(st + (j + 1) * size, tmp, size);
//
//			}
//		}
//	}
//}
//int comper(int* x, int* y) {
//	return(*x > *y ? 1 : 0);
//}
//int main() {
//	int arr[] = { 2,6,8,10,20,21 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	myQsort(arr, size, sizeof(int), comper);
//	for (int i = 0; i < size; i++) {
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
//n表示要打多少行
//void printyanghui(int n) {
//	int arr[100][100] = { 0 };
//	for (int row = 0; row <= n; row++) {
//		if (row == 0) {
//			arr[0][0] = 1;
//			continue;
//		}
//		if (row == 1) {
//			arr[1][0] = 1;
//			arr[1][1] = 1;
//			continue;
//		}
//		//第row行有row+1列(从0开始数)
//		for (int col = 0; col <= row; col++) {
//			//首尾元素都是1
//			if (col == 0 || col == row) {
//				arr[row][col] = 1;
//			}
//			else {
//				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
//			}
//		}
//	}
//	//打印数组内容
//	for (int row = 0; row < n; row++) {
//		for (int col = 0; col <= row; col++) {
//			printf("%d", arr[row][col]);
//		}
//		printf("\n");
//	}
//
//}
//char guessMunder() {
//	char munder = 'a';
//	for (; munder <= 'd'; munder++) {
//		if ((munder != 'a') + (munder == 'c') 
//			+ (munder == 'd') + (munder != 'd') == 3) {
//			printf("munder=%c\n", munder);
//		}
//	}
//}
//void guessOrder() {
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++) {
//		for (b = 1; b <= 5; b++) {
//			for (c = 1; c <= 5; c++) {
//				for (d = 1; d <= 5; d++) {
//					for (e = 1; e <= 5; e++) {
//						if (((b == 2) + (a == 3) == 1)
//							&& ((b == 2) + (e == 4) == 1)
//							&& ((c == 1) + (d == 2) == 1)
//							&& ((c == 5) + (d == 3) == 1)
//							&& ((e == 4) + (a == 1) == 1)
//							&&(a * b * c * d * e == 120)) {
//							printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//}
////形如这样的代码,在面试中移动要记住校验参数的合法性,典型校验空指针
//size_t strlen(const char* str) {
//	//两种校验方式
//	//此处校验只能校验空指针,不能校验野指针
//	/*if (str == NULL) {
//		return 0;
//	}*/
//	//assert是"断言",是一个宏.
//	assert(str != NULL);
//	size_t size = 0;
//	while (str[size] != '\0') {
//		size++;
//	}
//}
//typedef struct Student {
//	int id;
//	char name[1024];
//}Student;
//int main() {
//	char a[] = "abcd";
//	char b[1024] = { 0 };
//	char c[1024] = { 0 };
//	//strcpy(c,strcpy(b,a));
//	strcpy(b, a);
//	strcpy(c, a);
	/*char dest[4] = { 0 };
	char src[] = "abcd";
	strcpy(dest, src);
	printf("%s\n", dest);*/
	/*char* p = "abcd";
	p = NULL;
	printf("%d\n", strlen(p));*/
	/*char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);*/
	//guessOrder();
	//guessMunder();
	//printyanghui(5);
//	return 0;
//}