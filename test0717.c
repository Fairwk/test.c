#include <stdio.h>
int findNum(int n) {
	int count = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			count++;
		}
		n = n / 2;
	}
	return count;
}
int main() {
	int num = 15;
	int ret = findNum(num);
	printf("num中1的个数为:%d\n", ret);
	return 0;
}
//int fun(int x, int y)
//{
//	static int m = 0;
//	static int i = 2;
//	i += m + 1;
//	m = i + x + y;
//	return m;
//} 
//void main()
//{
//	int j = 4;
//	int m = 1;
//	int k;
//	k = fun(j, m);
//	printf("%d\n", k);
//	k = fun(j, m);
//	printf("%d\n", k);
//	return;
//}
//int main(int argc, char* argv[])
//{
//	char a[20];
//	char* p1 = (char*)a;
//	char* p2 = (char*)(a + 5);
//	int n = p2 - p1;
//	printf("%d", n);
//int main() {
//	enum ENUM_A
//	{
//		X1,
//		Y1,
//		Z1 = 5,
//		A1,
//		B1
//	};
//	enum ENUM_A enumA = Y1;
//	enum ENUM_A enumB = B1;
//	printf("%d\n", enumB);
//	return 0;
//}


//#define F(X,Y) ((X)+(Y))
//	int main()
//	{
//		int a = 3, b = 4;
//		printf("%d\n", F(a++, b++));
//	}

	//int i = 1, sum = 0;
	//while (i < 10) {
	//	sum = sum + 1;
	//	i++;
	//} 
	//	printf("i=%d,sum=%d",i, sum);
	/*struct tagTest1
	{
		short a;
		char d;
		long b;
		long c;
	};
	struct tagTest2
	{
		long b;
		short c;
		char d;
		long a;
	};
	struct tagTest3
	{
		short c;
		long b;
		char d;
		long a;
	};
	struct tagTest1 stT1;
	struct tagTest2 stT2;
	struct tagTest3 stT3;
	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
	return 0;*/
//}

	
