#include <stdio.h>
struct Datum { int dan, mjesec, godina };
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int tekuca_godina(int x) {
	int y=0;
	switch(x) {
		case 1: y=0; break;
		case 2: y=31; break;
		case 3: y=59; break;
		case 4: y=90; break;
		case 5: y=120; break;
		case 6: y=151; break;
		case 7: y=181; break;
		case 8: y=212; break;
		case 9: y=243; break;
		case 10: y=273; break;
		case 11: y=304; break;
		case 12: y=334; break;
	}
	return y;
}
int stariji(struct Datum kandidat, struct Datum direktor, int broj_dana) {
	int ref1, ref2, dani1=0, dani2=0;
	godina1=direktor.godina;
	godina2=kandidat.godina;
	ref=godina2;
	if(godina1<godina2) ref=godina1;
	dani1=tekuca_godina(direktor.mjesec);
	if(godina1%4==0 && godina1%100!=0) {
		dani1++;
	} else if(godina1%400==0) {
		dani1++;
	}
	for(i=godina1, )
	dani1=dani1+direktor.dan+(godina1-ref)*365;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int starost_kandidata, i=0;
	while(kandidati<kandidati+vel) {
		if(stariji(kandidat[i].datum_rodjenja, direktor.datum_rodjenja, broj_dana)) {
			
		}
		
		kandidati++;
		i++;
	}
}
int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
