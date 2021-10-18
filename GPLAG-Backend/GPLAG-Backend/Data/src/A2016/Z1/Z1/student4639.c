#include <stdio.h>
#include <math.h>
#define eps 1e-5
int main() {
	double I1,I2,I3,II1,II2,II3,z1,z2,z3,P1,P2,P3,Z1,Z2,Z3,U1,U2,U3;
	double O1,O2,O3;
	printf ("Unesite bodove za Tarika: ");
	printf ("\nI parcijalni ispit: "); scanf ("%lf",&I1); if (I1<0 || I1>20) { printf ("Neispravan broj bodova"); return 0; }
	printf ("II parcijalni ispit: "); scanf ("%lf",&II1); if (II1<0 || II1>20) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Prisustvo: "); scanf ("%lf",&P1); if (P1<0 || P1>10) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Zadace: "); scanf ("%lf",&z1); if (z1<0 || z1>10) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Zavrsni ispit: "); scanf ("%lf",&Z1); if (Z1<0 || Z1>40) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Unesite bodove za Bojana: ");
	printf ("\nI parcijalni ispit: "); scanf ("%lf",&I2); if (I2<0 || I2>20) { printf ("Neispravan broj bodova"); return 0; }
	printf ("II parcijalni ispit: "); scanf ("%lf",&II2); if (II2<0 || II2>20) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Prisustvo: "); scanf ("%lf",&P2); if (P2<0 || P2>10) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Zadace: "); scanf ("%lf",&z2); if (z2<0 || z2>10) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Zavrsni ispit: "); scanf ("%lf",&Z2); if (Z2<0 || Z2>40) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Unesite bodove za Mirzu: ");
	printf ("\nI parcijalni ispit: "); scanf ("%lf",&I3); if (I3<0 || I3>20) { printf ("Neispravan broj bodova"); return 0; }
	printf ("II parcijalni ispit: "); scanf ("%lf",&II3); if (II3<0 || II3>20) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Prisustvo: "); scanf ("%lf",&P3); if (P3<0 || P3>10) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Zadace: "); scanf ("%lf",&z3); if (z3<0 || z3>10) { printf ("Neispravan broj bodova"); return 0; }
	printf ("Zavrsni ispit: "); scanf ("%lf",&Z3); if (Z3<0 || Z3>40) { printf ("Neispravan broj bodova"); return 0; }
		U1=I1+II1+P1+z1+Z1;
		U2=I2+II2+P2+z2+Z2;
		U3=I3+II3+P3+z3+Z3;
	if (U1<55)  O1=5;
	if (U1>=55 && U1<65) O1=6;
	if (U1>=65 && U1<75) O1=7;
	if (U1>=75 && U1<85) O1=8;
	if (U1>=85 && U1<92) O1=9;
	if (U1>=92) O1=10;
	if (U2<55)	O2=5;
	if (U2>=55 && U2<65) O2=6;
	if (U2>=65 && U2<75) O2=7;
	if (U2>=75 && U2<85) O2=8;
	if (U2>=85 && U2<92) O2=9;
	if (U2>=92) O2=10;
	if (U3<55)	O3=5;
	if (U3>=55 && U3<65) O3=6;
	if (U3>=65 && U3<75) O3=7;
	if (U3>=75 && U3<85) O3=8;
	if (U3>=85 && U3<92) O3=9;
	if (U3>=92) O3=10;
	if (O1==5 && O2==5 && O3==5) printf ("Nijedan student nije polozio.");
	else {
		if ((O1==5 && O2==5 && O3!=5)||(O1!=5 && O2==5 && O3==5)||(O1==5 && O2!=5 && O3==5)) printf ("Jedan student je polozio.");
		if ((O1==5 && O2!=5 && O3!=5)||(O1!=5 && O2==5 && O3!=5)||(O1!=5 && O2!=5 && O3==5)) printf ("Dva studenta su polozila.");
	}
	if (O1!=5 && O2!=5 && O3!=5) {
		printf ("Sva tri studenta su polozila.");
		if (O1==O2 && O1==O3) printf ("\nSva tri studenta imaju istu ocjenu.");
		if (O1!=O2 && O1!=O3 && O2!=O3) printf ("\nSvaki student ima razlicitu ocjenu.");
		if ((O1==O2 && O1!=O3)||(O1==O3 && O2!=O3)||(O2==O3 && O1!=O2)) printf ("\nDva od tri studenta imaju istu ocjenu.");
	}
	return 0;
}
