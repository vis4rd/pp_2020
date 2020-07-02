#include <stdio.h>
#include <string.h>

int add2(int *first , int *second);
int comp2(int *first , int *second);
int add2_or_comp2 ( int fun(int*, int*) , int first , int second );

int main(void)
{
	int first, second;
	puts("Podaj dwie liczby");
	scanf("%d  %d",&first,&second);
	printf("\nsuma liczb:%d\n",add2_or_comp2(add2, first, second));
	printf("roznica liczb:%d\n",add2_or_comp2(comp2, first, second));
	return 0;
}

int add2(int *first , int *second)
{
	return *first+*second;
}

int comp2(int *first , int *second)
{
	return *first-*second;
}

int add2_or_comp2 (int fun(int*, int*), int first, int second)
{
	return fun(&first, &second);
}
