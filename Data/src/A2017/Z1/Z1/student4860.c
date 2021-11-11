#include <stdio.h>
#include <math.h>


int main() {
	
	double tpp,tdp,tp,tzad,tzi,mpp,mdp,mp,mzad,mzi,bpp,bdp,bp,bzad,bzi,ocjena,ocjena2,ocjena3;
    int ocjena1,ocjena21,ocjena31;

	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &tpp);
	if (tpp<0 || tpp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &tdp);
	if (tdp<0 || tdp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if (tp<0 || tp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &tzad);
	if (tzad<0 || tzad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzi);
	if (tzi<0 || tzi>40){
     	printf("Neispravan broj bodova");
     	return 0;
	
	}

	else if  ((tpp>=0 && tpp<=20) && (tdp>=0 && tdp<=20) && (tp>=0 && tp<=10) && (tzad>=0 && tzad<=10) && (tzi>=0 && tzi<=40) ) {
	 	ocjena=tpp+tdp+tp+tzad+tzi;
	}
	if(ocjena<55){
	ocjena1=5;}
	else if(ocjena>=55 && ocjena<65){
	ocjena1=6;}
	else if(ocjena>=65 && ocjena<75){
	ocjena1=7;}
	else if(ocjena>=75 && ocjena<85){
	ocjena1=8;}
	else if(ocjena>=85 && ocjena<92){
	ocjena1=9;}
	else if(ocjena>=92 && ocjena<=100){
	ocjena1=10;}
	
	
	printf("Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &bpp);
	if (bpp<0 || bpp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bdp);
	if (bdp<0 || bdp>20) {
		printf("Neispravan broj bodova");
		return 0;
		
	}
	printf("Prisustvo: ");
	scanf("%lf", &bp);
		if (bp<0 || bp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &bzad);
	if (bzad<0 || bzad>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzi);
		if (bzi<0 || bzi>40){
     	printf("Neispravan broj bodova");
     	return 0;
	
	}

	
	else if  ((bpp>=0 && bpp<=20) && (bdp>=0 && bdp<=20) && (bp>=0 && bp<=10) && (bzad>=0 && bzad<=10) && (bzi>=0 && bzi<=40) ) {
	 	ocjena2=bpp+bdp+bp+bzad+bzi;
		
	}
	if(ocjena2<55 ){
	ocjena21=5;}
	else if(ocjena2>=55 && ocjena2<65){
	ocjena21=6;}
	else if(ocjena2>=65 && ocjena2<75){
	ocjena21=7;}
	else if(ocjena2>=75 && ocjena2<85){
	ocjena21=8;}
	else if(ocjena2>=85 && ocjena2<92){
	ocjena21=9;}
	else if(ocjena2>=92 && ocjena2<=100){
	ocjena21=10;}

   	
    printf("Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &mpp);
	if (mpp<0 || mpp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &mdp);
		if (mdp<0 || mdp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &mp);
		if (mp<0 || mp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &mzad);
	if (mzad<0 || mzad>10){
		printf("Neispravan broj bodova");
		return 0;
		
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mzi);
		if (mzi<0 || mzi>40){
     	printf("Neispravan broj bodova");
     	return 0;
		}

		
	else if  ((mpp>=0 && mpp<=20) && (mdp>=0 && mdp<=20) && (mp>=0 && mp<=10) && (mzad>=0 && mzad<=10) && (mzi>=0 && mzi<=40) ) {
	 	ocjena3=mpp+mdp+mp+mzad+mzi;
	}
	if(ocjena3<55 ){
	ocjena31=5;}
	else if(ocjena3>=55 && ocjena3<65){
	ocjena31=6;}
	else if(ocjena3>=65 && ocjena3<75){
	ocjena31=7;}
	else if(ocjena3>=75 && ocjena3<85){
	ocjena31=8;}
	else if(ocjena3>=85 && ocjena3<92){
	ocjena31=9;}
	else if(ocjena3>=92 && ocjena3<=100){
	ocjena31=10;}

if(ocjena1>=6 && ocjena21>=6 && ocjena31>=6)
printf("Sva tri studenta su polozila.");
else if(ocjena1>=6 && ocjena21>=6 && ocjena31<6)
printf("Dva studenta su polozila.");
else if(ocjena1<6 && ocjena21>=6 && ocjena31>=6)
printf("Dva studenta su polozila.");
else if(ocjena1>=6 && ocjena21<6 && ocjena31>=6)
printf("Dva studenta su polozila.");
else if(ocjena1<6 && ocjena21<6 && ocjena31>=6)
printf("Jedan student je polozio.");
else if(ocjena1>=6 && ocjena21<6 && ocjena31<6)
printf("Jedan student je polozio.");
else if(ocjena1<6 && ocjena21>=6 && ocjena31<6)
printf("Jedan student je polozio.");
else if(ocjena1<6 && ocjena21<6 && ocjena31<6)
printf("Nijedan student nije polozio.");

if(ocjena1==ocjena21 && ocjena21==ocjena31 && ocjena1>=6 && ocjena21>=6 && ocjena31>=6)
printf("\nSva tri studenta imaju istu ocjenu.");
else if(ocjena1==ocjena21 && ocjena21!=ocjena31 && ocjena1>=6 && ocjena21>=6 && ocjena31>=6)
printf("\nDva od tri studenta imaju istu ocjenu.");
else if(ocjena1==ocjena31 && ocjena21!=ocjena1 && ocjena1>=6 && ocjena21>=6 && ocjena31>=6)
printf("\nDva od tri studenta imaju istu ocjenu.");
else if(ocjena21==ocjena31 && ocjena21!=ocjena1 && ocjena1>=6 && ocjena21>=6 && ocjena31>=6)
printf("\nDva od tri studenta imaju istu ocjenu.");
else if(ocjena1!=ocjena21 && ocjena21!=ocjena31 && ocjena1!=ocjena31 && ocjena1>=6 && ocjena21>=6 && ocjena31>=6)
printf("\nSvaki student ima razlicitu ocjenu.");




	return 0;
}
