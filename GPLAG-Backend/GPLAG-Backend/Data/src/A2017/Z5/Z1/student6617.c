#include <stdio.h>
#include <math.h>

struct Datum { int dan, mjesec, godina; };

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int godina){
	if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
		return 1;
	return 0;
}

int pretvorba_u_dane(struct Uposlenik x){
	
	int mjeseci[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int ukupno = 0, i;
	
	for(i = 1; i < x.datum_rodjenja.godina; i++){
		ukupno += 365 + prestupna(i); 
	}
	
	if(prestupna(x.datum_rodjenja.godina)) mjeseci[2]++;
	
	for(i = 1; i < x.datum_rodjenja.mjesec; i++){
		ukupno += mjeseci[i];
	}
	
	ukupno += x.datum_rodjenja.dan;
	
	return ukupno;
	
}

int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	
	int i,j,k,disa,razlika,starost = 0,radnik;
	
	//disa = pretvorba_u_dane(direktor);
	
	/*for(i = 0; i < vel; i++){
		int x;
		x = pretvorba_u_dane(kandidati[i]);
		razlika = fabs(disa - x) - broj_dana;
		
		if(razlika != 0){*/
		for(i = 0; i < vel; i++){
			//int radnik;
			//starost = 0;
			radnik = pretvorba_u_dane(kandidati[i]);
			disa = pretvorba_u_dane(direktor);
			razlika = disa - radnik;
			if(broj_dana > 0 && (razlika > 0 && fabs(razlika) > broj_dana) || (broj_dana < 0 && (razlika > 0 && razlika > fabs(broj_dana) || razlika))){ //|| (broj_dana > 0 && razlika > 0 && razlika > broj_dana)){
			/*starost = 1;
			if(broj_dana < 0 && razlika > 0 || razlika < fabs(broj_dana))
			starost = 1;

			//for(k = i; k < vel; k++){
				if(starost == 1){*/
					for(j = i; j < vel-1; j++){
						//for(k = j; k < vel-1; k++){
						kandidati[j] = kandidati[j+1];
					}
					//}
					vel--;
					i--;
				}
				//starost = 0;
		}
		/*}
	}*/
	
	return vel;
}

int main() {
	
	struct Uposlenik direktor = {" ", {1,9,1980}};
	struct Uposlenik kandidati = {"af ",{2,10,1980}};
	int x,y,rez;
	x = pretvorba_u_dane(direktor);
	y = pretvorba_u_dane(kandidati);
	rez = x-y;
	
	printf("direktor: %d, a kandidati: %d, rez: %d .",x,y,rez);
	return 0;
}
