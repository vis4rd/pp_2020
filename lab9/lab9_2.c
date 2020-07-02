#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cstring_cmp(const void *str1, const void *str2);
int double_cmp(const void *a,  const void *b);

int main(int argc, char* argv[])
{
	if(argc<2){
		printf("\nZa malo podanych argumentow!\n");
		return 0;
	}

	char *strings[] = { "Alex", "Bill","Bill","Celine", "Dexter", "Forest","Forest","Garcia","Garcia","Garcia", "Pedro","Zorro"};
	double numbers[] = {1.34, 1.34, 4.34, 5.55, 5.67, 5.67, 5.67, 7.76, 8.1, 8.1, 9.12, 11.23};

	char *input_string = argv[1];
	double input_dbl = atof(argv[2]);

	printf("str: %s, dbl: %lf\n", input_string, input_dbl);

	char **result_string;
	double *result_dbl;

	int size_strings = sizeof(strings)/sizeof(strings[0]);
	int size_double = sizeof(numbers)/sizeof(numbers[0]);
	
	result_string = (char**)bsearch(&input_string, strings, size_strings, sizeof(strings[0]), cstring_cmp);
	result_dbl = (double*)bsearch(&input_dbl, numbers, size_double, sizeof(numbers[0]), double_cmp);
	//printf("%s\n", *result_string);
	if(result_string!=NULL)
	{
		int str_index = result_string-strings;
		//printf("%d\n", str_index);
		int str_count = 0;
		while(strings[str_index]==*result_string)
		{
			str_index++;
			str_count++;
		}
		//printf("%d\n", str_count);
		str_index = result_string-strings;
		str_count--;
		while(strings[str_index]==*result_string)
		{
			str_index--;
			str_count++;
		}
		printf("klucz %s ma %d wystapien w tablicy\n", input_string, str_count);
	}
	else
		printf("nie znaleziono klucza %s w tablicy\n", input_string);

	if(result_dbl!=NULL)
	{
		int dbl_index = result_dbl-numbers;
		int dbl_count = 0;
		while(numbers[dbl_index]==*result_dbl)
		{
			dbl_index++;
			dbl_count++;
		}
		dbl_index = result_dbl-numbers;
		dbl_count--;
		while(numbers[dbl_index]==*result_dbl)
		{
			dbl_index--;
			dbl_count++;
		}
		printf("klucz %lf ma %d wystapien w tablicy\n", input_dbl, dbl_count);
	}
	else
		printf("nie znaleziono klucza %lf w tablicy\n", input_dbl);

}

int cstring_cmp(const void *str1, const void *str2) //komparator dla stringow
{
	//printf("\n%s %s = %d", str1, str2, strcmp(*(const char **)str1, *(const char **)str2));
	return strcmp(*(const char **)str1, *(const char **)str2);
}

int double_cmp(const void *x,  const void *y)//komparator dla double
{
	const double *a = x;
	const double *b = y;
    return (a>b)-(a<b);
}