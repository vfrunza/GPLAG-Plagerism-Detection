#include <stdio.h>

int main() {
	float tpp, tdp, tp, tz, tzi, bpp, bdp, bp, bz, bzi, mpp, mdp, mp, mz, mzi, tb, bb, mb;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &tpp);
	if(tpp>20 || tpp<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%f", &tdp);
	if(tdp>20 || tdp<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &tp);
	if(tp<0 || tp>10) {
		printf("Neispravan broj bodova.");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &tz);
	if(tz<0 || tz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &tzi);
	if(tzi>40 || tzi<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &bpp);
	if(bpp>20 || bpp<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &bdp);
	if(bdp<0 || bdp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &bp);
	if(bp<0 || bp>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&bz);
	if(bz<0 || bz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &bzi);
	if(bzi>40 || bzi<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &mpp);
	if(mpp<0 || mpp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &mdp);
	if(mdp<0 || mdp>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &mp);
	if(mp<0 || mp>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &mz);
	if(mz<0 || mz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &mzi);
	if(mzi<0 || mzi>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	
	tb = tpp + tdp + tp + tz + tzi;
	bb = bpp + bdp + bp + bz + bzi;
	mb = mpp + mdp + mp + mz + mzi;
	
	if(tb<55 && bb<55 && mb<55)  
	printf("Nijedan student nije polozio.\n"); 
	
	
	else if((tb>=55 && bb<55 && mb<55) || (bb>=55 && tb<55 && mb<55)  || (mb>=55 && tb<55 && bb<55 )) 
	printf("Jedan student je polozio.\n");
	
	
	else if((tb>=55 && bb>=55 && mb<55) || (tb>=55 && bb<55 && mb>=55) || (tb<55 && bb>=55 && mb>=55)) 
		printf("Dva studenta su polozila.\n");
		
	
	
	else if(tb>=55 && bb>=55 && mb>=55) {
	printf("Sva tri studenta su polozila.\n");
	if((tb<55 && mb<55 && bb<55) || (tb>=55 && tb<65 && bb>=55 && bb<65 && mb>=55 && mb<65) || (tb>=65 && tb<75 && bb>=65 && bb<75 && mb>=65 && mb<75) || (tb>=75 && tb<85 && bb>=75 && bb<85 && mb>=75 && mb<85) || (tb>=85 && tb<92 && bb>=85 && bb<92 && mb>=85 && mb<92) || (tb>=92 && tb<=100 && bb>=92 && bb<=100 && mb>=92 && mb<=100))
	printf("Sva tri studenta imaju istu ocjenu.\n");
	 else if((tb<55 && bb<55 && mb>=55) || (tb>=55 && tb<65 && bb>=55 && bb<65 && mb>=65 || mb<55) || (tb>=65 && tb<75 && bb>=65 && bb<75 && mb<65 || mb>=75) || (tb>=75 && tb<85 && bb>=75 && bb<85 && mb<75 || mb>=85) || (tb>=85 && tb<92 && bb>=85 && bb<92 && mb<85 || mb>=92) || (tb>=92 && tb<=100 && bb>=92 && bb<=100 && mb<92))
	printf("Dva od tri studenta imaju istu ocjenu.\n");
	 else if((tb<55 && mb<55 && bb>=55) || (tb>=55 && tb<65 && mb>=55 && mb<65 && bb>=65 || bb<55) || (tb>=65 && tb<75 && mb>=65 && mb<75 && bb<65 || bb>=75) || (tb>=75 && tb<85 && mb>=75 && mb<85 && bb<75 || bb>=85) || (tb>=85 && tb<92 && mb>=85 && mb<92 && bb<85 || bb>=92) || (tb>=92 && tb<=100 && mb>=92 && mb<=100 && bb<=92))
	printf("Dva od tri studenta imaju istu ocjenu.\n");
	 else if((mb<55 && bb<55 && tb>=55) || (mb>=55 && mb<65 && bb>=55 && bb<65 && tb>=65 || tb<55) || (mb>=65 && mb<75 && bb>=65 && bb<75 && tb<65 || tb>=75) || (mb>=75 && mb<85 && bb>=75 && bb<85 && tb<75 || tb>=85) || (mb>=85 && mb<92 && bb>=85 && bb<92 && tb<85 || tb>=92) || (mb>=92 && mb<=100 && bb>=92 && bb<=100 && tb<=92))
	printf("Dva od tri studenta imaju istu ocjenu.\n");
	
	else {
	printf("Svaki student ima razlicitu ocjenu.");
		
	} }
	
	
	
	
		return 0;
}
