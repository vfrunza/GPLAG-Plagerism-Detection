#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
struct Oblik oblikovi[65535];

void povecaj_N() {
	unsigned short N = 0;
	FILE *dat = fopen("oblici.dat", "rb+");
	if (dat == NULL) {
		printf("Neuspjesno otvaranje datoteke oblici.dat");
		exit(1);
	}
	fread(&N, 2, 1, dat);
	N++;
	fseek(dat, 0, SEEK_SET);
	fwrite(&N, 2, 1, dat);
	fclose(dat);
}

void dodaj_oblik(struct Oblik o) {
	unsigned char a = o.br_stranica; 
	float x; 
	int i;
	povecaj_N();
	FILE *dat = fopen("oblici.dat", "ab");
	if(dat == NULL) exit(1);
	fwrite(o.naziv, 1, 20, dat);
	fwrite(&a, 1, 1, dat);
	for(i = 0; i < o.br_stranica; i++) {
		x = o.stranice[i];
		fwrite(&x, 4, 1, dat);
	}
	fclose(dat);
}

unsigned short ucitaj() {
	int j;
	float duzina = 0;
	unsigned short N = 0, i;
	unsigned char X = 0;
	FILE *dat = fopen("oblici.dat", "rb");
	if (dat == NULL) {
		printf("Neuspjesno otvaranje datoteke oblici.dat");
		exit(1);
	}
	fread(&N, 2, 1, dat);
	for (i = 0; i < N; i++) {
		j = fread(oblikovi[i].naziv, 1, 20, dat);
		oblikovi[i].naziv[j] = '\0';
		fread(&X, 1, 1, dat);
		oblikovi[i].br_stranica = X;
		for (j = 0; j < oblikovi[i].br_stranica; j++) {
			fread(&duzina, 4, 1, dat);
			oblikovi[i].stranice[j] = duzina;
		}
	}
	fclose(dat);
	return N;
}

void izbaci_duple() {
	unsigned short N = ucitaj(), i, j, k;
	FILE *dat;
	for (i = 0; i < N; i++) 
		for (j = i+1; j < N; j++) 
			if (strcmp(oblikovi[i].naziv, oblikovi[j].naziv) == 0) {
				for (k = j+1; k < N; k++) 
					oblikovi[k-1] = oblikovi[k];
				j--;
				N--;
			}
	dat = fopen("oblici.dat", "wb");
	fclose(dat);
	for (i = 0; i < N; i++)
		dodaj_oblik(oblikovi[i]);
}

struct Oblik daj_najveci() {
	unsigned short N = ucitaj(), i, j, max = 0;
	double max_obim = 0, obim;
	for (i = 0; i < N; i++) {
		obim = 0;
		for (j = 0; j < oblikovi[i].br_stranica; j++)
			obim += oblikovi[i].stranice[j];
		if (obim > max_obim) {
			max_obim = obim;
			max = i;
		}
	}
	return oblikovi[max];
}

int main() {
	return 0;
}
