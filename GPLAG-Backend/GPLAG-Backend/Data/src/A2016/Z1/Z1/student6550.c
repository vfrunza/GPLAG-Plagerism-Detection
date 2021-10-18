#include <stdio.h>
#include <math.h>
#define EPS 0.0001

int main() {
	float ispit1,ispit2,pr,zad,zavrsni,T,B,M;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f",&ispit1);
	if(ispit1<0 || ispit1>20) {
	   printf("Neispravan broj bodova"); 
	   return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &ispit2);
	if(ispit2<0 || ispit2>20){
	   printf("Neispravan broj bodova"); 
	   return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &pr);
	if(pr<0 || pr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &zad);
	if(zad<0 || zad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni);
	if(zavrsni<0 || zavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	T=ispit1+ispit2+pr+zad+zavrsni;
	if(T<54.99) T='5';
	else if(T>=55 && T<65) T='6';
	else if(T>=65 && T<75) T='7';
	else if(T>=75 && T<85 ) T='8';
	else if(T>=85 && T<92) T='9';
	else if(T>=92 && T<=100) T='10';
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f",&ispit1);
	if(ispit1<0 || ispit1>20) {
	   printf("Neispravan broj bodova"); 
	   return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &ispit2);
	if(ispit2<0 || ispit2>20){
	   printf("Neispravan broj bodova"); 
	   return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &pr);
	if(pr<0 || pr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &zad);
	if(zad<0 || zad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni);
		if(zavrsni<0 || zavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	B=ispit1+ispit2+pr+zad+zavrsni;
	if(B<54.99) B='5';
	else if(B>=55 && B<65) B='6';
	else if(B>=65 && B<75) B='7';
	else if(B>=75 && B<85 ) B='8';
	else if(B>=85 && B<92) B='9';
	else if(B>=92 && B<=100) B='10';
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%f",&ispit1);
	if(ispit1<0 || ispit1>20) {
	   printf("Neispravan broj bodova"); 
	   return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &ispit2);
	if(ispit2<0 || ispit2>20){
	   printf("Neispravan broj bodova"); 
	   return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &pr);
	if(pr<0 || pr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &zad);
	if(zad<0 || zad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni);
		if(zavrsni<0 || zavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	M=ispit1+ispit2+pr+zad+zavrsni;
	if(M<54.99) M='5';
	else if(M>=55 && M<65) M='6';
	else if(M>=65 && M<75) M='7';
	else if(M>=75 && M<85 ) M='8';
	else if(M>=85 && M<92) M='9';
	else if(M>=92 && M<=100) M='10';
	
	if(T=='5' && M=='5' && B=='5') printf("Nijedan student nije polozio.");
	else if((T=='5' && M=='5' && B!='5') || (T=='5' && B=='5' && M!='5') || (T!='5' && M=='5' && B=='5')) printf("Jedan student je polozio.");
	else if((T!='5'&& M!='5'&& B=='5') || (T!='5' && M=='5' && B!='5') || (T=='5' && M!='5' && B!='5')) printf("Dva studenta su polozila.");
	else if(T!='5' && M!='5'&& B!='5'){
		printf("Sva tri studenta su polozila.");
		if((fabs(T-M)<EPS) && (fabs(T-B)<EPS)) printf("\nSva tri studenta imaju istu ocjenu.");
		else if ((fabs(T-M)<EPS && T!=B && M!=B) || (fabs(T-B)<EPS && T!=M && B!=M) || (fabs(B-M)<EPS && T!=B && M!=T)) printf("\nDva od tri studenta imaju istu ocjenu.");
		else printf("\nSvaki student ima razlicitu ocjenu.");
		
	} 
	
	
	
	
	
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

