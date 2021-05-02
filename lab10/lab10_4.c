#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define ROW 5
#define COL 5

int sum (const int t[], int len);
double avg (const int t[], const int len);
int rand_int (int a, int b);
int qcmp(const void *a, const void *b);
int bscmp(const void *a, const void *b);

int main(void)
{
	srand(time(NULL));
	int TAB[ROW][COL];
	for(int i=0; i<ROW; i++)
		for(int k=0; k<COL; k++)
			TAB[i][k] = rand_int(-10, 10);
	
	for(int i=0; i<ROW; i++)
	{
		for(int k=0; k<COL; k++)
			printf("%3d ", TAB[i][k]);
		printf("(%g)\n", avg(TAB[i], COL));
	}
	printf("\n");

	qsort(*TAB, ROW, COL*sizeof(**TAB), qcmp);

	printf("\n");
	for(int i=0; i<ROW; i++)
	{
		for(int k=0; k<COL; k++)
			printf("%3d ", TAB[i][k]);
		printf("(%g)\n", avg(TAB[i], COL));
	}
	printf("\n");

	double input;
	printf("Podaj liczbe typu double: ");
	scanf("%lf", &input);

	int *result = bsearch((const void *)&input, *TAB, ROW, COL*sizeof(**TAB), bscmp);
	if(!result)
		printf("Nie znaleziono takiego wiersza\n");
	else
	{
		printf("Znaleziono wiersz %ld: ", (result - *TAB)/ROW);
		for(int i = 0; i < COL; i++)
			printf("%3d ", result[i]);
		printf("\n");
	}
}

//---------------------------

int sum (const int t[], int len)
{
	int i;
	int ss = 0.;
	for (i=0; i<len; ss+=t[i++]);
	return ss;
}

double avg (const int t[], const int len)
{
	double ss = (double)sum(t,len)/len;
	return ss;
}

int rand_int (int a, int b) 
{
 	return a + rand()%(b-a+1);
}

int qcmp(const void *a, const void *b)
{
	int len = COL;
	const int (*x)[len] = (const int (*)[len])a;
	const int (*y)[len] = (const int (*)[len])b;

	const double first 	= avg(*x, len);
	const double second = avg(*y, len);

	if(first>second)
		return 1;
	else if(first<second)
		return -1;
	else
		return 0;
}

int bscmp(const void *a, const void *b)
{
	int len = COL;
	const double *key = (const double *)a;
	const int (*x)[len] = (const int (*)[len])b;

	const double aver = avg(*x, len);
	if(fabs(*key - aver) <= (0.01*fabs(*key)))
		return 0;
	else if (*key < aver)
		return -1;
	else
		return 1;
}