#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct Wektor
{
	double x;
	double y;
	double z;
}Wektor;

typedef struct abc
{
	Wektor vect;
	double len;
}abc;

double rand_double(double a, double b);
double wekt_len(Wektor wector);
void f_d(abc *w, int n);
int double_inStruct_cmp(const void *a,  const void *b);

int main(int argc, char* argv[])
{
	srand(time(NULL));

	if (argc!=2){
		printf("nieprawidlowa liczba argumentow (powinien byc (1) argument)\n");
		return 0;
	}

	int size = atoi(argv[1]);
	abc *tab = calloc(size, sizeof(abc));
	for(int iter=0; iter<size; iter++)
	{
		tab[iter].vect.x=rand_double(0.0, 20.0);
		tab[iter].vect.y=rand_double(0.0, 20.0);
		tab[iter].vect.z=rand_double(0.0, 20.0);
	}

	f_d(tab, size);

	printf("przed sortowaniem:\n");
	for(int k=0; k<size; k++)
		printf("v%d[ %.3lf; %.3lf; %.3lf ] = %lf\n", k, tab[k].vect.x,tab[k].vect.y,tab[k].vect.z, tab[k].len);
	
	qsort(tab, size, sizeof(*tab), double_inStruct_cmp);

	printf("\npo sortowaniu:\n");
	for(int k=0; k<size; k++)
		printf("v%d[ %.3lf; %.3lf; %.3lf ] = %lf\n", k, tab[k].vect.x,tab[k].vect.y,tab[k].vect.z, tab[k].len);

	free(tab);
}

double rand_double(double a, double b)
{
 	return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

double wekt_len(Wektor wector)
{
	return sqrt((wector.x*wector.x)+(wector.y*wector.y)+(wector.z*wector.z));
}

void f_d(abc *w, int n)
{
	for(int x=0; x<n; x++)
		w[x].len=wekt_len(w[x].vect);
}

int double_inStruct_cmp(const void *a,  const void *b)//komparator dla double
{
	/*const double *x = a;
	const double *y = b;*/
	const abc *x = a;
	const abc *y = b;
	if(x->len==y->len)
		return 0;
	else if(x->len>y->len)
		return 1;
	else
		return -1;
}