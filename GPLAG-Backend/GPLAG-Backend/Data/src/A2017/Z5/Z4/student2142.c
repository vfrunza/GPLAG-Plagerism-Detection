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
	FILE* dat = fopen("artikli.bin", "rb");
			 if (dat == NULL) {
			 printf("Greska pri otvaranju datoteke.\n");
			 return 0;
			}
    
    int ucitano = fread(niz, sizeof(struct Artikal), kap, dat);
	
	fclose(dat);

return ucitano;
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap);
int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na);
int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke);


int main() {
	
	struct Artikal a[50];
int n = ucitaj_artikle(a, 50), i;

for (i = 0; i < n; ++i)
	printf ("%s (cijena: %g, prodavnica: %d)\n", a[i].naziv, a[i].cijena, a[i].prodavnica);

		
	return 0;
}
