#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

void va_cat(char **result, int num, ...);

int main(void)
{
	char *tab1[3]={"If you never did You should.", "These things are fun.", "and Fun is good."};
	char *tab2[4]={"Sometimes ", "you will never know ", "the value of a moment ", "until it becomes a memory."};
	char *wynik1 = malloc(sizeof(char));
	char *wynik2 = malloc(sizeof(char));
	va_cat(&wynik1, 3, tab1[0], tab1[1], tab1[2]);
	va_cat(&wynik2, 4, tab2[0], tab2[1], tab2[2], tab2[3]);
	puts(wynik1);
	puts(wynik2);
	free(wynik1);
	free(wynik2);
}

void va_cat(char **result, int num, ...)
{
	int size_word;
	int size_sum=0;
	va_list pointer;
	**result='\0';
	char* temp;
	va_start(pointer, num);
	while(num)
	{
		temp = va_arg(pointer, char*);
		size_word=strlen(temp)+1;
		size_sum+=size_word;
		*result = realloc(*result, size_sum*sizeof(char));
		strcat(*result, temp);
		num--;
	}
	va_end(pointer);
	return;
}