#include <stdio.h>
#include <stdlib.h>

struct Datum { int dan, mjesec, godina; };

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna(int godina) {
	if(godina % 400 == 0 || godina % 4 == 0 && godina % 100 != 0)
		return 1;
	return 0;
}

int pretvoriUDane(struct Datum datum) {
	int i, dani = 0;
	for(i = 1; i < datum.godina; i++) {
		if(prestupna(i))
			dani += 366;
		else
			dani += 365;
	}
	for(i = 1; i < datum.mjesec; i++) {
		if(i == 1 || i == 3 || i == 5 || i == 7 ||
			i == 8 || i == 10 || i == 12)
			dani += 31;
		else if(i == 4 || i == 6 || i == 9 || i == 11)
			dani += 30;
		else if(i == 2) {
			if(prestupna(datum.godina))
				dani += 29;
			else
				dani += 28;
		}
	}
	dani += datum.dan;
	return dani;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int i, j, k, familija, brPrezimenaDirektor = 0, brPrezimenaKandidat = 0;
	char *prezimenaDirektor[2], *prezimenaKandidat[2], *temp, *slovo, *slovo2;
	
	temp = direktor.ime_prezime;
	while(*temp != '\0') {
		if(*temp == ' ') {
			prezimenaDirektor[0] = temp + 1;
			brPrezimenaDirektor = 1;
		}
		else if(*temp == '-') {
			prezimenaDirektor[1] = temp + 1;
			brPrezimenaDirektor = 2;
			break;
		}
		temp++;
	}
	
	for(i = 0; i < vel; i++) {
		if(pretvoriUDane(direktor.datum_rodjenja) - pretvoriUDane(kandidati[i].datum_rodjenja) > broj_dana) {
			familija = 0;
			temp = kandidati[i].ime_prezime;
			while(*temp != '\0') {
				if(*temp == ' ') {
					prezimenaKandidat[0] = temp + 1;
					brPrezimenaKandidat = 1;
				}
				else if(*temp == '-') {
					prezimenaKandidat[1] = temp + 1;
					brPrezimenaKandidat = 2;
					break;
				}
				temp++;
			}
			for(j = 0; j < brPrezimenaDirektor; j++) {
				for(k = 0; k < brPrezimenaKandidat; k++) {
					slovo = prezimenaDirektor[j];
					slovo2 = prezimenaKandidat[k];
					while(1) {
						if(*slovo == *slovo2 &&
							*slovo != '-' &&
							*slovo != '\0' &&
							*slovo2 != '-' &&
							*slovo2 != '\0') {
								slovo++;
								slovo2++;
								continue;
							}
						if(*slovo == '-' && *slovo2 == '-' ||
							*slovo == '-' && *slovo2 == '\0' ||
							*slovo == '\0' && *slovo2 == '-' ||
							*slovo == '\0' && *slovo2 == '\0') {
								familija = 1;
								break;
						}
						if(*slovo != *slovo2)
							break;
						slovo++;
						slovo2++;
					}
				}
			}
			if(!familija) {
				for(j = i; j < vel - 1; j++)
					kandidati[j] = kandidati[j + 1];
				vel--;
				i--;
			}
		}
	}
	return vel;
}

int main() {
	struct Datum d1, d2;
	int broj_dana = 28;
	
	d1.dan = 1;
	d1.mjesec = 3;
	d1.godina = 1980;
	
	d2.dan = 2;
	d2.mjesec = 2;
	d2.godina = 1980;
	
	printf("%d", prestupna(1980));
	printf("%d - %d = %d", pretvoriUDane(d1), pretvoriUDane(d2), pretvoriUDane(d1) - pretvoriUDane(d2));
	return 0;
}
