#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct Klient
{
	char f_name[20];
	char l_name[30];
	char code[10];
	int age;
}Klient;

Klient *read(char *nazwa, int *rozmiar);

int main(void)
{
	int size;
	Klient *result = read("spis.txt", &size);

    FILE *fb = fopen("dane.dat", "wb");
	if(!fb)
	{
		printf("error creating binary file\n");
		exit(0);
	}
	else
	{
		fwrite(result, sizeof(Klient), size, fb);
		fclose(fb);
	}

	FILE *fbruh = fopen("dane.dat", "rb");
	if(!fbruh)
	{
		printf("error reading binary file\n");
		exit(0);
	}
	else
	{
		Klient *temp;
		int cnt=0;
		while(true)
		{
			if(fread(temp, sizeof(Klient), 1, fbruh)!=1)
				break;
			cnt++;
			if(temp->age>17)
				printf("klient %d:\n  imie: %s\n  nazwisko: %s\n  kod: %s\n  wiek: %d\n\n", cnt, temp->f_name, temp->l_name, temp->code, temp->age);
		}
	}
	fclose(fbruh);

}

Klient *read(char *nazwa, int *rozmiar)
{
	FILE *fu = fopen(nazwa, "r");
	Klient *temp = calloc(1, sizeof(Klient));
	if(!temp)
	{
		printf("error0\n");
		return NULL;
	}
	int ile=0;
	while(1)
	{
		ile++;
		temp = realloc(temp, ile*sizeof(Klient));
		if(!temp)
		{
			printf("error1\n");
			return NULL;
		}
		if(fscanf(fu, "%s",temp[ile-1].l_name)!=1)
		{
			ile--;
			temp = realloc(temp, ile*sizeof(Klient));
			break;
		}
		fscanf(fu, "%s",temp[ile-1].f_name);
		fscanf(fu, "%s",temp[ile-1].code);
		fscanf(fu, "%d",&temp[ile-1].age);
	}
	fclose(fu);
	*rozmiar = ile;
	return temp;
}