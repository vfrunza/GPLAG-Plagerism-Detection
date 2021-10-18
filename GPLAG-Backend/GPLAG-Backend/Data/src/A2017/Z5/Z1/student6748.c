#include <stdio.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};


int razlika_datuma(struct Datum d1, struct Datum d2) {
	int mjeseci[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long int dani1, dani2;
	int i, broj_prestupnih, godina;
	/*dodamo pocetnu vrijednost, zatim je povecamo za broj dana po mjesecima, te na kraju dodamo onoliko dana koliko postoji prestupnih godina*/
	/*datum 1*/
	dani1 = d1.godina * 365 + d1.dan;
	for (i = 0; i < d1.mjesec - 1; i++) /*ne dodajemo za zadnji mjesec jer smo u liniji iznad dodali*/
		dani1 += mjeseci[i];
	/*sada je potrebno izracunati koliko je bilo prestupnih godina i racuna li se zadnja-ona u datumu u prestupnu
	(ne racuna se ako je mjesec januar ili februar-bez obzira na 29.-njega dodajemo kao dane) */
	godina = d1.godina;
	if (d1.mjesec < 3)
		godina--; /*dakle ako je mjesec januar ili februar, ne uzimamo u obzir trenutnu godinu u ukupan broj prestupnih*/
	broj_prestupnih = godina / 4 + godina / 400 - godina / 100; /*prema formuli*/
	dani1 += broj_prestupnih;
	
	/*datum 2*/
	dani2 = d2.godina * 365 + d2.dan;
	for (i = 0; i < d2.mjesec - 1; i++) 
		dani2 += mjeseci[i];
	godina = d2.godina;
	if (d2.mjesec < 3)
		godina--; /*dakle ako je mjesec januar ili februar, ne uzimamo u obzir trenutnu godinu u ukupan broj prestupnih*/
	broj_prestupnih = godina / 4 + godina / 400 - godina / 100; /*prema formuli*/
	dani2 += broj_prestupnih;
	
	return dani1 - dani2; /*ako se vrati negativan broj, to znaci da je datum d1 prije datuma d2*/
}

int poredjenje_prezimena(char *ime_prezime1, char *ime_prezime2) {
	char *p1, *p2; /*/*posto funkcija prima i ime i prezime, ovi se postavljaju na pocetak prezimena 1 i p2*/
	char *p, *q, *r, *s;
	
	/*postavljanje p1 na prezime 1*/
	p1 = ime_prezime1;
	while (*p1 != '\0') p1++;
	/*vratimo se nazad do prvog razmaka*/
	while (*p1 != ' ') p1--;
	p1++; /*pomicanje na prvo slovo prezimena*/
	
	/*isto za p2*/
	p2 = ime_prezime2;
	while (*p2 != '\0') p2++;
	while (*p2 != ' ') p2--;
	p2++;
	
	/*sa ovom petljom prolazimo kroz prvo prezime i za svaku rijec
	  iz njega, provjeravamo postoji li u drugom prezimenu*/
	/*unutrasnja petlja prolazi kroz drugo prezime svaki put od pocetka do kraja*/
	p = p1;
	while (*p != '\0') {
		if (*p >= 'A' && *p <= 'Z' || *p >= 'a' && *p <= 'z') {
			q = p2; /*restartujemo q na pocetak rezimena 2*/
			while (*q != '\0') {
				if (*q >= 'A' && *q <= 'Z' || *q >= 'a' && *q <= 'z') {
					r = p; /*na pocetak rijeci u prez 1 postavimo r*/
					s = q; /*na pocetak trenutne rijeci u prez 2 postavimo s*/
					/*ovo nas izbacuje na prvom razlicitom slovu ili kada je jedno ili oboje na '-' ili '\0'*/
					while (*r == *s && *r != '-' && *r != '\0' && *s != '-' && *s != '\0') {
						r++;
						s++;
					}
					/*sada, ako smo naisli na istu rijec tj prezime, oba se nalaze na - ili na \0 pa imamo*/
					if ((*r == '-' || *r == '\0') && (*s == '-' || *s == '\0')) 
						return 1; /*dakle postoji isto prezime u dva primljena*/
					/*u suprotnom prodjemo sa s do kraja trenutnog prezimena i idemo dalje*/
					else
						while (*s != '-' && *s != '\0') s++;
						
					/*sa q preskacemo na s-1 pa ce nas q++ uvecati na - ili na \0*/
					q = s - 1;
				}
				q++;
			}/*unutrasnji while*/
			/*ovdje je potrebno prebaciti p na naredni - ili na \0 tj jedno mjesto prije zbog p++ na kraju petlje*/
			while (*(p + 1) != '-' && *(p + 1) != '\0') p++;
		}
		p++;
	}
	/*ako je sve ovo proslo bez vracanja 1, onda ne postoji isto prezime u dva primljena pa vracamo 0*/
	return 0;
}

int izbaci_uposlenika(struct Uposlenik *kandidati, int vel, int pozicija) {
	int i;
	for (i = pozicija; i < vel - 1; i++)
		kandidati[i] = kandidati[i + 1];
	vel--;
	
	return vel;
}

/*ako je razlika datuma >= vel onda je to kandidat za izbacivanje, jos je potrebno provjeriti prezime*/
int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int i, razlika_dani;
	
	for (i = 0; i < vel; i++) {
		razlika_dani = razlika_datuma(direktor.datum_rodjenja, kandidati[i].datum_rodjenja);
		/*kada je kandidat mladnji za MANJE od poslanog broja dana(abs vr njegove)
		  ili kada je kandidat stariji za VISE od poslanog broja dana(kada je poslan pozitivan) vrijedi razlika_dani > broj_dana*/
		  /*jos uz to mora vrijediti i da se razlikuju prezimena kandidata i direktora*/
		if (razlika_dani > broj_dana && !poredjenje_prezimena(direktor.ime_prezime, kandidati[i].ime_prezime)) { /*ako se vrati nula znaci nema istog prezimena*/
			vel = izbaci_uposlenika(kandidati, vel, i);
			i--;
		}
	}
	return vel;
}

int main() {
    
    struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1980} };
	struct Uposlenik kandidati[7] = {
	    { "Meho Mehic", { 31, 1, 1980 } },
	    { "Pero Peric", { 1, 2, 1980 } },
	    { "Sara Sarac", { 2, 2, 1980 } },
	    { "Fata Mujic", { 1, 2, 1976 } },
	    { "Jozo Jozic", { 1, 10, 1980 } },
	    { "Mijo Mijic", { 4, 3, 1979 } },
	    { "Suljo Suljic", { 15, 1, 1982 } },
	};
	
	/* 1980 godina je bila prestupna, februar je imao 29 dana,
	   sto znaci da je Pero Peric za 29 dana stariji od direktora,
	   pa kako je 29>28 Pero treba biti izbacen a Sara ne. */
	
	int novi_br = suzi_listu(kandidati, 7, direktor, 28);
	int i;
	printf("Nakon suzenja liste:\n");
	for (i=0; i<novi_br; i++)
	    printf("%s\n", kandidati[i].ime_prezime);
    
	return 0;
}
