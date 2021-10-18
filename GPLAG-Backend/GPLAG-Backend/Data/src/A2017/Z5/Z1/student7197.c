#include <stdio.h>
#include <string.h>

struct Datum { int dan; int mjesec; int godina;};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int porodica(char *s1, char *s2){
	/*provjerava string odzada jer je na kraju prezime*/
	do{s1++;}while(*s1);
	do{s2++;}while(*s2);
	while(*s1!=' ' && *s1!='-' && *s2!=' ' && *s2!='-' && *s1==*s2){
		s1--;
		s2--;
	}
	if((*s1==' ' || *s1=='-') && (*s2==' ' || *s2=='-'))return 1;
	return 0;
}

int suzi_listu(struct Uposlenik *kandidat, int vel,struct Uposlenik direktor, int broj_dana){
	int i,j;
	int d,m,g,ukupno_dana;
	int  Mjeseci[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(broj_dana<0)broj_dana=-broj_dana;
	for(i = 0; i < vel; i++){
		
		
		/* ako je clan porodice tj ima isto prezime ne treba se izbaciti sa liste */
		if( porodica( kandidat[i].ime_prezime, direktor.ime_prezime) )continue;
	
	
		/*ukupno dana = direktor - kandidat
		d1 = direktor.datum_rodjenja.godina;
		d1 = d1*100+ direktor.datum_rodjenja.mjesec;
		d1 = d1*100 + direktor.datum_rodjenja.dan;
		d2 = kandidat[i].datum_rodjenja.godina;
		d2 = d2*100 + kandidat[i].datum_rodjenja.mjesec;
		d2 = d2*100 + kandidat[i].datum_rodjenja.mjesec;
		d1-=d2;
		
		razlika.dan = d1%100; d1/=100;
		razlika.mjesec = d1%100; d1/=100;
		razlika.godina = d1;
		ukupno_dana = razlika.dan + razlika.mjesec*12 +razlika.godina*365;*/

		if(direktor.datum_rodjenja.dan < kandidat[i].datum_rodjenja.dan){
			direktor.datum_rodjenja.dan+=Mjeseci[direktor.datum_rodjenja.mjesec - 1];
			direktor.datum_rodjenja.mjesec--;
		}
		if(direktor.datum_rodjenja.mjesec < kandidat[i].datum_rodjenja.mjesec){
			direktor.datum_rodjenja.mjesec+=12;
			direktor.datum_rodjenja.godina--;
		}
		d = direktor.datum_rodjenja.dan - kandidat[i].datum_rodjenja.dan;
		m = direktor.datum_rodjenja.mjesec - kandidat[i].datum_rodjenja.mjesec;
		g = direktor.datum_rodjenja.godina - kandidat[i].datum_rodjenja.godina;
		ukupno_dana = d + 30*m + 365*g;
		/*naci bolji nacin za racunanje razlike u godinama*/
		if(ukupno_dana > broj_dana){
			for(j=i;j<vel-1;j++){
				strcpy(kandidat[j].ime_prezime,kandidat[j+1].ime_prezime);
				kandidat[j].datum_rodjenja.dan = kandidat[j+1].datum_rodjenja.dan;
				kandidat[j].datum_rodjenja.mjesec = kandidat[j+1].datum_rodjenja.mjesec;
				kandidat[j].datum_rodjenja.dan = kandidat[j+1].datum_rodjenja.mjesec;
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	
	return 0;
}