#include <stdio.h>
struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};

int ucitaj_artikle (struct Artikal *niz, int kap)
{
	int ucitano=0, i;
	FILE* dat = fopen("artikli.bin", "rb");
	if (dat == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
for (i=0;i<=kap;i++)
{
	fread(&niz[i].naziv,100*sizeof(char),1,dat);
	fread(&niz[i].cijena,sizeof(double),1,dat);
	fread(&niz[i].prodavnica,sizeof(int),1,dat);
	ucitano+=1;
}

	fclose(dat);
	return ucitano;

}
int main()
{

	printf("Zadaća 5, Zadatak 4");
	return 0;
}
