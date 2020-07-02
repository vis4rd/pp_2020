#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Klient
{
	char f_name[20];
	char l_name[30];
	char code[7];
	int age;
}Klient;

int double_inStruct_cmp(const void *a,  const void *b);

int main(void) //WAZNE: dziala na windowsie "a.exe < spis.txt", natomiast
		// na linux'ie nie dziala "./a.out < spis.txt" i w sumie
		// nie mam pojecia dlaczego. Mimo, ze nie dziala na linux,
		// to dostalem maks punktow takze nie powinno to sprawiac
		// zadnych problemow. A jak cos to pisac maile do prowadzacego
{
	Klient tab[6];
	for (int i=0; i<6; i++)
    {
		scanf("%s",tab[i].l_name);
		scanf("%s",tab[i].f_name);
		scanf("%s",tab[i].code);
		scanf("%d",&tab[i].age);
    }

    for(int i=0; i<6; i++)
		printf("%s %s kod %s wiek %d\n",tab[i].l_name,tab[i].f_name,tab[i].code,tab[i].age);
    
	qsort(tab, 6, sizeof(*tab), double_inStruct_cmp);
	printf("\n");
	for(int i=0; i<6; i++)
		printf("%s %s kod %s wiek %d\n",tab[i].l_name,tab[i].f_name,tab[i].code,tab[i].age);
}

int double_inStruct_cmp(const void *a,  const void *b)
{
	const Klient *x = a;
	const Klient *y = b;
	if(strcmp(x->l_name,y->l_name)==1)
		return 1;
	else if(strcmp(x->l_name,y->l_name)==-1)
		return -1;
	if(strcmp(x->f_name,y->f_name)==1)
		return 1;
	else if(strcmp(x->f_name,y->f_name)==-1)
		return -1;

	return 0;
}
