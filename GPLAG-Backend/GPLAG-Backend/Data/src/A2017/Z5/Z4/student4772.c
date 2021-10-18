#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Prodavnica {
	char naziv[100];
	int ID;
} Prodavnica;

typedef struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
} Artikal;

int ucitaj_artikle (struct Artikal *niz, int kap){

	FILE* ulaz = fopen("artikli.bin", "rb");

	if(!ulaz){
		printf("Greska prilikom ucitavanja datoteke \"artikli.bin!\"");
		exit(1);
	}

	int i = 0;
	Artikal temp;

	//Ucitaj kap artikala iz "artikli.bin"
	while(i < kap && fread(&temp, sizeof(Artikal), 1, ulaz)){
		if(ferror(ulaz)){
			printf("Doslo je do greske prilikom citanja iz \"artikli.bin\"!");
			exit(1);
		}

		*(niz+i) = temp;

		i++;
	}

	fclose(ulaz);

	return i;
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap){

	FILE* ulaz = fopen("prodavnice.txt", "r");

	if(!ulaz){
		printf("Greska prilikom ucitavanja datoteke \"prodavnice.txt\"!");
		exit(1);
	}

	int i = 0, j = 0;
	Prodavnica temp;

	char c, strLen;

	//Ucitaj kap prodavnica iz "prodavnice.txt"
	while(i < kap){
		//Ucitaj string do ','
		j = 0;

		while(1){
			c = fgetc(ulaz);

			if(c == ',' || c == EOF) break;

			if(j < 99){
				*(temp.naziv+j) = c;
				strLen = j;
			}

			j++;
		}

		*(temp.naziv + strLen + 1) = '\0';

		c = fscanf(ulaz, "%d\n", &temp.ID);

		if(c != 1) break;

		//printf("Prodavnica: %s : %d\n", temp.naziv, temp.ID);
		*(niz+i) = temp;
		i++;
	}

	fclose(ulaz);

	return i;
}

int izbaci_skupe (struct Prodavnica *p, int np, struct Artikal *a, int na){
	int i, j;
	double avg_svih = 0;
	double avg_prod = 0;
	int br_poizvoda;

	//Srednja vrijednost svih artikala svih prodavnica
	for(i = 0; i < na; i++){
		avg_svih += a[i].cijena;
	}
	avg_svih /= na;

	for(i = 0; i < np; i++){
		//Pocetne vrijednosti su na nuli za svaku prodavnicu
		br_poizvoda = 0;
		avg_prod = 0;

		//Racunaj srednju svih proizvoda i-te prodavnice
		for(j = 0; j < na; j++){
			//Ako prodavnica u kojoj je artikal odgovara ID-u i-te prodavnice, povecaj broj artikala
			//i odmah uracunaj cijenu tog proizvoda u avg_prod
			if(a[j].prodavnica == p[i].ID){
				avg_prod += a[j].cijena;
				br_poizvoda++;
			}
		}

		//Nema proizvoda u ovoj prodavnici
		if(br_poizvoda == 0) continue;

		//Sracunaj srednju vrijednost
		avg_prod /= br_poizvoda;

		//Ako je veca od avg_svih, izbaci i-tu prodavnicu
		if(avg_prod > avg_svih){

			for(j = i; j < np - 1; j++){
				p[j] = p[j+1];
			}
			np--;
			i--;
		}
	}

	return np;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke){

	FILE* izlaz = fopen(ime_datoteke, "wb");

	if(!izlaz){
		return 0;
	}

	fwrite(p, sizeof(Prodavnica), n, izlaz);

	if(ferror(izlaz)) return 0;

	fclose(izlaz);

	return 1;
}

int main() {

	Prodavnica prod[10];
	int np = 4, i;

	np = ucitaj_prodavnice(prod, np);

	for(i = 0; i < np; i++){
		printf("->%s, %d\n", prod[i].naziv, prod[i].ID);
	}
FILE* izlaz = fopen("artikli.bin", "wb");

	if(!izlaz){
		return 0;
	}

	Artikal art[10] = {
		{"Brasno", 5.2, 1},
		{"Ulje", 2, 1},
		{"Secer", 1.5, 1},

		{"Brasno", 5.2, 2},
		{"Ulje", 2.1, 2},
		{"Secer", 2.2, 2},

		{"Brasno", 5.2, 3},
		{"Ulje", 1.1, 3},
		{"Secer", 1.2, 3},
		{"Grah", 5, 3}
	};

	fwrite(art, sizeof(Artikal), 10, izlaz);

	if(ferror(izlaz)) return 0;

	fclose(izlaz);
	return 0;
}

