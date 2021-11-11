include <stdio.h>

#define RP 6.80 /*Cijena pice u Restoranu kod konja i konjusara*/
#define RH 3.30 /*Cijena hamburgera u Restoranu kod konja i konjusara*/
#define RC 5 /*Cijena cevapa u Restoranu kod konja i konjusara*/
#define TP 8 
#define TH 3
#define TC 3.90
#define BP 5.30
#define BH 5
#define BC 6

int main () {
	
	double suma1=0; /*Restoran*/
	double suma2=0; /*Trovac*/
	double suma3=0; /*Bistro*/
	double popust=0.68; //10% popusta od najskupljeg obroka, tj. pizze
	
	char jeloT, jeloM, jeloB, novi_red;
	
	printf ("Unesite jelo za Tarika: ");
	scanf ("%c", &jeloT);
	scanf ("%c", &novi_red);
	
	if (jeloT=='P') {
		suma1+=RP;
		suma2+=TP;
		suma3+=BP;
	}
	
	else if (jeloT=='H') {
		
		suma1+=RH;
		suma2+=TH;
		suma3+=BH;
		
	}
	
	else if (jeloT=='C') {
	
	suma1+=RC;
	suma2+=TC;
	suma3+=BC;
		
	}
	
	printf ("Unesite jelo za Bojana: ");
	scanf ("%c", &jeloB);
	scanf ("%c", &novi_red);
	
	if (jeloB=='P') {
		suma1+=RP;
		suma2+=TP;
		suma3+=BP;
	}
	
	else if (jeloB=='H') {
		suma1+=RH;
		suma2+=TH;
		suma3+=BH;
	}
	
	else if (jeloB=='C') {
		suma1+=RC;
		suma2+=TC;
		suma3+=BC;
	}
	
	printf("Unesite jelo za Mirzu: ");
	scanf ("%c", &jeloM);
	scanf ("%c", &novi_red);
	
	if (jeloM=='P') {
		suma1+=RP;
		suma2+=TP;
		suma3+=BP;
	}
	
	else if (jeloM=='H') {
		suma1+=RH;
		suma2+=TH;
		suma3+=BH;
	}
	
	else if (jeloM=='C') {
		suma1+=RC;
		suma2+=TC;
		suma3+=BC;
	}
	
	if (suma1<suma2 && suma1<suma3) {
		printf ("Najjeftiniji je Restoran Kod konja i konjusara (%g KM)", suma1);
	}
	else if (suma2<suma1 && suma2<suma3) {
		suma1-=popust;
		if(suma1<suma2) printf("Najjeftiniji je Restoran Kod konja i konjusara (%g KM)", suma1);
		else printf ("Najjeftiniji je fast food Trovac (%g KM)", suma2);
	}
	else if (suma3<suma1 && suma3<suma2) {
		suma1-=popust;
		if(suma1<suma3) printf("Najjeftiniji je Restoran Kod konja i konjusara (%g KM)", suma1);
		else printf ("Najjeftiniji je Bistro Lorelei (%g KM)", suma3);
	}
	
	return 0;
}