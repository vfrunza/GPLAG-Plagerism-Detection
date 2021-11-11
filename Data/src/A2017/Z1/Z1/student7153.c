#include <stdio.h>
#define PR 6.80
#define PF 8.00
#define PB 5.30
#define HR 3.30
#define HF 3.00
#define HB 5.00
#define CR 5.00
#define CF 3.90
#define CB 6.00

int main() {

	double suma1, suma2, suma3, najmanja_cijena, max, popust;
	int brojacC=0, brojacH=0, brojacP=0;
	char mirza, bojan, tarik, novi_red;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	suma1=0;
	suma2=0;
	suma3=0;
	
	if(tarik=='C') {
		suma1 = suma1 + CR;
		suma2 = suma2 + CF;
		suma3 = suma3 + CB;
		brojacC++;
		
	}
	
	else if(tarik=='H') {
		suma1 = suma1 + HR;
		suma2 = suma2 + HF;
		suma3 = suma3 + HB;
		brojacH++;
	}
	
	else if(tarik=='P') {
		suma1 = suma1 + PR;
		suma2 = suma2 + PF;
		suma3 = suma3 + PB;
		brojacP++;
	}
	
	else if(mirza=='C') {
		suma1 = suma1 + CR;
		suma2 = suma2 + CF;
		suma3 = suma3 + CB;
		brojacC++;
	}
	
	else if(mirza=='H') {
		suma1 = suma1 + HR;
		suma2 = suma2 + HF;
		suma3 = suma3 + HB;
		brojacH++;
	}
	
	else if(mirza=='P') {
		suma1 = suma1 + PR;
		suma2 = suma2 + PF;
		suma3 = suma3 + PB;
		brojacP++;
		
	}
	
	else if(bojan=='C') {
		suma1 = suma1 + CR;
		suma2 = suma2 + CF;
		suma3 = suma3 + CB;
		brojacC++;
	}
	
	else if(bojan=='H') {
		suma1 = suma1 + HR;
		suma2 = suma2 + HF;
		suma3 = suma3 + HB;
		brojacH++;
	}
	
	else if(bojan=='P') {
		suma1 = suma1 + PR;
		suma2 = suma2 + PF;
		suma3 = suma2 + PB;
		brojacP++;
	}
	
	najmanja_cijena=suma1;
	
	if(suma2<najmanja_cijena) {
		najmanja_cijena=suma2;
	}
	
	
	if(suma3<najmanja_cijena) {
		najmanja_cijena=suma3;
	}
	
	max=brojacH*HR;
	
	if(max<brojacP*PR) {
		max=brojacP*PR;
	}
	
	if(max<brojacC*CR) {
		max=brojacC*CR;
	}
	
	popust=suma1-0.1*max;
	
	if(suma1<suma2 && suma1<suma3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1);
	}
	else if(suma2<suma1 && suma2<suma3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2);
		
		if(popust<suma2) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	
	else if(suma3<suma1 && suma3<suma2) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3);
		if(popust<suma3) {
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		}
	}
	
	return 0; 
	}
