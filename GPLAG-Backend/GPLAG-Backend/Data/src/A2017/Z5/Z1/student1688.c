#include <stdio.h>
#include <string.h>
#include <math.h>

struct Datum { int dan, mjesec, godina ; };

struct Uposlenik {
		char ime_prezime[50];
		struct Datum datum_rodjenja;
};

void daj_prezimena(char *prezime, char *prvo, char *drugo){
	char *pocetak = prezime;
	char *kraj = pocetak;
	char *pom1, *pom2 = NULL;
	int broj_prezimena = 1;
	while(*kraj != '\0') kraj++;
	pom1 = kraj;
	while(kraj > pocetak){
		if(*kraj == '-'){
			broj_prezimena++;
			strncpy(drugo,kraj+1,pom1-kraj+1);
			drugo[pom1-kraj+2] = '\0';
			pom2 = kraj;
		}
		if(*kraj == ' '){
			if(broj_prezimena == 1){
				strncpy(prvo,kraj+1,pom1-kraj+1);
				prvo[pom1-kraj+2] = '\0';
				drugo = "";
				return;
			}
			else{
				strncpy(prvo,kraj+1,pom2-kraj-1);
				prvo[pom2-kraj] = '\0';
				return;
			}
		}
		kraj--;
	}
}

int dan_u_godini(struct Datum d1){
	int mjeseci[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int prestupna = 0, i = 0, rezultat = 0;
	if(d1.godina % 4 == 0 && (d1.godina % 100 != 0 || d1.godina % 400 == 0)) prestupna = 1;
	if(prestupna == 1) mjeseci[1] = 29;
	for(i = 0; i < 12; i++){
		if(i + 1 == d1.mjesec) break;
		rezultat += mjeseci[i];
	}
	rezultat = rezultat + d1.dan;
	return rezultat;
}

int razlika_dana(struct Datum d1, struct Datum d2){
	int dan1 = dan_u_godini(d1);
	int dan2 = dan_u_godini(d2);
	int god1 = d1.godina;
	int god2 = d2.godina;
	int razlika = 0, prestupna;
	while (god1 < god2){
		prestupna = 0;
		if(god1 % 4 == 0 && (god1 % 100 != 0 || god1 % 400 == 0)) prestupna = 1;
		if(god1 == d1.godina) razlika = (365 + prestupna) - dan1;
		else razlika = razlika + 365 + prestupna;
		god1++;
		if(god1 == god2) razlika = razlika + dan2;
	}
	while (god2 < god1){
		prestupna = 0;
		if(god2% 4 == 0 && (god2 % 100 != 0 || god2 % 400 == 0)) prestupna = 1;
		if(god2 == d2.godina) razlika = (365 + prestupna) - dan2;
		else razlika = razlika + 365 + prestupna;
		god2++;
		if(god1 == god2) razlika = razlika + dan1;
	}
	if(d1.godina == d2.godina) return fabs(dan1-dan2);
	return razlika;
}


int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	int i = 0, j = 0;
	char niz1[100] = "";
	char niz2[100] = "";
	char niz3[100] = "";
	char niz4[100] = "";
	int br_pr_dir = 1, br_pr_uposl = 1;
	int isto_prezime = 0, razlika = 0;
	for(i = 0; i < vel; i++){
		isto_prezime = 0;
		br_pr_uposl = 1;
		br_pr_dir = 1;
		razlika = 0;
		daj_prezimena(kandidati[i].ime_prezime,niz1,niz2);
		daj_prezimena(direktor.ime_prezime,niz3,niz4);
		if(strlen(niz2) != 0) br_pr_uposl++;
		if(strlen(niz4) != 0) br_pr_dir++;
		if(br_pr_dir == 1 && br_pr_uposl == 1) {
			if(strcmp(niz1,niz3) == 0) isto_prezime = 1;
		}
		else if(br_pr_dir == 1 && br_pr_uposl == 2){
			if(strcmp(niz3,niz1) == 0 || strcmp(niz3,niz2)== 0) isto_prezime = 1;
		}
		else if(br_pr_dir == 2 && br_pr_uposl == 1){
			if(strcmp(niz3,niz1) == 0 || strcmp(niz4,niz1)== 0) isto_prezime = 1;
		}
		else {
			if(strcmp(niz3,niz1) == 0 || strcmp(niz3,niz2)== 0 || strcmp(niz4,niz1) == 0 || strcmp(niz4,niz2)== 0) isto_prezime = 1;
		}
		razlika = razlika_dana(kandidati[i].datum_rodjenja, direktor.datum_rodjenja);
		if(razlika > fabs(broj_dana) && isto_prezime == 0){
			for(j = i; j < vel - 1; j++){
				kandidati[j] = kandidati[j+1];
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1980} };
	struct Uposlenik kandidati[7] = {
    	{ "Meho Mehic", { 31, 1, 1980 } },
    	{ "Pero Peric", { 1, 2, 1980 } },
    	{ "Sara Sarac", { 2, 2, 1980 } },
    	{ "Fata Mujic", { 1, 2, 1976 } },
    	{ "Jozo Jozic", { 1, 10, 1980 } },
    	{ "Mijo Mijic", { 4, 3, 1979 } },
    	{ "Suljo Suljic", { 15, 1, 1982 } },
	};
	char niz1[100] = "";
	char niz2[100] = "";
	char niz3[100] = "";
	char niz4[100] = "";
	printf("%d\n",razlika_dana(direktor.datum_rodjenja,kandidati[1].datum_rodjenja));
	printf("%d\n",dan_u_godini(direktor.datum_rodjenja));
	printf("%d\n",dan_u_godini(kandidati[1].datum_rodjenja));
	return 0;
}
