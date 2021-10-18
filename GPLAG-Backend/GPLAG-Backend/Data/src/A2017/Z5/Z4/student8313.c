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



int ucitaj_artikle(struct Artikal *niz, int kap){
	int ucitano = 0;
	
	
	return ucitano;
}


int ucitaj_prodavnice(struct Prodavnica *niz, int kap){
	int ucitano = 0;
	
	return ucitano;
}


int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na){
	
}


int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke){
	
}


int main() {
	printf("Zadaća 5, Zadatak 4");
	return 0;
}
