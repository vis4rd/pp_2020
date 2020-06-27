#include <stdio.h>
#include <math.h> //wymaga kompilacji z uzyciem '-lm' !!!

// implementacja jedynie wskaznikowa, jako ze na poczatku trudniejsza do zrozumienia,
// z indeksowa kazdy sobie poradzi ;)

float suma(float *t, int n, float *minimalna, float *maksymalna, float *srednia, float *max_od, float *min_od);

int main(void)
{
	float t[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 1.3f, 2.4f, 3.5f, 4.6f, 5.7f };
	int t_size = sizeof(t)/sizeof(*t);

	float sum, min, max, sred, max_od, min_od;
	sum = suma(t, t_size, &min, &max, &sred, &max_od, &min_od);
	printf("suma = %f\nminimum = %f\nmaksimum = %f\nsrednia = %f\nmaksymalne odchylenie = %f\nminimalne odchylenie = %f\n", sum, min, max, sred, max_od, min_od);
}

float suma(float *t, int n, float *minimalna, float *maksymalna, float *srednia, float *max_od, float *min_od)
{
	float sumarycznie = 0.0f;
	*minimalna = 999.0f;
	*maksymalna = -999.0f;
	for(float *ptr = t; ptr < t+n; ptr++)
	{
		sumarycznie+=(*ptr);
		if(*ptr < *minimalna)
			*minimalna = *ptr;
		if(*ptr > *maksymalna)
			*maksymalna = *ptr;
	}

	*srednia = (float)sumarycznie / n;
	*max_od	= -999.0f;
	*min_od = 999.0f;
	for(float *k = t; k < t+n; k++)
	{
		if(fabs(*srednia-(*k)) < *min_od)
			*min_od = fabs(*srednia - (*k));
		if(fabs(*srednia-(*k)) > *max_od)
			*max_od = fabs(*srednia - (*k));
	}
	return sumarycznie;
}