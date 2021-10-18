#include <stdio.h>
#include <string.h>
#define KAPACITET 200

void unesi(char niz[])
{
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (znak != '\n') {
		if(i==9) break;
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
	if(znak != '\n') {
		int znak2;
		while((znak2 = getchar() )!= '\n' && znak2 != EOF);
	}
}

struct Vrijeme {
	int sati, minute, sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

int najraniji(struct Cas *raspored, int broj_casova)
{
	struct Vrijeme prvo;
	prvo.sati = 90;
	int i;
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].pocetak.sati < prvo.sati) prvo.sati = raspored[i].pocetak.sati;
	}
	return prvo.sati;
}
int redaradi=0;
int najkasniji(struct Cas *raspored, int broj_casova)
{
	struct Vrijeme posljednje;
	posljednje.sati = 0;
	int i;
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].kraj.sati > posljednje.sati) {
			posljednje.sati = raspored[i].kraj.sati;
		}
	}
	return posljednje.sati;
}

int poredi_vrijeme(struct Vrijeme a, struct Vrijeme b)
{
	int prvo = a.sati*3600 + a.minute*60 + a.sekunde;
	int drugo = b.sati*3600 + b.minute*60 + b.sekunde;

	if(prvo > drugo) return -1;
	return 0;
}

int ucitaj_datoteku(struct Cas raspored[])
{
	// Funkcija vraća broj uspješno učitanih stavki rasporeda
	int brojac=0;
	FILE *ulaz = fopen("raspored.dat", "rb+");
	if(ulaz == NULL) {
		ulaz = fopen("raspored.dat", "wb+");
		if(ulaz == NULL) {
			return 0;
		}
	}

	brojac = fread(raspored, sizeof (struct Cas), KAPACITET, ulaz);
	fclose(ulaz);
	return brojac;

}

int zapisi_datoteku(struct Cas raspored[], int broj_casova)
{
	// Funkcija prima važeći raspored (niz časova i broj članova tog niza),
	// zapisuje ga u binarnu datoteku raspored.dat, te vraća 1 ako je pisanje uspjelo a 0 ako nije

	FILE *ulaz = fopen("raspored.dat", "wb+");
	if(ulaz == NULL) {
		printf("Greska pri otvaranju datoteke raspored.dat \n");
		return 0;
	}

	int jeste = fwrite(raspored, sizeof (struct Cas), broj_casova, ulaz);
	if(ferror(ulaz)) {
		printf("Greska prilikom pisanja datoteke.\n");
		printf("%d", jeste);
	}

	fclose(ulaz);
	return 1;
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas)
{

	int i, pamti=0;
	for(i=0; i<broj_casova; i++) {
		if(poredi_vrijeme(raspored[i].kraj, cas.pocetak)  == -1) {
			if(poredi_vrijeme(cas.kraj, raspored[i].pocetak) == -1) {
				if(cas.dan_u_sedmici == raspored[i].dan_u_sedmici) {
					pamti =1;
					break;
				}
			}
		}
	}

	return pamti;
}

int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje)
{
	redaradi=1;
	// Funkcija prima parametre: važeći raspored, broj časova trenutno unesenih u raspored,
	// naziv predmeta koje treba dodati u raspored i trajanje u satima.
	// Ako je pronađen slobodan termin, potrebno je dodati čas u niz "raspored" na posljednje mjesto u nizu (dakle niz nije hronološki sortiran)
	// i vratiti broj 1 (podrazumijeva se da je broj članova niza povećan za 1), a ako nije funkcija treba vratiti 0 bez izmjene niza časova.

	if(trajanje>10) return 0; // trajanje casa moze biti max 10h, iako je apsurdno
	int i, j; // i po danima, j po satima
	struct Cas jedanCas;
	strncpy(jedanCas.predmet, predmet, 10);

	int pomoc1=0, pomoc2=0;
	// pomoc1 ce nam pomoci ako budemo imali preklapanje
	// a pomoc2 nam sluzi za provjeru satnice
	int k; // k po minutama

	jedanCas.pocetak.sekunde=0;

	for(i=1; i<7; i++) { // sve do nedjelje
		if(pomoc1==0) {
			pomoc2=0; // resetujemo za svaki dan do nedjelje
			jedanCas.dan_u_sedmici = i;
			for(j=9; j<19; j++) {
				if(pomoc1==0 && pomoc2==0) {
					jedanCas.pocetak.sati = j;
					jedanCas.kraj = jedanCas.pocetak; // resetujemo kraj i povecavamo za trajanje
					jedanCas.kraj.sati += trajanje;
					for(k=0; k<60; k++) {
						if(pomoc1 == 0 && pomoc2 ==0) {
							jedanCas.pocetak.minute = k;
							jedanCas.kraj = jedanCas.pocetak;
							jedanCas.kraj.sati += trajanje;
							if(jedanCas.kraj.sati>=19) {
								if(jedanCas.kraj.minute!=0) pomoc2=1;
								else if(jedanCas.kraj.sati>19) pomoc2=1;
							}
							if(preklapanje(raspored, broj_casova, jedanCas) == 0) {
								if(pomoc2==0) pomoc1 = 1;
							}
						} else break;
					}
				} else break;
			}
		} else break;
	}
	if(pomoc1==0) return 0;
	raspored[broj_casova] = jedanCas;
	return 1;
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan)
{
	int i=0, brojac_poseban=1;
	printf("Uneseni su casovi: \n");
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].dan_u_sedmici == dan) {
			printf("%d) %s (%02d:%02d-%02d:%02d)\n", brojac_poseban++, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
		}
	}
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj)
{
	int brojac=1;
	int pamti=0;
	int i;
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].dan_u_sedmici == dan && brojac == redni_broj) {
			pamti = 1;
			break;
		}
		if(raspored[i].dan_u_sedmici == dan) brojac++;
	}
	if(pamti == 0) return;
	else {
		raspored[i] = raspored[broj_casova-1];
		broj_casova--;
	}
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena)
{

	int brojac=1;
	int pamti=0;
	int i;
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].dan_u_sedmici == dan && brojac == redni_broj) {
			pamti = 1;
			break;
		}
		if(raspored[i].dan_u_sedmici == dan) brojac++;
	}
	if(pamti == 0) return;
	raspored[i] = promjena;
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova)
{
	int dodaj_broj=0;
	if(redaradi==0) dodaj_broj=1;
	else dodaj_broj=2;

	int prvi =-1, posljedni =0, i, j;
	int koliko_casova=0, k;
	if(broj_casova>0) {
		prvi = najraniji(raspored, broj_casova);
		posljedni = najkasniji(raspored, broj_casova);
		koliko_casova = posljedni - prvi;
	}
	printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
	if(prvi == -1) return;
	if(prvi < 10)  printf("%-d:00   ", prvi);
	else printf("%-d:00  ", prvi);

	for(i=1; i<7; i++) {
		for(j=0; j<broj_casova; j++) {
			if(raspored[j].dan_u_sedmici == i && raspored[j].pocetak.sati == prvi) {
				printf("%-10s", raspored[j].predmet);
				break;
			} 
		}
		if(j==broj_casova) printf("          ");
	}

	for(i=prvi+dodaj_broj; i<prvi+koliko_casova+1; i++) {
		if(redaradi==0) {
			if(i<10) printf("\n%-d:00   ", i);
			else printf("\n%-d:00  ", i);
		} else {
			if(i<11) printf("\n%-d:00   ", i-1);
			else printf("\n%-d:00  ", i-1);
		}
		for(j=1; j<7; j++) {
			for(k=0; k<broj_casova; k++) {
				if(raspored[k].dan_u_sedmici == j && raspored[k].kraj.sati >= i && raspored[k].pocetak.sati <= i) {
					printf("%-10s", raspored[k].predmet);
					break;
				}
			}
			if(k==broj_casova) printf("          ");
		}
	}
	printf("\n"); 
}

int main()
{
	char ime[11];
	int dan, pamti_redni_cas;
	int taj_cas;
	int taj_dan;
	int trajanje;
	char naziv_predmeta[11];
	struct Cas raspored_svih_dana[KAPACITET];
	int broj_casova = ucitaj_datoteku(raspored_svih_dana);
	int opcija;
	do {

		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &opcija);
		switch(opcija) {

		case 1:
			ispis_rasporeda(raspored_svih_dana, broj_casova);
			break;

		case 2:
			printf("Unesite naziv predmeta: ");
			unesi(naziv_predmeta);
			printf("Unesite broj casova: ");
			scanf("%d", &trajanje);
			int provjera = dodaj_cas(raspored_svih_dana, broj_casova, naziv_predmeta, trajanje);
			if(provjera == 1) broj_casova++;
			if(provjera == 0) printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", trajanje);
			break;

		case 3:

			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &taj_dan);
			ispisi_dan(raspored_svih_dana, broj_casova, taj_dan);
			printf("Izaberite koji cas zelite promijeniti: ");
			scanf("%d", &taj_cas);
			printf("Naziv predmeta: ");
			unesi(ime);
			printf("Vrijeme pocetka: ");
			int sat, min;
			char pamti;
			scanf("%d%c%d", &sat, &pamti, &min);
			printf("Vrijeme zavrsetka: ");
			int sat1, min1;
			char pamti2;
			scanf("%d%c%d", &sat1, &pamti2, &min1);

			struct Cas NoviCas; //= {ime, taj_dan, {sat, min, 0}, {sat1, min1, 0}};
			strcpy(NoviCas.predmet, ime);
			NoviCas.dan_u_sedmici = taj_dan;
			NoviCas.pocetak.sati = sat;
			NoviCas.pocetak.minute = min;
			NoviCas.kraj.sati = sat1;
			NoviCas.kraj.minute = min1;
			NoviCas.pocetak.sekunde=0;
			NoviCas.kraj.sekunde=0;
			promijeni_cas(raspored_svih_dana, broj_casova, taj_dan, taj_cas, NoviCas);

			break;
		case 4:
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored_svih_dana, broj_casova, dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d", &pamti_redni_cas);
			obrisi_cas(raspored_svih_dana, broj_casova, dan, pamti_redni_cas);
			printf("Cas obrisan\n");
			broj_casova--;
			break;
		case 0:
			zapisi_datoteku(raspored_svih_dana, broj_casova);
			break;

		default:
			printf("Nepostoji opcija!");
			break;
		}
	} while (opcija!=0);

	return 0;
}
