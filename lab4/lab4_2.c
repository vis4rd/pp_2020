#include <stdio.h>
#include <stdlib.h>

int *fl00r(float *jeden, float *dwa);

int main(void)
{
	float val1, val2;
	printf("podaj wartosc nr 1: ");
	scanf("%f", &val1);
	printf("\npodaj wartosc nr 2: ");
	scanf("%f", &val2);
	int *result = fl00r(&val1, &val2);
	printf("\npodloga z (%f * %f) = %f to %d\n",val1, val2, (float)val1*val2, *result);
	free(result);
}

int *fl00r(float *jeden, float *dwa)
{
	int *target = malloc(sizeof(int));
	float temp = (float)(*jeden)*(*dwa);
	*target = (int)temp;
	if(*target<0)
		(*target)--;
	return target;
}