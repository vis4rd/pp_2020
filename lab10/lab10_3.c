#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 20
#define SIZE 20

typedef struct Liczba
{
	char code;
	union
	{
		int val_int;
		double val_double;
	};
}Liczba;

int rand_int (int a, int b);
double rand_double (double a, double b);
void print_tab_struct(Liczba *T, int n);
int ultimateMegaUltraExtraEpicGigaOmegaCMP(const void *val1, const void *val2);

int main(void)
{
	srand(time(NULL));
	Liczba *tab = calloc(SIZE, sizeof(Liczba));
	int choice;
	for(int i=0; i<SIZE; i++)
	{
		choice = rand_int(0, 1);
		if(choice)
		{
			tab[i].code = 'i';
			tab[i].val_int = rand_int(MIN, MAX);
		}
		else
		{
			tab[i].code = 'd';
			tab[i].val_double = rand_double(MIN, MAX);
		}
	}
	printf("przed sortowaniem: \n");
	print_tab_struct(tab, SIZE);

	qsort(tab, SIZE, sizeof(*tab), ultimateMegaUltraExtraEpicGigaOmegaCMP);

	printf("\npo sortowaniu:\n");
	print_tab_struct(tab, SIZE);

	free(tab);
}

int rand_int (int a, int b) 
{
 	return a + rand()%(b-a+1);
}

double rand_double (double a, double b)
{
 	return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

void print_tab_struct(Liczba *T, int n)
{
	for(int k=0; k<n; k++)
	{
		if(T[k].code=='i')
			printf("tab[%2.1d] = %-6d (integer)\n",k, T[k].val_int);
		else
			printf("tab[%2.1d] = %-6.3lf (double)\n",k, T[k].val_double);
	}
	return;
}

int ultimateMegaUltraExtraEpicGigaOmegaCMP(const void *val1, const void *val2)
{
	const Liczba *x = val1;
	const Liczba *y = val2;
	double a, b;
	
	if(x->code=='i')
		a = (double)x->val_int;
	else
		a = x->val_double;
	if(y->code=='i')
		b = (double)y->val_int;
	else
		b = y->val_double;

	if(x->code=='i'&&y->code=='d')
		return -1;
	else if(x->code=='d'&&y->code=='i')
		return 1;

	if(x->code=='i'&&y->code=='i')
		return (a<b)-(a>b);
	else if(x->code=='d'&&y->code=='d')
		return (a>b)-(a<b);

	return 0;
	
}