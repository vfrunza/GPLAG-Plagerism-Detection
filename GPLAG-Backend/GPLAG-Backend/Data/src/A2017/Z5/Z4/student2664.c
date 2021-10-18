#include <stdio.h>
#include <stdlib.h> /* Radi funkcije exit() */

struct Prodavnica {
	char naziv[100];
	int ID;
};

struct Artikal {
	char naziv[100];
	double cijena;
	int prodavnica;
};

int ucitaj_artikle (struct Artikal *niz, int kap) {
	FILE* dat;
	int broj_ucitanih;
	dat = fopen("artikli.bin", "rb");
	if (dat == NULL) {
		printf ("Doslo je do greske!\n");
		exit(1);
	}
	broj_ucitanih = fread(niz, sizeof(struct Artikal), kap, dat);
	fclose(dat);
	return broj_ucitanih;
}

int ucitaj_prodavnice (struct Prodavnica *niz, int kap) {
	FILE* dat;
	char string[150], *pok, *p;
	int broj_ucitanih = 0, i = 0, temp, brojac;
	
	dat = fopen("prodavnice.txt", "r");
	if (dat == NULL) {
		printf ("Doslo je do greske!\n");
		exit(2);
	}
	/* %s ne uzima nikada razmake */
	while ((fgets(string, 150, dat) != NULL) && (broj_ucitanih < kap)) {
		/* rad sa stringom */
		brojac = 0;
		pok = string; /* ovo se mora resetovat */
		p = niz[i].naziv; /* i ovo isto */
		while (*pok != '\0' && *pok != ',' && brojac < 99) {
			*p = *pok;
			brojac++;
			pok++;
			p++;
		}
		*p = '\0';
		
		/* Rad sa brojevima stringa */
		temp = 0;
		while (*pok != '\0') {
			if (*pok >= '0' && *pok <= '9') {
				while (*pok >= '0' && *pok <= '9') {
					temp = 10*temp + *pok - '0'; /* iz stringa u broj ide - '0' a vice versa ide + '0' */
					pok++;
				}
			}
			else pok++;
		}
		niz[i].ID = temp;
		i++;
		
		broj_ucitanih++;
	}
	fclose(dat);
	/* nikad fscanf ako imamo proizvoljan broj razmaka unutar datoteke 
	while (fscanf (dat, "%50s %d\n", string, &broj) == 2) {
		printf ("%s, %d\n", string, broj);
	}
	*/
	return broj_ucitanih;
}

int izbaci_skupe (struct Prodavnica *p, int velp, struct Artikal *a, int vela) {
	int i, j, k, brojac_pojedinacnog = 0;
	double suma = 0, ukupni_prosjek = 0, pojedinacni_prosjek = 0;
	
	for (i=0; i<vela; i++) {
		suma += a[i].cijena;
	}
	ukupni_prosjek = suma/vela;
	
	for (i=0; i<velp; i++) {
		suma = 0;
		brojac_pojedinacnog = 0;
		pojedinacni_prosjek = 0;
		for (j=0; j<vela; j++) {
			if (p[i].ID == a[j].prodavnica) {
				suma += a[j].cijena;
				brojac_pojedinacnog++;
			}
		}
		pojedinacni_prosjek = suma / brojac_pojedinacnog;
		/* ALGORITAM ZA IZBACIVANJE VAZNO DRAMA !!! */
		if (pojedinacni_prosjek > ukupni_prosjek) {
			/* algoritam za izbacivanje iz niza */
			for (k=i; k<velp-1; k++) {
				p[k] = p[k+1];
			}
			velp--;
			i--;
		}
	}
	return velp;
}

int sacuvaj (struct Prodavnica *p, int n, const char *ime_datoteke) {
	FILE* dat;
	int broj_upisanih = 0;
	dat = fopen(ime_datoteke, "wb");
	if (dat == NULL) {
		printf ("Doslo je do greske!\n");
		return 0;
	}
	
	broj_upisanih = fwrite(p, sizeof(struct Prodavnica), n, dat);
	fclose(dat);
	
	return 1;
}

int main() {
	int br, i;
	struct Prodavnica niz[100];
	br = ucitaj_prodavnice(niz, 100);
	
	for (i=0; i<br; i++) {
		printf ("Naziv: %s, ID: %d\n", niz[i].naziv, niz[i].ID);
	}
	return 0;
}