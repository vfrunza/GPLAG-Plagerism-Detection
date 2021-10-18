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

void strcpy9(char *gdje, const char *odakle)
{
	int brojac=0;
	while(brojac<9 && (*gdje++=*odakle++)) brojac++;
}

void unesi(char *niz, int vel)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(znak!='\n') {
		niz[i]=znak;
		if (i<vel-1) i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int ucitaj_datoteku(struct Cas raspored[])
{
	FILE* ulaz=fopen("raspored.dat", "rb");
	if(ulaz==NULL) {
		//	printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	int ucitano=fread(raspored, sizeof(raspored), KAPACITET, ulaz);
	fclose(ulaz);
	return ucitano;
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova)
{
	FILE* ulaz=fopen("raspored.dat", "wb");
	if(ulaz==NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return 0;
	}
	int zapisano=fwrite(raspored, sizeof(raspored), broj_casova, ulaz);
	if(ferror(ulaz)) {
		printf("Greska prilikom pisanja datoteke.\n");
		printf("Zapisano je samo %d casova\n", zapisano);
	}
	fclose(ulaz);
	return 1;
}
int preklapanje (struct Cas raspored[], int broj_casova, struct Cas cas)
{
	int i;
	for (i=0; i<broj_casova; i++) {
		if (raspored[i].dan_u_sedmici!=cas.dan_u_sedmici) continue; //ako nisu isti dani nema ni preklopa
		if (cas.kraj.sati>raspored[i].pocetak.sati && cas.pocetak.sati<raspored[i].kraj.sati) return 1;
		else if (cas.kraj.sati==raspored[i].pocetak.sati ) {
			if (cas.pocetak.sati==raspored[i].kraj.sati) {
				if (cas.kraj.minute>raspored[i].pocetak.minute && cas.pocetak.minute<raspored[i].kraj.minute) return 1;
			} else if (cas.kraj.minute>raspored[i].pocetak.minute) return 1;
		} else if (cas.pocetak.sati==raspored[i].kraj.sati) {
			if (cas.pocetak.minute<raspored[i].kraj.minute) return 1;
		}
	}
	return 0;
}
int preklapanje_dana (struct Cas raspored[], int broj_casova, struct Cas cas, int koji)
{
	int i;
	for (i=0; i<broj_casova; i++) {
		if (i==koji) continue;
		if (raspored[i].dan_u_sedmici!=cas.dan_u_sedmici) continue; //ako nisu isti dani nema ni preklopa
		if (cas.kraj.sati>raspored[i].pocetak.sati && cas.pocetak.sati<raspored[i].kraj.sati) return 1;
		else if (cas.kraj.sati==raspored[i].pocetak.sati ) {
			if (cas.pocetak.sati==raspored[i].kraj.sati) {
				if (cas.kraj.minute>raspored[i].pocetak.minute && cas.pocetak.minute<raspored[i].kraj.minute) return 1;
			} else if (cas.kraj.minute>raspored[i].pocetak.minute) return 1;
		} else if (cas.pocetak.sati==raspored[i].kraj.sati) {
			if (cas.pocetak.minute<raspored[i].kraj.minute) return 1;
		}
	}
	return 0;
}
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan)
{
	int i, brojac=0;
	printf("Uneseni su casovi: ");
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].dan_u_sedmici==dan) {
			brojac++;
			printf("\n%d) %s (%02d:%02d-%02d:%02d)", brojac, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
		}
	}
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj)
{
	int i, brojac=0;
	for(i=0; i<broj_casova-1; i++) {
		if(raspored[i].dan_u_sedmici==dan) brojac++;
		if(brojac==redni_broj) {
			raspored[i]=raspored[i+1];
			strcpy9(raspored[i].predmet, raspored[i+1].predmet);
		}
	}
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena)
{
	int i, brojac=0;
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].dan_u_sedmici==dan) brojac++;
		if(brojac==redni_broj) {
			raspored[i]=promjena;
			strcpy9(raspored[i].predmet, promjena.predmet);
		}
	}
}


int dodaj_cas(struct Cas raspored[], int broj_casova, const char *predmet, int trajanje)
{
	int i, j, pocetak, popunjeni_casovi[6][20] = { 0 }; // lose rjesenje, jeste da je manje od 10 byta u pitanju, ali opet lose rjesenje

	if(trajanje > 10)
		return 0;

	for(j = 0; j < broj_casova; j++)
		for(i = raspored[j].pocetak.sati; i < raspored[j].kraj.sati; i++)
			popunjeni_casovi[ raspored[j].dan_u_sedmici - 1][i]++;

	for(i = 0; i < 6; i++) {
		for(pocetak = 9; pocetak <= 19 && popunjeni_casovi[i][pocetak]; )
			pocetak++;

		if(pocetak+trajanje > 19)
			continue;

		break;
	}
	if(i == 6)
		return 0;

	strcpy9(raspored[broj_casova].predmet, predmet); // samo prvih devet znakova treba biti uzeto u obzir
	raspored[broj_casova].dan_u_sedmici = i + 1;
	raspored[broj_casova].pocetak.sati = pocetak;
	raspored[broj_casova].pocetak.minute = 0;
	raspored[broj_casova].pocetak.sekunde = 0;
	raspored[broj_casova].kraj.sati = pocetak + trajanje;
	raspored[broj_casova].kraj.minute = 0;
	raspored[broj_casova].kraj.sekunde = 0;

//	printf("(%i, %i, %i)\n", raspored[broj_casova].dan_u_sedmici, raspored[broj_casova].pocetak.sati, raspored[broj_casova].kraj.sati);

	return preklapanje(raspored, broj_casova, raspored[broj_casova]) == 0;
}

int najraniji(struct Cas *raspored, int broj_casova)
{
	int sat=24, i;
	for(i=0; i<broj_casova; i++) 
		if(raspored[i].pocetak.sati < sat) sat = raspored[i].pocetak.sati;
	return sat;
}

int najkasniji(struct Cas *raspored, int broj_casova)
{
	int sat=-1, i;
	for(i=0; i<broj_casova; i++) 
		if(raspored[i].kraj.sati > sat) sat = raspored[i].kraj.sati;
	return sat;
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova)
{
	int prvi =-1, posljedni =0, i, j;
	int koliko_casova=0, k;
	if(broj_casova>0) {
		prvi = najraniji(raspored, broj_casova);
		posljedni = najkasniji(raspored, broj_casova);
		koliko_casova = posljedni - prvi;
	}
	printf("\n       PON       UTO       SRI       CET       PET       SUB\n");
	if(prvi == -1) return;
	if(prvi<10) printf("%-d:00   ", prvi);
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

	for(i=prvi+1; i<prvi+koliko_casova+1; i++) {
		printf("\n%-d:00  ", i);
		if (i<10) printf (" ");
		for(j=1; j<7; j++) {
			for(k=0; k<broj_casova; k++) {
				if(raspored[k].dan_u_sedmici == j && raspored[k].kraj.sati >= i && raspored[k].pocetak.sati <= i ) {
					printf("%-10s", raspored[k].predmet);
					break;
				}
			}
			if(k==broj_casova) printf("          ");
		}
	}
	printf ("\n");
}

int main()
{
	char string[100], s2[100];
	int broj_casova=0, opcija, br_casova=0, dan, i, obrisati;
	struct Cas raspored[200], pomocni= {"",1,{0,0,0},{0,0,0}};
	for (i=0; i<200; i++) raspored[i]=pomocni; //inicijalizujemo sve :)
	ucitaj_datoteku(raspored);
	while(1) {
	pocetak_svega0:	printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &opcija);
		if(opcija==0) {
			break;
		}
		if (opcija==1) {
			ispis_rasporeda(raspored,broj_casova);
			continue;
		}
		if(opcija==2) {
pocetak_svega2:
			printf("Unesite naziv predmeta: ");
			unesi(string, 100);
			strcpy9(s2, string);
			printf("Unesite broj casova: ");
			scanf("%d", &br_casova);
			if(dodaj_cas(raspored, broj_casova, s2, br_casova)==0) {
				printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", br_casova);
				goto pocetak_svega0;
			} else broj_casova++;
			continue;
		}
		if(opcija==3) {
pocetak_svega:
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			while (1) {
				ispisi_dan(raspored,broj_casova,dan);
				printf ("\nIzaberite koji cas zelite promijeniti: ");
				scanf ("%d",&obrisati);
				if (obrisati>0 && obrisati<=broj_casova) break;
				else {
					printf ("Neispravan redni broj casa.\n");
					goto pocetak_svega;
				}
			}
			printf ("Naziv predmeta: ");
			unesi (string,100);
			strcpy9(pomocni.predmet,string);
			printf ("Vrijeme pocetka: ");
			scanf ("%d:%d",&pomocni.pocetak.sati,&pomocni.pocetak.minute);
			printf ("Vrijeme zavrsetka: ");
			scanf ("%d:%d",&pomocni.kraj.sati,&pomocni.kraj.minute);
			if (preklapanje_dana(raspored,broj_casova,pomocni, obrisati-1)) {
				printf ("Promjena nije moguca jer dovodi do preklapanja\n");
				goto pocetak_svega;
			} else promijeni_cas(raspored, broj_casova, dan, obrisati, pomocni);
			continue;
		}
		if(opcija==4) {
pocetak_svega3:
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			while (1) {
				ispisi_dan(raspored,broj_casova,dan);
				printf ("\nIzaberite koji cas zelite obrisati: ");
				scanf ("%d",&obrisati);
				if (obrisati>0 && obrisati<=broj_casova) break;
				else {
					printf ("Neispravan redni broj casa.\n");
					goto pocetak_svega3;
					continue;
				}
			}
			obrisi_cas(raspored,broj_casova, raspored[obrisati-1].dan_u_sedmici, obrisati-1);
			printf ("Cas obrisan\n");
			broj_casova--;
			continue;
		}
	}
	zapisi_datoteku(raspored,broj_casova);

	return 0;
}