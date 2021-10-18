#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int broj_dana_niz[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int god) {
	if(god%400==0) return 1;
	if(god%4==0 && god%100!=0) return 1;
	return 0;
}

int ispravan(struct Datum d) {
	if(d.dan<1 || d.dan>broj_dana_niz[d.mjesec])
		return 0;
	if(d.mjesec<1 || d.mjesec>12) return 0;
	return 1;
}

int brojDana(struct Datum d) {
	int rezultat = 0, i;

	for (i=1; i<d.godina; i++) {
		if (prestupna(i))
			rezultat += 366;
		else
			rezultat += 365;
	}

	for (i=1; i<d.mjesec; i++) {
		rezultat += broj_dana_niz[i];

		if (i == 2 && prestupna(d.godina))
			rezultat++;
	}

	rezultat += d.dan;
	return rezultat;
}

int suzi_listu(struct Uposlenik kandidati[], int vel, struct Uposlenik direktor, int broj_dana) {
	char prezime_direktora[45];
	char prezime_kandidata[45], prezime_kandidata_temp[45];
	int duzina=0;
	char*a=direktor.ime_prezime, *b=prezime_direktora;
	char*c=prezime_kandidata, *d=prezime_kandidata_temp;
	char *e=NULL, *f=NULL;
	int direktor_starost, uposlenik_starost;
	int i=0,j=0,razlika;

	while(*a!='\0') a++;
	while(*(a-1)!=' ') a--;
	while(*a!='\0')
		*b++=*a++;
	*b='\0';

	direktor_starost=brojDana(direktor.datum_rodjenja);

	if(!ispravan(direktor.datum_rodjenja))
		return vel;

	else {
		do {
			uposlenik_starost=brojDana(kandidati[i].datum_rodjenja);
			razlika=direktor_starost-uposlenik_starost;

			e=kandidati[i].ime_prezime;
			while(*e!='\0') e++;
			while(*(e-1)!=' ') e--;

			while(*e!='\0')
				*c++=*e++;
			*c='\0';

			c=prezime_kandidata;
			while(*c!='\0') {
				duzina=0;
				d=prezime_kandidata_temp;

				while(*c!='-' && *c!='\0')
					*d++=*c++;
				*d='\0';

				if(*c=='\0') c--;

				/* Da li se prezime kandidata javlja kod prezimena direktora */
				f=strstr(prezime_direktora,prezime_kandidata_temp);

				if(f!=NULL) {
					while(*f!='-' && *f!='\0') {
						f++;
						duzina++;
					}
					if(duzina!=strlen(prezime_kandidata_temp))
						f=NULL;

					break;
				}

				c++;
			}


			if(razlika>0 && razlika>broj_dana && f==NULL) {
				for(j=i; j<vel-1; j++) {
					kandidati[j]=kandidati[j+1];
				}
				i--;
				vel--;
			}

			if(broj_dana<0) {

				if(razlika<0 && razlika>broj_dana && f==NULL) {
					for(j=i; j<vel-1; j++) {
						kandidati[j]=kandidati[j+1];
					}
					i--;
					vel--;
				}
			}

			c=prezime_kandidata;
			i++;

		} while(i<vel);

	}

	return vel;
}

int main() {
	struct Uposlenik direktor = {"Mujo Mujic-Sarac-Jozic", {1, 3, 1982} };
	struct Uposlenik kandidati[7] = {
		{ "Meho Meha Mehic", { 31, 1, 1975 } },
		{ "Pero Periska Peric", { 1, 2, 1982 } },
		{ "Sarah Sara Sarac", { 2, 2, 1970 } },
		{ "Jozefina Mujic", { 1, 2, 1976 } },
		{ "Jozo Jozic-Sarac-Mujic", { 1, 10, 1986 } },
		{ "Mijo Mijic", { 4, 3, 1979 } },
		{ "Suljo Suljic", { 15, 1, 1962 } },
	};

	int novi_br = suzi_listu(kandidati, 7, direktor, 40);
	int i;
	printf("Nakon suzenja liste:\n");
	for (i=0; i<novi_br; i++)
		printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
