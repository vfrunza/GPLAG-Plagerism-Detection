#include <stdio.h>

struct Datum{
	int dan,mjesec,godina;
};

struct Uposlenik{
	char ime[20],prezime[20];
	struct Datum datum_rodjenja;
};

int ProvjeriPrestupnu(int godina){
	return (((godina % 4 == 0) && (godina % 100 != 0)) || (godina % 400 == 0));
}

/* int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	int broj_dana_u_mjesecu[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i,j;
	int uposlenik_1, direktor_1, direktor_2, direktor_3,kandidat_1, kandidat_2, kandidat_3;
	int pomoc=0;
	
	if(ProvjeriPrestupnu(direktor.datum_rodjenja.godina)){
		broj_dana_u_mjesecu[1]=29;
	}
	
	direktor_3=((direktor.datum_rodjenja.godina-1)/4 - (direktor.datum_rodjenja.godina-1)/100+(direktor.datum_rodjenja.godina-1)/400)*366 + ((direktor.datum_rodjenja.godina-1)-((direktor.datum_rodjenja.godina-1)/4-(direktor.datum_rodjenja.godina-1)/100+(direktor.datum_rodjenja.godina-1)/400)*366)*365;
	/*po mjesecima*/
	/*
	for(i=0; i<direktor.datum_rodjenja.mjesec-1;i++){
		direktor_3+=broj_dana_u_mjesecu[i];
	}
	
	/*sada provjeravamo kandidate
	for(i=0; i<vel; i++){
		if(ProvjeriPrestupnu(kandidati[i].datum_rodjenja.godina)){
			broj_dana_u_mjesecu[1]=29;
		}
		
		kandidat_3=((kandidati[i].datum_rodjenja.godina-1)/4-(kandidati[i].datum_rodjenja.godina-1)/100+(kandidati[i].datum_rodjenja.godina-1)/400)*366 + ((kandidati[i].datum_rodjenja.godina-1)-((kandidati[i].datum_rodjenja.godina-1)/4-(kandidati[i].datum_rodjenja.godina-1)/100+(kandidati[i].datum_rodjenja.godina-1)/400)*366)*365;
		/*kandidati po mjesecima
		for(i=0; i<kandidati[i].datum_rodjenja.mjesec-1; i++){
			kandidat_3+=broj_dana_u_mjesecu[i];
		}
		/*dodamo dan
		kandidat_3+=kandidati[i].datum_rodjenja.dan;
		if(broj_dana>0){
			if(direktor_3 - kandidat_3 > broj_dana && direktor)
		}
	}
	
}*/
int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
