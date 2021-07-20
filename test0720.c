#include<stdio.h>
#include<stdlib.h>
#pragma pack(2)
struct A {
	char a;
	int b;
	char c;
}; 
//( )里没有参数,此时就是把默认对齐数还原成默认值
#pragma pack()
struct IpPacked {
	//前4个bit位就表示版本号
	int version : 4;
	int headerlen : 4;
	int tos : 8;
	int length : 16;
};
enum Sex {
	MALE,
	FEMALE,
	UNKNOWN
};
enum Week {
	Monday,
	Tuesday,
	Wednesday,
};
//联合体每个成员,公用一块内存空间
union Un {
	char i;
	int a;
};
union TPSddress {
	//给计算机看,就当成一个大整数即可
	unsigned int data;
	//给人看,就当成四个比较小的整数
	struct IP {
		unsigned char a;
		unsigned char b;
		unsigned char c;
		unsigned char d;
	}ip;
};
//int isBigEnd() {
//	int num = 0x11223344;
//	int* p = &num;
//	char* p2 = (char*)p;
//	if (*p2 == 0x11) {
//		return 1;
//	}
//}
int isBigEnd() {
	union Un {
		int num;
		char num2;
	}u;
	u.num=0x11223344;
		if (u.num2 == 0x11) {
			return 1;
		}
		return 0;
}
int fun(int a, int b)
{
	if (a > b)
		return(a + b);
	else
		return(a - b);
}
int main() {
	int x = 3, y = 8, z = 6, r;
	r = fun(fun(x, y), 2 * z);
	printf("%d\n", r);
	
	//写一个代码区分主机是大端还是小端
	//int ret = isBigEnd();
	//printf("ret=%d\n", ret);
	//union Un u;
	//u.i = 10;

	//u.a = 0;
	//printf("%d\n", u.i); 
	//enum Sex s = MALE;
	//s = Monday;
	//printf("%d\n", MALE + 1); 
	/*struct A structA; 
	printf("%p\n", &structA);
	printf("%p\n", &structA.a);
	printf("%p\n", &structA.b);
	printf("%p\n", &structA.c);
	printf("%d\n", sizeof(structA));*/
	return 0;
}