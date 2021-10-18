#include <stdio.h>
#include <stdlib.h>
#define KAPACITET 200

struct Vrijeme {
	int sati,minute,sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};

int preklapanje (struct Cas raspored[], int broj_casova, struct Cas cas) {
	int i,postoji=1;
	
	/*Ako je isti dan i ako jedan počinje odmah na početku dana (0 sati), a drugi počinje skoro na kraju (23 sata), nema preklapanja*/
	for (i=0; i<broj_casova; i++) {
		if (cas.dan_u_sedmici == raspored[i].dan_u_sedmici) {
			if (cas.pocetak.sati==0 && (raspored[i].pocetak.sati<=23 && raspored[i].pocetak.sati!=0))
				postoji=0;
		}
	}
	
	if (postoji==0)
		return postoji;
		
	for (i=0; i<broj_casova; i++) {
		if (raspored[i].dan_u_sedmici!=cas.dan_u_sedmici)
			postoji=0;
	}
	if (postoji==0)
		return postoji;
	for (i=0; i<broj_casova; i++) {
		if ((raspored[i].kraj.sati <= cas.pocetak.sati) && (raspored[i].kraj.minute<=cas.pocetak.minute) && (cas.kraj.sati>=raspored[i].pocetak.sati) && (cas.kraj.minute>=raspored[i].pocetak.minute))
			postoji=0;
	}
	return postoji;
}

int ucitaj_datoteku (struct Cas raspored[]) {
	FILE *ulaz;
	int ucitano;

	ulaz=fopen ("raspored.dat","rb");
	if (ulaz==NULL) {
		printf("Otvaranje datoteke 'raspored.dat' nije uspjelo.");
		exit(1);
	}
	ucitano = fread (raspored, sizeof(struct Cas), KAPACITET, ulaz);
	if (ferror (ulaz)) {
		printf("Greska prilikom citanja datoteke.\n");
		return ucitano;
	}
	fclose(ulaz);
	return ucitano;
}

int zapisi_datoteku (struct Cas raspored[], int broj_casova) {
	FILE *ulaz=fopen ("raspored.dat", "wb");
	int zapisano=1;
	int pomocni;
	if (ulaz==NULL) {
		printf ("Greska prilikom otvaranja datoteke.\n");
		exit (2);
	}
	pomocni = fwrite (raspored, sizeof (struct Cas), broj_casova, ulaz);
	
	if (ferror(ulaz)) {
		printf ("Greska prilikom pisanja datoteke.\n");
		zapisano=0;
		return zapisano;
	}
	fclose(ulaz);
	return zapisano;
}

void ispisi_dan (struct Cas raspored[], int broj_casova, int dan) {
	int i,brojac=0;
	printf("Uneseni su casovi:\n");
	for (i=0; i<broj_casova; i++) {
		if (raspored[i].dan_u_sedmici==dan) {
			printf ("%d) %s (%.2d:%.2d-%.2d:%.2d)\n",brojac+1, raspored[i].predmet,raspored[i].pocetak.sati, raspored[i].pocetak.minute,raspored[i].kraj.sati,raspored[i].kraj.minute );
			brojac++;
		}
	}
}

void meni () {
	int izbor;
	do {
	printf ("1)Ispis rasporeda\n2)Dodavanje casa\n3)Promjena casa\n4)Brisanje casa\n0)Kraj rada\nIzaberite opciju: ");
	scanf ("%d",&izbor);
	switch (izbor) {
	/*	case 1: ispis_rasporeda(); break;
		case 2: dodaj_cas(); break;
		case 3: promijeni_cas(); break;
		case 4: obrisi_cas(); break;*/
		default: printf ("Nepoznat izbor\n");
	}
	} while (izbor!=0);
}
int main() {
	/*meni();*/
	return 0;
}
