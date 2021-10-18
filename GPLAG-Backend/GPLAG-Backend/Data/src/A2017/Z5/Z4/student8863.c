#include <stdio.h>
#include <stdlib.h>

struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};

int ucitaj_artikle(struct Artikal *niz, int kap) {
	int br = 0;
	FILE *dat = fopen("artikli.bin", "rb");
	if (dat == NULL) {
		printf("Greska prilikom otvaranja datoteke");
		exit(1);
	}
	br = fread(niz, sizeof(struct Artikal), kap, dat);
	fclose(dat);
	return br;
}

int ucitaj_prodavnice(struct Prodavnica *niz, int kap) {
	int br = 0, i = 0;
	char c;
	FILE *text = fopen("prodavnice.txt", "r");
	if (text == NULL) {
		printf("Greska prilikom otvaranja datoteke");
		exit(1);
	}
	do {
		c = fgetc(text);
		if (c != EOF && c != ',' && i < 99) {
			niz->naziv[i] = c; i++;
		}
		if (c == ',') {
			niz->naziv[i] = '\0';
			if(fscanf(text, "%d\n", &niz->ID) == 0) break;
			br++; niz++;
			i = 0;
		}
		
	} while(br < kap && c != EOF);
	fclose(text);
	return br;
}

int izbaci_skupe(struct Prodavnica *p, int np, struct Artikal *a, int na) {
	int i, j, br_pr;
	double suma1, suma2 = 0;
	for (i = 0; i < na; i++) {
		suma2 += a[i].cijena;
	}
	for (i = 0; i < np; i++) {
		suma1 = 0;
		br_pr = 0;
		for (j = 0; j < na; j++) {
			if (p[i].ID == a[j].prodavnica) {
				suma1 += a[j].cijena;
				br_pr++;
			}
		}
		if (br_pr != 0 && suma1/br_pr > suma2/na) {
			for (j = i+1; j < np; j++)
				p[j-1] = p[j];
			i--; np--;
		}
	}
	return np;
}

int sacuvaj(struct Prodavnica *p, int n, const char *ime_datoteke) {
	FILE *izlaz = fopen(ime_datoteke, "wb");
	if (izlaz == NULL) return 0;
	if(fwrite(p, sizeof(struct Prodavnica), n, izlaz) != n) {
		fclose(izlaz);
		return 0;
	}
	fclose(izlaz);
	return 1;
}

int main() {
	return 0;
}
