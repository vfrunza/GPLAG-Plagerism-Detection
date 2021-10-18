#include <stdio.h>

int main() {
	float t1p, t2p, tp, tz, tzz,  b1p , b2p, bp, bz, bzz,  m1p, m2p, mp, mz, mzz;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &t1p);
	if(t1p > 20 || t1p < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%f", &t2p);
	if(t2p > 20 || t2p < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%f", &tp);
	if(tp > 10 || tp < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%f", &tzz);
	if(tzz > 10 || tzz < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%f", &tz);
	if(tz > 40 || tz < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &b1p);
	
	
	if(b1p > 20 || b1p < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%f", &b2p);
	if(b2p > 20 || b2p < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%f", &bp);
	if(bp > 10 || bp < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%f", &bzz);
	if(bzz > 10 || bzz < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%f", &bz);
	if(bz > 40 || bz < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &m1p);
	if(m1p > 20 || m1p < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%f", &m2p);
	if(m2p > 20 || m2p < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%f", &mp);
	if(mp > 10 || mp < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%f", &mzz);
	if(mzz > 10 || mzz < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%f", &mz);
	if(mz > 40 || mz < 0 )
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	float rt, rb, rm;
	rt = t1p + t2p + tp + tz + tzz;
	rb = b1p + b2p + bp + bz + bzz;
	rm = m1p + m2p + mp + mz + mzz;
	int br = 0;
	if(rt>=55) br++;
	if(rb>=55) br++;
	if(rm>=55) br++;
	if(br==0) printf("Nijedan student nije polozio.\n");
	else if(br==1) printf("Jedan student je polozio.\n");
	else if(br==2) printf("Dva studenta su polozila.\n");
	else if(br==3)
		{
			printf("Sva tri studenta su polozila.\n");
			int to,bo,mo;
			if(rt>=55 && rt<65) to = 6;
			if(rt>=65 && rt<75) to = 7;
			if(rt>=75 && rt<85) to = 8;
			if(rt>=85 && rt<92) to = 9;
			if(rt>=92 && rt<100) to = 10;
			if(rb>=55 && rb<65) bo = 6;
			if(rb>=65 && rb<75) bo = 7;
			if(rb>=75 && rb<85) bo = 8;
			if(rb>=85 && rb<92) bo = 9;
			if(rb>=92 && rb<100) bo = 10;
			if(rm>=55 && rm<65) mo = 6;
			if(rm>=65 && rm<75) mo = 7;
			if(rm>=75 && rm<85) mo = 8;
			if(rm>=85 && rm<92) mo = 9;
			if(rm>=92 && rm<100) mo = 10;
			if( to!=bo && to!=mo && bo!=mo) printf("Svaki student ima razlicitu ocjenu.\n");
			else if( to==bo && bo==mo ) printf("Sva tri studenta imaju istu ocjenu.\n");
			else printf("Dva od tri studenta imaju istu ocjenu.\n");
		}
	return 0;
}
