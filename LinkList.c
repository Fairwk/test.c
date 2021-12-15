#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXSIZE 100
int list[MAXSIZE];
int n;
/*insert in a seqlist*/
int sq_insert(int list[], int* p_n, int i, int x)
{
	int j;
	if (i<0 || i>*p_n)  return(1);
	if (*p_n == MAXSIZE)  return(2);
	for (j = *p_n + 1; j > i; j--)
		list[j] = list[j - 1];
	list[i] = x;
	(*p_n)++;
	return(0);
}
/*delete in a seq list*/
int sq_delete(int list[], int* p_n, int i)

{
	int j;
	if (i < 0 || i >= *p_n)  return(1);
	for (j = i + 1; j <= *p_n; j++)
		list[j - 1] = list[j];
	(*p_n)--;
	return(0);
}

void main()
{
	int i, x, temp;
	printf("please input the number for n\n");
	printf("n=");
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
	{
		printf("list[%d]=", i);
		scanf("%d", &list[i]);
	}

	printf("The list before insertion is\n");
	for (i = 0; i <= n; i++) printf("%d  ", list[i]);
	printf("\n");
	printf("please input the position where you want to insert a value\nposition=");
	scanf("%d", &i);
	printf("please input the value you want to insert.\nx=");
	scanf("%d", &x);
	temp = sq_insert(list, &n, i, x);
	switch (temp)
	{
	case 0:printf("The insertion is successful!\n");
		printf("The list is after insertion is\n");
		for (i = 0; i <= n; i++) printf("%d  ", list[i]);
		printf("\n");
		printf("%d\n", n);
		break;
	case 1:
	case 2:printf("The insertion is not successful!\n"); break;
	}
	/*deleting*/
	printf("The list before deleting is\n");
	for (i = 0; i <= n; i++) printf("%d  ", list[i]);
	printf("\n");
	printf("please input the position where you want to delete a value\nposition=");
	scanf("%d", &i);
	temp = sq_delete(list, &n, i);
	switch (temp)
	{
	case 0:printf("The deleting is successful!\n");
		printf("The list is after deleting is\n");
		for (i = 0; i <= n; i++) printf("%d  ", list[i]);
		printf("\n");
		printf("%d", n);
		break;
	case 1:printf("The deleting is not successful!"); break;
	}
}
