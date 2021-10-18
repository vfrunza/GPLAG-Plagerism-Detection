#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme {
	int sati, minute, sekunde; 
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

/* slicno kao strcmp (ako je povratna vrijednost negativna prvi argument dolazi prije) */
int vrcmp(struct Vrijeme a, struct Vrijeme b) {
	int rez;
	rez = a.sati - b.sati;
	if (rez) return rez;
	rez = a.minute - b.minute;
	if (rez) return rez;
	rez = a.sekunde - b.sekunde;
	return rez;
}

/* funckija vraca sve casove iz dana po redu */
int daj_sortiran_dan(struct Cas raspored[], int broj_casova, struct Cas dan[], int koji_dan) {
	int i, j, mjesto, broj = 0;
	for (i = 0; i < broj_casova; i++)
		if (raspored[i].dan_u_sedmici == koji_dan) {
			mjesto = 0;
			for (j = 0; j < broj; j++)
				if (vrcmp(dan[j].pocetak, raspored[i].pocetak) > 0)
					mjesto++;
			broj++;
			for (j = broj - 1; j > mjesto; j--)
				dan[j] = dan[j-1];
			dan[mjesto] = raspored[i];
		}
	return broj;
}

/* ucitava datoteku */
int ucitaj_datoteku(struct Cas raspored[]) {
	FILE *ulaz;
	int rez;
	
	ulaz = fopen("raspored.dat", "r");
	if (!ulaz) return 0;

	rez = fread(raspored, sizeof(struct Cas), KAPACITET, ulaz);
	fclose(ulaz);
	return rez;
}

/* zapisuje datoteku */
int zapisi_datoteku(struct Cas raspored[], int broj_casova) {
	FILE *izlaz;
	int rez;
	
	izlaz = fopen("raspored.dat", "w");
	if (!izlaz) return 0;
	
	rez = fwrite(raspored, sizeof(struct Cas), broj_casova, izlaz);
	fclose(izlaz);
	return rez == broj_casova;
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas) {
	int i;
	for (i = 0; i < broj_casova; i++) 
		if (raspored[i].dan_u_sedmici == cas.dan_u_sedmici && 
			vrcmp(raspored[i].pocetak, cas.kraj) < 0 && /* logicki ispit izveden primjenom demorgranove teoreme = !(ne preklapaju se) */
			vrcmp(cas.pocetak, raspored[i].kraj) < 0) return 1;
	return 0;
}

/* daje novo vrijeme pomjereno za x sati */
struct Vrijeme pomjeri(struct Vrijeme x, int sati) {
	struct Vrijeme novo = x;
	novo.sati += sati;
	return novo;
}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje) {
	struct Cas dan[KAPACITET], novi;
	int i, j, broj;
	struct Vrijeme pocetak = {9, 0, 0}, kraj = {19, 0, 0};
	strcpy(novi.predmet, predmet);
	for (i = 1; i <= 6; i++) {
		novi.dan_u_sedmici = i;
		novi.pocetak = pocetak;
		novi.kraj = pomjeri(novi.pocetak, trajanje); /* provjera da li cas moze na pocetak dana */
		if (!preklapanje(raspored, broj_casova, novi) && vrcmp(novi.kraj, kraj) <= 0) {
			raspored[broj_casova] = novi;
			return 1;
		}
		broj = daj_sortiran_dan(raspored, broj_casova, dan, i);
		for (j = 0; j < broj; j++) /* i da li moze nakon bilo kojeg casa u tom danu */
			if (vrcmp(pocetak, dan[j].kraj) < 0) {
				novi.pocetak = dan[j].kraj;
				novi.kraj = pomjeri(novi.pocetak, trajanje);
				if (!preklapanje(raspored, broj_casova, novi) && vrcmp(novi.kraj, kraj) <= 0) {
					raspored[broj_casova] = novi;
					return 1;
				}
			}
	}
	
	return 0;
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova) {
	int minh, maxh, i, sat, dan, broj, ispisan;
	struct Cas sortiran[KAPACITET];
	struct Vrijeme vrijeme = {0, 0, 0};
	printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
	if (broj_casova == 0) return;
	minh = maxh = raspored[0].pocetak.sati;
	for (i = 0; i < broj_casova; i++) { /* odredjivanje prvog i zadnjeg vremena (mozda bolje preko vrcmp) */
		minh = minh < raspored[i].pocetak.sati ? minh : raspored[i].pocetak.sati;
		sat = raspored[i].kraj.sati;
		if (raspored[i].kraj.minute == 0 && raspored[i].kraj.sekunde == 0) sat--;
		maxh = maxh > sat ? maxh : sat;
	}
	for (sat = minh; sat <= maxh; sat++) {
		printf("%d:00  ", sat);
		if (sat < 10) printf(" ");
		vrijeme.sati = sat;
		for (dan = 1; dan <= 6; dan++) {
			ispisan = 0;
			broj = daj_sortiran_dan(raspored, broj_casova, sortiran, dan);
			for (i = 0; i < broj; i++) /* ispisujemo dan po dan za svaki sat */
				if (sortiran[i].pocetak.sati <= sat && vrcmp(sortiran[i].kraj, vrijeme) > 0) {
					printf("%-10s", sortiran[i].predmet);
					ispisan = 1;
					break;
				}
			if (!ispisan) printf("          ");
		}
		printf("\n");
	}
}

/* ispisuje casove u danu kako su poredani u nizu raspored */
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan) {
	int redni = 1, i;
	struct Cas casi;
	printf("Uneseni su casovi: \n");
	for (i = 0; i < broj_casova; i++) 
		if ((casi = raspored[i]).dan_u_sedmici == dan)
			printf("%d) %s (%02d:%02d-%02d:%02d)\n", redni++, casi.predmet, 
					casi.pocetak.sati, casi.pocetak.minute,
					casi.kraj.sati, casi.kraj.minute);
}

/* vraca lokaciju casa u rasporedu po danu i rednom broju */
int indeks(struct Cas raspored[], int broj_casova, int dan, int redni_broj) {
	int redni = 0, i;
	
	for (i = 0; i < broj_casova; i++) 
		if (raspored[i].dan_u_sedmici == dan) {
			redni++;
			if (redni == redni_broj) return i;
		}
	return -1;
}

/* ova bi funkcija po svoj prilici trebala biti int jer se dupla posao */
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj) {
	int i = indeks(raspored, broj_casova, dan, redni_broj);
	
	if (i != -1) {
		raspored[i] = raspored[broj_casova - 1];
	}
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena) {
	int i = indeks(raspored, broj_casova, dan, redni_broj);

	if (i != -1) {	
		raspored[i] = promjena;
	}
}

/* utility */
int unesi_dan() {
	int dan;
	printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
	scanf("%d", &dan);
	return dan;
}

void unesi(char buf[], int n) { /* unos sa stdin */
	int i;
	char c;
	c = getchar();
	while (c == '\n' || c == ' ') c = getchar();
	for (i = 0; i < n-1 && c != '\n'; i++) {
		buf[i] = c;
		c = getchar();
	}
	buf[i] = '\0';
	while (c != '\n') c = getchar();
}

int main() {
	int unos, broj_casova = 0;
	struct Cas raspored[KAPACITET];
	broj_casova = ucitaj_datoteku(raspored);
	/* ovaj kod dalje je manje vise jasan sam po sebi */
	while (1) {
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &unos);
		if (unos == 0) break;
		if (unos == 1) ispis_rasporeda(raspored, broj_casova);
		if (unos == 2) {
			char buf[10];
			int trajanje;
			int rez;
			printf("Unesite naziv predmeta: ");
			unesi(buf, 10);
    		printf("Unesite broj casova: ");
    		scanf("%d", &trajanje);
    		rez = dodaj_cas(raspored, broj_casova, buf, trajanje);
    		if (rez == 0) 
    			printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", trajanje);
    		else broj_casova++;
		}
		if (unos == 3) {
			while (1) {
				int dan, redni_broj, ind, i, prekl = 0;
				struct Cas novi;
				dan = unesi_dan();
				ispisi_dan(raspored, broj_casova, dan);
				printf("Izaberite koji cas zelite promijeniti: "); 
				scanf("%d", &redni_broj);
				ind = indeks(raspored, broj_casova, dan, redni_broj);
				if (ind == -1 ) {
					printf("Neispravan redni broj casa.\n");
					continue;
				}
				printf("Naziv predmeta: ");
				unesi(novi.predmet, 10);
	    		printf("Vrijeme pocetka: ");
	    		scanf("%d:%d", &novi.pocetak.sati, &novi.pocetak.minute);
	    		printf("Vrijeme zavrsetka: ");
	    		scanf("%d:%d", &novi.kraj.sati, &novi.kraj.minute);
	    		novi.kraj.sekunde = novi.pocetak.sekunde = 0; /* hmm */
	    		novi.dan_u_sedmici = dan;
				for (i = 0; i < broj_casova; i++) /* isprobavanje preklapanja bez posmatranog casa */
					if (i != ind &&
						raspored[i].dan_u_sedmici == dan &&
						vrcmp(raspored[i].pocetak, novi.kraj) < 0 &&
						vrcmp(novi.pocetak, raspored[i].kraj) < 0) prekl =  1;
	    		
	    		if (!prekl) {
	    			raspored[ind] = novi;
	    			break;
	    		} else printf("Promjena nije moguca jer dovodi do preklapanja\n");
			}
		}
		if (unos == 4) {
			int dan, redni_broj, i;
			dan = unesi_dan();
			ispisi_dan(raspored, broj_casova, dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d", &redni_broj);
			/* dupli posao zato sto obrisi_cas ne vraca nista */
			i = indeks(raspored, broj_casova, dan, redni_broj);
			if (i != -1) {
				obrisi_cas(raspored, broj_casova, dan, redni_broj);
				broj_casova--;
				printf("Cas obrisan\n");
			}
		}
	}
	zapisi_datoteku(raspored, broj_casova);
	return 0;
}
