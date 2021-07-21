#include <stdio.h>
#include <stdlib.h>
//得到数组中第任意K大的数字位置
int qort(int arr[], int left, int right) {
	int tmp = arr[left];
	right--;
	while (left < right) {
		while (left < right && arr[right] >= tmp) {
			right--;
		}
		if (arr[right] < tmp) {
			arr[left] = arr[right];
			arr[right] = tmp;
		}
		while (left < right && arr[left] <= tmp) {
			left++;
		}
		if (arr[left] > tmp) {
			arr[right] = arr[left];
			arr[left] = tmp;
		}
	}
	return right;
}
//得到第任意K大的数字位置与K-1进行比较查找
void preKNum(int* arr, int len, int k) {
	int left = 0;
	int right = len;
	int par = qort(arr, left, right);
	int i = 0;
	while (par != k - 1) {
		if (par > k - 1) {
			right = par - 1;
			par = qort(arr, left, right);
		}
		else {
			left = par + 1;
			par = qort(arr, left, right);
		}
	}
	for (i = 0; i < k; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[] = { 2,4,6,9,10,1,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	preKNum(arr, len, 5);
	return 0;
}
//int a = 1;
//void test()
//{
//	int a = 2;
//	a += 1;
//} 
//#define MOD(x,y) x%y
//int main() {
//	int x = 0;
//	switch (++x)
//	{
//	case 0: ++x;
//	case 1: ++x;
//	case 2: ++x;
//	}
//	printf("%d", x);
	//int a = 13, b = 94;
	//printf("%d\n", MOD(b,a + 4));
	//int i = 0;
	//int j = 0;
	//if ((++i > 0) || (++j > 0)) {
	//	printf("i=%d;j=%d\n", i, j);
	//}
	//test();
	//printf("%d\n", a);
	//return 0;
//}
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node,*List;
//void init(List* L) {
//	(*L) = (List)malloc(sizeof(Node));
//	if (NULL == L)exit(0);
//	(*L)->next = NULL;
//}
//void print(List L) {
//	List p;
//	p = L;
//	while (L != NULL) {
//		printf("%d", L->data);
//		L = L->next;
//	}
//	printf("\n");
//}
//void insert(List* L, int x) {
//	List p = (List)malloc(sizeof(Node));
//	p->data = x;
//	p->next = L;
//	L = p;
//}
//void reverse(List* L) {
//	List *p, *q;
//	p = NULL; q = L;
//	while (q != NULL) {
//		L = L->next;
//		q->next = p;
//		p = q;
//		q = L;
//	}
//	L = p;
//	return L;
//}
//int main() {
//	int i, temp;
//	List L;
//	init(L);
//	printf("请输入10个数据:");
//	for (i = 0; i < 10; i++) {
//		scanf("%d", &temp);
//		insert(L, temp);
//	}
//	print(L);
//	reverser(L);
//	print(L);
//	return 0;
//}
//int f(int a)
//{
//	int b = 0;
//	static int c = 3;
//	a = c++, b++;
//	return (a);
//} 
//int x = 3;
//void inc()
//{
//	static int x = 1;
//	x *= (x + 1);
//	printf("%d", x);
//	return;
//}
//int main()
//{
//	int i;
//	for (i = 1; i < x; i++) {
//		inc();
//	}
//	/*int a = 2, i, k;
//	for (i = 0; i < 2; i++) {
//		k = f(a++);
//	} 
//		printf("%d\n", k);*/
//	return 0;
//}