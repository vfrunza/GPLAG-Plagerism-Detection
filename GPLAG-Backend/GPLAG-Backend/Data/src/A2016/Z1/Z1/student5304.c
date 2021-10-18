#include <stdio.h>

int main() {
	double pp1, pp2, pp3;
	double dp1, dp2, dp3;
	double p1, p2, p3;
	double z1, z2, z3;
	double zi1, zi2, zi3;
	double t, b, m;

	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &pp1);
	if(pp1<0 || pp1>20) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("II parcijalni ispit: ");
	scanf("%lf", &dp1);
	if(dp1<0 || dp1>20) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("Prisustvo: ");
	scanf("%lf", &p1);
	if(p1<0 || p1>10) {
		printf("Neispravan broj bodova");
		return 0;
	} else 
	printf("Zadace: ");
	scanf("%lf", &z1);
	if(z1<0 || z1>10) {
		printf("Neispravan broj bodova");
		return 0;
	} else 
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi1);
	if(zi1<0 || zi1>40) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &pp2);
	if(pp2<0 || pp2>20) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("II parcijalni ispit: ");
	scanf("%lf", &dp2);
	if(dp2<0 || dp2>20) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("Prisustvo: ");
	scanf("%lf", &p2);
	if(p2<0 || p2>10) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("Zadace: ");
	scanf("%lf", &z2);
	if(z2<0 || z2>10) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi2);
	if(zi2<0 || zi2>40) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &pp3);
	if(pp3<0 || pp3>20) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("II parcijalni ispit: ");
	scanf("%lf", &dp3);
	if(dp3<0 || dp3>20) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("Prisustvo: ");
	scanf("%lf", &p3);
	if(p3<0 || p3>10) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("Zadace: ");
	scanf("%lf", &z3);
	if(z3<0 || z3>10) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi3);
	if(zi3<0 || zi3>40) {
		printf("Neispravan broj bodova");
		return 0;
	} else
	
	t=pp1+dp1+p1+z1+zi1;
	b=pp2+dp2+p2+z2+zi2;
	m=pp3+dp3+p3+z3+zi3;
	
	
	if(t<55 && b<55 && m<55) {
		printf("Nijedan student nije polozio.");
	}
	if((t>=55 && b<55 && m<55) || (t<55 && b>=55 && m<55) || (t<55 && b<55 && m>=55)) {
		printf("Jedan student je polozio.");
	}
	if((t>=55 && b>=55 && m<55) || (t>=55 && b<55 && m>=55) || (t<55 && b>=55 && m>=55)) {
		printf("Dva studenta su polozila.");
	}
	if(t>=55 && b>=55 && m>=55) {
		printf("Sva tri studenta su polozila.");
	}
	
	
	if((t>=55 && t<65) && (b>=55 && b<65) && (m>=55 && m<65)) {
		printf("\nSva tri studenta imaju istu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=65 && b<75) && (m>=65 && m<75)) {
		printf("\nSva tri studenta imaju istu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=75 && b<85) && (m>=75 && m<85)) {
		printf("\nSva tri studenta imaju istu ocjenu.");
	} else 
	if((t>=85 && t<92) && (b>=85 && b<92) && (m>=85 && m<92)) {
		printf("\nSva tri studenta imaju istu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=92 && b<=100) && (m>=92 && m<=100)) {
		printf("\nSva tri studenta imaju istu ocjenu.");
	} else
	
	
	if((t>=55 && t<65) && (b>=55 && b<65) && m>=65) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else
	if((t>=55 && t<65) && (m>=55 && m<65) && b>=65) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((b>=55 && b<65) && (m>=55 && m<65) && t>=65) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=65 && b<75) && (m>=75 || (m>=55 && m<65))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((t>=65 && t<75) && (m>=65 && m<75) && (b>=75 || (b>=55 && b<65))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else
	if((m>=65 && m<75) && (b>=65 && b<75) && (t>=75 || (t>=55 && t<65))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((t>=75 && t<85) && (b>=75 && b<85) && (m>=85 || (m>=55 && m<75))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else
	if((t>=75 && t<85) && (m>=75 && m<85) && (b>=85 || (b>=55 && b<75))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((m>=75 && m<85) && (b>=75 && b<85) && (t>=85 || (t>=55 && t<75))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((t>=85 && t<92) && (b>=85 && b<92) && (m>=92 || (m>=55 && m<85))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else
	if((t>=85 && t<92) && (m>=85 && m<92) && (b>=92 || (b>=55 && b<85))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((m>=85 && m<92) && (b>=85 && b<92) && (t>=92 || (t>=55 && t<85))) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((t>=92 && t<=100) && (b>=92 && b<=100) && (m>=55 && m<92)) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((t>=92 && t<=100) && (m>=92 && m<=100) && (b>=55 && b<92)) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else 
	if((m>=92 && m<=100) && (b>=92 && b<=100) && (t>=55 && t<92)) {
		printf("\nDva od tri studenta imaju istu ocjenu.");
	}
	
	if((t>=55 && t<65) && (b>=65 && b<75) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=55 && t<65) && (b>=65 && b<75) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=55 && t<65) && (b>=65 && b<75) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=55 && t<65) && (b>=75 && b<85) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=55 && t<65) && (b>=75 && b<85) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=55 && t<65) && (b>=75 && b<85) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else 
	if((t>=55 && t<65) && (b>=85 && b<92) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else 
	if((t>=55 && t<65) && (b>=85 && b<92) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else 
	if((t>=55 && t<65) && (b>=85 && b<92) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else 
	if((t>=55 && t<65) && (b>=92 && b<=100) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else 
	if((t>=55 && t<65) && (b>=92 && b<=100) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else 
	if((t>=55 && t<65) && (b>=92 && b<=100) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else 
	if((t>=65 && t<75) && (b>=55 && b<65) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=55 && b<65) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=55 && b<65) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=75 && b<85) && (m>=55 && m<55)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=75 && b<85) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=75 && b<85) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=85 && b<92) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=85 && b<92) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=85 && b<92) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=92 && b<=100) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=92 && b<=100) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=65 && t<75) && (b>=92 && b<=100) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=55 && b<65) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=55 && b<65) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=55 && b<65) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=75 && b<85) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=75 && b<85) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=75 && b<85) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=85 && b<92) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=85 && b<92) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=85 && b<92) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=92 && b<=100) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=92 && b<=100) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=75 && t<85) && (b>=92 && b<=100) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=55 && b<65) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=55 && b<65) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=55 && b<65) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=65 && b<75) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=65 && b<75) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=65 && b<75) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=75 && b<85) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=75 && b<85) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=75 && b<85) && (m>=92 && m<=100)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=92 && b<=100) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=92 && b<=100) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=85 && t<92) && (b>=92 && b<=100) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=55 && b<65) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=55 && b<65) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=55 && b<65) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=65 && b<75) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=65 && b<75) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=65 && b<75) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=75 && b<85) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=75 && b<85) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=75 && b<85) && (m>=85 && m<92)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=85 && b<92) && (m>=55 && m<65)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=85 && b<92) && (m>=65 && m<75)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} else
	if((t>=92 && t<=100) && (b>=85 && b<92) && (m>=75 && m<85)) {
		printf("\nSvaki student ima razlicitu ocjenu.");
	} 

	return 0;
}
