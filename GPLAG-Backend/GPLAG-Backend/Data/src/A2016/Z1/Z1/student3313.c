#include <stdio.h>
#include<math.h>
int main() {
	double t,t1, t2, tz, tza, tp;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&t1);
	if (t1<0 || t1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&t2);
	if(t2<0 || t2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Prisustvo: ");
	scanf("%lf",&tp);
	if(tp<0 || tp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&tza);
	if(tza<0 || tza>10)
	{
		printf("Neispravan broj bododva");
		return 0;
	}

	printf("Zavrsni ispit: ");
	scanf("%lf",&tz);
	if(tz<0 || tz>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	double m, m1, m2, mz, mza, mp;
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&m1);
	if (m1<0 || m1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&m2);
	if(m2<0 || m2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Prisustvo: ");
	scanf("%lf",&mp);
	if(mp<0 || mp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&mza);
	if(mza<0 || mza>10)
	{
		printf("Neispravan broj bododva");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&mz);
	if(mz<0 || mz>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}

	
		double b, b1, b2, bz, bza, bp;
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&b1);
	if (b1<0 || b1>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&b2);
	if(b2<0 || b2>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&bp);
	if(bp<0 || bp>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&bza);
	if(bza<0 || bza>10)
	{
		printf("Neispravan broj bododva");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf",&bz);
	if(bz<0 || bz>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	t=t1+t2+tz+tza+tp;
	m=m1+m2+mz+mza+mp;
	b=b1+b2+bz+bza+bp;
	
	int to, mo, bo;
	if(t<55)
		to=5;
	else if (t>=55 && t<65)
		to=6;
	else if(t>=65 && t<75)
		to=7;
	else if(t>=75 && t<85)
		to=8;
	else if(t>=85 && t<92)
		to=9;
	else
		to=10;
	
	if(m<55)
		mo=5;
	else if (m>=55 && m<65)
		mo=6;
	else if(m>=65 && m<75)
		mo=7;
	else if(m>=75 && m<85)
		mo=8;
	else if(m>=85 && m<92)
		mo=9;
	else
		mo=10;
		
	if(b<55)
		bo=5;
	else if (b>=55 && b<65)
		bo=6;
	else if(b>=65 && b<75)
		bo=7;
	else if(b>=75 && b<85)
		bo=8;
	else if(b>=85 && b<92)
		bo=9;
	else
		bo=10;
	
	if(to==5 && mo==5 && bo==5)
		printf("Nijedan student nije polozio.");
	else if(   ( to>5 && mo==5 && bo==5) || (mo>5 && to==5 && bo==5) || (bo>5 && to==5 && mo==5)        )
		printf("Jedan student je polozio.");
	else if(to>5 && mo>5 && bo>5)
	{
		printf("Sva tri studenta su polozila.\n");
		if(to==mo && mo==bo)
			printf("Sva tri studenta imaju istu ocjenu.");
		else if(to!=mo && to!=bo && mo!=bo)
			printf("Svaki student ima razlicitu ocjenu.");
		else
			printf("Dva od tri studenta imaju istu ocjenu.");
	}
	else
		printf("Dva studenta su polozila.");
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
