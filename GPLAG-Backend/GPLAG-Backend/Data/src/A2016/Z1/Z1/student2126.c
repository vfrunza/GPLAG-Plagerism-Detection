#include <stdio.h>

int main() {
	double PPIT, DPIT, PT, ZT, ZIT, KBBT, PPIB, DPIB, PB, ZB, ZIB, KBBB, PPIM, DPIM, PM, ZM, ZIM, KBBM;
	
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &PPIT);
	if(PPIT<0 || PPIT>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &DPIT);
	if (DPIT<0 || DPIT>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &PT);
	if (PT<0 || PT>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &ZT);
	if (ZT<0 || ZT>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT);
	if (ZIT<0 || ZIT>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	KBBT=PPIT+DPIT+PT+ZT+ZIT;
	
	
	printf("Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &PPIB);
	if (PPIB<0 || PPIB>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &DPIB);
	if(DPIB<0 || DPIB>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &PB);
	if (PB<0 || PB>10){
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &ZB);
	if (ZB<0 || ZB>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIB);
	if (ZIB<0 || ZIB>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	KBBB=PPIB+DPIB+PB+ZB+ZIB;
	
	printf("Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &PPIM);
	if (PPIM<0 || PPIM>20){
		printf("Neispravan broj bodova");
		return 0;
	
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &DPIM);
	if (DPIM<0 || DPIM>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf", &PM);
	if(PM<0 || PM>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf", &ZM);
	if(ZM<0 || ZM>10){
		printf("Neispravan broj bodova");
		return 0;
	}

	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIM);
	if (ZIM<0 || ZIM>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	KBBM=PPIM+DPIM+PM+ZM+ZIM;
	
	if (KBBT<55 && KBBB<55 && KBBM<55)
	{
		printf("Nijedan student nije polozio.");
	}
	
	else if (((KBBT<55) && (KBBB<55) && (KBBM>=55)) || ((KBBT<55) && (KBBB>=55)&&(KBBM<55)) || ((KBBT>=55) && (KBBB<55) && (KBBM<55)))
	{
		printf("Jedan student je polozio.");
	
	}
	
	else if (((KBBT<55) && (KBBB>=55) && (KBBM>=55))|| ((KBBT>=55) && (KBBB<55)&&(KBBM>=55))||((KBBT>=55)&&(KBBB>=55)&&(KBBM<55)))
	{
	printf("Dva studenta su polozila.");

	}
	
	else if (((KBBT>=55 && KBBT<65) && (KBBB>=55 && KBBB<65) && (KBBM>=55 && KBBM<65))||((KBBT>=65 && KBBT<75) && (KBBB>=65 && KBBB<75) && (KBBM>=65 && KBBM<75))||((KBBT>=75 && KBBT<85) && (KBBB>=75 && KBBB<85) && (KBBM>=75 && KBBM<85))||((KBBT>=85 && KBBT<92) && (KBBB>=85 && KBBB<92) && (KBBM>=85 && KBBM<92))||((KBBT>=92 || KBBT<=100) && (KBBB>=92 && KBBB<=100) && (KBBM>=92 && KBBM<=100)))
	{
	printf("Sva tri studenta su polozila.");
	printf("\nSva tri studenta imaju istu ocjenu.");

	}
	
	
	else if ((((KBBT>=55 && KBBT<65) && (KBBB>=55 && KBBB<65) && (KBBM>=65 && KBBM<=100))||((KBBT>=65 && KBBT<75) && (KBBB>=65 && KBBB<75) && (KBBM>=55 && KBBM<65 && KBBM>=75 && KBBM<=100))||((KBBT>=75 && KBBT<85) && (KBBB>=75 && KBBB<85) && (KBBM>=55 && KBBM<75 && KBBM>=85 && KBBM<=100))||((KBBT>=85 && KBBT<92) && (KBBB>=85 && KBBB<92) && (KBBM>=55 && KBBM<85 && KBBM>=92 && KBBM<=100))||((KBBT>=92 && KBBT<=100) && (KBBB>=92 && KBBB<=100) && (KBBM>=55 && KBBM<92)))||(((KBBT>=65 && KBBT<=100) && (KBBB>=55 && KBBB<65) && (KBBM>=55 && KBBM<65))||((KBBT>=55 && KBBT<65 && KBBT>=75 && KBBT<=100) && (KBBB>=65 && KBBB<75) && (KBBM>=65 && KBBM<75))||((KBBT>=55 && KBBT<75 && KBBT>=85 && KBBT<=100) && (KBBB>=75 && KBBB<85) && (KBBM>=75 && KBBM<85))||((KBBT>=55 && KBBT<85 && KBBT>=92 && KBBT<=100) && (KBBB>=85 && KBBB<92) && (KBBM>=85 && KBBM<92))||((KBBT>=55 && KBBT<92) && (KBBB>=92 && KBBB<=100) && (KBBM>92 && KBBM<=100)))||(((KBBT>=55 && KBBT<65) && (KBBB>=65 && KBBB<=100) && (KBBM>=55 && KBBM<65))||((KBBT>=65 && KBBT<75) && (KBBB>=55 && KBBB<65 && KBBB>=75 && KBBB<=100) && (KBBM>=65 && KBBM<75))||((KBBT>=75 && KBBT<85) && (KBBB>=55 && KBBB<75 && KBBB>=85 && KBBB<=100) && (KBBM>=75 && KBBM<85))||((KBBT<85 && KBBT<92) && (KBBB>=55 && KBBB<85 && KBBB>=92 && KBBB<=100) && (KBBM>=85 && KBBM<92))||((KBBT>=92 && KBBT<=100) && (KBBB>=55 && KBBB<92) && (KBBM>=92 && KBBM<=100))))
	{
	printf("Sva tri studenta su polozila.");
	printf("\nDva od tri studenta imaju istu ocjenu.");

	}
	
	

	else if ((((KBBT>=55 && KBBT<65) && (KBBB>=65 && KBBB<=100) && (KBBM>=65 && KBBM<=100))||((KBBT>=65 && KBBT<75) && (KBBB>=55 && KBBB<65 && KBBB>=75 && KBBB<=100) && (KBBM>=55 && KBBM<65 && KBBM>=75 && KBBM<=100))||((KBBT>=75 && KBBT<85) && (KBBB>=55 && KBBB<75 && KBBB>=85 && KBBB<=100) && (KBBM>=55 && KBBM<75 && KBBM>=85 && KBBM<=100))||((KBBT>=85 && KBBT<92) && ( KBBB>=55 && KBBB<85 && KBBB>=92 && KBBB<=100) && (KBBM>=55 && KBBM<85 && KBBM>=92 && KBBM<=100))||((KBBT>=92 && KBBT<=100) && (KBBB>=55 && KBBB<92) && (KBBM>=55 && KBBM<92)))||(((KBBT>=65 && KBBT<=100) && (KBBB>=65 && KBBB<=100) && (KBBM>=55 && KBBM<65))||((KBBT>=55 && KBBT<65 && KBBT>=75 && KBBT<=100) && (KBBB>=55 && KBBB<65 && KBBB>=75 && KBBB<=100) && (KBBM>=65 && KBBM<75))||((KBBT>=55 && KBBT<75 && KBBT>=85 && KBBT<=100) && (KBBB>=55 && KBBB<75 && KBBB>=85 && KBBB<=100) && (KBBM>=75 && KBBM<85))||((KBBT>=55 && KBBT<85 && KBBT>=92 && KBBT<=100) && (KBBB>=55 && KBBB<85 && KBBB>=92 && KBBB<=100) && (KBBM>=85 && KBBM<92))||((KBBT>=55 && KBBT<92) && (KBBB>=55 && KBBB<92) && (KBBM>92 && KBBM<=100)))||(((KBBT>=65 && KBBT<=100) && (KBBB>=55 && KBBB<65) && (KBBM>=65 && KBBM<=100))||((KBBT>=55 && KBBT<65 && KBBT>=75 && KBBT<=100) && (KBBB>=65 && KBBB<75) && (KBBM>=55 && KBBM<65 && KBBM>=75 && KBBM<=100))||((KBBT>=55 && KBBT<75 && KBBT>=85 && KBBT<=100) && (KBBB>=75 && KBBB<85) && (KBBM>=55 && KBBM<75 && KBBM>=85 && KBBM<=100))||((KBBT>=55 && KBBT<85 && KBBT>=92 && KBBT<=100) && (KBBB>=85 && KBBB<92) && (KBBM>=55 && KBBM<85 && KBBM>=92 && KBBM<=100))||((KBBT>=55 && KBBT<92) && (KBBB>=92 && KBBB<=100) && (KBBM>=55 && KBBM<92))))
	{
	printf("Sva tri studenta su polozila.");
	printf("\nSvaki student ima razlicitu ocjenu.");
	}
	

	return 0;
}
