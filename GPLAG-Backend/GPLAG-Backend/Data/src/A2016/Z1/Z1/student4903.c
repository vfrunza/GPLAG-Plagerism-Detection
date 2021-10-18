#include <stdio.h>
/*
#include<math.h>
#define epsilon 0.000*/

double a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, e1, e2, e3, suma1, suma2, suma3, bodovi;
int prolaz1, prolaz2, prolaz3, ocjena1, ocjena2, ocjena3;
int main() {
	printf("Unesite bodove za Tarika: \nI parcijalni ispit:");
	scanf("%lf", &a1);
	if(a1<0 || a1>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" II parcijalni ispit:");
	scanf("%lf", &b1);
	if(b1<0 || b1>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Prisustvo:");
	scanf("%lf", &c1);
	if(c1<0 || c1>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zadace:");
	scanf("%lf", &d1);

	if(d1<0 || d1>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zavrsni ispit:");
	scanf("%lf", &e1);
	if(e1<0 || e1>40) {printf(" Neispravan broj bodova"); return 0;}
	
	
	
	printf(" Unesite bodove za Bojana: \nI parcijalni ispit:");
	scanf("%lf", &a2);
	if(a2<0 || a2>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" II parcijalni ispit:");
	scanf("%lf", &b2);
	if(b2<0 ||  b2>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Prisustvo:");
	scanf("%lf", &c2);
	if(c2<0 ||  c2>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zadace:");
	scanf("%lf", &d2);
	if(d2<0 ||  d2>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zavrsni ispit:");
	scanf("%lf", &e2);
	if(e2<0 ||  e2>40) {printf(" Neispravan broj bodova"); return 0;}
	
	printf(" Unesite bodove za Mirzu: \nI parcijalni ispit:");
	scanf("%lf", &a3);
	if(a3<0 ||  a3>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" II parcijalni ispit:");
	scanf("%lf", &b3);
	if(b3<0 ||  b3>20) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Prisustvo:");
	scanf("%lf", &c3);
	if(c3<0 ||  c3>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zadace:");
	scanf("%lf", &d3);
	if(d3<0 ||  d3>10) {printf(" Neispravan broj bodova"); return 0;}
	printf(" Zavrsni ispit:");
	scanf("%lf", &e3);
	if(e3<0 ||  e3>40) {printf(" Neispravan broj bodova"); return 0;}
	
	suma1=a1+b1+c1+d1+e1; 
	suma2=a2+b2+c2+d2+e2;
	suma3=a3+b3+c3+d3+e3;
	
	
	bodovi=suma1;
	
	if(bodovi<55){ prolaz1=0; ocjena1=5;}
	else if(bodovi>=55 && bodovi<65) {prolaz1=1; ocjena1=6;}
	else if(bodovi>=65 && bodovi<75) {prolaz1=1; ocjena1=7;}
	else if(bodovi>=75 && bodovi<85) {prolaz1=1; ocjena1=8;}
	else if(bodovi>=85 && bodovi<92) {prolaz1=1; ocjena1=9;}
	else{prolaz1=1; ocjena1=10;}
	
	bodovi=suma2;
	if(bodovi<55){ prolaz2=0; ocjena2=5;}
	else if(bodovi>=55 && bodovi<65) {prolaz2=1; ocjena2=6;}
	else if(bodovi>=65 && bodovi<75) {prolaz2=1; ocjena2=7;}
	else if(bodovi>=75 && bodovi<85) {prolaz2=1; ocjena2=8;}
	else if(bodovi>=85 && bodovi<92) {prolaz2=1; ocjena2=9;}
	else{prolaz2=1; ocjena2=10;}
	
	bodovi=suma3;
	if(bodovi<55){ prolaz3=0; ocjena3=5;}
	else if(bodovi>=55 && bodovi<65) {prolaz3=1; ocjena3=6;}
	else if(bodovi>=65 && bodovi<75) {prolaz3=1; ocjena3=7;}
	else if(bodovi>=75 && bodovi<85) {prolaz3=1; ocjena3=8;}
	else if(bodovi>=85 && bodovi<92) {prolaz3=1; ocjena3=9;}
	else{prolaz3=1; ocjena3=10;}
	
	if(prolaz1==0 && prolaz2==0 && prolaz3==0) printf(" Nijedan student nije polozio.\n");
	else if(prolaz1==1 && prolaz2==1 && prolaz3==1){ printf(" Sva tri studenta su polozila.\n");
			if(ocjena1==ocjena2 && ocjena1==ocjena3) printf("Sva tri studenta imaju istu ocjenu.");
			else if(ocjena1 != ocjena2 && ocjena1!=ocjena3 && ocjena2 !=ocjena3) printf("Svaki student ima razlicitu ocjenu.");
			else printf("Dva od tri studenta imaju istu ocjenu.");}
	
	else if((prolaz1==1 && prolaz2==0 && prolaz3==0) || (prolaz2==1 && prolaz1==0 && prolaz3==0) || (prolaz3==1 && prolaz2==0 && prolaz1==0)) printf(" Jedan student je polozio.\n");
	else printf(" Dva studenta su polozila.\n");
	
	

	
	return 0;
}

