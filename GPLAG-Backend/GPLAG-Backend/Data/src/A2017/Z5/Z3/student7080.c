#include <stdio.h>

#include <stdlib.h>



#include <stdbool.h>

#include <string.h>



#define KAPACITET           200

#define datoteka            "C:\\Users\\ramiz\\Desktop\\raspored.dat"

#define MAX_SAT				23

#define MAX_MINUT			59

#define MAX_SEKUND			59



#define POCETNO_VRIJEME		9

#define KRAJNJE_VRIJEME		14

#define ZADNJE_VRIJEME		19



char* DAN[6] = {"PON", "UTO", "SRI", "CET", "PET", "SUB"};

int TEMP = -1;





struct Vrijeme {

    int sati, minute, sekunde;

};



struct Cas {

    char predmet[10];

    int dan_u_sedmici;

    struct Vrijeme pocetak, kraj;

};





/////////////////////////////////////////////////// functions

/* 		validnost vremena		*/

bool valid_time(int sat, int minut, int sekund) {

	if(	sat <= MAX_SAT && sat >= 0 && 

		minut <= MAX_MINUT && minut >= 0 &&

		sekund <= MAX_SEKUND && sekund >= 0)

			return true;

	else

		return false;

}



/* 		ispis reda tabele		*/

void ispisi_red(struct Cas raspored[], int broj_casova, int sat) {

	int i, dan;

	bool postavljen;

	struct Cas cas_ispis;

	for(dan = 1; dan <= 6; dan++) {

		strcpy(cas_ispis.predmet , "");

		postavljen = false;

		

		for(i = 0; i < broj_casova; i++) {

			if(raspored[i].dan_u_sedmici == dan && raspored[i].pocetak.sati <= sat) {

				if (!postavljen) 

					if(raspored[i].pocetak.sati == sat) {

						cas_ispis = raspored[i];

						postavljen;

					}

				else {

					if((raspored[i].pocetak.sati <= cas_ispis.pocetak.sati && raspored[i].kraj.sati >= cas_ispis.kraj.sati && raspored[i].pocetak.minute < cas_ispis.pocetak.minute) ||

						(raspored[i].pocetak.sati == cas_ispis.pocetak.sati && raspored[i].pocetak.minute < cas_ispis.pocetak.minute) ||

						(raspored[i].pocetak.sati == cas_ispis.pocetak.sati && raspored[i].kraj.minute == 0) ||

						(raspored[i].pocetak.sati <= sat && raspored[i].kraj.minute <= cas_ispis.pocetak.minute && raspored[i].kraj.minute > 0) ||

						(raspored[i].pocetak.sati <= sat && raspored[i].kraj.sati > sat && raspored[i].pocetak.sati != raspored[i].kraj.sati))

							cas_ispis = raspored[i];

				}

			}

		}

		printf("%-9s", cas_ispis.predmet);

	}

}



/////////////////////////////////////////////// !functions

/* 		citanje datoteke		*/

int ucitaj_datoteku(struct Cas raspored[]) {

    int i = 0;

    FILE *fp;

    if((fp = fopen(datoteka, "r+")) == NULL) {

        printf("Ne postoji takva datoteka.\n");

        exit(1);

    }

    int ucitanih;

    while ((ucitanih = fscanf(fp, "%9s %d %d %d %d %d %d %d\n",   &raspored[i].predmet, &raspored[i].dan_u_sedmici,

        &raspored[i].pocetak.sati, &raspored[i].pocetak.minute, &raspored[i].pocetak.sekunde,

        &raspored[i].kraj.sati, &raspored[i].kraj.minute, &raspored[i].kraj.sekunde)) != EOF) {

        

		if(i >= KAPACITET)

            break;

            

        if(ucitanih == 8)

        	if(raspored[i].dan_u_sedmici >= 1 && raspored[i].dan_u_sedmici <= 6 &&

	        	raspored[i].pocetak.sati <= raspored[i].kraj.sati &&

	        	raspored[i].pocetak.sati >= POCETNO_VRIJEME && raspored[i].pocetak.sati <= KRAJNJE_VRIJEME &&

	        	raspored[i].kraj.sati >= POCETNO_VRIJEME && raspored[i].kraj.sati <= ZADNJE_VRIJEME &&

				valid_time(raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].pocetak.sekunde) &&

				valid_time(raspored[i].kraj.sati, raspored[i].kraj.minute, raspored[i].kraj.sekunde)) 

        			i++;

    }

    return i;

}



/* 		spremanje datoteke		*/

int zapisi_datoteku(struct Cas raspored[], int broj_casova) {

	FILE *fp = fopen(datoteka, "ab+");

	if (fp == NULL)

	{

	    printf("Greska pri otvaranju datoteke.\n");

	    exit(1);

	}

	int i;

	int spremljeno = 0;

	for(i = 0; i < broj_casova; i++) {

		fprintf(fp, "%-9s %d %d %d %d %d %d %d\n", raspored[i].predmet, raspored[i].dan_u_sedmici,

    	raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].pocetak.sekunde,

        raspored[i].kraj.sati, raspored[i].kraj.minute, raspored[i].kraj.sekunde);

        fprintf(fp, "\n");

        spremljeno++;

	}

	printf("Spremljeno %d casova.\n", i);

	fclose(fp);

}



/* 		dodavanje casa		*/

int dodaj_cas(struct Cas raspored[], int broj_casova,

    const char* predmet, int trajanje) {

	

	int i, j;

	int dan, vrijeme;

	

	/// reset

	bool zauzeti[7][20];

	for(i = POCETNO_VRIJEME; i <= ZADNJE_VRIJEME; i++) 

		for(j = 1; j <= 6; j++) 

			zauzeti[j][i] = false;	

			

	/// postavka

	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].predmet != "") {

			zauzeti[raspored[i].dan_u_sedmici][raspored[i].pocetak.sati] = true;

			

			if(raspored[i].kraj.sati > raspored[i].pocetak.sati) {

				int j;

				for(j = raspored[i].pocetak.sati; j < raspored[i].kraj.sati; j++) 

					zauzeti[raspored[i].dan_u_sedmici][j] = true;

				if(raspored[i].kraj.minute > 0) 

					zauzeti[raspored[i].dan_u_sedmici][raspored[i].kraj.sati] = true;	

			}

			else {

				if(raspored[i].kraj.minute > 0) 

					zauzeti[raspored[i].dan_u_sedmici][raspored[i].kraj.sati] = true;

			}

		}

	}

	

	/// search

	for(dan = 1; dan <= 6; dan++) {

		int duzina = 0;

		vrijeme = POCETNO_VRIJEME;

		while(vrijeme <= KRAJNJE_VRIJEME)

		{

			duzina = 0;

			while(!zauzeti[dan][vrijeme] && vrijeme-trajanje <= KRAJNJE_VRIJEME) {

				duzina++;

				vrijeme++;

				if(duzina == trajanje && vrijeme-trajanje <= KRAJNJE_VRIJEME) {

					if(broj_casova+1 < KAPACITET) {

						

						struct Cas n_cas;

						strcpy(n_cas.predmet, predmet);

						n_cas.dan_u_sedmici = dan;

						n_cas.pocetak.sati = vrijeme-trajanje; n_cas.pocetak.minute = 0; n_cas.pocetak.sekunde = 0;

						n_cas.kraj.sati = vrijeme; n_cas.kraj.minute = 0; n_cas.kraj.sekunde = 0;

				

						raspored[broj_casova] = n_cas;

						return 1;

					}

					else {

						printf("Kapacitet popunjen!\n");

						return 0;

					}

				}

			}

			vrijeme++;

		}

	}

	return 0;

}



/* 		provjera preklapanja		*/

int preklapanje(struct Cas raspored[], int broj_casova,

    struct Cas cas) {

	int i;

	int dan = cas.dan_u_sedmici;

	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].dan_u_sedmici == dan) {

			//// logicko rješenje zbog jednostavnosti (negacija nepoklapanja)

			if(!(((cas.kraj.sati < raspored[i].pocetak.sati) || ((cas.kraj.sati == raspored[i].pocetak.sati) && (cas.kraj.minute <= raspored[i].pocetak.minute))) ||

			((raspored[i].kraj.sati < cas.pocetak.sati) || ((cas.pocetak.sati == raspored[i].kraj.sati) && (cas.pocetak.minute >= raspored[i].kraj.minute)))))

			{

				TEMP = i;

				return 1;

			}

		}

	}

	return 0;    	

}



/* 		ispis rasporeda		*/

void ispis_rasporeda(struct Cas raspored[], int broj_casova) {

	//// header

	int i;

	printf("\n%-6s", "");

	for(i = 1; i <= 6; i++) {

		printf("%-9s", DAN[i-1]);

	}

	printf("\n");

	

	/// ispis za dane

	int sati;

	for(sati = POCETNO_VRIJEME; sati <= KRAJNJE_VRIJEME; sati++) {

		if(sati == POCETNO_VRIJEME) 

			printf("%d:00  ", sati);

		else

			printf("%d:00 ", sati);

			

		ispisi_red(raspored, broj_casova, sati);

		printf("\n");

	}

	printf("\n");

}



/* 		ispis dana		*/

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan) {

	int i;

	int poredak = 0;

	printf("Uneseni su casovi:\n");

	for(i = 0; i < broj_casova; i++)

		if(raspored[i].dan_u_sedmici == dan)  {

			poredak++;

			printf("%d) %-9s (%d:%d - %d:%d)\n", poredak, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);

		}

}



/* 		funkcija promjene casa		*/

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan,

    int redni_broj, struct Cas promjena) {

    int i = 0;

	int pozicija = 0;

	bool postoji = false;

	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].dan_u_sedmici == dan) {

			pozicija++;

			if(pozicija == redni_broj) {

				postoji = true;

				if(preklapanje(raspored, broj_casova, promjena) == 0) {

					raspored[i] = promjena;

					printf("Cas izmijenjen.\n");

				}

				else if(TEMP == i) {

					raspored[i] = promjena;

					printf("Cas izmijenjen.\n");

				}

				else 

					printf("Cas nije izmijenjen (preklapanje).\n");

				break;

			} 

		} 	

	}

	if(!postoji) {

		printf("Neispravan redni broj casa.\n");

	}

}



/* 		brisanje casa		*/

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan,

    int redni_broj) {

    int i = 0;

	int pozicija = 0;

	bool postoji = false;

	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].dan_u_sedmici == dan) {

			pozicija++;

			if(pozicija == redni_broj) {

				int j;

				for(j = i; j < broj_casova-1; j++)

					raspored[j]=raspored[j+1];

				postoji = true;

				printf("Cas obrisan.\n");

				TEMP = 1;

				break;

			} 

		} 	

	}

	if(!postoji) {

		printf("Neispravan redni broj casa.\n");

	}	

}



/* 		KREIRAJ GLAVNI MENI		*/

void kreiraj_menu(struct Cas raspored[], int broj_casova) {

	int opcija;

	int dan, cas;

	

	printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");

	scanf("%d", &opcija);

	

	if(opcija == 1) {

		ispis_rasporeda(raspored, broj_casova);

		kreiraj_menu(raspored, broj_casova);

	}

	else if(opcija == 2) {

		char naziv[10];

		int duzina;

		printf("Unesite naziv predmeta: "); scanf("%9s", &naziv);

		printf("Unesite broj casova: "); scanf("%d", &duzina);

		if(duzina < 1 || duzina > 10 || naziv == "") {

			printf("Pogresan unos.\n");

			kreiraj_menu(raspored, broj_casova);

		}

		else {

			int dodano = dodaj_cas(raspored, broj_casova, naziv, duzina);

			if(dodano == 1) broj_casova++;

			else printf("Nema dovoljno mjesta u rasporedu za %d casova.", duzina);

			ispis_rasporeda(raspored, broj_casova);

			kreiraj_menu(raspored, broj_casova);

		}

	}

	else if(opcija == 3) {

		char naziv[10];

		int poc_h, poc_min, kraj_h, kraj_min;

		

		printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): "); scanf("%d", &dan);

		if(dan >= 1 && dan <= 6) {

			ispisi_dan(raspored, broj_casova, dan);

		}

		else {

			printf("Pogresan unos.\n");

			kreiraj_menu(raspored, broj_casova);	

		}

		printf("Izaberite koji cas zelite promijeniti: "); scanf("%d", &cas);

		printf("Naziv predmeta: "); scanf("%s", &naziv);

		printf("Vrijeme pocetka: "); scanf("%d : %d", &poc_h, &poc_min);

		printf("Vrijeme zavrsetka: "); scanf("%d : %d", &kraj_h, &kraj_min);

		if(valid_time(poc_h, poc_min, 0) && valid_time(kraj_h, kraj_min, 0) && naziv != "" && 

			poc_h >= POCETNO_VRIJEME && poc_h <= KRANJE_VRIJEME && 

			kraj_h >= POCETNO_VRIJEME && kraj_h <= ZADNJE_VRIJEME) 

		{

			struct Cas n_cas;

			

			strcpy(n_cas.predmet, naziv);

			n_cas.dan_u_sedmici = dan;

			n_cas.pocetak.sati = poc_h; n_cas.pocetak.minute = poc_min; n_cas.pocetak.sekunde = 0;

			n_cas.kraj.sati = kraj_h; n_cas.kraj.minute = kraj_min; n_cas.kraj.sekunde = 0;

			

			promijeni_cas(raspored, broj_casova, dan, cas, n_cas);	

			kreiraj_menu(raspored, broj_casova);

		}

		else {

			printf("Neispravan redni broj casa.\n");

			kreiraj_menu(raspored, broj_casova);

		}	

	}

	else if(opcija == 4) {

		printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): "); scanf("%d", &dan);

		if(dan >= 1 && dan <= 6) {

			ispisi_dan(raspored, broj_casova, dan);

		}

		else {

			printf("Pogresan unos.\n");

			kreiraj_menu(raspored, broj_casova);	

		}



		printf("Izaberite koji cas zelite obrisati: "); scanf("%d", &cas);

		TEMP = 0;

		obrisi_cas(raspored, broj_casova, dan, cas);

		if(TEMP == 1) broj_casova--;

		kreiraj_menu(raspored, broj_casova);

	}

	else if(opcija == 0) {

		zapisi_datoteku(raspored, broj_casova);

		exit(0);

	}

	else {

		printf("Pogresan unos.");

		exit(1);

	}

}



//////////////////////////////

/* 		main function		*/

int main() {

    struct Cas raspored[KAPACITET];

    int broj_casova = ucitaj_datoteku(raspored);

    

    kreiraj_menu(raspored, broj_casova);

    exit(0);

}