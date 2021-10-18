#include <stdio.h>

void unesi (char niz[], int velicina)
{
	int i=0;
	char znak=getchar();
	if (znak == '\n') znak=getchar();
	while (i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

struct Datum unos_datuma_rodjenja ()
{
	struct Datum datum;
	scanf ("%d.%d.%d", &datum.dan, &datum.mjesec, &datum.godina);
	return datum;
}

struct Uposlenik unos_kandidata ()
{
	struct Uposlenik kandidat;
	printf ("Unesite ime i prezime kandidata: ");
	kandidat.ime_prezime=unesi(ime_prezime,50);
	printf ("Unesite datum rodjenja kandidata: ");
	kandidat.datum_rodjenja=unos_datuma_rodjenja();
	return kandidat;
}

struct Uposlenik unos_direktora ()
{
	struct Uposlenik direktor;
	printf ("Unesite ime i prezime direktora: ");
	direktor.ime_prezime=unesi(ime_prezime,50);
	printf ("Unesite datum rodjenja direktora: ");
	direktor.datum_rodjenja=unos_datuma_rodjenja();
	return direktor;
}

int uporedi (char *s1, char *s2) {
	char *p, *q;
	p=s2;
	while (*s2!='\0') {
		if (*s2==' ') {
			p=s2;
			p++;
		}
		s2++;
	}
	while (*s1!='\0') {
		if (*s1==' ') {
			q=s1;
			q++;
		}
		s1++;
	}
	
	while (*q!='\0') {
		if (*q==*p) {
			q++;
			p++;
		} else {
			return 0;
		}
	}
	
	if (*q=='\0' && *p=='\0') {
		return 1;
	}
	
}

int suzi_listu (char Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int novi_kandidati=vel, br_dana_k;
	while (i<vel) {
		br_dana_k=0;
		if (kandidati.datum_rodjenja.godina==direktor.datum_rodjenja.godina) {
			if (kandidati.datum_rodjenja.mjesec==direktor.datum_rodjenja.mjesec) {
				if((kandidati.datum_rodjenja.dan-kandidati.datum_rodjenja.dan)=broj_dana && uporedi(kandidati.ime_prezime,direktor.ime_prezime)==0) {
					novi_kandidati--;
				} else if ((kandidati.datum_rodjenja.mjesec-1)==direktor.datum_rodjenja.mjesec) {
					novi_dani=broj-kandidati.datum_rodjenja.dan;
				}
			}
		}
	}


}

int main()
{
	struct Uposlenik kandidati[100];
	struct Uposlenik direktor;
	int n, i, broj_dana;

	printf ("Unesite broj kandidata: ");
	scanf ("%d", &n);
	printf ("Unesite kandidate: ");
	for (i=0; i<n; i++) {
		kandidati[i]=unos_kandidata();
	}

	printf ("Unesite direktora: ");
	direktor=unos_direktora();

	printf ("Unesite broj dana: ");
	scanf ("%d", &broj_dana);

	return 0;
}
