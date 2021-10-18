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



int napraviBinarnu(struct Artikal* niz, int kap){
	FILE* dat = fopen("artikli.bin", "wb");
	if(dat==NULL){
		printf("Greska!");
		return 0;
	}
	int ucitano = fwrite(niz,sizeof(struct Artikal), kap, dat);
	if (ferror(dat)) 
	{
		printf("Greska prilikom pisanja datoteke.\n");
		printf("Zapisano je samo %d osoba\n", ucitano);
	}
	
	fclose(dat);
	return ucitano;
}


int ucitaj_artikle (struct Artikal *niz, int kap){
	FILE* dat = fopen("artikli.bin", "rb");
	if (dat == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	int ucitano = fread(niz, sizeof(struct Artikal),kap, dat);
	fclose(dat);
	return ucitano;

}



int ucitaj_prodavnice (struct Prodavnica *niz, int kap){
	
}



int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na){
	
}



int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke){
	
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
}
