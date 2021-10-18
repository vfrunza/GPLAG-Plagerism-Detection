#include <stdio.h>

int main() {
	double IpT,IIpT, pT, zT, ziT, IpB, IIpB,pB,zB,ziB,IpM,IIpM,pM,zM,ziM;
	double sumaT=0.00, sumaB=0.00, sumaM=0.00;
	int ocjenaT=0, ocjenaB=0, ocjenaM=0;
	printf("Unesite bodove za Tarika:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf",&IpT);
	if (IpT>20 || IpT<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" II parcijalni ispit:");
	scanf ("%lf", &IIpT);
	if (IIpT>20 || IIpT<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Prisustvo:");
	scanf ("%lf",&pT);
	if (pT<0 || pT>10){printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zadace:");
	scanf ("%lf", &zT);
	if (zT>10 || zT<0) {printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zavrsni ispit:");
	scanf("%lf", &ziT);
	if (ziT<0 || ziT>40) {printf ( " Neispravan broj bodova ");
	return 0; }

	printf(" Unesite bodove za Bojana:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf",&IpB);
	if (IpB>20 || IpB<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" II parcijalni ispit:");
	scanf ("%lf", &IIpB);
	if (IIpB>20 || IIpB<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Prisustvo:");
	scanf ("%lf",&pB);
	if (pB<0 || pB>10){printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zadace:");
	scanf ("%lf", &zB);
	if (zB>10 || zB<0) {printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zavrsni ispit:");
	scanf("%lf", &ziB);
	if (ziB<0 || ziB>40) {printf ( " Neispravan broj bodova ");
	return 0; }
	
	printf(" Unesite bodove za Mirzu:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf",&IpM);
	if (IpM>20 || IpM<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" II parcijalni ispit:");
	scanf ("%lf", &IIpM);
	if (IIpM>20 || IIpM<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Prisustvo:");
	scanf ("%lf",&pM);
	if (pM<0 || pM>10){printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zadace:");
	scanf ("%lf", &zM);
	if (zM>10 || zM<0) {printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zavrsni ispit:");
	scanf("%lf", &ziM);
	if (ziM<0 || ziM>40) {printf ( " Neispravan broj bodova ");
	return 0; }
	
	sumaT=IpT+IIpT+pT+zT+ziT;
	sumaB=IpB+IIpB+pB+zB+ziB;
	sumaM=IpM+IIpM+pM+zM+ziM;
	
	{if (sumaT>=55 && sumaT<65) ocjenaT=6;
	else if (sumaT>=65 && sumaT<75) ocjenaT=7;
	else if (sumaT>=75 && sumaT<85) ocjenaT=8;
	else if (sumaT>=85 && sumaT<92) ocjenaT=9;
	else if (sumaT>=92 && sumaT<101) ocjenaT=10;}
	
	{if (sumaB>=55 && sumaB<65) ocjenaB=6;
	else if (sumaB>=65 && sumaB<75) ocjenaB=7;
	else if (sumaB>=75 && sumaB<85) ocjenaB=8;
	else if (sumaB>=85 && sumaB<92) ocjenaB=9;
	else if (sumaB>=92 && sumaB<101) ocjenaB=10;}
	
	{if (sumaM>=55 && sumaM<65) ocjenaM=6;
	else if (sumaM>=65 && sumaM<75) ocjenaM=7;
	else if (sumaM>=75 && sumaM<85) ocjenaM=8;
	else if (sumaM>=85 && sumaM<92) ocjenaM=9;
	else if (sumaM>=92 && sumaM<101) ocjenaM=10;}
	
	if (sumaT>=55 && sumaB<55 && sumaM>=55)
	printf (" Dva studenta su polozila.");
	else if (sumaT<55 && sumaB>=55 && sumaM>=55)
	printf (" Dva studenta su polozila.");
	else if (sumaT>=55 && sumaB>=55 && sumaM<55)
	printf (" Dva studenta su polozila.");
	else if (sumaT>=55 && sumaB<55 && sumaM<55)
	printf (" Jedan student je polozio.");
	else if (sumaT<55 && sumaB>=55 && sumaM<55)
	printf(" Jedan student je polozio.");
	else if (sumaT<55 && sumaB<55 && sumaM>=55)
	printf (" Jedan student je polozio.");
	else if (sumaT<55 && sumaB<55 && sumaM<55)
	printf (" Nijedan student nije polozio.");
	
	
	if (sumaT>54 && sumaB>54 && sumaM>54){
		printf (" Sva tri studenta su polozila.");
		if (ocjenaT==ocjenaB && ocjenaT==ocjenaM) printf ("\nSva tri studenta imaju istu ocjenu.");
		else if (ocjenaT==ocjenaB && ocjenaB!=ocjenaM) printf ("\nDva od tri studenta imaju istu ocjenu.");
		else if (ocjenaT!=ocjenaB && ocjenaB==ocjenaM) printf ("\nDva od tri studenta imaju istu ocjenu.");
		else printf ("\nSvaki student ima razlicitu ocjenu.");
	}
	return 0;
}
