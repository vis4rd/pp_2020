#include <stdio.h>
#include <string.h>
#include <math.h>

int zero(double (*f)(double), double a, double b, double* m_z, double eps);
double funkcja(double x);

int main(void)
{
	double mzerowe;
	double precyzja = 0.0000001;
	double poczatek = 0.0;
	double koniec = 8.0;
	int ok = zero(funkcja, poczatek, koniec, &mzerowe, precyzja);
	if(ok)
		printf("miejsce zerowe: %f\n", mzerowe);
	else
		printf("miejsce zerowe nie istnieje\n");
}

int zero(double (*f)(double), double a, double b, double* m_z, double eps)
{
	double pivot;

	if(f(a)*f(b)<0.0)
	{
		pivot=(a+b)/2;
		if(b-pivot<eps)
		{
			*m_z=pivot;
			return 1;
		}
		if(f(a)*f(pivot)<0.0)
			 return zero(f, a, pivot, m_z, eps);
		else
			 return zero(f, pivot, b, m_z, eps);
	}
	else
		return 0;

}

double funkcja(double x)
{
	return (double)(-x*x)+(3*x)+11;
}

