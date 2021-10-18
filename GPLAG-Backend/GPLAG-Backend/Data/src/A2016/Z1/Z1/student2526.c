#include <stdio.h>

int main() 
{
	double tp1,tp2,tp,tz,tzi,bp1,bp2,bp,bz,bzi,mp1,mp2,mp,mz,mzi,mbodovi,tbodovi,bbodovi,mocjena,tocjena,bocjena;
	printf ("Unesite bodove za Tarika:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf", &tp1);
	if (tp1<0 || tp1>20) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" II parcijalni ispit:");
	scanf ("%lf", &tp2);
	if (tp2<0 || tp2>20) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Prisustvo:");
	scanf ("%lf", &tp);
	if (tp<0 || tp>10) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Zadace:");
	scanf ("%lf", &tz);
	if (tz<0 || tz>10) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Zavrsni ispit:");
	scanf ("%lf", &tzi);
	if (tzi<0 || tzi>40) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Unesite bodove za Bojana:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf", &bp1);
	if (bp1<0 || bp1>20) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" II parcijalni ispit:");
	scanf ("%lf", &bp2);
	if (bp2<0 || bp2>20) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Prisustvo:");
	scanf ("%lf", &bp);
	if (tp<0 || tp>10) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Zadace:");
	scanf ("%lf", &bz);
	if (bz<0 || bz>10) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Zavrsni ispit:");
	scanf ("%lf", &bzi);
	if (bzi<0 || bzi>40) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Unesite bodove za Mirzu:\n");
	printf ("I parcijalni ispit:");
	scanf ("%lf", &mp1);
	if (mp1<0 || mp1>20) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" II parcijalni ispit:");
	scanf ("%lf", &mp2);
	if (mp2<0 || mp2>20) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Prisustvo:");
	scanf ("%lf", &mp);
	if (mp<0 || mp>10) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Zadace:");
	scanf ("%lf", &mz);
	if (mz<0 || mz>10) {printf (" Neispravan broj bodova");
	return 0;}
	printf (" Zavrsni ispit:");
	scanf ("%lf", &mzi);
	if (mzi<0 || mzi>40) {printf (" Neispravan broj bodova");
	return 0;}
	tbodovi=tp1+tp2+tp+tz+tzi;
	bbodovi=bp1+bp2+bp+bz+bzi;
	mbodovi=mp1+mp2+mp+mz+mzi;
	if (tbodovi<55) {
		tocjena=5;
			}
	else {
		if (tbodovi>=55. && tbodovi<65.) tocjena=6;
		if (tbodovi>=65. && tbodovi<75.) tocjena=7;
		if (tbodovi>=75. && tbodovi<85.) tocjena=8;
		if (tbodovi>=85. && tbodovi<92.) tocjena=9;
		if (tbodovi>=92. && tbodovi<=100.) tocjena=10;
        if (bbodovi<55.) bocjena=5;
	    if (bbodovi>=55. && bbodovi<65.) bocjena=6;
		if (bbodovi>=65. && bbodovi<75.) bocjena=7;
		if (bbodovi>=75. && bbodovi<85.) bocjena=8;
		if (bbodovi>=85. && bbodovi<92.) bocjena=9;
		if (bbodovi>=92. && bbodovi<=100.) bocjena=10;
	    if (mbodovi<55.) mocjena=5;
	    if (mbodovi>=55. && mbodovi<65.) mocjena=6;
		if (mbodovi>=65. && mbodovi<75.) mocjena=7;
		if (mbodovi>=75. && mbodovi<85.) mocjena=8;
		if (mbodovi>=85. && mbodovi<92.) mocjena=9;
		if (mbodovi>=92. && mbodovi<=100.) mocjena=10;}
    if (tocjena>=6 && bocjena>=6 && mocjena>=6) {
	    printf(" Sva tri studenta su polozila.\n");
	    if ((tocjena==bocjena)&&(bocjena==mocjena)) {
	    	printf("Sva tri studenta imaju istu ocjenu.\n");}
	    else {
	    	if ((tocjena==bocjena)&&(tocjena!=mocjena)) printf ("Dva od tri studenta imaju istu ocjenu.\n");
		    if ((tocjena==mocjena)&&(tocjena!=bocjena)) printf ("Dva od tri studenta imaju istu ocjenu.\n");
		    if ((bocjena==mocjena)&&(tocjena!=mocjena)) printf ("Dva od tri studenta imaju istu ocjenu.\n");
		    if ((tocjena!=bocjena)&&(tocjena!=mocjena)&&(bocjena!=mocjena)) printf ("Svaki student ima razlicitu ocjenu.\n");
	    }
    }
    else
    {
        if ((tbodovi<55.)&&(bbodovi>=55.)&&(mbodovi>=55.)) printf(" Dva studenta su polozila.\n");
		if ((tbodovi>=55.)&&(bbodovi<55.)&&(mbodovi>=55.)) printf(" Dva studenta su polozila.\n");
		if ((tbodovi>=55.)&&(bbodovi>=55.)&&(mbodovi<55.)) printf(" Dva studenta su polozila.\n");
		if ((tbodovi<55.)&&(bbodovi>=55.)&&(mbodovi<55.)) printf(" Jedan student je polozio.\n");
		if ((tbodovi<55.)&&(bbodovi<55.)&&(mbodovi>=55.)) printf(" Jedan student je polozio.\n");
		if ((tbodovi>=55.)&&(bbodovi<55.)&&(mbodovi<55.)) printf(" Jedan student je polozio.\n");
		if ((tbodovi<55.)&&(bbodovi<55.)&&(mbodovi<55.)) printf(" Nijedan student nije polozio.\n");}
return 0;
}
