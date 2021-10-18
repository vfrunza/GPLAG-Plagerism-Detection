#include <stdio.h>

int main() {
	double BT, PIT1, PIT2, PT, DZT, ZIT,
	BB, PIB1, PIB2, PB, DZB, ZIB,
	BM, PIM1, PIM2, PM, DZM, ZIM;
	int OT, OB, OM;
	
	/* Unos podataka za Tarika */ 
	
	printf("Unesite bodove za Tarika: \n");
	
	printf("I parcijalni ispit: ");
	scanf("%lf", &PIT1);
	if(PIT1 < 0 || PIT1 > 20){
		printf("Neispravan broj bodova ");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &PIT2);
	if(PIT2 < 0 || PIT2 > 20){
		printf("Neispravan broj bodova ");
		return 0;
	}
		
	printf("Prisustvo: ");
	scanf("%lf", &PT);
	if(PT < 0 || PT > 10){
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("Zadace: ");
	scanf("%lf", &DZT);
	if(DZT < 0 || DZT > 10){
		printf("Neispravan broj bodova ");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT);
	if (ZIT < 0 || ZIT > 40) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	/* Ukupan broj bodova Tarik (BT) */
	
	
	BT=PIT1+PIT2+PT+DZT+ZIT;
	
	if(BT >= 55 && BT < 65) {
		OT=6;
	} else if(BT >= 65 && BT < 75) {
		OT=7;
	} else if(BT >= 75 && BT < 85){
		OT=8;
	} else if(BT >= 85 && BT < 92){
		OT=9;
	} else if(BT >= 92 && BT <= 100){
		OT=10;
	} 
	
	/*Unos podataka za Bojana*/
	
	printf("Unesite bodove za Bojana: \n");
	
	printf("I parcijalni ispit: ");
	scanf("%lf", &PIB1);
	if (PIB1 < 0 || PIB1 > 20) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &PIB2);
	if (PIB2 < 0 || PIB2 > 20) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("Prisustvo: ");
	scanf("%lf", &PB);
	if (PB < 0 || PB > 10) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("Zadace: ");
	scanf("%lf", &DZB);
	if (DZB < 0 || DZB > 10) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIB);
	if (ZIB < 0 || ZIB > 40) {
		printf("Neispravan broj bodova ");
		return 0;
	}
	
	/* Ukupan broj bodova Bojan (BB) */
	
	BB=PIB1+PIB2+PB+DZB+ZIB;
	

	if (BB >= 55 && BB < 65) {
		OB=6;
	} else if (BB >= 65 && BB < 75) {
		OB=7;
	} else if (BB >= 75 && BB < 85) {
		OB=8;
	} else if (BB >= 85 && BB < 92) {
		OB=9;
	} else if (BB >= 92 && BB <= 100) {
		OB=10;
	} 
	
	/* Unos podataka za Mirzu */
	
	printf("Unesite bodove za Mirzu: \n");
	
	printf("I parcijalni ispit: ");
	scanf("%lf", &PIM1);
	if(PIM1 < 0 || PIM1 > 20) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &PIM2);
	if(PIM2 < 0 || PIM2 > 20) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("Prisustvo: ");
	scanf("%lf", &PM);
	if (PM < 0 || PM > 10) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("Zadace: ");
	scanf("%lf", &DZM);
	if (DZM < 0 || DZM > 10) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIM);
	if (ZIM < 0 || ZIM > 40) {
		printf("Neispravan broj bodova ");
		return 0;
	} 
	
	/* Ukupan broj bodova za Mirznu (BM) */
	
	BM=PIM1+PIM2+PM+DZM+ZIM;
	
	if (BM >= 55 && BM < 65) {
		OM=6;
	} else if (BM >= 65 && BM < 75) {
		OM=7;
	} else if (BM >= 75 && BM < 85) {
		OM=8;
	} else if (BM >= 85 && BM < 92) {
		OM=9;
	} else if (BM >= 92 && BM <= 100) {
		OM=10;
	} 
	/* Broj studenata koji su polozili */
	
	if((BM < 55 && BB <55 && BT >= 55) || (BT < 55 && BM < 55 && BB >= 55) || (BT < 55 && BB < 55 && BM >= 55)) {
		printf("Jedan student je polozio. \n");
	} else if ((BT >= 55 && BB >= 55 && BM < 55) || (BB >= 55 && BM >= 55  && BT < 55) || (BM >= 55 && BT >= 55 && BB < 55)) {
		printf("Dva studenta su polozila. \n");
	} else if ((BM >= 55) && (BT >= 55) && (BB >= 55)) {
		printf("Sva tri studenta su polozila. \n");
	} else {
		printf("Nijedan student nije polozio. \n");
	}
	
	/* Koliko ima istih ili razicith ocjena */
	
	if (BT >= 55 && BT <= 100 && BB >= 55 && BB <= 100 && BM >= 55 && BM <= 100){	
		if ((BT < 65 && BB < 65 && BM < 65) || (BT >= 65 && BT < 75) && (BB >= 65 && BB < 75) && ( BM>= 65 && BM < 75) || (BT >= 75 && BT < 85) && (BB >= 75 && BB < 85) && (BM >= 75 && BM < 85) || (BM >= 85 && BM < 92) && (BB >= 85 && BB < 92) && (BM >= 85 && BM < 92) || BT >= 92 && BB >= 92 && BT >= 92){
			printf("Sva tri studenta imaju istu ocjenu. \n");
		}
		else if (( BT < 65 && BB < 65) || (BT >= 65 && BT < 75) && (BB >= 65 && BB < 75) || (BT >= 75 && BT < 85) && (BB >= 75 && BB < 85) || (BT >= 85 && BT < 92) && (BB >= 85 && BB < 92) || (BT >= 92 && BB >= 92)){
		printf("Dva od tri studenta imaju istu ocjenu. \n");
		}
		else if((BT < 65 && BM < 65) || (BT >= 65 && BT < 75) && (BM >= 65 && BM < 75) || (BT >= 75 && BT < 85) && (BM >= 75 && BM < 85) || (BT >= 85 && BT < 92) && (BM >= 85 && BM < 92) || (BT >= 92 && BM >= 92)){
		printf("Dva od tri studenta imaju istu ocjenu. \n");
		}
		else if((BM < 65 && BB < 65) || (BM >= 65 && BM < 75) && (BB >= 65 && BB < 75) || (BM >= 75 && BM < 85) && (BB >= 75 && BB < 85) || (BM >= 85 && BM < 92) && (BB >= 85 && BB < 92) || (BM >= 92 && BB >= 92)){
		printf("Dva od tri studenta imaju istu ocjenu. \n");
		}  
		else {
		printf("Svaki student ima razlicitu ocjenu. \n");
	}}
	return 0;
}
