#include <stdio.h>
#include <math.h>
#define eps 0.00000000001
int main() {
	float tp1,tp2,tz,tp,tu,bp1,bp2,bz,bp,bu,mp1,mp2,mz,mp,mu,tuk=0,buk=0, muk=0,ocjenat=0,ocjenam=0,ocjenab=0;
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%f", &tp1);
	if(tp1<0 || tp1>20) {
		printf("Neispravan broj bodova");
		return 0; 
				}
		tuk+=tp1;
		printf("II parcijalni ispit: ");
		scanf("%f", &tp2);
		if(tp2<0 || tp2>20) {
			printf("Neispravan broj bodova");
			return 0;
					}
					tuk+=tp2;
		printf("Prisustvo: ");
		scanf("%f", &tp);
		if(tp<0 || tp > 10) {
			printf("Neispravan broj bodova");
			return 0;
					}
					tuk+=tp;
		printf("Zadace: ");
		scanf("%f", &tz);
		if(tz<0 || tz>10) {
			printf("Neispravan broj bodova");
			return 0;
					}
					tuk+=tz;
		printf("Zavrsni ispit: ");
		scanf("%f", &tu);
		if(tu<0 || tu>40) {
			printf("Neispravan broj bodova");
			return 0;
					}
					tuk+=tu;
		printf("Unesite bodove za Bojana:");
		printf("\nI parcijalni ispit: ");
		scanf("%f", &bp1);
		if(bp1<0 || bp1 >20) {
			printf("Neispravan broj bodova");
			return 0;
		}
		buk+=bp1;
		printf("II parcijalni ispit: ");
		scanf("%f", &bp2);
		if(bp2<0 || bp2>20) {
			printf("Neispravan broj bodova");
			return 0;
		}
		buk+=bp2;
		printf("Prisustvo: ");
		scanf("%f", &bp);
		if(bp<0 || bp>10) {
			printf("Neispravan broj bodova");
			return 0;
		}
		buk+=bp;
		printf("Zadace: ");
		scanf("%f", &bz);
		if(bz<0 || bz>10) {
			printf("Neispravan broj bodova");
			return 0;
		}
		buk+=bz;
		printf("Zavrsni ispit: ");
		scanf("%f", &bu);
		if(bu<0 || bu>40) {
			printf("Neispravan broj bodova");
			return 0;
		}
		buk+=bu;
		printf("Unesite bodove za Mirzu:");
		printf("\nI parcijalni ispit: ");
		scanf("%f", &mp1);
		if(mp1<0 || mp1>20) {
			printf("Neispravan broj bodova");
			return 0;
		}
		muk+=mp1;
		printf("II parcijalni ispit: ");
		scanf("%f", &mp2);
		if(mp2<0 || mp2>20) {
			printf("Neispravan broj bodova");
			return 0;
		}
		muk+=mp2;
		printf("Prisustvo: ");
		scanf("%f", &mp);
		if(mp<0 || mp>10) {
			printf("Neispravan broj bodova");
			return 0;
		}
		muk+=mp;
		printf("Zadace: ");
		scanf("%f", &mz);
		if(mz<0 || mz>10) {
			printf("Neispravan broj bodova");
			return 0;
		}
		muk+=mz;
		printf("Zavrsni ispit: ");
		scanf("%f", &mu);
		if(mu<0 || mu>40) {
			printf("Neispravan broj bodova");
			return 0;
		}
		muk+=mu;
		
		if(tuk<55 && buk<55 && muk<55) {
			printf("Nijedan student nije polozio.");
			return 0;
		}    
		if((tuk>=55 && muk<55 && buk<55) || (tuk<55 && muk>=55 && buk<55) || (tuk<55 && muk<55 && buk>=55)) {
			printf("Jedan student je polozio.");
			return 0;
		}
		if((tuk>=55 && muk>=55 && buk<55) ||(tuk>=55 && muk<55 && buk>=55) || (tuk<55 && muk>=55 && buk>=55)) {
			printf("Dva studenta su polozila.");
			return 0;
		}
		if(tuk>=55 && muk>=55 && buk>=55) printf("Sva tri studenta su polozila.");
					
		if(tuk>=55 && tuk<65) ocjenat+=6;	
		if(tuk>=65 && tuk<75) ocjenat+=7;
		if(tuk>=75 && tuk<85) ocjenat+=8;
		if(tuk>=85 && tuk<92) ocjenat+=9;
		if(tuk>=92 && tuk<=100) ocjenat+=10;
		
		if(buk>=55 && buk<65) ocjenab+=6;
		if(buk>=65 && buk<75) ocjenab+=7;
		if(buk>=75 && buk<85) ocjenab+=8;
		if(buk>=85 && buk<92) ocjenab+=9;
		if(buk>=92 && buk<=100) ocjenab+=10;
		
		if(muk>=55 && muk<65) ocjenam+=6;
		if(muk>=65 && muk<75) ocjenam+=7;
		if(muk>=75 && muk<85) ocjenam+=8;
		if(muk>=85 && muk<92) ocjenam+=9;
		if(muk>=92 && muk<=100) ocjenam+=10;
		
		if(ocjenat==ocjenab && ocjenab==ocjenam && ocjenam==ocjenat) printf("\nSva tri studenta imaju istu ocjenu.");
		if(ocjenat!=ocjenab && ocjenab!=ocjenam && ocjenam!=ocjenat) printf("\nSvaki student ima razlicitu ocjenu.");
		if((ocjenat==ocjenab && ocjenat!=ocjenam) || (ocjenat==ocjenam && ocjenam!=ocjenab) || (ocjenab==ocjenam && ocjenam!=ocjenat)) printf("\nDva od tri studenta imaju istu ocjenu.");
		
			return 0;
}
