#include <stdio.h>

int main() 
{
	double I,II,Z,P,ZI,Ib,IIb,Zb,Pb,ZIb,Im,IIm,Zm,Pm,ZIm,ocjenaT,ocjenaB,ocjenaM,ocjM,ocjT,ocjB;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &I);
	if (I<0 || I>20){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &II);
	if(II<0 || II>20) {
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &P);
	if(P<0||P>10){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Z);
	if(Z<0||Z>10){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZI);
	if(ZI<0||ZI>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	ocjenaT=I+II+Z+P+ZI;
	
	if (ocjenaT>=55 && ocjenaT<65){
		ocjT= 6;
	}
	else if (ocjenaT>=65 && ocjenaT<75){
		ocjT= 7;
	}
	else if (ocjenaT>=75 && ocjenaT<85){
		ocjT= 8;
	}
	else if (ocjenaT>=85 && ocjenaT<92){
		ocjT= 9;
	}
	else if (ocjenaT>=92 && ocjenaT<=100){
		ocjT= 10;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &Ib);
	if(Ib<0 || Ib>20){
       printf("Neispravan broj bodova\n");
       return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIb);
	if (IIb<0||IIb>20){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Pb);
	if(Pb<0||Pb>10){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Zb);
	if(Zb<0||Zb>10){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIb);
	if(ZIb<0||ZIb>40){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	ocjenaB=Ib+IIb+Zb+Pb+ZIb;
	
    if (ocjenaB>=55 && ocjenaB<65){
		ocjB= 6;
	}
	else if (ocjenaB>=65 && ocjenaB<75){
		ocjB= 7;
	}
	else if (ocjenaB>=75 && ocjenaB<85){
		ocjB= 8;
	}
	else if (ocjenaB>=85 && ocjenaB<92){
		ocjB= 9;
	}
	else if (ocjenaB>=92 && ocjenaB<=100){
		ocjB= 10;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &Im);
	if(Im<0||Im>20){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIm);
	if(IIm<0||IIm>20){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Pm);
	if(Pm<0||Pm>10){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Zm);
	if(Zm<0||Zm>10){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIm);
	if(ZIm<0||ZIm>40){
		printf("Neispravan broj bodova\n");
		return 0;
	}
	ocjenaM=Im+IIm+Zm+Pm+ZIm;
	
	if (ocjenaM>=55 && ocjenaM<65){
		ocjM= 6;
	}
	else if (ocjenaM>=65 && ocjenaM<75){
		ocjM= 7;
	}
	else if (ocjenaM>=75 && ocjenaM<85){
		ocjM= 8;
	}
	else if (ocjenaM>=85 && ocjenaM<92){
		ocjM= 9;
	}
	else if (ocjenaM>=92 && ocjenaM<=100){
		ocjM= 10;
	}
	if((ocjenaT<55&&ocjenaM>=55&&ocjenaB>=55)||(ocjenaT>=55&&ocjenaM>=55&&ocjenaB<55)||(ocjenaT>=55&&ocjenaM<55&&ocjenaB>=55)){
		printf("Dva studenta su polozila.");
	}

	else if ((ocjenaT<55&&ocjenaM<55&&ocjenaB>=55)||(ocjenaT>=55&&ocjenaM<55&&ocjenaB<55)||(ocjenaT<55&&ocjenaM>=55&&ocjenaB<55)){
		printf("Jedan student je polozio.");
	}
	else if (ocjenaB<55&&ocjenaM<55&&ocjenaT<55){
		printf("Nijedan student nije polozio.");
	}
	else if (ocjenaT>=55&&ocjenaM>=55&&ocjenaB>=55){
		printf("Sva tri studenta su polozila.\n");
		
	if (ocjT==ocjB && ocjB==ocjM) {
		printf("Sva tri studenta imaju istu ocjenu.");}
	    
	    else if ((ocjT==ocjB && ocjB!=ocjM)||(ocjT!=ocjB && ocjB==ocjM)||(ocjT==ocjM && ocjM!=ocjB)){
		printf("Dva od tri studenta imaju istu ocjenu.");
     	}
    	else if (ocjT!=ocjM && ocjM!=ocjB){
		printf("Svaki student ima razlicitu ocjenu.");
    	}
	}
    	
	return 0;
}
