#include <stdio.h>

int main() {
	double p11,p21,pr1,dz1,zi1,p12,p22,pr2,dz2,zi2,p13,p23,pr3,dz3,zi3,T,M,B,o1,o2,o3;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
    scanf("%lf", &p11);
	if(p11<0 || p11>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &p21);
	if(p21<0 || p21>20) {
		printf("Neispravan broj bodova");
		return 0;}
	printf("Prisustvo: ");
   scanf("%lf", &pr1);
	if(pr1<0 || pr1>10) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Zadace: ");
	scanf("%lf", &dz1);
	if(dz1<0 || dz1>10) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Zavrsni ispit: ");
	scanf("%lf", &zi1);
	if(zi1<0 || zi1>40) {
		printf("Neispravan broj bodova");
		return 0;}
			printf("Unesite bodove za Bojana: ");
			printf("\nI parcijalni ispit: ");
		scanf("%lf", &p12);
	if(p12<0 || p12>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &p22);
	if(p22<0 || p22>20) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Prisustvo: ");
    scanf("%lf", &pr2);
	if(pr2<0 || pr2>10) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Zadace: ");
	scanf("%lf", &dz2);
	if(dz2<0 || dz2>10) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Zavrsni ispit: ");
	scanf("%lf", &zi2);
	if(zi2<0 || zi2>40) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Unesite bodove za Mirzu: ");
		printf("\nI parcijalni ispit: ");
		scanf("%lf", &p13);
	if(p13<0 || p13>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
scanf("%lf", &p23);
	if(p23<0 || p23>20) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Prisustvo: ");
    scanf("%lf", &pr3);
	if(pr3<0 || pr3>10) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Zadace: ");
	scanf("%lf", &dz3);
	if(dz3<0 || dz3>10) {
		printf("Neispravan broj bodova");
		return 0;}
		printf("Zavrsni ispit: ");
	scanf("%lf", &zi3);
	if(zi3<0 || zi3>40) {
		printf("Neispravan broj bodova");
		return 0;}
	T=p11+p21+dz1+zi1+pr1;
	B=p12+p22+dz2+zi2+pr2;
	M=p13+p23+dz3+zi3+pr3;
	if(T<55){
		o1=5;
	}
	else if(T>=55 && T<65) {
		o1=6;
	}
	else if(T>=65 && T<75){
		o2=7;
	}
	else if(T>=75 && T<85){
		o1=8;
	}
	else if(T>=85 && T<92){
		o1=9;
	}
	else if(T>=92 && T<=100){
		o1=10;
	}
	if(B<55){
		o2=5;
	}
	else if(B>=55 && B<65) {
		o2=6;
	}
	else if(B>=65 && B<75){
		o2=7;
	}
	else if(B>=75 && B<85){
		o2=8;
	}
	else if(B>=85 && B<92){
		o2=9;
	}
	else if(B=92 && B<=100){
		o2=10;
	}
	if(M<55){
		o3=5;;
	}
	else if(M>=55 && M<65) {
		o3=6;
	}
	else if(M>=65 && M<75){
		o3=7;
	}
	else if(M>=75 && M<85){
		o3=8;
	}
	else if(M>=85 && M<92){
		o3=9;
	}
	else if(M>=92 && M<=100){
	    o3=10;
	}
	if(T<55 && M<55 && B<55){
		printf("Nijedan student nije polozio. ");
	}
	 else if(T>=55 && M>=55 && B>=55){
	 	printf("Sva tri studenta su polozila. ");
	 	if(o1==o2 && o2==o3){
	 		printf("\nSva tri studenta imaju istu ocjenu.");
	 	}
	 	else if(o1==o2 || o2==o3 || o1==o3){
	 		printf("\nDva od tri studenta imaju istu ocjenu.");
	 	}
	 	else {printf("\nSvaki student ima razlicitu ocjenu.");
	 	
	 	}}
	 else if((T>=55 && B>=55) || (T>=55 && M>=55) || (M>=55 && B>=55)){
	 	printf("Dva studenta su polozila.");
	 }
	 else if(T>=55 || B>=55 || M>=55){
	 	printf("Jedan student je polozio. ");
	 }
	 
	return 0;
}


