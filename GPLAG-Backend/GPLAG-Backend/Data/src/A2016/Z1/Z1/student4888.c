#include <stdio.h>

int main() {
	//printf("Zadaća 1, Zadatak 1");
	
	//Tarik
	
	float Tp1, Tp2, Tp, Tz, Tzi, Tu;
	int To;
	printf ("Unesite bodove za Tarika: ");
	printf ("\nI parcijalni ispit: ");
	scanf ("%f", &Tp1);
	if (Tp1>20 || Tp1<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &Tp2);
	if (Tp2>20 || Tp2<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%f", &Tp);
	if (Tp>10 || Tp<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%f", &Tz);
	if (Tz>10 || Tz<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &Tzi);
	if (Tzi>40 || Tzi<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	Tu = Tp1 + Tp2 + Tz + Tp + Tzi;
	if (Tu<55) To = 0;
	if (Tu>=55 && Tu<65) To = 6;
	if (Tu>=65 && Tu<75) To = 7;
	if (Tu>=75 && Tu<85) To = 8;
	if (Tu>=85 && Tu<92) To = 9;
	if (Tu>=92 && Tu<=100) To = 10;
	
//	printf("Tu %f", Tu);
//	printf ("To %d", To);
	//Bojan
	
	float Bp1, Bp2, Bp, Bz, Bzi, Bu;
	int Bo;
	printf ("Unesite bodove za Bojana: ");
	printf ("\nI parcijalni ispit: ");
	scanf ("%f", &Bp1);
	if (Bp1>20 || Bp1<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &Bp2);
	if (Bp2>20 || Bp2<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%f", &Bp);
	if (Bp>10 || Bp<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%f", &Bz);
	if (Bz>10 || Bz<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &Bzi);
	if (Bzi>40 || Bzi<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	Bu = Bp1 + Bp2 + Bz + Bp + Bzi;
	if (Bu<55) Bo = 0;
	if (Bu>=55 && Bu<65) Bo = 6;
	if (Bu>=65 && Bu<75) Bo = 7;
	if (Bu>=75 && Bu<85) Bo = 8;
	if (Bu>=85 && Bu<92) Bo = 9;
	if (Bu>=92 && Bu<=100) Bo = 10;
	
//	printf("Bu %f", Bu);
//	printf ("Bo %d", Bo);
	//Mirza
	
	float Mp1, Mp2, Mp, Mz, Mzi, Mu;
	int Mo;
	printf ("Unesite bodove za Mirzu: ");
	printf ("\nI parcijalni ispit: ");
	scanf ("%f", &Mp1);
	if (Mp1>20 || Mp1<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &Mp2);
	if (Mp2>20 || Mp2<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%f", &Mp);
	if (Mp>10 || Mp<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%f", &Mz);
	if (Mz>10 || Mz<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &Mzi);
	if (Mzi>40 || Mzi<0 ) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	Mu = Mp1 + Mp2 + Mz + Mp + Mzi;
	if (Mu<55) Mo = 0;
	if (Mu>=55 && Mu<65) Mo = 6;
	if (Mu>=65 && Mu<75) Mo = 7;
	if (Mu>=75 && Mu<85) Mo = 8;
	if (Mu>=85 && Mu<92) Mo = 9;
	if (Mu>=92 && Mu<=100) Mo = 10;
	
//	printf("Mu %f", Mu);
//	printf ("Mo %d", Mo);
	
	//ISPITIVANJE	int a;
/*	a=0;
	if (To>5 && Mo>5 && Bo>5) {
		printf ("Sva tri studenta su polozila. ");
		a = 1;
	}
	
	else if (To>5 && Mo>5 && Bo<6 || To>5 && Mo<6 && Bo>5 || To<6 && Mo>5 && Bo>5) printf ("Dva studenta su polozila. ");
	else if (To>5 && Mo<6 && Bo<6 || To<6 && Mo>5 && Bo<6 || To<6 && Mo<5 && Bo>5) printf ("Jedan student je polozio. ");
	else printf ("Nijedan student nije polozio. ");
	
	if (To>=6) {
		if (Bo>=6) {
			if (Mo>=6) {
				printf ("Sva tri studenta su polozila. ");
				a = 1;
			}
			else printf ("Dva studenta su polozila. ");
		}
		else printf ("Jedan student je polozio. ");
	}
	else printf ("Nijedan student nije polozio. "); 
	
	if (a) {
		if (To == Bo && To == Mo) printf ("\nSva tri studenta imaju istu ocjenu. ");
		if (To == Bo && Bo != Mo || Mo == To && Bo != To) printf ("\nDva od tri studenta imaju istu ocjenu. ");
		if (To != Bo && Mo != To) printf ("\nSvaki student ima razlicitu ocjenu. ");
	}
	*/
	
	int t=0;
	int b=0;
	int m=0;
	int s=0;
	
	if (To>5) t++;
	if (Bo>5) b++;
	if (Mo>5) m++;
	
	s = t+ b +m;
	
	if (s==0) printf ("Nijedan student nije polozio. ");
	if (s==1) printf ("Jedan student je polozio. ");
	if (s==2) printf ("Dva studenta su polozila. ");
	if (s==3) {
		printf ("Sva tri studenta su polozila. ");
		if (To == Bo && To == Mo) printf ("\nSva tri studenta imaju istu ocjenu. ");
		if (To == Bo && Bo != Mo || Mo == To && Bo != To) printf ("\nDva od tri studenta imaju istu ocjenu. ");
		if (To != Bo && Mo != To) printf ("\nSvaki student ima razlicitu ocjenu. ");
	}
	
	return 0;
}
