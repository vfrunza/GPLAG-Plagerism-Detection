#include <stdio.h>

int main() {
	double parc1st, parc2nd, prisustvo, zadace, zavrsni, sumTarik=0, sumBojan=0, sumMirza=0;
	int ocjenaTarik, ocjenaBojan, ocjenaMirza, brojacpol=0;
	/*Unos bodova za Tarika, eventualni prekid programa, suma bodova i dodjela odgovarajuce ocjene*/
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: "); scanf("%lf", &parc1st);
		if (parc1st<0 || parc1st>20){printf("Neispravan broj bodova"); return 0;}else{sumTarik+=parc1st;}
	printf("II parcijalni ispit: "); scanf("%lf", &parc2nd);
		if (parc2nd<0 || parc2nd>20){printf("Neispravan broj bodova"); return 0;}else{sumTarik+=parc2nd;}
	printf("Prisustvo: "); scanf("%lf", &prisustvo);
		if (prisustvo<0 || prisustvo>10){printf("Neispravan broj bodova"); return 0;}else{sumTarik+=prisustvo;}
	printf("Zadace: "); scanf("%lf", &zadace);
		if (zadace<0 || zadace>10){printf("Neispravan broj bodova"); return 0;}else{sumTarik+=zadace;}
	printf("Zavrsni ispit: "); scanf("%lf", &zavrsni);
		if (zavrsni<0 || zavrsni>40){printf("Neispravan broj bodova"); return 0;}else{sumTarik+=zavrsni;}
		
	if (sumTarik<55) ocjenaTarik=5;
	if (sumTarik>=55 && sumTarik<65) ocjenaTarik=6;
	if (sumTarik>=65 && sumTarik<75) ocjenaTarik=7;
	if (sumTarik>=75 && sumTarik<85) ocjenaTarik=8;
	if (sumTarik>=85 && sumTarik<92) ocjenaTarik=9;
	if (sumTarik>=92 && sumTarik<=100) ocjenaTarik=10;
	/*Unos bodova za Bojana, eventualni prekid programa, suma bodova i dodjela odgovarajuce ocjene*/
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: "); scanf("%lf", &parc1st);
		if (parc1st<0 || parc1st>20){printf("Neispravan broj bodova"); return 0;}else{sumBojan+=parc1st;}
	printf("II parcijalni ispit: "); scanf("%lf", &parc2nd);
		if (parc2nd<0 || parc2nd>20){printf("Neispravan broj bodova"); return 0;}else{sumBojan+=parc2nd;}
	printf("Prisustvo: "); scanf("%lf", &prisustvo);
		if (prisustvo<0 || prisustvo>10){printf("Neispravan broj bodova"); return 0;}else{sumBojan+=prisustvo;}
	printf("Zadace: "); scanf("%lf", &zadace);
		if (zadace<0 || zadace>10){printf("Neispravan broj bodova"); return 0;}else{sumBojan+=zadace;}
	printf("Zavrsni ispit: "); scanf("%lf", &zavrsni);
		if (zavrsni<0 || zavrsni>40){printf("Neispravan broj bodova"); return 0;}else{sumBojan+=zavrsni;}
	
	if (sumBojan<55) ocjenaBojan=5;
	if (sumBojan>=55 && sumBojan<65) ocjenaBojan=6;
	if (sumBojan>=65 && sumBojan<75) ocjenaBojan=7;
	if (sumBojan>=75 && sumBojan<85) ocjenaBojan=8;
	if (sumBojan>=85 && sumBojan<92) ocjenaBojan=9;
	if (sumBojan>=92 && sumBojan<=100) ocjenaBojan=10;
	/*Unos bodova za Mirzu, eventualni prekid programa, suma bodova i dodjela odgovarajuce ocjene*/
		
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: "); scanf("%lf", &parc1st);
		if (parc1st<0 || parc1st>20){printf("Neispravan broj bodova"); return 0;}else{sumMirza+=parc1st;}
	printf("II parcijalni ispit: "); scanf("%lf", &parc2nd);
		if (parc2nd<0 || parc2nd>20){printf("Neispravan broj bodova"); return 0;}else{sumMirza+=parc2nd;}
	printf("Prisustvo: "); scanf("%lf", &prisustvo);
		if (prisustvo<0 || prisustvo>10){printf("Neispravan broj bodova"); return 0;}else{sumMirza+=prisustvo;}
	printf("Zadace: "); scanf("%lf", &zadace);
		if (zadace<0 || zadace>10){printf("Neispravan broj bodova"); return 0;}else{sumMirza+=zadace;}
	printf("Zavrsni ispit: "); scanf("%lf", &zavrsni);
		if (zavrsni<0 || zavrsni>40){printf("Neispravan broj bodova"); return 0;}else{sumMirza+=zavrsni;}
		
		if (sumMirza<55) ocjenaMirza=5;
		if (sumMirza>=55 && sumMirza<65) ocjenaMirza=6;
		if (sumMirza>=65 && sumMirza<75) ocjenaMirza=7;
		if (sumMirza>=75 && sumMirza<85) ocjenaMirza=8;
		if (sumMirza>=85 && sumMirza<92) ocjenaMirza=9;
		if (sumMirza>=92 && sumMirza<=100) ocjenaMirza=10;
		/*Koliko je studenata polozilo i ako su sva tri polozila provjerimo koliko ih ima razlicite ocjene*/
		
	if (ocjenaTarik>5) brojacpol++; if (ocjenaBojan>5) brojacpol++; if (ocjenaMirza>5) brojacpol++;
	if (brojacpol==0) printf("Nijedan student nije polozio.");
	if (brojacpol==1) printf("Jedan student je polozio.");
	if (brojacpol==2) printf("Dva studenta su polozila.");
	if (brojacpol==3){ 
		printf("Sva tri studenta su polozila.");
		if (ocjenaTarik==ocjenaMirza && ocjenaTarik==ocjenaBojan){
			printf("\nSva tri studenta imaju istu ocjenu.");
		}else if (ocjenaTarik!=ocjenaMirza && ocjenaTarik!=ocjenaBojan && ocjenaMirza!=ocjenaBojan){
			printf("\nSvaki student ima razlicitu ocjenu.");
		}else{
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}
	}
	return 0;
}
