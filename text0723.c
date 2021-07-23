#include <stdio.h>
#include <stdlib.h>
int find(int* p, int n) {
	int max = 0,temp = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (temp <= 0) {
			temp = p[i];
		}
		else {
			temp += p[i];
		}
		if (max < temp) {
			max = temp;
		}
	}
	return max;
}
int main() {
	int arr[] = { 1,-2,3,10,-4,7,2,-5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", find(arr, n));
	return 0;
}

	//int a[5] = { 1, 2, 3, 4, 5 };
	//int* p1 = (int*)(&a + 1);
	//int* p2 = (int*)((int)a + 1);
	//int* p3 = (int*)(a + 1);
	//printf("%d, %x, %d\n", p1[-1], p2[0], p3[1]);
	//int a, x;
	//for (a = 0, x = 0; a <= 1 && !x++; a++)
	//{
	//	a++;
	//} 
	//printf("%d %d", a, x);
	//a.x = 0x11223344;
	//printf("%x\n", a.y[1]);
//	return 0;
//}
