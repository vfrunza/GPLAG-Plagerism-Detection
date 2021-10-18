#include <stdio.h>
#include <stdlib.h>

struct Datum {
	int dan;
	int mjesec;
	int godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
struct Datum unos_datuma()
{
	struct Datum t;
	printf("Unesite datum rodjenja kandidata (d m g):");
	scanf("%d%d%d", &t.dan,&t.mjesec, &t.godina);
	return t;
}
struct Uposlenik unos_uposlenika()
{
	struct Uposlenik kandidat;
	char znak=getchar();
	int i=0;
	if (znak=='\n') znak=getchar();
	while(i < 50-1 && znak !='\n') {
		kandidat.ime_prezime[i]=znak;
		i++;
		znak=getchar();
	}
	kandidat.ime_prezime[i]='\0';
	kandidat.datum_rodjenja=unos_datuma();
	return kandidat;
}
int ukupno_dana(struct Datum date)
{
	int ukupno=0,i=0;
	ukupno=date.dan+date.godina*365;
	for(i=0; i<date.godina; i++) {
		if(i%4==0 && i%100>0)
			ukupno=ukupno+1;
		else if(i%400==0)
			ukupno=ukupno+1;
	}
	if(date.mjesec>2) {
		if(date.godina%4==0 && date.godina%100>0)
			ukupno=ukupno+29;
		else if(date.godina%400==0)
			ukupno=ukupno +29;
		else
			ukupno=ukupno+28;
	}
	for(i=0; i<date.mjesec; i++) {
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
			ukupno=ukupno+31;
		else if(i!=2)
			ukupno=ukupno+30;
	}
	return ukupno;
}
int prezimenjak( char *s1, char *s2)
{
	int i=0,j,tacnost=0;
	char *p1, *p2;
	p1=s1;
	p2=s2;
	//Provjeravamo da li imaju isto prezime odmah na pocetku
	while(p1[i]==p2[i] && p1[i]!='\0' && p2[i]!='\0') {
		if(p1[i+1]=='\0' && p2[i+1]=='\0') tacnost=1;
		i++;
	}
	p1=s1;
	p2=s2;
	i=0;
	while(p1[i]!='\0') {
		j=0;
		while(p2[j]!='\0') {
			if(p2[j]=='-') {
				j++;
				while(p1[i]==p2[j]) {
					//Provjeravamo da li postoje dva prezimena, pa zbog toga koristimo -
					if((p1[i+1]=='\0' && p2[j+1]=='\0') || (p1[i+1]=='-' && p2[j+1]=='\0')) {
						tacnost=1;
						break;
					}
					i++;
					j++;
				}
			}
			if(p1[i]=='-') {
				i++;
				while(p1[i]==p2[i]) {
					if((p1[i+1]=='\0' && p2[j+1]=='\0') || (p1[i+1]=='-' && p2[j+1]=='\0')) {
						tacnost=1;
						break;
					}
					i++;
					j++;
				}
			}
			j++;
		}
		i++;
	}
	return tacnost;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana)
{
	int dani_direktor, dani_kandidat, brojac, i=0, j=0,k=0,l=0,ukupno_razmaka;
	char direktor_prezime[50],kandidat_prezime[50];
	struct Uposlenik* pomocni, *zadnji_clan;
	brojac=vel;
	dani_direktor=ukupno_dana(direktor.datum_rodjenja);
	ukupno_razmaka=0;
	//brojimo razmake
	while(direktor.ime_prezime[i] !='\0') {
		if(direktor.ime_prezime[i] ==' ') ukupno_razmaka++;
		i++;
	}
	i=0;
	//odvajamo prezime
	while(direktor.ime_prezime[i] !='\0') {
		if(direktor.ime_prezime[i]==' ') j++;
		if(j==ukupno_razmaka) {
			direktor_prezime[k]=direktor.ime_prezime[i+1];
			k++;
		}
		i++;
	}
	zadnji_clan=kandidati+vel;
	while(kandidati<zadnji_clan) {
		j=0;
		k=0;
		l=0;
		//brojimo razmake
		ukupno_razmaka=0;
		while(kandidati->ime_prezime[l]!='\0') {
			if(kandidati->ime_prezime[l]==' ') ukupno_razmaka++;
			l++;
		}
		l=0;
		//odvajamo prezime
		while(kandidati->ime_prezime[l]!='\0') {
			if(kandidati->ime_prezime[l]==' ') j++;
			if(j==ukupno_razmaka) {
				kandidat_prezime[k]=kandidati->ime_prezime[l+1];
				k++;
			}
			l++;
		}
		//pozivamo funkciju ukupno_dana kako bismo izracunali protekle dane od pocetka racunanja vremena do datuma rodjenja
		dani_kandidat=ukupno_dana(kandidati->datum_rodjenja);
		if((dani_direktor-dani_kandidat>broj_dana && !prezimenjak(direktor_prezime,kandidat_prezime)) || (dani_direktor-dani_kandidat>broj_dana && !prezimenjak(kandidat_prezime,direktor_prezime))) {
			pomocni=kandidati;
			while(pomocni<zadnji_clan-1) {
				*pomocni=*(pomocni+1);
				pomocni++;
			}
			brojac--;
			zadnji_clan--;
		} else kandidati++;
	}
	return brojac;
}

int main()
{
	int i=0,ukupno_kandidata, razlika,broj_kandidata;
	struct Uposlenik radnici[50];
	struct Uposlenik direktor;
	printf("Unesite ukupan broj kandidata: ");
	scanf("%d",&ukupno_kandidata);
	for(i=0; i<ukupno_kandidata; i++) {
		printf("Unesite ime i prezime %d. kandidata:\n ",i+1);
		radnici[i]= unos_uposlenika();
	}
	printf("Unesite ime i prezime direktora firme: ");
	direktor = unos_uposlenika();
	printf("Unesite starosnu razliku u danima kandidata koje zelite izbaciti sa liste: ");
	scanf("%d", &razlika);
	broj_kandidata=suzi_listu(radnici, ukupno_kandidata,direktor,razlika);
	printf("Lista sada ima %d clana.\n", broj_kandidata);
	for(i=0; i<broj_kandidata; i++) {
		printf("%s\n", radnici[i].ime_prezime);
	}
	return 0;
}