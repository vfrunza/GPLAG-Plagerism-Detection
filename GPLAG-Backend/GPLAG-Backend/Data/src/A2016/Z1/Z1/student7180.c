#include <stdio.h>
#include <stdlib.h>

int main() {
	float tp1, tp2, tp, tz, tzi, bp1, bp2, bp, bz, bzi, mp1, mp2, mp, mz, mzi, tu, bu, mu;
	int tpolozio, bpolozio, mpolozio, tocjena, bocjena, mocjena;
	printf ("Unesite bodove za Tarika: \n");
	printf ("I parcijalni ispit: "); 
	scanf("%f", &tp1);
	if(tp1<0 || tp1>20) {printf ("Neispravan broj bodova"); return 0;}
	printf ("II parcijalni ispit: ");
	scanf("%f", &tp2);
	if(tp2<0 || tp2>20) {printf ("Neispravan broj bodova"); return 0;}
	printf ("Prisustvo: ");
	scanf("%f", &tp);
	if(tp<0 || tp>10) {printf ("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &tz);
	if(tz<0 || tz>10) {printf ("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf ("%f", &tzi);
	if(tzi<0 || tzi>40) {printf ("Neispravan broj bodova"); return 0;}
	
	printf ("Unesite bodove za Bojana: \n");
	printf ("I parcijalni ispit: ");
	scanf("%f", &bp1);
	if(bp1<0 || bp1>20) {printf ("Neispravan broj bodova"); return 0;}
	printf ("II parcijalni ispit: ");
	scanf("%f", &bp2);
	if(bp2<0 || bp2>20) {printf ("Neispravan broj bodova"); return 0;}
	printf ("Prisustvo: ");
	scanf("%f", &bp);
	if(bp<0 || bp>10) {printf ("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &bz);
	if(bz<0 || bz>10) {printf ("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf ("%f", &bzi);
	if(bzi<0 || bzi>40) {printf ("Neispravan broj bodova"); return 0;}
	
	printf ("Unesite bodove za Mirzu: \n");
	printf ("I parcijalni ispit: ");
	scanf("%f", &mp1);
	if(mp1<0 || mp1>20) {printf ("Neispravan broj bodova"); return 0;}
	printf ("II parcijalni ispit: ");
	scanf("%f", &mp2);
	if(mp2<0 || mp2>20) {printf ("Neispravan broj bodova"); return 0;}
	printf ("Prisustvo: ");
	scanf("%f", &mp);
	if(mp<0 || mp>10) {printf ("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%f", &mz);
	if(mz<0 || mz>10) {printf ("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf ("%f", &mzi);
	if(mzi<0 || mzi>40) {printf ("Neispravan broj bodova"); return 0;}
	
	tu=tp1+tp2+tp+tz+tzi+0.0001;
	bu=bp1+bp2+bp+bz+bzi+0.0001;
	mu=mp1+mp2+mp+mz+mzi+0.0001;
	
	if(tu<55) {tpolozio=0; tocjena=0;}
	else if (tu>=55 && tu<65) {tpolozio=1; tocjena=6;}
	else if (tu>=65 && tu<75) {tpolozio=1; tocjena=7;}
	else if (tu>=75 && tu<85) {tpolozio=1; tocjena=8;}
	else if (tu>=85 && tu<92) {tpolozio=1; tocjena=9;}
	else if (tu>=92 && tu<=100) {tpolozio=1; tocjena=10;}
	
	if(bu<55) {bpolozio=0; bocjena=0;}
	else if (bu>=55 && bu<65) {bpolozio=1; bocjena=6;}
	else if(bu>=65 && bu<75) {bpolozio=1; bocjena=7;}
	else if(bu>=75 && bu<85) {bpolozio=1; bocjena=8;}
	else if(bu>=85 && bu<92) {bpolozio=1; bocjena=9;}
	else if (bu>=92 && bu<=100) {bpolozio=1; bocjena=10;}
	
	if(mu<55) {mpolozio=0; mocjena=0; }
	else if (mu>=55 && mu<65) {mpolozio=1; mocjena=6;}
	else if (mu>=65 && mu<75) {mpolozio=1; mocjena=7;}
	else if (mu>=75 && mu<85) {mpolozio=1; mocjena=8;}
	else if (mu>=85 && mu<92) {mpolozio=1; mocjena=9;}
	else if (mu>=92 && mu<=100) {mpolozio=1; mocjena=10;}
	
	if (tpolozio+mpolozio+bpolozio==3) {printf("Sva tri studenta su polozila.\n");}
	else if (tpolozio+mpolozio+bpolozio==2) {printf("Dva studenta su polozila.\n");}
	else if(tpolozio+mpolozio+bpolozio==1) {printf("Jedan student je polozio.\n");}
	else printf ("Nijedan student nije polozio.\n");
	
	if (tpolozio+mpolozio+bpolozio==3)
	{
		if(tocjena==mocjena && tocjena==bocjena) {printf("Sva tri studenta imaju istu ocjenu.");}
	else if((tocjena==bocjena && tocjena!=mocjena) || (bocjena==mocjena && bocjena!=tocjena) ||
	(tocjena==mocjena && tocjena!=bocjena) || (bocjena==tocjena && bocjena!=mocjena) || 
	(mocjena==tocjena && mocjena!=bocjena) || (mocjena==bocjena && mocjena!=tocjena))
	{printf ("Dva od tri studenta imaju istu ocjenu.");}
	else printf("Svaki student ima razlicitu ocjenu.");
	}
	
	
	
	return 0;
}
