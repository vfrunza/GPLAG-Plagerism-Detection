#include <stdio.h>
#include <string.h>

struct Datum { 
	int dan, mjesec, godina; 
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

void ukloni() {
	
}

int dodjel_mu_sta(struct Uposlenik direktor, struct Uposlenik* potencijalni_rod) {
	char prezime1[50],prezime2[50];
	char* p;
	char* d;
	char* p1=(*potencijalni_rod).ime_prezime;
	char* p2=(*potencijalni_rod).ime_prezime;
	char* d1=direktor.ime_prezime;
	char* d2=direktor.ime_prezime;
	char* pok;
	while(*(p1+1)!='\0') p1++;
	while(*(p1-1)!=' ') {
		if(*p1=='-') {
			p=p2-1;
			p2=p1+1;
		}
		p1--;
	}
	while(*(d1+1)!='\0') d1++;
	while(*(d1-1)!=' ') {
		if(*d1=='-') {
			d=d2-1;
			d2=d1+1;
		}
		d1--;
	}
	pok=d1;
	while(*pok!='\0') {
		if(*pok1==*pok) {
			pok++;
			pok1++;
		}
		else if(*pok1!=*pok && pok<pok2 && pok!='-') {
			pok=pok2;
		} 
	}
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int i,faktor_nepotizma;
	for(i=0;i<vel;i++) {
		faktor_nepotizma=dodjel_mu_sta(direktor,kandidati);
		if(faktor_nepotizma=1) kandidati++;
		else {
			if((*kandidati).godina<direktor.godina) kandidati++;
			else if((*kandidati).godina>direktor.godina) {
				ukloni(kandidati,vel);
				vel--;
			}
			else {
				if((*kandidati).mjesec<direktor.mjesec) {
					if((*kandidati).dan-direktor.dan>fabs(x)) {
						ukloni(*kandidati);
						vel--;
					}
				}
				else if((*kandidati).mjesec=kandidati.mjesec) {
					if((*kandidati).dan-direktor.dan > x) {
						ukloni(kandidati);
						vel--;
					}
					else kandidati++;
				}
				else {
					ukloni(kandidati,vel);
					vel--;
				}
			}
	}
	return vel;
}

int main() {
	/* Neki main */
	return 0;
}
