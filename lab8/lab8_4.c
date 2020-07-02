#include <stdio.h>
#include <math.h>

double fun0(double x);
double fun1(double x);
double fun2(double x);
double fun3(double x);
double (**find_max(double (*not_fun[])(double), double x))(double);

int main(void)
{
	char *nazwy[]={"log", "pow","sin","cos"};
	double (*TAB_FUN[5])(double);
	TAB_FUN[0] = fun0;
	TAB_FUN[1] = fun1;
	TAB_FUN[2] = fun2;
	TAB_FUN[3] = fun3;
	TAB_FUN[4] = NULL;

	double (**wsk_fun)(double);
	wsk_fun = TAB_FUN;

	double data[8] = { 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0 };

	char** str = nazwy;
/*	for(wsk_fun; wsk_fun<TAB_FUN+4; wsk_fun++) //pętla po wskaźnikach do funkcji
	{ 
		for (int i = 0; i < 8; i++) //pętla po argumentach
			printf(" %s( %.2f ) = %.4f\n", str[wsk_fun-TAB_FUN], data[i], (*wsk_fun)(data[i]));
		printf("\n");
	}*/

	while(*wsk_fun!=NULL)
	{
		for (int i = 0; i < 8; i++) //pętla po argumentach
			printf(" %s( %.2f ) = %.4f\n", *str, data[i], (*wsk_fun)(data[i]));
		printf("\n");
		*wsk_fun++;
		str++;
	}

	//printf("1\n");
	double (**wsk_max)(double);
	wsk_max=find_max(TAB_FUN, 0.05);
	//printf("2\n");
	printf ("dla x= %f najwieksza wartosc ma %s, ktora wynosi %.3f\n", 0.05, nazwy[wsk_max-TAB_FUN], (*wsk_max)(0.05));
}

double fun0(double x) 
{ 
	return log(x); 
}
double fun1(double x) 
{ 
	return x*x; 
}
double fun2(double x) 
{ 
	return sin(x); 
}
double fun3(double x) 
{ 
	return cos(x); 
}

double (**find_max(double (*not_fun[])(double), double x))(double)
{
	int iter=1;
	int max=0;
	while(1)
	{
		if(not_fun[iter]==NULL)
			break;
		if(not_fun[iter](x)>not_fun[max](x))
			max=iter;
		iter++;
	}
	return not_fun+max;
}