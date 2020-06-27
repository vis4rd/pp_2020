#include <stdio.h>

void zamiana(int *one, int *two);
void odwroc(int *tab, int size);
void wymien_tablice(int *one, int *two, int size);

int main(void)
{
	int jeden = 2, dwa = 1;
	int *p = NULL;
	printf("przed: jeden = %d, dwa = %d\n", jeden, dwa);
	zamiana(&jeden, &dwa);
	printf("po: jeden = %d, dwa = %d\n", jeden, dwa);

	int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("przed: ");
	for(p = tab; p<tab+10; p++)
		printf("%d ", *p);
	printf("\n");

	odwroc(tab, 10);

	printf("po: ");
	for(p = tab; p<tab+10; p++)
		printf("%d ", *p);
	printf("\n\n");

	int tab2[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	printf("tab2: ");
	for(p = tab2; p<tab2+10; p++)
		printf("%d ", *p);
	printf("\n");

	wymien_tablice(tab, tab2, 10);
	printf("po zamianie tablic tab i tab2: \n");
	printf("tab: ");
	for(p = tab; p<tab+10; p++)
		printf("%d ", *p);
	printf("\n");

	printf("tab2: ");
	for(p = tab2; p<tab2+10; p++)
		printf("%d ", *p);
	printf("\n");
}

void zamiana(int *one, int *two) //typ void, bo to ma byc procedura
{
	int temp = *one;
	*one = *two;
	*two = temp;
}

void odwroc(int *tab, int size)
{
	for(int i=0; i<(size/2); i++)
		zamiana(tab+i, tab+size-i-1);
}

void wymien_tablice(int *one, int *two, int size) //tylko jeden size, bo zeby dokonac zamiany, to tablice musza byc tej samej wielkosci
{
	for(int i=0; i<size; i++)
		zamiana(one+i, two+i);
}