#include <stdio.h>
#include <stdlib.h>

struct Datum 
{
	int dan, mjesec, godina;
};

struct Uposlenik 
{
	char ime_prezime[50];
	struct Datum dan.rodjenja;
};

/*Funkcija koja racuna starost osobe u danima*/
int dan (struct Datum) {
	struct Datuma=d;
	int br_ukdana;
	/*Kako da znamo koliko mjesec ima dana*/
	if (d.mjesec>=1 && d.mjesec<=12) {
		if (d.mjesec<8 && d.mjesec%2==1) d.mjesec=31;
		else if (d.mjesec==2) {
			if (d.godina%4==0 && (d.godina%400==0 || d.godina%100==1)) d.mjesec=29;
			else d.mjesec=28;
		}
		else if (d.mjesec>8 && d.mjesec%2==0) d.mjesec=31;
		else d.mjesec=30;
	}
	br_ukdana=d.godina*365+d.mjesec+(d.mjesec-d.dan);
	return br_ukdana;
}

/*Funkcija kojom poredimo prezimena*/
int prezime (struct Uposlenik kandidat, struct Uposlenik direktor) 
{
	struct Uposlenik u;
	kandidat=u.ime_prezime;
	char* s=kandidat;
	direktor=u.ime_prezime;
	char* s1=direktor;
	char* poc=s;
	int provjera;
	while (*s!='\0') {
		if (((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && (*s==poc || *(s-1)==' ') {
			brojac++;
			char* r=s;
			if (brojac>1) {
				char* l=s;
				while ((!(*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && (*(s-1)==' ' || *(s-1)=='-')) l++;
				if (*l=='-' || *l=='\n') {
					while (*s1!=0) {
						char* p=s1;
						char* q=r;
					}
					while (*p++==q++) {
						if (*p!'-' || *q!='\n') provjera 1;
						else provjera=0;
						s1++;
					}
				}
			}
		}
		s++;
	}
	if (provjera==1) return 1;
	else return 0;
}

/*funkcija za direktora*/
int suzi_listu (struct Uposlenik* kandidat, int vel, struct Uposlenik direktor, int broj_dana/*Iz main-a*/) {
	int i;
	int br_dozdana, uk, srodstvo, br=0;
	while (i<vel) {
		uk=dan(struct Uposlenik u);
		br_dozdana=abs(broj_dana-uk);
		srodstvo=prezime(struct Uposlenik prezime);
		if (srodstvo!=1 || br_dozdana>broj_dana) {
			for (j=i; j<vel; j++) {
				kandidat[j]=kandidat[j+1];
				br++;
			}
			vel--;
		}
		i++;
	}
	return vel-br;
}

int main() {

	return 0;
}
