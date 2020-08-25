#include <stdio.h>
#include <ctype.h>

typedef struct xyz
{
	char znak;
	struct xyz *wskaznik;
}xyz;

xyz **dlaczego(FILE *bin);

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

	FILE *bruh = fopen("dane.dat", "wb");
	fwrite(&a, sizeof(xyz), 1, bruh);
	fwrite(&b, sizeof(xyz), 1, bruh);
	fwrite(&c, sizeof(xyz), 1, bruh);
	fclose(bruh);

}

xyz **dlaczego(FILE *bin)
{
	int s = ftell(bin);
}