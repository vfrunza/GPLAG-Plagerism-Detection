#include <stdio.h>
#include <math.h>

struct Datum {
	int dan, mjesec, godina;
};

void unesite (char niz[], int velicina)
{
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i< velicina-1 && znak != '\n') {
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

struct Uposlenik {
	char ime_prezime [50];
	struct Datum datum_rodjenja;
};

struct Datum unos_datuma ()
{

	struct Datum d;
	scanf ("%d%d%d", &d.dan, &d.mjesec, &d.godina);
	return d;
}

struct Uposlenik unos_kandidata ()
{

	struct Uposlenik kandidati;
	unesite(kandidati.ime_prezime,50);
	kandidati.datum_rodjenja=unos_datuma();

}


struct Uposlenik unos_direktora ()
{

	struct Uposlenik direktor;
	unesite(direktor.ime_prezime,50);
	direktor.datum_rodjenja=unos_datuma();

}
int suzi_listu (struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i=0, j=0;
	int broj_dana_direktora=0, broj_dana_kandidata=0, razlika=0;

	
	if (direktor.datum_rodjenja.godina % 4==0 && direktor.datum_rodjenja.godina % 100!=0 && direktor.datum_rodjenja.godina % 400==0) {
		int mjeseci [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
		//odredujemo koliko dana treba proci od pocetka godine do direktorovog rodendana
		for (i=1; i<direktor.datum_rodjenja.mjesec; i++) {
			broj_dana_direktora=broj_dana_direktora+mjeseci[i-1];
		}
		broj_dana_direktora=broj_dana_direktora+direktor.datum_rodjenja.dan;
	}

	else {
		int mjeseci [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		for (i=1; i<direktor.datum_rodjenja.mjesec; i++) {
			broj_dana_direktora=broj_dana_direktora+mjeseci[i];
		}
		broj_dana_direktora=broj_dana_direktora+direktor.datum_rodjenja.dan;
	}

	for (i=0; i<vel; i++) {

		if (kandidati[i].datum_rodjenja.godina % 4==0 && kandidati[i].datum_rodjenja.godina % 100!=0 && kandidati[i].datum_rodjenja.godina % 400==0) {
			if (kandidati[i].datum_rodjenja.godina>direktor.datum_rodjenja.godina) continue;
			else {
				int mjeseci [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
				//odredujemo koliko dana treba proci od pocetka godine do kandidatovog rodendana
				for (j=1; j<kandidati[i].datum_rodjenja.mjesec; j++) {
					broj_dana_kandidata=broj_dana_kandidata+mjeseci[j-1];
				}
				broj_dana_kandidata=broj_dana_kandidata+kandidati[i].datum_rodjenja.dan;

			}
		} else {
			if (kandidati[i].datum_rodjenja.godina>direktor.datum_rodjenja.godina) continue;
			else {
				int mjeseci [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
				int mjesec_kadidata=kandidati[i].datum_rodjenja.mjesec;
				for (j=1; j<mjesec_kadidata; j++) {
					broj_dana_kandidata=broj_dana_kandidata+mjeseci[j-1];
				}
				broj_dana_kandidata=broj_dana_kandidata+kandidati[i].datum_rodjenja.dan;
			}
		}

		//racunamo koliko se razlikuju dani rodenja
		razlika=broj_dana_kandidata-broj_dana_direktora;
		if (razlika>0 && razlika>fabs(broj_dana)) {
			for (j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			i--;
			vel--;
		}
	}
	return vel;
}
int main()
{
	int i=0, razlika_dana=0;
	struct Uposlenik kandidati[1000];
	struct Uposlenik direktor;

	int broj;
	direktor=unos_direktora();
	printf ("Unesite broj kandidata: ");
	scanf ("%d", &broj);
	for (i=0; i<broj; i++) {
		kandidati[i]=unos_kandidata();
		if (i==broj) break;
	}
	printf ("Unesite razliku dana: ");
	scanf ("%d", &razlika_dana);
	int novi_br = suzi_listu (kandidati, broj, direktor, razlika_dana);
	printf("Nakon suzenja liste:\n");
	for (i=0; i<novi_br; i++)
		printf ("%s\n", kandidati[i].ime_prezime);
	return 0;
}
