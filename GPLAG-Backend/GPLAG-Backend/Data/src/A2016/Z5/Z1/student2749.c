#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define Eps 0.0001
struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
    int br_ocjena;
};
struct Ispis{
	double prosjek;
	int pozicija;
};
void unesi(char niz[], int velicina) {
    char znak = getchar();
    int i = 0;
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
void ispisi(struct Student niz[], int vel){
	struct Ispis prosjeci[20], foo;
	double suma;
	int i,j,brojac=0, temp_prezime=0, temp_ime=0;
	for(i =0; i < vel; i++){
		brojac = 0;
		suma = 0;
		for(j = 0; j < niz[i].br_ocjena; j++){
			suma += niz[i].ocjene[j];
			brojac++;
		}
		prosjeci[i].prosjek = suma / brojac;
		prosjeci[i].pozicija = i;
	}
	for(i = 0; i < vel; i++){
		for(j = i+1; j < vel; j++){
			if(prosjeci[i].prosjek < prosjeci[j].prosjek){
				foo = prosjeci[i];
				prosjeci[i] = prosjeci[j];
				prosjeci[j] = foo;
				
			}
		}
	}
 
	for(i = 0; i < vel; i++){
		for(j = i+1; j < vel; j++){
			if(fabs(prosjeci[i].prosjek - prosjeci[j].prosjek) < Eps){
				temp_prezime = strcmp(niz[prosjeci[i].pozicija].prezime, niz[prosjeci[j].pozicija].prezime);
				if(temp_prezime == 0){
					temp_ime = strcmp(niz[prosjeci[i].pozicija].ime, niz[prosjeci[j].pozicija].ime);
					if(temp_ime > 0) {
						foo = prosjeci[i];
						prosjeci[i] = prosjeci[j];
						prosjeci[j] = foo;
					}
				} else if(temp_prezime > 0){
					foo = prosjeci[i];
					prosjeci[i] = prosjeci[j];
					prosjeci[j] = foo;
				}
			}
		}
	}
	if(vel >= 3){
		for(i = 0; i < 3; i++) printf("%s %s\n", niz[prosjeci[i].pozicija].prezime, niz[prosjeci[i].pozicija].ime);
	}
	else if(vel == 2){
		printf("%s %s\n", niz[prosjeci[0].pozicija].prezime, niz[prosjeci[0].pozicija].ime);
		printf("%s %s\n", niz[prosjeci[1].pozicija].prezime, niz[prosjeci[1].pozicija].ime);
	}
	else if(vel == 1){
		printf("%s %s\n", niz[prosjeci[0].pozicija].prezime, niz[prosjeci[0].pozicija].ime);
	}
}
int genijalci(struct Student niz[], int vel, double prosjek){
	int i,j,k,brojac = 0;
	double suma = 0, bar;
	for(i = 0; i < vel; i++){
		bar = 5.0;
		suma = 0;
		brojac = 0;
		for(k = 0; k < niz[i].br_ocjena; k++){
			if(niz[i].ocjene[k] != 5){
				suma += niz[i].ocjene[k];
				brojac++;
			}else{
				break;
			}
		}
		if(k == niz[i].br_ocjena && brojac != 0) bar = suma / brojac;
		else bar = 5.0;
		/*if ((abs(bar - 5.0) < Eps) && (brojac != 0)) bar = suma / brojac;*/
		
		if(bar < prosjek){
			for(j = i; j < vel-1; j++){
				niz[j] = niz[j+1];	
			}
			vel--;
			i--;
		}
	}
	ispisi(niz, vel);
	return vel;
}
int main() {
	struct Student niz[]  = { 
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 10, 10, 10, 10, 5}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
	genijalci(niz, 5, 6.5);
	return 0;
}

