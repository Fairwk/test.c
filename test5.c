#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fib(int n) {
	if(n == 1 || n == 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}
int fib2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	//使用i表示当前项
	int last2 = 1;//i-2项
	int last1 = 1;//i-1项
	int cur = 0;//当前第i项的结果
	for (int i = 3; i <= n; i++) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}
int main() {
	int a;
	scanf("%d", &a);
	int ret1 = fib(a);
	int ret2 = fib2(a);
	printf("递归的方法:%d\n", ret1);
	printf("非递归的方法:%d\n", ret2);
	return 0;
}
//int power(int n, int k) {
//	if (k > 1) {
//		return power(n, k - 1) * n;
//	}
//	return n;
//}
//int main() {
//	int n = 0;
//	int k = 0;
//	scanf("%d", &n);
//	scanf("%d", &k);
//	int ret = power(n, k);
//	printf("%d\n", ret);
//	return 0;
//}
//int DigitSum(int n) {
//	if (n > 9) {
//		return(n % 10) + DigitSum(n / 10);
//	}
//	return n;
//}
//int main() {
//	int a = 1729;
//	int ret = DigitSum(a);
//	printf("%d\n",ret);
//	return 0;
//}
//int my_strlen(char* string) {
//	int count = 0;
//	while (*string != '\0') {
//		count++;
//		string++;
//	}
//	return count;
//}
//void reverse_string(char* string) {
//	char temp = string[0];
//	int len = my_strlen(string);
//	string[0] = string[len - 1];
//	string[len - 1] = '\0';//末尾置1方便计算字符串长度
//	if (my_strlen(string) > 1) {
//		reverse_string(string + 1);
//	}
//	string[len - 1] = temp;//将末尾置换	
//}
//int main() {
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}
//int my_strlen(char* string) {
//	int count = 0;
//	if (*string != '\0') {
//		string++;
//		count = 1 + my_strlen(string);
//	}
//	return count;
//}
//int my_strlen2(char* string) {
//	int count = 0;
//	while (*string++ != '\0') {
//		count++;
//	}
//	return count;
//}
//int main() {
//	char* str = "abcdef";
//	printf("递归方法=%d\n", my_strlen(str));
//	printf("非递归方法=%d\n", my_strlen2(str));
//	return 0;
//}
//int Factorial(int n) {
//	if (n == 0) {
//		return 1;
//	}
//	return n * Factorial(n - 1);
//}
//int fac(int n) {
//	int i;
//	int result = 1;
//	for (i = 1; i <= n; i++) {
//		result *= i;
//	}
//	return(result);
//}
//int main() {
//	int n, result, result1;
//	scanf("%d", &n);
//	result = Factorial(n);
//	result1 = fac(n);
//	printf("递归%d的阶乘为:%d\n", n, result);
//	printf("非递归%d的阶乘为:%d\n", n, result1);
//	return 0;
//
//}
//void printNum(unsigned int num) {
//	if (num > 9) {
//		printNum(num / 10);
//	}
//	printf("%d", num % 10);
//}
//int main() {
//	printNum(1234);
//	return 0;
//}
//void Mult(int n) {
//	int row, lin;
//	for (row = 1; row <= n; row++) {
//		for (lin = 1; lin <= row; lin++) {
//			printf("%-2d*%-2d=%-3d", row, lin, row * lin);//%-2d表示左对齐占2位美观
//		}
//		printf("\n");
//	}
//}
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	Mult(n);
//	return 0;
//}
//void swap(int* x, int* y) {
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main() {
//	int a,b;
//	printf("请输入两个整数:\n");
//	scanf("%d %d", &a, &b);
//	swap(&a,&b);
//	printf("%d %d\n", a,b);
//}
//int isLeapYear(int year) {
//	if (year % 100 == 0){
//		if (year % 400 == 0) {
//			return 1;
//		}
//		return 0;
//	}
//	else {
//		if (year % 4 == 0){
//			return 1;
//		}
//		return 0;
//	}
//}
//int main() {
//	int i;
//	printf("请输入年份:\n");
//	scanf("%d", &i);
//	if (isLeapYear(i)) {
//		printf("是闰年");
//	}
//	else {
//		printf("不是闰年");
//	}
//	return 0;
//}
//int primeNum(int num) {
//	int i, tmp;
//	tmp = sqrt(num);
//	for (int tmp= 100; tmp <= 200;tmp ++) {
//		int i = 0;
//		for (i = 2; i <= tmp; i++) {
//			if (num % i == 0) {
//				return 0;
//			}
//		}return 1;
//		
//	}
//}
//int main(){
//	int i;
//	scanf("%d", &i);
//	if (primeNum(i)) {
//		printf("是素数");
//	}
//	else {
//		printf("不是素数");
//	}
//	  return 0;
//}
//int binarySearch(int* arr, int size, int toFind) {
//	int left = 0;
//	int right = size - 1;
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (toFind < arr[mid]) {
//			right = mid - 1;
//		}
//		else if (toFind > arr[mid]) {
//			left = mid + 1;
//		}
//		else {
//			printf("找到了!\n");
//			return mid;
//			break;
//		}
//
//	}if (left > right) {
//		printf("没找到元素!\n");
//	}return -1;
//}
//int main() {
//	int arr [10] = { 1,5,7,2,12,15,17,23,34,25,};
//	int ret = binarySearch(arr, 10, 23);
//	printf("%d\n", ret);
//	return 0;
//}
	


//	void game(){//viod表示函数没有返回值
//		printf("开始一句猜数字游戏\n");
//		int toGuess = rand() % 100 + 1;//生成一个[1-100]的随机整数
//		while(1){
//			printf("请输入一个整数[1-100]:");
//			int inputNum = 0;
//			scanf("%d", &inputNum);
//			if (inputNum < toGuess) {
//				printf("低了!\n");
//			}
//			else if (inputNum > toGuess) {
//				printf("高了!\n");
//			}
//			else {
//				printf("猜对了!\n");
//				break;
//			}
//		}
//	}
//	int menu() {
//		printf("====================\n");
//		printf("欢迎来到猜数字游戏!\n\n");
//		printf("1.开始游戏\n");
//		printf("0.退出游戏\n");
//		printf("====================\n");
//		printf("请输入您的选择:");
//		int choice = 0;
//		scanf("%d", &choice);
//		return choice;
//	}
//	int main()
//	{
//		srand((unsigned int)time(0));//使用time（0）获取当前时间戳
//		while (1) {
//			int choice = menu();
//			if (choice == 1) {
//				game();
//			}
//			else if (choice == 0) {
//				printf("goodbye!\n");
//				break;
//			}
//			else {
//				printf("您的输入有误!\n");
//			}
//		}
//}
	/*int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d*%d=%d", i, j, i * j);
		}printf("\n");
	}
	return 0;
}*/
	/*int a[10],max;
	printf("请输入10个整数：");
	for (int i = 0; i < 10; i++) {
	    scanf("%d", &a[i]);
	}
	max=a[0];
	for (int i = 1; i <10; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}printf("max = %d\n", max);
	return 0;
}*/

//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++) {
//		if ((i % 10) == 9) {//利用模运算算出个位数为9的个数
//			count++;//用count来统计出现了多少个数字
//		}
//		if ((i / 10) == 9) {//利用商运算得出十位数为9的数字
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++) {
//		
//		sum +=flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
	


//	int i = 0;
//	int count = 0;//用count来定义素数的个数
//	for (i = 100; i <= 200; i++) {
//		int j = 0;
//		for (j = 2; j < i; j++) {
//			if (i % j == 0)
//				break;
//		}
//		if (j >= i) {
//			printf("%d\n", i);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}
//
//	