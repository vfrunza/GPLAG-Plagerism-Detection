#include <stdio.h>

int main() {
	double z1, z2, z3, p1, p2, p3, pp1, pp2, pp3, dp1, dp2, dp3, u1, u2, u3, ub1, ub2, ub3, o1, o2, o3;
	printf ("Unesite bodove za Tarika: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &pp1);
	if (pp1<0 || pp1>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &dp1);
	if (dp1<0 || dp1>20){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf", &p1);
	if (p1<0 || p1>10){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf", &z1);
	if (z1<0 || z1>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &u1);
	if (u1<0 || u1>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Unesite bodove za Bojana: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &pp2);
	if (pp2<0 || pp2>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &dp2);
	if (dp2<0 || dp2>20){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf", &p2);
	if (p2<0 || p2>10){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf", &z2);
	if (z2<0 || z2>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &u2);
	if (u2<0 || u2>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	printf ("Unesite bodove za Mirzu: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &pp3);
	if (pp3<0 || pp3>20) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &dp3);
	if (dp3<0 || dp3>20){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Prisustvo: ");
	scanf ("%lf", &p3);
	if (p3<0 || p3>10){
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zadace: ");
	scanf ("%lf", &z3);
	if (z3<0 || z3>10) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &u3);
	if (u3<0 || u3>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	
	ub1=p1+pp1+dp1+z1+u1;
	if (ub1>=55 && ub1<65){
		o1=6;
	}
	else if (ub1>=65 && ub1<75){
		o1=7;
	}
	else if (ub1>=75 && ub1<85){
		o1=8;
	}
	else if (ub1>=85 && ub1<92){
		o1=9;
	}
	else if (ub1>=92 && ub1<=100){
		o1=10;
	}
	ub2=p2+pp2+dp2+z2+u2;
		if (ub2>=55 && ub2<65){
		o2=6;
	}
	else if (ub2>=65 && ub2<75){
		o2=7;
	}
	else if (ub2>=75 && ub2<85){
		o2=8;
	}
	else if (ub2>=85 && ub2<92){
		o2=9;
	}
	else if (ub2>=92 && ub2<=100){
		o2=10;
	}
	ub3=p3+pp3+dp3+z3+u3;
		if (ub3>=55 && ub3<65){
		o3=6;
	}
	else if (ub3>=65 && ub3<75){
		o3=7;
	}
	else if (ub3>=75 && ub3<85){
		o3=8;
	}
	else if (ub3>=85 && ub3<92){
		o3=9;
	}
	else if (ub3>=92 && ub3<=100){
		o3=10;
	}
	
	
	if (ub1>=55 && ub2>=55 && ub3>=55) {
		printf ("Sva tri studenta su polozila.");
		if (o1==o2 && o1==o3 && o2==o3) {
			printf ("\nSva tri studenta imaju istu ocjenu.");
		}
		else if (o1!=o2 && o1!=o3 && o2!=o3) {
			printf ("\nSvaki student ima razlicitu ocjenu.");
		}
		else if ((o1==o2 && o1!=o3 && o2!=o3) || (o1==o3 && o1!=o2 && o3!=o2) || (o2==o3 && o2!=o1 && o3!=o1)){
			printf ("\nDva od tri studenta imaju istu ocjenu.");
		}
	}
	else if ((ub1<55 && ub2>=55 && ub3>=55) || (ub1>=55 && ub2<55 && ub3>=55) || (ub1>=55 && ub2>=55 && ub3<55)) {
		printf ("Dva studenta su polozila.");
	}
	else if ((ub1>=55 && ub2<55 && ub3<55) || (ub1<55 && ub2>=55 && ub3<55) || (ub1<55 && ub2<55 && ub3>=55)) {
		printf ("Jedan student je polozio.");
	}
	else if (ub1<55 && ub2<55 && ub3<55) {
		printf ("Nijedan student nije polozio.");
	}
	
		return 0;
}
