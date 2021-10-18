#include <stdio.h>
int main () {
	double ipi, iipi, p, z, zi,sumaT, sumaB, sumaM, ocjenaT, ocjenaB, ocjenaM;
	printf ("Unesite bodove za Tarika: \n");	
	printf ("I parcijalni ispit: "); scanf ("%lf", &ipi); if (ipi<0.0 || ipi>20.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("II parcijalni ispit: "); scanf ("%lf", &iipi); if (iipi<0.0 || iipi>20.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Prisustvo: "); scanf ("%lf", &p); if (p<0.0 || p>10.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Zadace: "); scanf ("%lf", &z); if (z<0.0 || z>10.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Zavrsni ispit: "); scanf ("%lf", &zi); if (zi<0.0 || zi>40.0) {printf ("Neispravan broj bodova"); return 0; }
	
	
	
	sumaT=ipi+iipi+z+p+zi;

	 if (sumaT <65.0) ocjenaT=6;
	else if (sumaT <75.0) ocjenaT=7;
	else if (sumaT <85.0) ocjenaT=8;
	else if (sumaT <92.0) ocjenaT=9; 
	else if (sumaT <=100.0) ocjenaT=10;
	
	printf ("Unesite bodove za Bojana: \n");
	printf ("I parcijalni ispit: "); scanf ("%lf", &ipi); if (ipi<0.0 || ipi>20.0) {printf ("Neispravan broj bodova"); return 0;}
	printf ("II parcijalni ispit: "); scanf ("%lf", &iipi); if (iipi<0.0 || iipi>20.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Prisustvo: "); scanf ("%lf", &p); if (p<0.0 || p > 10.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Zadace: "); scanf ("%lf", &z); if (z<0.0 || z >10.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Zavrsni ispit: "); scanf ("%lf", &zi); if (zi<0.0 || zi>40.0) {printf ("Neispravan broj bodova"); return 0; }
	sumaB=ipi+iipi+z+p+zi;
	 if (sumaB<65.0) ocjenaB=6;
	else if (sumaB<75.0) ocjenaB=7;
	else if (sumaB<85.0) ocjenaB=8;
	else if (sumaB<92.0) ocjenaB=9;
	else if (sumaB<=100.0) ocjenaB=10;
	
	printf ("Unesite bodove za Mirzu: \n"); 
	printf ("I parcijalni ispit: "); scanf("%lf", &ipi); if (ipi<0.0 || ipi >20.0) {printf ("Neispravan broj bodova"); return 0; }
	printf  ("II parcijalni ispit: "); scanf("%lf", &iipi); if (iipi<0.0 || iipi >20.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Prisustvo: "); scanf("%lf", &p); if (p<0.0 || p>10.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Zadace: "); scanf("%lf", &z); if (z<0.0 || z>10.0) {printf ("Neispravan broj bodova"); return 0; }
	printf ("Zavrsni ispit: "); scanf ("%lf", &zi); if (zi<0.0 || zi>40.0) {printf("Neispravan broj bodova"); return 0; }
	sumaM=ipi+iipi+z+p+zi;
	 if (sumaM<65.0) ocjenaM=6;
	else if (sumaM<75.0) ocjenaM=7;
	else if (sumaM<85.0) ocjenaM=8;
	else if (sumaM<92.0) ocjenaM=9;
	else if (sumaM<=100.0) ocjenaM=10;
	
	if ( sumaM<55.0 && sumaB<55.0 && sumaT<55.0 ) {printf ("Nijedan student nije polozio."); return 0; }
	if ( ((sumaM<55.0 && sumaB<55.0 && sumaT>=55.0 ) || (sumaM<55.0 && sumaB>=55.0 && sumaT<55.0)) || ( sumaM>=55.0 && sumaB<55.0 && sumaT<55.0 ) ) {printf ("Jedan student je polozio."); return 0; }
	if ( sumaM<55.0 && sumaB>=55.0 && sumaT>=55.0 || sumaM>=55.0 && sumaB<55.0 && sumaT>=55.0 || sumaM>=55.0 && sumaB>=55.0 && sumaT<55.0) {printf ("Dva studenta su polozila."); return 0; }
	if ( sumaM>=55.0 && sumaB>=55.0 && sumaT>=55.0 ) {
		printf ("Sva tri studenta su polozila.\n");
		if (ocjenaM==ocjenaB && ocjenaT!=ocjenaM || ocjenaM==ocjenaT && ocjenaB!=ocjenaM || ocjenaT==ocjenaB && ocjenaM!=ocjenaB) {
			printf ("Dva od tri studenta imaju istu ocjenu.");
		}
		else if (ocjenaM==ocjenaB && ocjenaM==ocjenaT) {
			printf ("Sva tri studenta imaju istu ocjenu.");
		}
		else if (ocjenaM!=ocjenaT && ocjenaM!=ocjenaB) {
			printf ("Svaki student ima razlicitu ocjenu.");
		}
	}
			return 0;
}
