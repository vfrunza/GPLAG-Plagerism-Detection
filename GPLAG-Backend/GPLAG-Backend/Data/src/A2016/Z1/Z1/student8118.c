#include <stdio.h>

int main() {
	double P1, P2, PR, ZAD, ZI, UKT, UKM, UKB;
	int OCJENAM, OCJENAT, OCJENAB;
	
	printf ("Unesite bodove za Tarika:");
	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &P1);
	if (P1<0 || P1>20) { printf ("Neispravan broj bodova"); } else {
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &P2);
	if (P2<0 || P2>20) { printf ("Neispravan broj bodova"); } else {
	printf ("Prisustvo: ");
	scanf ("%lf", &PR);
	if (PR<0 || PR>10) { printf ("Neispravan broj bodova"); } else {
	printf ("Zadace: ");
	scanf ("%lf", &ZAD);
	if (ZAD<0 || ZAD>10) { printf ("Neispravan broj bodova"); } else {
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &ZI);
	if (ZI<0 || ZI>40) { printf ("Neispravan broj bodova"); }
		UKT=P1+P2+PR+ZAD+ZI;
	if ((P1<0 || P1>20) || (P2<0 || P2>20) || (PR<0 || PR>10) || (ZAD<0 || ZAD>10) || (ZI<0 || ZI>40))
	{ printf ("Neispravan broj bodova");}
     	if (UKT>=55 && UKT<65) OCJENAT=6; 
		if (UKT>=65 && UKT<75) OCJENAT=7;
		if (UKT>=75 && UKT<85) OCJENAT=8;
		if (UKT>=85 && UKT<92) OCJENAT=9;
		if (UKT>=92 && UKT<=100) OCJENAT=10; 
		
	printf ("Unesite bodove za Bojana:");
	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &P1);
	if (P1<0 || P1>20) { printf ("Neispravan broj bodova"); } else {
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &P2);
	if (P2<0 || P2>20) { printf ("Neispravan broj bodova"); } else { 
	printf ("Prisustvo: ");
	scanf ("%lf", &PR);
	if (PR<0 || PR>10) { printf ("Neispravan broj bodova"); } else {
	printf ("Zadace: ");
	scanf ("%lf", &ZAD);
	if (ZAD<0 || ZAD>10) { printf ("Neispravan broj bodova"); } else {
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &ZI);
	if (ZI<0 || ZI>40) { printf ("Neispravan broj bodova"); }
	UKB=P1+P2+PR+ZAD+ZI;
	if ((P1<0 || P1>20) || (P2<0 || P2>20) || (PR<0 || PR>10) || (ZAD<0 || ZAD>10) || (ZI<0 || ZI>40))
		{ printf ("Neispravan broj bodova");	} 
  else if (UKB>=55 && UKB<65) OCJENAB=6;
		if (UKB>=65 && UKB<75) OCJENAB=7;
		if (UKB>=75 && UKB<85) OCJENAB=8;
		if (UKB>=85 && UKB<92) OCJENAB=9;
		if (UKB>=92 && UKB<=100) OCJENAB=10;
		
	printf ("Unesite bodove za Mirzu:");
	printf ("\nI parcijalni ispit: ");
	scanf ("%lf", &P1);
	if (P1<0 || P1>20) { printf ("Neispravan broj bodova"); } else {
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &P2);
	if (P2<0 || P2>20) { printf ("Neispravan broj bodova"); } else {
	printf ("Prisustvo: ");
	scanf ("%lf", &PR);
	if (PR<0 || PR>10) { printf ("Neispravan broj bodova"); } else {
	printf ("Zadace: ");
	scanf ("%lf", &ZAD);
	if (ZAD<0 || ZAD>10) { printf ("Neispravan broj bodova"); } else {
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &ZI);
	if (ZI<0 || ZI>40) { printf ("Neispravan broj bodova"); }
	UKM=P1+P2+PR+ZAD+ZI;
		if (UKM>=55 && UKM<65) OCJENAM=6;
		if (UKM>=65 && UKM<75) OCJENAM=7;
		if (UKM>=75 && UKM<85) OCJENAM=8;
		if (UKM>=85 && UKM<92) OCJENAM=9;
		if (UKM>=92 && UKM<=100) OCJENAM=10;
		
    if (UKM<55 && UKT<55 && UKB<55) 
	{ printf ("Nijedan student nije polozio."); }
	if ((UKM>=55 && UKT<55 && UKB<55) || (UKT>=55 && UKM<55 && UKB<55) || (UKB>=55 && UKM<55 && UKT<55)) 
	{ printf ("Jedan student je polozio."); }
	if ((UKM>=55 && UKT>=55 && UKB<55) || (UKM<55 && UKT>=55 && UKB>=55)||(UKM>=55 && UKT<55 && UKB>55))
	{ printf ("Dva studenta su polozila."); }
	if (UKM>=55 && UKT>=55 && UKB>=55)
	{ printf ("Sva tri studenta su polozila."); } 
	
   if (UKM<55 || UKT<55 || UKB<55); else {
   if (OCJENAT==OCJENAB && OCJENAB==OCJENAM) 
	{ printf ("\nSva tri studenta imaju istu ocjenu."); }
	else if ((OCJENAT==OCJENAM && OCJENAM!=OCJENAB) || (OCJENAB==OCJENAT && OCJENAM!=OCJENAT ) || (OCJENAB==OCJENAM && OCJENAT!=OCJENAM))
	{ printf ("\nDva od tri studenta imaju istu ocjenu."); }
	else if (OCJENAT!=OCJENAM && OCJENAT!=OCJENAM)
	{ printf ("\nSvaki student ima razlicitu ocjenu."); }
}}}}}}}}}}}}}
	return 0;
}
