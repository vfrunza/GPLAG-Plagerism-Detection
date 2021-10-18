#include <stdio.h>
#include <math.h>

struct Datum {
	int dan, mjesec, godina; 
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
struct Uposlenik kandidati[100];
struct Uposlenik direktor;

/*prototipi funkcija*/
int prestupna(int godina);
int dani_od_pocetka(struct Uposlenik *kandidati, int vel);
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana);

/*Unos informacija*/
struct Uposlenik unos_kandidata(){
	int i,vel;

	for(i=0;i<100;i++){
		scanf("%s", &kandidati[i].ime_prezime);
		scanf("%s %s %s", &kandidati[i].datum_rodjenja.dan, &kandidati[i].datum_rodjenja.mjesec, &kandidati[i].datum_rodjenja.godina);
	}
	vel=i;
	return kandidati[vel];
}
struct Uposlenik unos_direktor(){
	scanf("%s", &direktor.ime_prezime );
	scanf("%s %s %s", &direktor.datum_rodjenja.dan, &direktor.datum_rodjenja.mjesec, &direktor.datum_rodjenja.dan);
	return direktor;
}

int main() {
	
	return 0;
}

int prestupna(int godina) {
	if(godina%4==0 && godina%100!=0 || godina%400==0)
	return 1;
	return 0;
}
int dani_od_pocetka(struct Uposlenik* kandidati, int vel) {
int ukupno=0, i, j;
int bdum[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

for(i=0;i<vel;i++) {
	if(prestupna(kandidati[i].datum_rodjenja.godina)) bdum[2]++;
	for(j=1;j<kandidati[i].datum_rodjenja.godina;j++)
	ukupno+=365+prestupna(i);
}
for(i=0;i<vel;i++) {
   for(j=1;j<kandidati[i].datum_rodjenja.mjesec;j++)
	ukupno+=bdum[i];
	ukupno+=kandidati[i].datum_rodjenja.dan;
}
return ukupno;
}
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	int i, j;
	for(i=0;i<vel;i++) {
		if((dani_od_pocetka(kandidati[i].datum_rodjenja,vel))-(dani_od_pocetka(direktor.datum_rodjenja,1))>(abs(broj_dana))) {
			for(j=i;j<vel-1;j++) {
				kandidati[j]=kandidati[j+1];
		}
		vel--;
		i--;
	}
	}
	return vel;
}

