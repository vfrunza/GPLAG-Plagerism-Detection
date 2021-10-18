#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/* racuna prosjek studenta */
double prosjek(struct Student s) {
	double sum = 0;
	int i;
	if (s.br_ocjena == 0) return 5;
	for (i = 0; i < s.br_ocjena; i++) {
		if (s.ocjene[i] == 5) return 5;
		sum += s.ocjene[i];
	}
	return sum / s.br_ocjena;
}

/* slicno kao strcmp (ako je povratna vrijednost negativna prvi argument dolazi prije) */
int poredi(struct Student a, struct Student b) {
	int rez;
	if (prosjek(a) > prosjek(b)) return -1;
	if (prosjek(a) < prosjek(b)) return 1;
	rez = strcmp(a.prezime, b.prezime);
	if (rez != 0) return rez;
	rez = strcmp(a.ime, b.prezime);
	return rez;
}

void print_genijalce(struct Student studenti[], int n) {
	struct Student *genijalci[3] = {0};
	int i, j, n_gen = 0, mjesto;
	for (i = 0; i < n; i++) {
		mjesto = 0;
		/* za svakog studenta odredjujemo mjesto u top listi */
		for (j = 0; j < n_gen; j++)
			if (poredi(studenti[i], *genijalci[j]) >= 0) 
				mjesto++;
		if (mjesto == 3 && n_gen == 3) continue; /* puni smo */
		/* punimo tablicu */
		if (n_gen < 3) n_gen++; 
		/* sve elemente koji su ispod novog guramo prema dole */
		for (j = n_gen - 1; j > mjesto; j--) 
			genijalci[j] = genijalci[j-1];
		genijalci[mjesto] = &studenti[i]; /* i dodajemo novi element */
	}
	for (i = 0; i < n_gen; i++) 
		printf("%s %s\n", genijalci[i]->prezime, genijalci[i]->ime);
}

int genijalci(struct Student studenti[], int n, double granica) {
	int i, j;
	/* izbacujemo studente koji nisu zadovoljili uslov */
	for (i = 0; i < n; i++) 
		if (prosjek(studenti[i]) < granica) { 
			for (j = i; j < n - 1; j++) 
				studenti[j] = studenti[j+1];
			i--;
			n--;
		}
	
	/* printanje top liste */
	print_genijalce(studenti, n);
	return n;
}

int main() {
	return 0;
}