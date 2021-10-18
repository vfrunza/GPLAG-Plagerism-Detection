#include <stdio.h>
#include <math.h>

struct Datum {
	int dan,mjesec,godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

struct Datum unesi_datum ()
{
	struct Datum d;
	scanf ("%d %d %d", &d.dan,&d.mjesec,&d.godina);
	return d;
}

struct Uposlenik unos_uposlenika ()
{
	struct Uposlenik covjek;
	printf ("Unesite ime i prezime: \n");
	scanf ("%s", covjek.ime_prezime);
	printf ("Unesite datum rodjenja: \n");
	covjek.datum_rodjenja = unesi_datum();
	return covjek;
}

int moon (int a, int prestupna)
{
	int month;
	if (prestupna) {
		switch (a) {
		case 1:
			month = 0;
			break;
		case 2:
			month = 31;
			break;
		case 3:
			month = 60;
			break;
		case 4:
			month = 91;
			break;
		case 5:
			month = 121;
			break;
		case 6:
			month = 152;
			break;
		case 7:
			month = 182;
			break;
		case 8:
			month = 213;
			break;
		case 9:
			month = 244;
			break;
		case 10:
			month = 274;
			break;
		case 11:
			month = 305;
			break;
		case 12:
			month = 335;
			break;
		}
	} else {
		switch (a) {
		case 1:
			month = 0;
			break;
		case 2:
			month = 31;
			break;
		case 3:
			month = 59;
			break;
		case 4:
			month = 90;
			break;
		case 5:
			month = 120;
			break;
		case 6:
			month = 151;
			break;
		case 7:
			month = 181;
			break;
		case 8:
			month = 212;
			break;
		case 9:
			month = 243;
			break;
		case 10:
			month = 273;
			break;
		case 11:
			month = 304;
			break;
		case 12:
			month = 334;
			break;
		}
	}
	return month;

}

int suzi_listu (struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	if (broj_dana<0);
	broj_dana=-broj_dana;
	struct Uposlenik* trenutno;
	int i=0,dani_direktora,dani_kandidata[100],prestupna=0,j=0,kraj=vel;
	/* Trazenje koliko zivi direktor dana*/

	if (((direktor.datum_rodjenja.godina % 4 == 0) || (direktor.datum_rodjenja.godina % 400 == 0)) && (direktor.datum_rodjenja.godina % 100 !=0 )) {
		prestupna = 1;
		dani_direktora=direktor.datum_rodjenja.dan+moon(direktor.datum_rodjenja.mjesec,prestupna);
	} else
		dani_direktora=direktor.datum_rodjenja.dan+moon(direktor.datum_rodjenja.mjesec,prestupna);
	
	while (i<vel) {
		prestupna=0;
		/* Trazenje koliko zivi dana kandidat*/
		if (((kandidati[i].datum_rodjenja.godina % 4 == 0) || (kandidati[i].datum_rodjenja.godina % 400 == 0)) && (kandidati[i].datum_rodjenja.godina % 100 !=0 )) {
			prestupna = 1;
			dani_kandidata[i]=kandidati[i].datum_rodjenja.dan+moon(kandidati[i].datum_rodjenja.mjesec,prestupna);
		} else
			dani_kandidata[i]=kandidati[i].datum_rodjenja.dan+moon(kandidati[i].datum_rodjenja.mjesec,prestupna);
		/*izbacivanje kandidata*/
		printf ("Dani direktora: %d, dani kandidata: %d, a razlika je: %d\n", dani_direktora,dani_kandidata[i], dani_direktora-dani_kandidata[i]);
		if ((dani_direktora-dani_kandidata[i])>broj_dana || (direktor.datum_rodjenja.godina-kandidati[i].datum_rodjenja.godina)>1) {
			for (j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			vel--;
			i--;
		}
		i++;
	}
	printf ("Velicina je: %d", vel);
	return vel;
}

int main()
{
	struct Uposlenik direktor;
	struct Uposlenik kandidati[100];
	int i=0,n,x;
	printf ("Unesite podatke direktora: \n");
	direktor = unos_uposlenika();
	printf ("BRoj kandidata: \n");
	scanf ("%d", &n);
	while (i<n) {
		printf ("Unesite podatke %d. kandidata: \n", i+1);
		kandidati[i] = unos_uposlenika();
		i++;
	}
	printf ("Kolika je razlika dana: \n");
	scanf ("%d", &x);
	printf ("Nakon suzenja: %d", suzi_listu(kandidati,n,direktor,x));
	return 0;

}
