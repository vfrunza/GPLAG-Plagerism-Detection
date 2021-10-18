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

int ucitaj_artikle( struct Artikal *niz, int kap){
FILE *dat= fopen("artikli.bin", "rb");
if(dat==NULL){
	
 printf("Greska pri otvaranju!\n");
return 0;
}

int ucitano=fread (niz, sizeof(struct Artikal), kap, dat);
fclose(dat);
return ucitano;
}

int ucitaj_prodavnice( struct Prodavnica *p, int kap){
	FILE *dat=fopen("prodavnice.txt", "r");
	int i=0;
	if(dat==NULL){
		printf("Greska");
		return 0;
		
	}
	while(i<kap && fscanf(dat, "%100s,%d\n", p[i].naziv, p[i].ID)==2){
		i++;
	}
	fclose(dat);
	return i;
	}
	  
int main() {
	FILE *fp;
fprintf (fp = fopen ("prodavnice.txt", "w"), "Amko,1\nBingo,2\nRobot,3\nKonzum,4");
fclose (fp);

/* Sada ucitavamo */
struct Prodavnica p[10];
int n = ucitaj_prodavnice(p, 10), i;
for (i = 0; i < n; ++i)
	printf ("'%s', id: %d\n", p[i].naziv, p[i].ID);

	return 0;
}
