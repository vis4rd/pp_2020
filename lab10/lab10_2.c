#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fun
{
	char* nazwa;
	double (*wsk)(double*, int);
}fun;

double sum (double t[], int len);
double avg (double t[], int len);
double min (double t[], int len);
double max (double t[], int len);
fun *fun_tab(double (*TAB_FUN[])(double*, int), char** names, int n);
void fun_prn(fun* tab, int len_tab, double* t, int len_t);
int cmp(const void* a, const void *b);

int main(void)
{
	double (*TAB_FUN[])(double* ,int) = {sum, avg, min, max};
	char *names[] = {"sum", "avg", "min", "max"};
	double data[][4] = {1.3, 1.2, 0.2, 2.3, 3.4, 1.1, 1.1, 2.1, 0.4, 0.9, 2.3, 1.3, 2.3, 0.6, 1.1};
	int var = 4;
	fun *wsk_fun = fun_tab(TAB_FUN, names, var);
	fun_prn(wsk_fun, sizeof(wsk_fun), *data, sizeof(*data));
}

double sum (double t[], int len)
{
	int i;
	double ss = 0.;
	for (i=0; i<len; ss+=t[i++]);
	return ss;
}

double avg (double t[], int len)
{
	double ss = sum(t,len)/len;
	return ss;
}

double min (double t[], int len)
{
	int i;
	int min = 0;
	for (i=0; i<len; i++)
		if (t[i]<t[min]) 
			min=i;
	return t[min];
}

double max (double t[], int len)
{
	int i;
	int max = 0;
	for (i=0; i<len; i++)
		if (t[i]>t[max]) 
			max=i;
	return t[max];
}

fun *fun_tab(double (*TAB_FUN[])(double*, int), char** names, int n)
{
	fun *tablica = calloc(n, sizeof(fun));
	for(int k=0; k<n; k++)
	{
		strcpy(tablica[k].nazwa, names[k]);
		tablica[k].wsk=TAB_FUN[k];
	}
	return tablica;
}

void fun_prn(fun* tab, int len_tab, double* t, int len_t)
{
	for(int p=0; p<4; p++)
	{
		printf("wiersz %d\n", p);
		printf("%s --> %lf\n", tab[p].nazwa, t[p]);
		printf("%s --> %lf\n", tab[p].nazwa, t[p]);
		printf("%s --> %lf\n", tab[p].nazwa, t[p]);
		printf("%s --> %lf\n", tab[p].nazwa, t[p]);
	}

}

double *fun_find(fun *T_F, int number, double(d)[4], int len)
{
	double vals[len];
	for(int i=0; i<len; i++){
	    vals[i] = T_F[i].wsk(&d[i],len);
	}

	qsort(vals,len,sizeof(double),cmp);
	double *min;
	*min = vals[0];
	return min;
}

int cmp(const void* a, const void *b)
{
	const double *x = a;
	const double *y = b;
	if(a<b)
		return -1;
	else if(a>b)
		return 1;
	else
		return 0;

}