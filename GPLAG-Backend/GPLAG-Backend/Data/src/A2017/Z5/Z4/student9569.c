#include <stdio.h>
#include <stdlib.h>

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};

struct Prodavnica {
	char naziv[100];
	int ID;
};

int ucitaj_artikle(struct Artikal *niz, int kapacitet){
	int broj_ucitanih=0;
	FILE *ulaz=fopen("artikli.bin", "rb");
	{
		if(ulaz == NULL) {
			printf("Greska");
			return -1;
		}
	}
	broj_ucitanih=fread(niz, sizeof(struct Artikal), kapacitet, ulaz);
	fclose(ulaz);
	return broj_ucitanih;
}

int ucitaj_prodavnice(struct Prodavnica *niz, int kapacitet){
	int i=0, br=0;
	char znak='\0';
	FILE *prodavnica=fopen("prodavnice.txt", "r");
	{
		if(prodavnica == NULL){
			printf("Greska");
			return -1;
		}
		
	}
	for(i=0; i<kapacitet; i++) {
		znak=fgetc(prodavnica);
		if(znak == EOF) break;
		br=0;
		do{
			niz[i].naziv[br++] = znak;
		} while((znak=fgetc(prodavnica))!=',' && br < 99);
		
		if(br==99 && znak!= ','){
			while((znak=fgetc(prodavnica)) != ',');
		}
		niz[i].naziv[br] = 0;
		fscanf(prodavnica, "%d", &niz[i].ID);
		
		znak=fgetc(prodavnica);
		
	}
	return i;
}

double Prosjek(struct Artikal *niz, int ID_prodavnice, int kapacitet){
	int i, br=0;
	double suma=0;
	for(i=0; i<kapacitet; i++){
		if(niz[i].prodavnica == ID_prodavnice){
			suma+=niz[i].cijena;
			br++;
		}
	}
	if(br==0) return 0;
	else
	return suma/br;
}

void izbaci(struct Prodavnica *niz, int ind, int kapacitet){
	int i=ind;
	for(i=ind; i<kapacitet-1; i++){
		niz[i]=niz[i+1];
	}
	kapacitet--;
}

int izbaci_skupe(struct Prodavnica *p, int naziv_prod, struct Artikal *a, int naziv_art){
	int i;
	double suma=0, prosjek, temp;
	if(naziv_art == 0 || naziv_prod==0) return naziv_prod;
	for(i=0; i<naziv_art; i++){
		suma+=a[i].cijena;
	}
	prosjek=suma/naziv_art;
	for(i=0; i<naziv_prod; i++){
		temp=Prosjek(a, p[i].ID, naziv_art);
		if(temp>prosjek){
			izbaci(p,i,naziv_prod);
			naziv_prod--;
		}
	}
	return naziv_prod;
}

int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke){
	FILE* izlaz=fopen(ime_datoteke, "wb");
	if(izlaz == NULL){
		printf("Greska");
		return 0;
	}
	int ucitano=fwrite(p,sizeof(struct Prodavnica), n, izlaz);
	if(ferror(izlaz)){
		printf("Greska");
		return 0;
	}
	fclose(izlaz);
	return 1;
}

int main() {
	printf("Zadaća 5, Zadatak 4");
	return 0;
}
