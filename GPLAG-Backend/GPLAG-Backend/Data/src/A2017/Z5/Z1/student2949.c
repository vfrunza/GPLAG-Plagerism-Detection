#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Datum{
	int dan, mjesec, godina;
};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int godina){
	if( (godina%4==0 && godina%100!=0) || godina%400==0) return 1;
	return 0;
}

int razlika(struct Uposlenik prvaOsoba){
	struct Datum d = prvaOsoba.datum_rodjenja;
	int bdum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
if (prestupna(d.godina)) bdum[2]++;
	int ukupno=0, i;
for (i=1; i<d.godina; i++)
ukupno += 365 + prestupna(i);

for (i=1; i<d.mjesec; i++)
ukupno += bdum[i];
ukupno += d.dan;
return ukupno;

	
	

}




int pomocna(char *direktor, char* radnik){
	
	char prvoPrezimeDirektor[100]={'\0'}, drugoPrezimeDirektor[100]={'\0'};
	char prvoPrezimeKandidat[100]={'\0'}, drugoPrezimeKandidat[100]={'\0'};
	char *direktor1=prvoPrezimeDirektor, *direktor2=drugoPrezimeDirektor;
	char *kandidat1=prvoPrezimeKandidat, *kandidat2=drugoPrezimeKandidat;
	
	char *pok1=direktor, *pok2=NULL, *g1=radnik, *g2=NULL;
	
	while(*pok1){
		if(*pok1==' ')pok2=pok1;
		pok1++;
	}
	pok2++;
	
	while(*g1){
		if(*g1==' ')g2=g1;
		g1++;
	}
	g2++;
	
	while(*pok2!='-' && *pok2!='\0')*direktor1++=*pok2++;
	while(*g2!='-' && *g2!='\0')*kandidat1++=*g2++;
	if(*pok2=='-')pok2++;
	if(*g2=='-')g2++;
	while(*pok2!='\0') *direktor2++=*pok2++;
	while(*g2!='\0') *kandidat2++=*g2++;

	
	if(strcmp(prvoPrezimeDirektor, prvoPrezimeKandidat)==0 && prvoPrezimeDirektor[0]!='\0' && prvoPrezimeKandidat[0]!='\0') return 1;
	if(strcmp(prvoPrezimeDirektor, drugoPrezimeKandidat)==0 && prvoPrezimeDirektor[0]!='\0' && drugoPrezimeKandidat[0]!='\0') return 1;
	if(strcmp(drugoPrezimeDirektor, prvoPrezimeKandidat)==0 && drugoPrezimeDirektor[0]!='\0' && prvoPrezimeKandidat[0]!='\0') return 1;
	if(strcmp(drugoPrezimeDirektor, drugoPrezimeKandidat)==0 && drugoPrezimeDirektor[0]!='\0' && drugoPrezimeKandidat[0]!='\0') return 1;
	return 0;
}

int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	

	int i=0, j=0, k=0, rez=0, brojac=0;
	int vel2 = vel;
	if(vel == 0) return vel;
	for(i=0;i<vel2;i++){
		rez = (razlika(direktor)-razlika(kandidati[i]));
	//	printf("%d\n",rez);
		if(pomocna(direktor.ime_prezime, kandidati[i].ime_prezime)==0 && rez > broj_dana){
			
			for(j=i;j<vel2-1;j++){
				kandidati[j]=kandidati[j+1];
			}
			i--;
			vel2--;
			brojac++;
		}
	}

	
return vel-brojac;	
	
}

void printaj(struct Uposlenik direktor){
	char *p=direktor.ime_prezime;
	while(*p){
		printf("%c",*p);
		p++;
	}
}
int main() {/* AT1: Neki clanovi ce biti izbaceni */
struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1980} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1980 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 2, 2, 1980 } },
    { "Fata Mujic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 1, 10, 1980 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljic", { 15, 1, 1982 } },
};

/* 1980 godina je bila prestupna, februar je imao 29 dana,
   sto znaci da je Pero Peric za 29 dana stariji od direktora,
   pa kako je 29>28 Pero treba biti izbacen a Sara ne. */

int novi_br = suzi_listu(kandidati, 7, direktor, 28);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
return 0;
}
