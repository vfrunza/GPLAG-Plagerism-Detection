#include <stdio.h>
int main() {
double prva_parc=0,druga_parc=0,prisustvo=0,zadace=0,zavrsni=0,s1=0;
int x1=0,x2=0,x3=0;
printf("Unesite bodove za Tarika: ");
printf("\nI parcijalni ispit: ");
scanf("%lf",&prva_parc);
if(prva_parc<0 || prva_parc>20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&druga_parc);
if(druga_parc<0 || druga_parc>20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prisustvo);
if(prisustvo<0 || prisustvo>10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%lf",&zadace);
if(zadace<0 || zadace >10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zavrsni);
if(zavrsni<0 || zavrsni>40) {
	printf("Neispravan broj bodova");
	return 0;
}
s1=prva_parc+druga_parc+prisustvo+zadace+zavrsni;
if(s1>=55 && s1<65)
x1=6;
else if(s1>=65 && s1<75)
x1=7;
else if(s1>=75 && s1<85)
x1=8;
else if(s1>=85 && s1<92)
x1=9;
else if(s1>=92 && s1<=100)
x1=10;
else x1=5;
s1=0;
printf("Unesite bodove za Bojana: ");
printf("\nI parcijalni ispit: ");
scanf("%lf",&prva_parc);
if(prva_parc<0 || prva_parc>20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&druga_parc);
if(druga_parc<0 || druga_parc>20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prisustvo);
if(prisustvo<0 || prisustvo>10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%lf",&zadace);
if(zadace<0 || zadace>10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zavrsni);
if(zavrsni<0 || zavrsni>40) {
	printf("Neispravan broj bodova");
	return 0;
}
s1=prva_parc+druga_parc+zavrsni+zadace+prisustvo;
if(s1>=55 && s1<65)
x2=6;
else if(s1>=65 && s1<75)
x2=7;
else if(s1>=75 && s1<85)
x2=8;
else if(s1>=85 && s1<92)
x2=9;
else if(s1>=92 && s1<=100)
x2=10;
else x2=5;
s1=0;
printf("Unesite bodove za Mirzu: ");
printf("\nI parcijalni ispit: ");
scanf("%lf",&prva_parc);
if(prva_parc<0 || prva_parc>20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&druga_parc);
if(druga_parc<0 || druga_parc>20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prisustvo);
if(prisustvo<0 || prisustvo>10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%lf",&zadace);
if(zadace<0 || zadace>10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zavrsni);
if(zavrsni<0 || zavrsni>40) {
	printf("Neispravan broj bodova");
	return 0;
}
s1=prva_parc+druga_parc+prisustvo+zadace+zavrsni;
if(s1>=55 && s1<65)
x3=6;
else if(s1>=65 && s1<75)
x3=7;
else if(s1>=75 && s1<85)
x3=8;
else if(s1>=85 && s1<92)
x3=9;
else if(s1>=92 && s1<=100)
x3=10;
else x3=5;
if(x1==5 && x2==5 && x3==5)
printf("Nijedan student nije polozio.");
else if((x1==5 && x2==5 && x3!=5) ||(x1==5 && x3==5 && x2!=5) ||(x2==5 && x3==5 && x1!=5))
printf("Jedan student je polozio.");
else if((x1!=5 && x2!=5 && x3==5) ||(x1!=5 && x3!=5 && x2==5) ||(x1==5 && x2!=5 && x3!=5))
printf("Dva studenta su polozila.");
else if(x1!=5 && x2!=5 && x3!=5) {
	if((x1==x2)&&(x2==x3)) {
		printf("Sva tri studenta su polozila.");
		printf("\nSva tri studenta imaju istu ocjenu.");
	}
	else if((x1==x2 && x1!=x3) ||(x1==x3 && x1!=x2) ||(x2==x3 && x2!=x1)){
	printf("Sva tri studenta su polozila.");
	printf("\nDva od tri studenta imaju istu ocjenu."); }
	else {
		printf("Sva tri studenta su polozila.");
		printf("\nSvaki student ima razlicitu ocjenu.");
	}
}
	return 0;
}
