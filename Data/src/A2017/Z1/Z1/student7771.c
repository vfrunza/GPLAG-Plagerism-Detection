#include <stdio.h>
#include <math.h>
#define pizza1 6.8
#define pizza2 8.00
#define pizza3 5.30
#define hamburger1 3.30
#define hamburger2 3.00
#define hamburger3 5.00
#define cevapi1 5.00
#define cevapi2 3.90
#define cevapi3 6.00

int main()
{
//Do 43 linije koda samo kopirano jer sam greskom iskuco zadatak u zadataku 2//
	char T,B,M,novi_red;

	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &novi_red);

	double restoran=0,trovac=0,lorelei=0,popust=0;


	if((B=='P' && T=='P' && M=='C')||(B=='C' && T=='P' && M=='P')||(B=='P' && T=='C' && M=='P')) {
		restoran=2*pizza1+cevapi1;
		if(2*pizza1>cevapi1)
			popust=2*pizza1*0.9+cevapi1;
		else popust=2*pizza1+cevapi1*0.9;
		trovac=2*pizza2+cevapi2;
		lorelei=2*pizza3+cevapi3;
	}

	if((B=='P' && T=='P' && M=='H')||(B=='P' && T=='H' && M=='P')||(B=='H' && T=='P' && M=='P')) {
		restoran=2*pizza1+hamburger1;
		if(2*pizza1>hamburger1)
			popust=2*pizza1*0.9+hamburger1;
		else popust=2*pizza1+hamburger1*0.9;
		trovac=2*pizza2+hamburger2;
		lorelei=2*pizza3+hamburger3;
	}

	if((B=='H' && T=='H' && M=='P')||(B=='P' && T=='H' && M=='H')||(B=='H' && T=='P' && M=='H')) {
		restoran=2*hamburger1+pizza1;
		if(2*hamburger1>pizza1)
			popust=2*hamburger1*0.9+pizza1;
		else popust=2*hamburger1+pizza1*0.9;
		trovac=2*hamburger2+pizza2;
		lorelei=2*hamburger3+pizza3;
	}

	if((B=='C' && T=='H' && M=='H')||(B=='H' && T=='C' && M=='H')||(B=='H' && T=='H' && M=='C')) {
		restoran=2*hamburger1+cevapi1;
		if(2*hamburger1>cevapi1)
			popust=2*hamburger1*0.9+cevapi1;
		else popust=2*hamburger1+cevapi1*0.9;
		trovac=2*hamburger2+cevapi2;
		lorelei=2*hamburger3+cevapi3;
	}

	if((B=='P' && T=='C' && M=='C')||(B=='C' && T=='C' && M=='P')||(B=='C' && T=='P' && M=='C')) {
		restoran=2*cevapi1+pizza1;
		if(2*cevapi1>pizza1)
			popust=2*cevapi1*0.9+pizza1;
		else popust=2*cevapi1+pizza1*0.9;
		trovac=2*cevapi2+pizza2;
		lorelei=2*cevapi3+pizza3;
	}

	if((B=='C' && T=='C' && M=='H')||(B=='C' && T=='H' && M=='C')||(B=='H' && T=='C' && M=='C')) {
		restoran=2*cevapi1+hamburger1;
		if(2*cevapi1>hamburger1)
			popust=2*cevapi1*0.9+hamburger1;
		else popust=2*cevapi1+hamburger1*0.9;
		trovac=2*cevapi2+hamburger2;
		lorelei=2*cevapi3+hamburger3;
	}

	if((B=='C' && T=='P' && M=='H')||(B=='P' && T=='H' && M=='C')||(B=='H' && T=='C' && M=='P')) {
		restoran=cevapi1+hamburger1+pizza1;
		popust=pizza1*0.9+cevapi1+hamburger1;
		trovac=cevapi2+hamburger2+pizza2;
		lorelei=cevapi3+hamburger3+pizza3;
	}

	if(B=='P' && T=='P' && M=='P') {
		restoran=3*pizza1;
		popust=(3*pizza1)*0.9;
		trovac=3*pizza2;
		lorelei=3*pizza3;
	}

	if(B=='H' && T=='H' && M=='H') {
		restoran=3*hamburger1;
		popust=(3*hamburger1)*0.9;
		trovac=3*hamburger2;
		lorelei=3*hamburger3;
	}

	if(B=='C' && T=='C' && M=='C') {
		restoran=3*cevapi1;
		popust=(3*cevapi1)*0.9;
		trovac=3*cevapi2;
		lorelei=3*cevapi3;
	};

	if(restoran<trovac && restoran<lorelei) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",restoran );
	} else if(lorelei<trovac && lorelei<restoran) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n",lorelei );
		if(lorelei>popust)
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
	} else if(trovac<restoran && trovac<lorelei) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n",trovac );
		if(popust<trovac)
			printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).",popust);
	}
	return 0;
}
