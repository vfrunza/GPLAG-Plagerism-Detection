#include <stdio.h>

int main() {
	float p1t, p2t, pst, zdt, zit, p1b, p2b, psb, zdb, zib, p1m, p2m, psm, zdm, zim, tuk, buk, muk, ot=0, ob=0, om=0;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: "); scanf("%f", &p1t);
	if (p1t<0 || p1t>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: "); scanf("%f", &p2t);
	if (p2t<0 || p2t>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: "); scanf("%f", &pst);
	if (pst<0 || pst>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: "); scanf("%f", &zdt);
	if (zdt<0 || zdt>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: "); scanf("%f", &zit);
	if (zit<0 || zit>40) {printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: "); scanf("%f", &p1b);
	if (p1b<0 || p1b>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: "); scanf("%f", &p2b);
	if (p2b<0 || p2b>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: "); scanf("%f", &psb);
	if (psb<0 || psb>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: "); scanf("%f", &zdb);
	if (zdb<0 || zdb>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: "); scanf("%f", &zib);
	if (zib<0 || zib>40) {printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: "); scanf("%f", &p1m);
	if (p1m<0 || p1m>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: "); scanf("%f", &p2m);
	if (p2m<0 || p2m>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: "); scanf("%f", &psm);
	if (psm<0 || psm>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: "); scanf("%f", &zdm);
	if (zdm<0 || zdm>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: "); scanf("%f", &zim);
	if (zim<0 || zim>40) {printf("Neispravan broj bodova"); return 0;}
	
	tuk=p1t+p2t+pst+zdt+zit+0.001;
	buk=p1b+p2b+psb+zdb+zib+0.001;
	muk=p1m+p2m+psm+zdm+zim+0.001;
	
	if (tuk>=55 && tuk<65) ot=6;
	if (tuk>=65 && tuk<75) ot=7;
	if (tuk>=75 && tuk<85) ot=8;
	if (tuk>=85 && tuk<92) ot=9;
	if (tuk>=92 && tuk<=100) ot=10;
	
	if (buk>=55 && buk<65) ob=6;
	if (buk>=65 && buk<75) ob=7;
	if (buk>=75 && buk<85) ob=8;
	if (buk>=85 && buk<92) ob=9;
	if (buk>=92 && buk<=100) ob=10;
	
	if (muk>=55 && muk<65) om=6;
	if (muk>=65 && muk<75) om=7;
	if (muk>=75 && muk<85) om=8;
	if (muk>=85 && muk<92) om=9;
	if (muk>=92 && muk<=100) om=10;
	
	
	if (tuk>=55 && buk>=55 && muk>=55)
	{
		printf("Sva tri studenta su polozila.\n");
		if (ot==ob && ob==om) printf("Sva tri studenta imaju istu ocjenu.");
		else 
		{
			if (ot!=ob && ob!=om && ot!=om) printf("Svaki student ima razlicitu ocjenu.");
			else printf("Dva od tri studenta imaju istu ocjenu.");
		}
		return 0;
	}
	else
	{
		if ((tuk>=55 && buk<55 && muk<55) || (buk>=55 && tuk<55 && muk<55) || (muk>=55 && buk<55 && tuk<55))
		{
			printf("Jedan student je polozio.");
			return 0;
		}
		else
		{
			if (tuk<55 && buk<55 && muk<55)
			{
				printf("Nijedan student nije polozio.");
				return 0;
			}
			else
			{
				printf("Dva studenta su polozila.");
				return 0;
			}
		}
	}

	return 0;
}
