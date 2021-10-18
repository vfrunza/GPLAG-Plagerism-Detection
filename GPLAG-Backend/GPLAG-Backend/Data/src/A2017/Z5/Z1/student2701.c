#include <stdio.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int godina) {
	return (godina % 400 == 0 || (godina % 4 == 0 && godina % 100 != 0));
}

int mj_u_dane(struct Datum dat) {
	int prg  = 0;
	if (prestupna(dat.godina)) prg++;
	switch(dat.mjesec) {
		case 12: return 334 + prg;
		case 11: return 304 + prg;
		case 10: return 273 + prg;
		case 9: return 243 + prg;
		case 8: return 212 + prg;
		case 7: return 181 + prg;
		case 6: return 151 + prg;
		case 5: return 120 + prg;
		case 4: return 90 + prg;
		case 3: return 59 + prg;
		case 2: return 31;
	}
	return 0;
}

int daj_dane(struct Datum datum1, struct Datum datum2) {
	int dan1 = 0, dan2 = 0;
	dan1 = datum1.godina/4 + datum1.godina/400 - datum1.godina/100;
	dan2 = datum2.godina/4 + datum2.godina/400 - datum2.godina/100;
	if(prestupna(datum1.godina)) dan1--;
	if(prestupna(datum2.godina)) dan2--;
	dan1 += datum1.godina*365; 		dan2 += datum2.godina*365;
	dan1 += mj_u_dane(datum1);		dan2 += mj_u_dane(datum2);
	dan1 += datum1.dan; 			dan2 += datum2.dan;
	return dan1 - dan2;
}

char *prezime(char *ime_prezime) {
	char *s = NULL;
	while (*ime_prezime != '\0') {
		if (*ime_prezime == ' ') {
			s = ++ime_prezime;
			while (*s != '\0' && *s != ' ' && *s != '-') s++;
			if (*s == '-' || *s == '\0') return ime_prezime;
		}
		ime_prezime++;
	}
	return ime_prezime;
}
/*potecijalni skriveni razmaci prije imena, vise razmaka izmedju imena/prezimena*/
int familija(char *direktor, char *radnik) {
	char *prvo1 = prezime(direktor), *prvo2 = prezime(radnik), *drugo1 = prvo1, *drugo2 = prvo2, *pomocni1 = NULL, *pomocni2 = NULL;
	while (*drugo1 != '\0' && *drugo1 != '-') drugo1++;
	while (*drugo2 != '\0' && *drugo2 != '-') drugo2++;
	if (*drugo1 == '-') {
		pomocni1 = drugo1;
		while (*pomocni1 != '\0') pomocni1++;
	}
	if (*drugo2 == '-') {
		pomocni2 = drugo2;
		while (*pomocni2 != '\0') pomocni2++;
	}
	if (drugo1-prvo1 == drugo2-prvo2 && strncmp(prvo1, prvo2, drugo1-prvo1) == 0) return 1;
	if (pomocni2 != NULL && drugo1-prvo1 == pomocni2-(drugo2+1) && strncmp(prvo1, drugo2+1, drugo1-prvo1) == 0) return 1;
	if (pomocni1 != NULL && pomocni1-(drugo1+1) == drugo2-prvo2 && strncmp(drugo1+1, prvo2, pomocni1-drugo1+1) == 0) return 1;
	if (pomocni1 != NULL && pomocni2 != NULL && pomocni1-(drugo1+1) == pomocni2-(drugo2+1) && strncmp(drugo1+1, drugo2+1, pomocni1-drugo1+1) == 0) return 1;
	return 0;
}

int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int i, j, k;
	for (i = 0; i < vel; i++) {
		if ((daj_dane(direktor.datum_rodjenja, kandidati[i].datum_rodjenja) > broj_dana && !familija(direktor.ime_prezime, kandidati[i].ime_prezime)) || (daj_dane(direktor.datum_rodjenja, kandidati[i].datum_rodjenja) == 0 && strcmp(direktor.ime_prezime, kandidati[i].ime_prezime) == 0)) {
			for (j = i+1; j < vel; j++)
				kandidati[j-1] = kandidati[j];
			vel--;
			i--;
		}
	}
	for (i = 0; i < vel; i++) {
		for (j = i+1; j < vel; j++) {
			if (daj_dane(kandidati[i].datum_rodjenja, kandidati[j].datum_rodjenja) == 0 && strcmp(kandidati[i].ime_prezime, kandidati[j].ime_prezime) == 0) {
				for (k = j+1; k < vel; k++) {
					kandidati[k-1] = kandidati[k];
				}
				j--;
				vel--;
			}
		}
	}
	return vel;
}

int main() {
	struct Uposlenik direktor = {"", {1, 2, 1980} };
	struct Uposlenik kandidati[7] = {
	    { "Meho Mehaga Peric-Mehic", { 31, 1, 1980 } },
	    { "Pero Jozic-Peric", { 7, 2, 1980 } },
	    { "Sara Sarac", { 2, 2, 1980 } },
	    { "Mujo Mujic", { 1, 2, 1980 } },
	    { "Jozo Jozic", { 1, 10, 1980 } },
	    { "Pero Peric", { 7, 2, 1980 } },
	    { "Pero Peric", { 7, 2, 1980 } },
	};
	
	/* 1980 godina je bila prestupna, februar je imao 29 dana,
	   sto znaci da je Pero Peric za 29 dana stariji od direktora,
	   pa kako je 29>28 Pero treba biti izbacen a Sara ne. */
	
	int novi_br = suzi_listu(kandidati, 7, direktor, -5);
	int i;
	printf("Nakon suzenja liste:\n");
	for (i=0; i<novi_br; i++)
	    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
