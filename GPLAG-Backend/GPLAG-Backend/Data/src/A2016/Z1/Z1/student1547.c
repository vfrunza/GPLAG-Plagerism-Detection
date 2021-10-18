#include <stdio.h>

int main() {
	double tp1, tp2, tz, tpr, tzav, mp1, mp2, mz, mpr, mzav, bp1, bp2, bz, bpr, bzav, to, mo, bo;
	double tb=0.00, mb=0.00, bb=0.00;
	
	printf("Unesite bodove za Tarika:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf",&tp1);
	if (tp1>20 || tp1<0){
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" II parcijalni ispit:");
	scanf ("%lf", &tp2);
		if (tp2>20 || tp2<0){
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" Prisustvo:");
	scanf ("%lf",&tpr);
		if (tpr<0 || tpr>10){
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" Zadace:");
	scanf ("%lf", &tz);
		if (tz>10 || tz<0) {
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" Zavrsni ispit:");
	scanf("%lf", &tzav);
		if (tzav<0 || tzav>40) {
			printf ( " Neispravan broj bodova ");
			return 0; }

	printf(" Unesite bodove za Bojana:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf",&bp1);
		if (bp1>20 || bp1<0){
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" II parcijalni ispit:");
	scanf ("%lf", &bp2);
		if (bp2>20 || bp2<0){
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" Prisustvo:");
	scanf ("%lf",&bpr);
		if (bpr<0 || bpr>10){
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" Zadace:");
	scanf ("%lf", &bz);
		if (bz>10 || bz<0) {
			printf ( " Neispravan broj bodova ");
			return 0; }
	printf (" Zavrsni ispit:");
	scanf("%lf", &bzav);
		if (bzav<0 || bzav>40) {
			printf ( " Neispravan broj bodova ");
			return 0; }
	
	printf(" Unesite bodove za Mirzu:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf",&mp1);
	if (mp1>20 || mp1<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" II parcijalni ispit:");
	scanf ("%lf", &mp2);
	if (mp2>20 || mp2<0){
	printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Prisustvo:");
	scanf ("%lf",&mpr);
	if (mpr<0 || mpr>10){printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zadace:");
	scanf ("%lf", &mz);
	if (mz>10 || mz<0) {printf ( " Neispravan broj bodova ");
	return 0; }
	printf (" Zavrsni ispit:");
	scanf("%lf", &mzav);
	if (mzav<0 || mzav>40) {printf ( " Neispravan broj bodova ");
	return 0; }

	tb = tp1+tp2+tz+tpr+tzav;
	mb = mp1+mp2+mz+mpr+mzav;
	bb = bp1+bp2+bz+bpr+bzav;
	
	to=0;
	mo=0;
	bo=0;
	
		if(tb<55 && mb<55 && bb<55)
			printf(" Nijedan student nije polozio.\n");
		else if (tb<55 && mb>=55 && bb>=55 || tb>=55 & mb<55 && bb>=55 || tb>=55 && mb>=55 && bb<55)
		    printf (" Dva studenta su polozila.\n");
		else if (tb>=55 && mb<55 && bb<55 || tb<55 && mb>=55 && bb<55 || tb<55 && mb<55 && bb>=55)
		    printf (" Jedan student je polozio.\n");
		else if (tb>=55 && mb>=55 && bb>=55)
		    {
		    	printf(" Sva tri studenta su polozila.\n");
		if (tb>=55 && tb<65)
		to=6;
		else if (tb>=65 && tb<75)
		to=7;
		else if (tb>=75 && tb<85)
		to=8;
		else if (tb>=85 && tb<92)
		to=9;
		else if (tb>=92 && tb<=100)
		to=10;
		if (mb>=55 && mb<65)
		mo=6;
		else if (mb>=65 && mb<75)
		mo=7;
		else if (mb>=75 && mb<85)
		mo=8;
		else if (mb>=85 && mb<92)
		mo=9;
		else if (mb>=92 && mb<100)
		mo=10;
		if (bb>=55 && bb<65)
		bo=6;
		else if (bb>=65 && bb<75)
		bo=7;
		else if (bb>=75 && bb<85)
		bo=8;
		else if (bb>=85 && bb<92)
		bo=9;
		else if (bb>=92 && bb<100)
		bo=10;
		if (to==mo && mo==bo)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if (to==mo && mo!=bo || mo==bo && bo!=to || to==bo && mo!=bo)
		printf("Dva od tri studenta imaju istu ocjenu.\n");
		else if (mo!=to && to!=bo && mo!=bo)
		printf ("Svaki student ima razlicitu ocjenu.\n");
	}
	return 0;
}
