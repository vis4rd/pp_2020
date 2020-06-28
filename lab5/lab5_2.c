#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string_array(char **string, int stringLenght);//procedura wypisująca tablicę stringów
char *min_string (char **string, int stringLenght); //znajdowanie najmniejszego stringu w sensie leksykalnym w tablicy stringów - zwraca wskaźnik do minimalnego

int main(void)
{
	char *strings[] = { "Zorro", "Alex", "Celine", "Bill", "Forest", "Dexter"};
	size_t strings_len = 6; //okreslenie długości tablicy strings

	print_string_array(strings, strings_len); //wypisanie tablicy stringów

	char *wsk_string = min_string(strings, strings_len);//znalezienie najmniejszego stringu w tablicy

	printf("\n%s\n", wsk_string); //wypisanie najmniejszego stringu
	return 0;
}

void print_string_array(char **string, int stringLenght)
{
	char **temp=string;
	for(temp; temp<(string)+stringLenght; temp++)
	//for(int k=0; k<stringLenght; k++)
		printf("%s ", *temp);
}

char *min_string (char **string, int stringLenght)
{
	char *min;
	char **temp = string;
	min = *string;
	for(temp; temp<(string)+stringLenght; temp++)
	{
		if(strcmp(*temp, min)<=0)
			min=*temp;
	}
	return min;
}