#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct xyz
{
	char znak;
	struct xyz *wskaznik;
}xyz;

xyz *czytaj(FILE *bin);

int main(void)
{
	xyz a,b,c;
	a.wskaznik = &b;
	b.wskaznik = &c;
	c.wskaznik = &a;
	a.znak = 'a';
	a.wskaznik->znak = 'b';
	a.wskaznik->wskaznik->znak = 'c';
	printf("a:%c b:%c c:%c\n", b.wskaznik->wskaznik->znak, b.znak, b.wskaznik->znak);

	c.znak = toupper(c.znak);
	c.wskaznik->znak = toupper(c.wskaznik->znak);
	c.wskaznik->wskaznik->znak = toupper(c.wskaznik->wskaznik->znak);

	printf("a:%c b:%c c:%c\n", b.wskaznik->wskaznik->znak, b.znak, b.wskaznik->znak);

	FILE *fin = fopen("dane.txt", "w");
	fprintf(fin, "%c %p %c %p %c %p", a.znak, a.wskaznik, b.znak, b.wskaznik, c.znak, c.wskaznik);
	fclose(fin);

	FILE *fbin = fopen("dane.dat", "wb");
	fwrite(&a, sizeof(xyz), 1, fbin);
	fwrite(&b, sizeof(xyz), 1, fbin);
	fwrite(&c, sizeof(xyz), 1, fbin);
	fclose(fbin);

	fbin = fopen("dane.dat", "rb");
	xyz *tab = czytaj(fbin);
	fseek(fbin, 0, SEEK_END);
	int size = ftell(fbin);

	for(int i = 0; i < size/sizeof(xyz); i++)
		printf("xyz: %c %p\n", tab[i].znak, tab[i].wskaznik);
	free(tab);
	fclose(fbin);
}

xyz *czytaj(FILE *bin)
{
	fseek(bin, 0, SEEK_END);
	int s = ftell(bin);
	printf("rozmiar: %d\n", s);

	rewind(bin);
	xyz *tab = calloc(s/sizeof(xyz), sizeof(xyz));
	fread(tab, sizeof(xyz), s/sizeof(xyz), bin);

	return tab;
}