//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef int DataType;
typedef struct SlistNode {
	DataType data;
	struct SlistNode* next;
}SlistNode;
SlistNode* BuyNode(DataType x) {
	SlistNode* next = (SlistNode*)malloc(sizeof(SlistNode));
	next->data = x;
	next->next = NULL;
	return next;
}
void PushBack(SlistNode* ppHead, DataType x) {
	if (ppHead == NULL) {
		ppHead = BuyNode(x);
	}
	else {
		SlistNode* tail = ppHead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = BuyNode(x);
	}
}
//查找单链表的倒数第k个结点
SlistNode* FindLastKmiddle(SlistNode* ppHead, DataType k) {
	SlistNode* slow = ppHead;
	SlistNode* fast = ppHead;
	while (fast != NULL && k--) {
		fast = fast->next;
	}
	if (k > 0) {
		return NULL;
	}
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
void printNodeList(SlistNode* ppHead) {
	while (ppHead) {
		printf("%d->", ppHead->data);
		ppHead = ppHead->next;
	}
	printf("\n");
}
void Test3() {
	SlistNode* List = NULL;
	PushBack(List, 1);
	PushBack(List, 2);
	PushBack(List, 3);
	PushBack(List, 4);
	PushBack(List, 5);
	printNodeList(List);
	SlistNode* ret = FindLastKmiddle(List, 4);
	if (ret == NULL) {
		printf("该值不存在!\n");
	}
	else {
		printf("%d", ret->data);
	}
}
int main() {
	Test3();
	return 0;
}
#define MAX_ROW 3
#define MAX_COL 3

void rotateLeftOne(char* str) {
	char tmp = str[0];//这个值最终放置在最右侧
	for (int i = 1; i < (int)strlen(str); i++) {
		str[i - 1] = str[i];
	}
	//把tmp中的元素放在数组最后
	str[strlen(str) - 1] = tmp;
}
void rotateLeft(char* str, int n) {
	assert(str != NULL);
	assert(strlen(str) > 0);
	assert(n >= 0);
	n = n % strlen(str);
	for (int i = 0; i < n; i++) {
		rotateLeftOne(str);
	}
}
//能找到就是1
//找不到就是0
int  isRotated(char* str1, char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(strlen(str1) > 0);
	assert(strlen(str2) > 0);
	for (int i = 0; i < (int)strlen(str2); i++) {
		if (strcmp(str1, str2) == 0) {
			return 1;
		}
		rotateLeftOne(str2);
	}
	return 0;
}
int findNum(int arr[MAX_ROW][MAX_COL], int toFind) {
	int row = 0;
	int col = MAX_COL - 1;//找右上角元素
	
	while (row >= 0 && row < MAX_ROW 
		&& col >= 0 && col < MAX_COL) {
		int cur = arr[row][col];
		if (cur < toFind) {
			row++;
		}
		else if (cur > toFind) {
			col--;
		}
		else {
			return 1;
		}
	}
	return 0;
}
typedef struct Student {
	int id;
	char name[1024];
}Student;
//这个写法完全错误
//struct A {
//	int id;
//	struct A a;
//};
struct A {
	int id;
	struct A* a;
};
int Change(int* pX)
{
	int y = 8;
	y = y - *pX;
	pX = & y;
	return 0;
}
int fun(int x)
{
	int count = 0;
	while (x) {
		count++;
		x = x & (x - 1);
	} 
		return count;
} 
//int main() {
unsigned long g_ulGlobal = 0;
void GlobalInit(unsigned long ulArg)
{
	ulArg = 0x01;
	return;
} 
void Test()
{
	GlobalInit(g_ulGlobal);
	printf("%lu", g_ulGlobal);
	return;
}
//int main() {
//	Test();
//	return 0;
//}
//#define CIR(r) r * r
//void main()
//{
//	int a = 1;
//	int b = 2;
//	int t;
//	t = CIR(a + b);
//	printf("%d/n", t);
//	return;
//}
		//printf("fun(2017)=%d\n", fun(2019));
		
	
		/*char arr[2][4];
		strcpy((char*)arr, "you");
		strcpy(arr[1], "me");
		arr[0][3] = '&';
		printf("%s\n", arr);*/
			

		/*int xx = 3;
		int* pY = &xx;
		Change(pY);
		printf("%d\n", *pY);
		return 0;
	*/
	/*int a[10];
	int* pa;
	pa = a;
	printf("%p,%p", &a+1,pa+1);*/
	//printf("%d\n", sizeof(struct A));
	//char str[] = "abcd";
	//rotateLeft(str, 3);
	//rotateLeftOne(str);
	//rotateLeft(NULL, 3);
	//rotateLeft(str, -1);
	//rotateLeft(str,5 );
	/*char str1[] = "abcd";
	char str2[] = "cdab";
	printf("%d\n",isRotated(str1,str2));*/
	/*int arr[MAX_ROW][MAX_COL] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	int ret = findNum(arr, 10);
	printf("ret=%d\n", ret);*/
	//return 0;
//}