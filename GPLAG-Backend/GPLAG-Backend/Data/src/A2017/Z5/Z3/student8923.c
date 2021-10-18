#include <stdio.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

int ucitaj (struct Oblik *oblik, FILE *ulaz) {
	int i = 0;
	float a = 0;
	unsigned char c = 0;
	oblik->br_stranica = 0;
	if(fread(oblik->naziv, 1, 20, ulaz) == 20 && fread(&c, 1, 1, ulaz) == 1) {
		oblik->br_stranica = (int) c;
		while(i < c && fread(&a, 4, 1, ulaz) == 1)
			oblik->stranice[i++] = (double) a;
		return 1;
	}
	return 0;
}

int dodaj_oblik (struct Oblik oblik) {
	FILE *ulaz = fopen("oblici.dat", "rb+");
	float a = 0; 
	unsigned char c = 0;
	int i = 0;
	unsigned short n = 0;
	if(!ulaz) ulaz = fopen("oblici.dat", "wb+");
	if(!ulaz) return 1;
	if(fread(&n, 2, 1, ulaz) != 1) n = 1;
	else n++;
	fseek(ulaz, 0, SEEK_SET);
	fwrite(&n, 2, 1, ulaz);
	
	fwrite(oblik, sizeof(struct Oblik), 1, ulaz);
	fclose(ulaz);
}

struct Oblik daj_najveci () {
	struct Oblik niz[1000];
	double trenutni_obim = 0, najveci_obim = 0;
	int i, vel, indeks = 0, j;
	vel = ucitaj(niz, 1000);
	for(i = 0; i < niz[0].br_stranica; i++) najveci_obim += niz[0].stranice[i];
	for(i = 1; i < vel; i++) {
		for(j = 0; j < niz[1].br_stranica; j++) trenutni_obim += niz[i].stranice[j];
		if(trenutni_obim > najveci_obim) {
			najveci_obim = trenutni_obim;
			indeks = i;
		}
	}
	return niz[indeks];
}

int main() {
	printf("Zadaća 5, Zadatak 3");
	return 0;
}
