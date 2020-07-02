#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int double_cmp(const void *a, const void *b); //komparator dla double
int cstring_cmp(const void *str1, const void *str2); //komparator dla stringow
int tabchars_cmp(const void *str1, const void *str2);//komparator dla tablicy napisow
void print_double_array(double* tab, int n); //wypisywanie tablicy double
void print_cstring_array(char** tab, int n); //wypisywanie tablicy string'ow
void print_tabchars_array(char (*tab)[10],int n);  //wypisywanie tablicy napisow 
void sort_double_example();
void sort_cstrings_example();
void sort_tabchars_example(); //sortowanie tablicy stringow  

// MAIN program (wywołanie funkcji sortujacych)
int main()
{
	sort_double_example();
	sort_cstrings_example();
	sort_tabchars_example();
	return 0;
}

int double_cmp(const void *a,  const void *b)//komparator dla double
{
	const double *x = a;
	const double *y = b;
	if(*x==*y)
		return 0;
	else if(*x>*y)
		return 1;
	else
		return -1;
}

int cstring_cmp(const void *str1, const void *str2) //komparator dla stringow
{
	//printf("\n%s %s = %d", str1, str2, strcmp(*(const char **)str1, *(const char **)str2));
	return strcmp(*(const char **)str1, *(const char **)str2);
}

int tabchars_cmp(const void *str1, const void *str2)
{
	return strcmp((const char *)str1, (const char *)str2);
}

void print_double_array(double* tab, int n) //wypisywanie tablicy double
{
	double *iter = tab;
	for(iter; iter<tab+n; iter++)
		printf("%5.2f  ", *iter);
	printf("\n");
}

void print_cstring_array(char** tab, int n) //wypisywanie tablicy string'ow
{
	char **iter = tab;
	for(iter; iter<tab+n; iter++)
		printf("%s  ", *iter);
	printf("\n");
}

void print_tabchars_array(char(*tab)[10],int n)
{
	char (*temp)[]=tab+n;
	for(*tab; *tab<*temp; *tab++)
		printf("%s  ", (*tab));
	printf("\n");
}

void sort_double_example() //sortowanie tablicy double
{
	double numbers[] = { 7.4, 1.3, 14.5, 0.1, -1.0, 2.3, 1,2, 43.0, 2.0, -4.7, 5.8 };
	size_t numbers_len = sizeof(numbers)/sizeof(numbers[0]); //okreslenie dlugosci tablicy

	puts("*** Double sorting...");
	print_double_array(numbers, numbers_len); //wypisanie tablicy double przed sortowaniem
	qsort(numbers, numbers_len, sizeof(numbers[0]), double_cmp); //sortowanie tablicy double funkcja qsort

	print_double_array(numbers, numbers_len); //wypisanie tablicy double po sortowaniu
}

void sort_cstrings_example() //sortowanie tablicy stringow
{
	char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
	size_t strings_len = sizeof(strings)/sizeof(strings[0]); //okreslenie dlugosci tablicy
	puts("*** String sorting...");
	print_cstring_array(strings, strings_len); //wypisanie tablicy stringow przed sortowaniem
	qsort(strings, strings_len, sizeof(strings[0]), cstring_cmp); //sortowanie tablicy stringow funkcja qsort
	print_cstring_array(strings, strings_len); //wypisanie tablicy stringow sortowaniu
}

void sort_tabchars_example() //sortowanie tablicy stringow  
{ 
	char tab_char[][10] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"}; 
	size_t tab_char_N = sizeof(tab_char)/sizeof(tab_char[0]); //okreslenie ilosci napisow w tablicy 
	puts("*** table sorting..."); 
	print_tabchars_array(tab_char, tab_char_N); //wypisanie tablicy napisow przed sortowaniem  
	qsort(tab_char, tab_char_N, sizeof(tab_char[0]), tabchars_cmp); //sortowanie tablicy stringow funkcja qsort
	print_tabchars_array(tab_char, tab_char_N); //wypisanie tablicy napisow po sortowaniu 
 } 
