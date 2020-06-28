#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_f(float *tab, int size);
void merge(float *T1, float *T2, float *finalT, int size1, int size2);

int main(void)
{
	srand(time(NULL));

	float arg_1[] = {1.0, 1.2, 1.2, 1.5, 1.5, 1.5, 1.6, 1.6, 1.8, 1.9} ;
	float arg_2[] = {1.0, 1.1, 1.1, 1.2, 1.4, 1.5, 1.6, 1.6, 1.8, 1.8, 1.8, 1.9, 1.9, 2.0, 2.0} ;

	int size1 = sizeof(arg_1)/sizeof(float);
	int size2 = sizeof(arg_2)/sizeof(float);

	printf("\narg_1: "); wypisz_f(arg_1, size1);
	printf("\narg_2: "); wypisz_f(arg_2, size2);

	float *wynik = (float*)malloc(sizeof(float));
	merge(arg_1, arg_2, wynik, size1, size2);

	free(wynik);
}

void wypisz_f(float *tab, int size)
{
	for(int g=0; g<size; g++)
		printf("%2.1f ", (float)tab[g]);
	printf("\n");
}

void merge(float *T1, float *T2, float *finalT, int size1, int size2)
{
	int iter1=0, iter2=0;
	int size3=0;
	float temp=666;
	while(iter1!=size1 || iter2!=size2)
    {
        if(iter1==size1)
        {
            temp=T2[iter2];
            iter2++;
        }
        else if(iter2==size2)
        {
            temp=T1[iter1];
            iter1++;
        }
        else if(T1[iter1]>T2[iter2])
        {
            temp=T2[iter2];
            iter2++;
        }
        else
        {
            temp=T1[iter1];
            iter1++;
        }

        if(temp!=finalT[size3-1])
        {
            size3++;
            finalT=(float*)realloc(finalT, size3*sizeof(float));
            if(finalT==NULL) 
            {
            	printf("alokacja pamieci nieudana"); 
            	exit(0);
            }
            finalT[size3-1]=temp;
        }
    }
	printf("\nwynik: "); wypisz_f(finalT, size3);
}