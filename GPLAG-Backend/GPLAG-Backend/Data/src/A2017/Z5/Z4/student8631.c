#include <stdio.h>
#include<stdlib.h>
struct Prodavnica{
 char naziv[100]; 
 int ID; 
};

struct Artikal{
char naziv[100]; 
double cijena; 
int prodavnica; 
};
//artikli.bin, prodavnice.txt
int ucitaj_prodavnice(struct Prodavnica *niz, int kap){
 	int i=0; 
 	FILE *Ulaz=fopen("prodavnica.txt", "r"); 
 	if(Ulaz==NULL){
 		printf("Greska pri otvaranju datoteke za citanje.\n");
 		return 1; 
 	}
 while (fscanf(Ulaz, "%100s%d", niz[i].naziv, &niz[i].ID )==2 && kap!=0)
 { kap--;
 i++;	
 }	
 fclose(Ulaz); 
 return i; 
}

int ucitaj_artikle(struct Artikal *niz, int kap){
	//ucitavanje iz dat i smjestanje u niz
	//if kap premal ucitat koliki je kap
	// vraca broj ucitanih 
	FILE *Ulaz=fopen("artikli.bin", "rb"); 
	if(Ulaz==NULL) {
		printf("Greska pri otvaranju datoteke.\n"); 
		return 0; }
		// for petlja koja sa fread smjesti 1 po 1 na &niz[i]
	int ucitano=fread(niz, sizeof(struct Artikal),kap, Ulaz);
	fclose(Ulaz);
	return ucitano;
}

int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke){
	FILE *Ulaz=fopen("prodavnice.txt", "r"); 
	if(Ulaz==NULL) {
		printf("Greska pri otvaranju datoteke.\n"); 
		return 0; }
int zapisano=fwrite(ime_datoteke, sizeof (struct Prodavnica), n, Ulaz );	
	if(ferror(Ulaz)){
		printf("Greska prilikom pisanja datoteke.\n");
	}
	fclose(Ulaz); 
	if(zapisano>0) return 1; 
	return 0; 
}

/*int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na){
	//izbacuje sve prodavnice cija je prosjecna cijena artikla veca od svih prosjecnih cijena svih prodavnica
	FILE * bin=fopen("artikli.bin", "r");
	FILE *dat= fopen("prodavnice.txt", "r");// il "w"
	if(bin==NULL) {printf("Greska pri otvaranju datoteke.\n"); exit(1);}
	if(dat==NULL){printf("Greska pri otvaranju datoteke.\n"); exit(1); }
	int i,j; 
	for(i=0; i<np; i++) 
	{
		for(j=0; na; j<na; j++) 
		   if(a[j].cijena>) // ????
	}
	fclose(dat); 
	fclose(bin);
}*/

int main() {
	printf("Zadaća 5, Zadatak 4");
	return 0;
}
