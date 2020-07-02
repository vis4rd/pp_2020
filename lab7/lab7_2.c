#include <stdio.h>
#include <string.h>

#define SIZE 80

int main(int argc, char* argv[]) //wywolanie a.exe < lokomotywa.dat tak
{
    char temp[SIZE];
    char *line;
    char *word= argv[1];
    int ile_wyrazow=0;
    char *next;

    do
    {
        line = fgets(temp, SIZE, stdin);
        if (line == NULL)
        	break;
        next=strstr(line,word);
        if(next!=NULL)
        {
        	puts(line);
        	while(next!=NULL)
        	{
        		next=strstr(next+1, word);
        		ile_wyrazow++;
        	}
        }

    }while (1);
    printf("wystapienia wyrazu \"%s\": %d\n", word, ile_wyrazow);

    return 0;
}