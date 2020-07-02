#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** podziel(char *sentence, int *ile_tok);
void sort(char **lan, int num);
char* sklej(char **tab, int ile);

int main(int argc, char* argv[])
{
	char *input = argv[1];
	int ile_tok=0;

	char **temp = podziel(input, &ile_tok);
	sort(temp, ile_tok);
	char *result = sklej(temp, ile_tok);
	
	printf("\nresult: ");
	puts(result);

	/*for(int j=0; j<ile_tok; j++)
		free(temp[j]);*/
	free(temp);

	free(result);

}

char **podziel(char *sentence, int *ile_tok)
{
	char sep[] = ", :;.";
	char *token = strtok(sentence, sep);
	char **tab = calloc(1, sizeof(char*));
	int ile=1;
	do
	{
		tab=realloc(tab, ile*sizeof(char*));
		tab[ile-1]=token;
	
		for(int g=0; g<ile; g++)
			if(g>0&&strcmp(token, tab[g-1])==0)
				ile--;
		ile++;
		token = strtok(0, sep);
	}while(token!=0);
	*ile_tok=ile-1;
	return tab;
}

void sort(char **lan, int num) 
{ 
  int i=0, j=0; //potrzebne zmienne lokalne 
  char *temp;
  for (i; i<num-1; i++) 
    for (j=i+1; j<num; j++) 
      if (strcmp(lan[i],lan[j]) > 0) 
      { 
          temp=lan[i];
          lan[i]=lan[j];
          lan[j]=temp;
      }
} 

char* sklej(char **tab, int ile)
{
	int size_word;
	int size_sum=0;
	char *result = malloc(sizeof(char));
	result[0]='\0';
	int i=0;

	while(i<ile)
	{
		size_word=strlen(tab[i]);
		size_sum+=size_word+2;
		result = realloc(result, size_sum*sizeof(char));
		strcat(result, tab[i]);
		strcat(result, " ");
		i++;
	}
	return result;
}