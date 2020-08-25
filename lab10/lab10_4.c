#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int sum (int t[], int len);
double avg (int t[], int len);
int rand_int (int a, int b);
int qcmp(const void *a, const void *b);
int bscmp(const void *a, const void *b);

int main(void)
{
	srand(time(NULL));
	int TAB[ROW][COL];
	for(int i=0; i<ROW; i++)
	{
		for(int k=0; k<COL; k++)
			TAB[i][k] = rand_int(-10, 10);
	}
	for(int i=0; i<ROW; i++)
	{
		for(int k=0; k<COL; k++)
			printf("%2d ", TAB[i][k]);
		printf("\n");
	}
	qsort(TAB, ROW*COL*sizeof(int), sizeof(**TAB), qcmp);


}

//---------------------------

int sum (int t[], int len)
{
	int i;
	int ss = 0.;
	for (i=0; i<len; ss+=t[i++]);
	return ss;
}

double avg (int t[], int len)
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
	const int (*x)[len] = a;
	const int (*y)[len] = b;

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

}