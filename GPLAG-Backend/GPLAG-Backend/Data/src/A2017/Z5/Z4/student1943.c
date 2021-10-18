#include <stdio.h>
#include <stdlib.h>

struct Prodavnica{
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};


int ucitaj_artikle (struct Artikal *niz, int kap){
	int i=0, brUspjesnih=0;
	char *nizz[100];
	FILE *ulaz;
	
		if ((ulaz=fopen ("artikli.bin", "r"))==NULL){
			printf ("Greska pri otvaranju datoteke artikli.bin");
			exit (1);
		}
	
	for (i=0; i<kap; i++){
		if 	(fscanf (ulaz, "%s", *nizz)==1){
			/*nizz++;*/
			brUspjesnih++;
		}
	}
	
	return brUspjesnih;
}

int ucitaj_prodavnice(struct Prodavnica *niz, int kap){
	int brojUcitanih=0;
	int i;
	struct Prodavnica prodavnica[1000];
	FILE *ulaz;
	
	if ((ulaz=fopen ("prodavnice.txt", "r"))==NULL){
		printf ("Greska pri otvaranju datoteke prodavnice-txt");
		exit(1);
	}
	i=0;
	while (fscanf (ulaz, "%s, %d", prodavnica[i].naziv, &prodavnica[i].ID ) ==2 && i<kap)
    i++;
    brojUcitanih=i;
	
	return brojUcitanih;
}
int main() {
	
	int n;
	FILE *ulaz;
	
	struct Artikal a[50];
	struct Prodavnica p[10];
	
	if ((ulaz=fopen ("artikli.bin", "r"))==NULL){
		printf ("Greska pri otvaranju datoteke artikli.bin");
		exit (1);
	}
	
	printf ("Pozivanje funkcije: ");
	
	ucitaj_artikle(a, 50);
	
   n=ucitaj_prodavnice (p, 10);
   
   printf ("%d", n);
	return 0;
}
