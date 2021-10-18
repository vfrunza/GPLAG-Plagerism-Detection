#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Datum {
	int dan, mjesec, godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int godina)
{
	return ((godina%4==0 && godina%100!=0) || (godina%400==0));
}

int rodjaci(char*ime_prezime1,char*ime_prezime2)
{
	char *s1=ime_prezime1;
	char *s2=ime_prezime2;
	char *pocetak_prezime1,*pocetak_prezime2;
	char*k1=s1,*k2=s2;
	int i,j,br_znakova1,br_znakova2;
	char prezimena1[4][30];
	int vel1=0;
	char prezimena2[4][30];
	int vel2=0;


	while (*k1!='\0') {
		k1++;
	}
	while (*k2!='\0') {
		k2++;
	}
	while (*k1==' ') {
		k1--;
	}
	while (*k1!=' ') {
		k1--;
	}

	while (*k2==' ') {
		k2--;
	}
	while (*k2!=' ') {
		k2--;
	}


	pocetak_prezime1=k1+1;
	pocetak_prezime2=k2+1;

	br_znakova1=0;
	while(*pocetak_prezime1!='\0'&&*pocetak_prezime1!=' ') {
		if(*pocetak_prezime1=='-') {
			prezimena1[vel1][br_znakova1] ='\0';
			br_znakova1=0;
			vel1++;
			pocetak_prezime1++;
		}

		prezimena1[vel1][br_znakova1] = *pocetak_prezime1;

		br_znakova1++;
		pocetak_prezime1++;
	}
	prezimena1[vel1][br_znakova1] ='\0';
	vel1++;

	br_znakova2=0;
	while(*pocetak_prezime2!='\0'&&*pocetak_prezime2!=' ') {
		if(*pocetak_prezime2=='-') {
			prezimena2[vel2][br_znakova2] ='\0';
			br_znakova2=0;
			vel2++;
			pocetak_prezime2++;
		}

		prezimena2[vel2][br_znakova2] = *pocetak_prezime2;

		br_znakova2++;
		pocetak_prezime2++;
	}
	prezimena2[vel2][br_znakova2] ='\0';
	vel2++;

	for(i=0; i<vel1; i++) {
		for(j=0; j<vel2; j++) {
			if(strcmp(prezimena1[i],prezimena2[j])==0)
				return 1;
		}
	}

	return 0;
}

int broj_dana(struct Datum d)  /* broj dana od 1. januara 1800. godine*/
{

	int mjeseci[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int ukupno_dana=0;
	int godina=1800;
	int mjesec=1;
	
	while(godina<d.godina) {
		ukupno_dana+=365;
		if(prestupna(godina))ukupno_dana++;
		godina++;
	}


	while(mjesec<d.mjesec) {

		ukupno_dana+=mjeseci[mjesec-1];
		if(mjesec==2&&prestupna(godina)) ukupno_dana++;
		mjesec++;
	}
	ukupno_dana+=d.dan;

	return ukupno_dana;
}


int razlika(struct Datum d1, struct Datum d2)
{
	return broj_dana(d1)-broj_dana(d2);
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int i,j,r,izbaci;

	for ( i = 0; i < vel; i++) {
		izbaci=0;

		if(rodjaci(kandidati[i].ime_prezime,direktor.ime_prezime)==0) {
			int r = razlika( direktor.datum_rodjenja,kandidati[i].datum_rodjenja);
			if(broj_dana>0) {
				if(r>broj_dana)izbaci=1;
			} else {
				if(r>(broj_dana)) izbaci=1;
			}

			if(izbaci) {
				for(j=i; j<vel-1; j++) {
					kandidati[j]=kandidati[j+1];
				}
				vel--;
				i--;
			}
		}
	}
	return vel;
}




int main()
{
/* AT6: Negativna razlika dana */
struct Uposlenik direktor = {"Mujo Mujic", {1, 1, 1992} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1990 } },
    { "Pero Peric", { 1, 2, 1990 } },
    { "Sara Sarac", { 2, 10, 1990 } },
    { "Fata Mujicic", { 1, 2, 1986 } },
    { "Jozo Jozic", { 1, 10, 1990 } },
    { "Mijo Mijic", { 4, 3, 1989 } },
    { "Suljo Suljc", { 15, 1, 1992 } },
};
int novi_br = suzi_listu(kandidati, 7, direktor, 15);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);


	return 0;
}

