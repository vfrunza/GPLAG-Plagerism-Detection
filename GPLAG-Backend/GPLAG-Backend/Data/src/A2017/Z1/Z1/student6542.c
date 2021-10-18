#include <stdio.h>

int main() {
	char T,B,M,novired;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &novired);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &novired);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &novired);
	
	double pizza1=6.80,pizza2=8.00,pizza3=5.30,hamburger1=3.30,hamburger2=3.00,hamburger3=5.00,cevapi1=5.00,cevapi2=3.90,cevapi3=6.00;
	double restoran=0,trovac=0,lorelei=0,popust=0;

	if(T=='P' && B=='P' && M=='P'){
		restoran=3*pizza1;
		popust=3*pizza1-3*pizza1/10;
		trovac=3*pizza2;
		lorelei=3*pizza3;
	} 
	if(T=='H' && B=='H' && M=='H'){
		restoran=3*hamburger1;
		popust=3*hamburger1-3*hamburger1/10;
		trovac=3*hamburger2;
		lorelei=3*hamburger3;
	} 
	if(T=='C' && B=='C' && M=='C'){
		restoran=3*cevapi1;
		popust=3*cevapi1-3*cevapi1/10;
		trovac=3*cevapi2;
		lorelei=3*cevapi3;
	} 
	if((T=='P' && B=='P' && M=='C')||(T=='P' && B=='C' && M=='P')||(T=='C' && B=='P' && M=='P')){
		restoran=2*pizza1+cevapi1;
		if(2*pizza1>cevapi1) popust=2*pizza1-2*pizza1/10+cevapi1;
		else popust=2*pizza1+cevapi1-cevapi1/10;
		trovac=2*pizza2+cevapi2;
		lorelei=2*pizza3+cevapi3;
	}
	if((T=='P' && B=='P' && M=='H')||(T=='P' && B=='H' && M=='P')||(T=='H' && B=='P' && M=='P')){
		restoran=2*pizza1+hamburger1;
		if(2*pizza1>hamburger1) popust=2*pizza1-2*pizza1/10+hamburger1;
		else popust=2*pizza1+hamburger1-hamburger1/10;
		trovac=2*pizza2+hamburger2;
		lorelei=2*pizza3+hamburger3;
	}	
	if((T=='H' && B=='H' && M=='P')||(T=='P' && B=='H' && M=='H')||(T=='H' && B=='P' && M=='H')){
		restoran=2*hamburger1+pizza1;
		if (2*hamburger1>pizza1)  popust=pizza1+2*hamburger1-2*hamburger1/10;
		else popust=pizza1-pizza1/10+2*hamburger1;
		trovac=2*hamburger2+pizza2;
		lorelei=2*hamburger3+pizza3;
	}	
	if((T=='H' && B=='H' && M=='C')||(T=='C' && B=='H' && M=='H')||(T=='H' && B=='C' && M=='H')){
		restoran=2*hamburger1+cevapi1;
		if (2*hamburger1>cevapi1)  popust=cevapi1+2*hamburger1-2*hamburger1/10;
		else popust=cevapi1-cevapi1/10+2*hamburger1;
		trovac=2*hamburger2+cevapi2;
		lorelei=2*hamburger3+cevapi3;
	}
	if((T=='C' && B=='C' && M=='P')||(T=='P' && B=='C' && M=='C')||(T=='C' && B=='P' && M=='C')){
		restoran=2*cevapi1+pizza1;
		if(2*cevapi1>pizza1) popust=2*cevapi1-2*cevapi1/10+pizza1;
		else popust=2*cevapi1+pizza1-pizza1/10;
		trovac=2*cevapi2+pizza2;
		lorelei=2*cevapi3+pizza3;
	}
	if((T=='C' && B=='C' && M=='H')||(T=='H' && B=='C' && M=='C')||(T=='C' && B=='H' && M=='C')){
		restoran=2*cevapi1+hamburger1;
		if(2*cevapi1>hamburger1) popust=2*cevapi1-2*cevapi1/10+hamburger1;
		else popust=2*cevapi1+hamburger1-hamburger1/10;
		trovac=2*cevapi2+hamburger2;
		lorelei=2*cevapi3+hamburger3;
	}
	if((T=='P' && B=='H' && M=='C') || (T=='P' && B=='C' && M=='H') || (T=='H' && B=='P' && M=='C') || (T=='H' && B=='C' && M=='P') || (T=='C' && B=='H' && M=='P') || (T=='C' && B=='P' && M=='H')){
		restoran=pizza1+hamburger1+cevapi1;
		trovac=pizza2+hamburger2+cevapi2;
		lorelei=pizza3+hamburger3+cevapi3;
		if (pizza1>hamburger1 && pizza1>cevapi1) popust=pizza1-pizza1/10+hamburger1+cevapi1;
		if (cevapi1>hamburger1 && cevapi1>pizza1) popust=pizza1+cevapi1-cevapi1/10+hamburger1;
		if (hamburger1>pizza1 && hamburger1>cevapi1) popust=pizza1+hamburger1-hamburger1/10+cevapi1;
	}
	if(restoran<trovac && restoran<lorelei){
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", restoran);
	}
	else if(trovac<restoran && trovac<lorelei){
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", trovac);
		if (popust<trovac) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	else if(lorelei<restoran && lorelei<trovac){
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", lorelei);
		if (popust<lorelei) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	return 0;
}
