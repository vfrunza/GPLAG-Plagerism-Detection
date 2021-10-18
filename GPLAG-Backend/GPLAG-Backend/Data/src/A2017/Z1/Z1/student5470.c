#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
#define CP1 6.8 // cijene za konj
#define CH1 3.3
#define CC1 5.0
#define CP2 8.0 // cijene za trov
#define CH2 3.0
#define CC2 3.9
#define CP3 5.3 // cijene za lor
#define CH3 5.0
#define CC3 6.0

int main() {
	char tarik, bojan, mirza, novired;
	float konj=0, trov=0, lor=0, jeftin, pkonj, pjeftin;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novired);
	if(tarik=='P'){		// Racunanje cijene
		konj=CP1;
		trov=CP2;
		lor=CP3;
	} else if(tarik=='H'){
		konj=CH1;
		trov=CH2;
		lor=CH3;
	} else{
		konj=CC1;
		trov=CC2;
		lor=CC3;
	}
	if(bojan=='P'){
		konj=konj+CP1;
		trov=trov+CP2;
		lor=lor+CP3;
	} else if(bojan=='H'){
		konj=konj+CH1;
		trov=trov+CH2;
		lor=lor+CH3;
	} else {
		konj=konj+CC1;
		trov=trov+CC2;
		lor=lor+CC3;
	}
	if(mirza=='P'){
		konj=konj+CP1;
		trov=trov+CP2;
		lor=lor+CP3;
	} else if(mirza=='H'){
		konj=konj+CH1;
		trov=trov+CH2;
		lor=lor+CH3;
	} else {
		konj=konj+CC1;
		trov=trov+CC2;
		lor=lor+CC3;
	}
	if(konj<trov && konj<lor) jeftin=konj;		// Trazenje najjeftinijeg prvi put
	else if(trov<konj && trov<lor) jeftin=trov;
	else jeftin=lor;
	pkonj=konj;		// Ako restoran nije najjeftiniji
	if(fabs(konj-jeftin)>EPSILON) { // S obzirom da je CP1>CH1>CC1
		if(tarik=='P' || bojan=='P' || mirza=='P'){
			if(tarik=='P' && mirza=='P' && bojan=='P') pkonj=pkonj-0.3*CP1;
			else if((tarik=='P' && bojan=='P')||(tarik=='P' && mirza=='P')||(bojan=='P' && mirza=='P')) pkonj=pkonj-0.2*CP1;
			else pkonj=pkonj-0.1*CP1;
		} else if(tarik=='C' || bojan=='C' || mirza=='C') {
			if(tarik=='C' && mirza=='C' && bojan=='C') pkonj=pkonj-0.3*CC1;
			else if((tarik=='C' && bojan=='C')||(tarik=='C' && mirza=='C')||(bojan=='C' && mirza=='C')) pkonj=pkonj-0.2*CC1;
			else pkonj=pkonj-0.1*CC1;
		} else {
			if(tarik=='H' && mirza=='H' && bojan=='H') pkonj=pkonj-0.3*CH1;
			else if((tarik=='H' && bojan=='H')||(tarik=='H' && mirza=='H')||(bojan=='H' && mirza=='H')) pkonj=pkonj-0.2*CH1;
			else pkonj=pkonj-0.1*CH1;
		}
		
	} 
	if(pkonj<trov && pkonj<lor) pjeftin=pkonj;		// Trazenje najjeftinijeg drugi put
	else if(trov<pkonj && trov<lor) pjeftin=trov;
	else pjeftin=lor;
	// Ispis najjeftinijeg iz prvog puta
	if(fabs(trov-jeftin)<EPSILON) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", jeftin);
	else if(fabs(lor-jeftin)<EPSILON) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", jeftin);
	else printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", jeftin);
	if(fabs(pkonj-pjeftin)<EPSILON && fabs(konj-jeftin)>EPSILON) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", pkonj);
	return 0;
}
