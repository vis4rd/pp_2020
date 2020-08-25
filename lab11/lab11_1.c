#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

double rand_double(double a, double b);
void fill_double_array1(double *T, int num);
void print_text_double(char *name);
void print_double_array(double *start, int n);
void print_bin_double(char *name);
void read_stdfile(char *name);
void read_binfile(char *name);

int main(int argc, char **argv)
{
	srand(time(NULL));
	printf("Podaj rozmiar tablicy: \n");
	int tabsize;
	scanf("%d", &tabsize);
	double tab[tabsize];

	char *standardfile = argv[2];
	char *binaryfile = argv[1];

	fill_double_array1(tab, tabsize);

	FILE *fp = fopen(standardfile, "w");
	if(!fp)
	{
		printf("error creating txt file\n");
		exit(0);
	}
	else
	{
		for(int i=0; i<tabsize; i++)
			fprintf(fp, "%lf\n", tab[i]);
		int standard_size = ftell(fp);
		fclose(fp);
		printf("plik tekstowy: %d bajtow\n", standard_size);
		//print_double_array(tab, tab+SIZE);
	}

	FILE *fb = fopen(binaryfile, "wb");
	if(!fb)
	{
		printf("error creating binary file\n");
		exit(0);
	}
	else
	{
		fwrite(tab, sizeof(double), sizeof(tab)/sizeof(*tab), fb);
		int binary_size = ftell(fb);
		fclose(fb);
		printf("plik binarny: %d bajtow\n", binary_size);
	}

	printf("prosto z pliku:\n");
	print_text_double(standardfile);
	print_bin_double(binaryfile);

	printf("\npo wpisaniu do tablic:\n");
	read_stdfile(standardfile);
	read_binfile(binaryfile);

}

double rand_double(double a, double b)
{
 	return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

void fill_double_array1(double *T, int num)
{
	for(int i=0; i<num; i++)
		T[i]=rand_double(0, 20);
	return;
}

void print_text_double(char *name)
{
	FILE *fout = fopen(name, "r");
	if(!fout)
	{
		printf("error opening txt file\n");
		exit(0);
	}
	double temp;
	int ile = 0;
	while(1)
	{
		//printf("3");
		if(fscanf(fout, "%lf\n", &temp)==1)
		{
			printf("t[ %d ] = %lf\n", ile, temp);
			ile++;
		}
		else
			break;
	}
	fclose(fout);
	return;
}

void print_double_array(double *start, int n)
{
	for(int i=0;i<n; i++)
		printf("tab[%d] = %lf\n", i, start[i]);
	return;
}

void print_bin_double(char *name)
{
	FILE *fbout = fopen(name, "rb");
	if(!fbout)
	{
		printf("error opening binary file\n");
		exit(0);
	}
	printf("\n");
	double temp;
	int cnt=0;
	while(1)
	{
		if(fread(&temp, sizeof(double), 1, fbout)!=1)
			break;
		printf("bin[ %d ] = %lf\n", cnt, temp);
		cnt++;
	}
	fclose(fbout);
	return;
}

void read_stdfile(char *name)
{
	FILE *fout = fopen(name, "r");
	if(!fout)
	{
		printf("error opening txt file\n");
		exit(0);
	}
	double temp;
	int ile=0;
	double *target = calloc(1, sizeof(double));
	while(1)
	{
		//printf("3");
		if(fscanf(fout, "%lf\n", &temp)==1)
		{
			//printf("%lf\n", temp);
			ile++;
			target = realloc(target, ile*sizeof(double));
			target[ile-1] = temp;
		}
		else
			break;
	}
	fclose(fout);
	printf("txt:\n");
	print_double_array(target, ile);
	free(target);
	return;
}

void read_binfile(char *name)
{
	FILE *fbout = fopen(name, "rb");
	if(!fbout)
	{
		printf("error opening binary file\n");
		exit(0);
	}
	fseek(fbout, 0, SEEK_END);
	int bytes = ftell(fbout);
	double *target = malloc(bytes);
	rewind(fbout);
	fread(target, sizeof(double), bytes/sizeof(double), fbout);
	fclose(fbout);
	printf("bin:\n");
	print_double_array(target, bytes/sizeof(double));

	FILE *zero = fopen(name, "rb+");
	if(!fbout)
	{
		printf("error opening binary file\n");
		exit(0);
	}
	double temp = 0.0;
	int ile=0;
	printf("\n");
	while(ile<(bytes/sizeof(double)))
	{
		if(ile==0)
			fwrite(&temp, sizeof(double), 1, zero);
		fseek(zero, 4*sizeof(double), SEEK_CUR);
		fwrite(&temp, sizeof(double), 1, zero);
		ile++;
	}
	fclose(zero);

	FILE *one = fopen(name, "rb");
	fread(target, sizeof(double), bytes/sizeof(double), one);
	fclose(one);
	print_double_array(target, bytes/sizeof(double));
	free(target);

	return;
}