#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Datum {
	int dan;
	int mjesec;
	int godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
/* Funkcija za prestupnu godinu */
int prestupna(int godina)
{
	if(godina%400==0)
		return 1;
	else if (godina%100==0)
		return 0;
	else if(godina%4==0)
		return 1;
	else return 0;

}
/* Funkcija za izdvanje prezimena */
void izdvoji_prezime(char* p, char* j)
{
	char* q=p;

	while(*q!=' ')
		q++;
	q++;

	while(*q!='\0') {
		*j=*q;
		j++;
		q++;
	}
	*j='\0';
}


int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	char prezime_direktora[50];
	int i, vel1=vel, j;

	memset(prezime_direktora, '\0', sizeof(prezime_direktora));
	strcpy(prezime_direktora, direktor.ime_prezime);

	izdvoji_prezime(direktor.ime_prezime, prezime_direktora);

	for(i=0; i<vel; i++) {
		if(direktor.datum_rodjenja.godina!=kandidati[i].datum_rodjenja.godina || direktor.datum_rodjenja.mjesec!=kandidati[i].datum_rodjenja.mjesec) {
			for(j=0; j<vel-1; j++)
				kandidati[j]=kandidati[j+1];
		}

		vel--;
		i--;
	}
	return vel;
}


int main()
{

	return 0;
}
