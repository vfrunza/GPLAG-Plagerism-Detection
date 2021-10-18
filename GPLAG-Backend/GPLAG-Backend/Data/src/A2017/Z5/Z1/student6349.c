#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void unesi(char niz[], int velicina) {
	
// Funkcija za unos stringa.
	
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

struct Datum {
	int dan;
	int mjesec;
	int godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

void unesi_direktora(struct Uposlenik direktor) {
	
	// Unosimo podatke direktora
	
	printf("Unesi ime i prezime direktora: ");
	unesi(direktor.ime_prezime, 50);
	printf("Unesi datum rodjenja direktora(dan mjesec godina): ");
	scanf("%d %d %d", &direktor.datum_rodjenja.dan, &direktor.datum_rodjenja.mjesec, &direktor.datum_rodjenja.godina);
}

void unesi_uposlenika(struct Uposlenik kandidati) {
	
	// Unosimo podatke kandidata
	
	printf("Unesi ime i prezime kandidata: ");
	unesi(kandidat.ime_prezime, 50);
	printf("Unesi datum rodjenja kandidata(dan mjesec godina): ");
	scanf("%d %d %d", &kandidat.datum_rodjenja.dan, &kandidat.datum_rodjenja.mjesec, &kandidat.datum_rodjenja.godina);
}
int Vrati_Broj_Prestupnih(struct Datum datum){  
	
	// Funkcija vraca broj prestupnih godina od datuma koji se prenosi u parametru funkcije.
	
	int i=4;
	int broj_prestupnih=0;
	while (i<=datum.godina && i%4==0 && i%100!=0 || i%400 ==0) {
		 broj_prestupnih++;
		 i+=4;
	}
	return broj_prestupnih;
	
}

int Vrati_Razlika_Dana(struct Datum d1, struct Datum d2){
	
	// Ova funkcija vraca broj dana izmedju dva datuma d1 i d2
	// Prvo izracunamo ukupan broj dana od prvog dana sa d1, a zatim na isti nacin izdracunamo koliko dana je proslo do d2.
	// Ovdje cemo korisiti pomocnu funkciju, koja ce za neku godinu odrediti broj prestupnih godina do te godine.
	
	int niz_mjeseci[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int broj_dana_prvog=0, broj_dana_drugog=0, i;
	broj_dana_prvog = 365*d1.godina + d1.dan;
	for(i=0; i<d1.mjesec-1; i++ ){
		broj_dana_prvog += niz_mjeseci[i];
	}
	broj_dana_prvog += Vrati_Broj_Prestupnih(d1);
	
	broj_dana_drugog = 365*d2.godina + d2.dan;
	for(i=0; i<d2.mjesec-1; i++ ){
		broj_dana_drugog += niz_mjeseci[i];
	}
	broj_dana_drugog += Vrati_Broj_Prestupnih(d2);
	
	return abs(broj_dana_prvog-broj_dana_drugog);
}

int DaLiImaIstihPrezimena(char string1[50], char string2[50]){
	
	// Ova funkcija provjerava da li kandidat ostaje na listi, iako je za x dana stariji odnosno mladji od direktora, na osnovu prezimena.
	
	int i=0, j=0, t=0, Jesmo_Li_Posjetili=0, k=0;
	char ili_ime_ili_prezime1[25], ime1[25], ime2[25],prezime1[25], prezime2[25], prezime3[25], prezime4[25];
	
	while(string1[i]!=' '){
		ime1[i]=string1[i]; // Kopiramo ime u string ime1.
		i++;
	}
	i++;
	if(string1[i]=='\0'){
		strcpy(prezime1,ime1); // Ako string pocinje sa prezimenom kopiramo string ime1 u string prezime1.
	}
	else{
	while(string1[i]!='\0') {
		if(string1[i]==' ') {
			for(j=i+1; j<strlen(string1);j++){
				prezime1[k] = string1[j]; // Stavimo k na nulu jer zelimo da kopiramo ostatak niza string1 u pomocni niz prezime1(cija numeracija pocinje od k=0).
				k++;
			}
			Jesmo_Li_Posjetili = 1;
			break;
		}
		else if(string1[i]=='-'){
			strcpy (prezime1,ime2); // Ako imamo 2 prezimena kopiramo rijec za koju smo mislila da je ime u string prezime2.
			for(j=i+1; j<strlen(string1); j++){
				prezime2[k]=string1[i];
				k++;
			}
			Jesmo_Li_Posjetili =1;
			break;
		}
		ime2[t] = string1[i];
		t++;
		i++;
	}
	if(Jesmo_Li_Posjetili==0){
		strcpy(prezime1,ime2);
	}
	}
	
	i=0; j=0; t=0; Jesmo_Li_Posjetili=0; k=0;
	while(string1[i]!=' '){
		ime1[i]=string1[i];
		i++;
	}
	i++;
	if(string1[i]=='\0'){
		strcpy(prezime3,ime1);
	}
	else {
	while(string2[i]!='\0') {
		if(string2[i]==' ') {
			for(j=i+1; j<strlen(string1);j++){
				prezime3[k] = string1[j]; // Stavimo k na nulu jer zelimo da kopiramo ostatak niza string1 u pomocni niz prezime3(cija numeracija pocinje od k=0)
				k++;
			}
			Jesmo_Li_Posjetili = 1;
			break;
		}
		else if(string1[i]=='-'){
			strcpy (prezime3,ime2);
			for(j=i+1; j<strlen(string1); j++){
				prezime4[k]=string1[i];
				k++;
			}
			Jesmo_Li_Posjetili =1;
			break;
		}
		ime2[t] = string1[i];
		t++;
		i++;
	}
	if(Jesmo_Li_Posjetili==0){
		strcpy(prezime3,ime2);
	}
	}
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int i, j;
	for(i=0; i<vel; i++){
	    if(Vrati_Razlika_Dana(direktor.datum_rodjenja, kandidati[i].datum_rodjenja)>abs(broj_dana)){  //Pozivamo funkciju koja vraca razliku dana direktora i kandidata te provjeravamo da li je ta razlika veca od dozvoljene
	    	for(j=i; j<vel; j++) {
	    	kandidati[j]=kandidati[j+1];
	    	}
	    vel--;
	    }
	}
	return vel;
}

int main() {
	struct Uposlenik direktor;
	struct Uposlenik kandidati[500];
	int broj_dana, n, i, konacan_broj_kandidata;
	
	printf("Unesite broj dana za koliko kandidat smije maksimalno biti stariji: ");
	scanf("%d", &broj_dana);
	
	printf("Unesite podatke direktora: \n");
	unesi_direktora(direktor); // Pozivamo funkciju kojom unosimo podatke direktora
	for(i=0; i<500; i++) {
		printf("Unesite kandidate: (1 za unos, -1 za izlaz!)\n"); // Pozivamo funkciju kojom unosimo podatke kandidata
		scanf("%d", &n);
		if(n==-1) break;
		unesi_uposlenika(kandidati[i]);
	}
	
	konacan_broj_kandidata = suzi_listu(kandidati, 500, direktor, broj_dana);
	
	printf("Broj konacnih kandidata je: %d\n", konacan_broj_kandidata);
	
	return 0;
}
