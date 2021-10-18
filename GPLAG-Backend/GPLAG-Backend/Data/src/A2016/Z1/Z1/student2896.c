#include <stdio.h>

int main() {
	double t1p,t2p,tp,tz,tzi,b1p,b2p,bp,bz,bzi,m1p,m2p,mp,mz,mzi,tuk,buk,muk;
	int t=5,b=5,m=5,br=3;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &t1p);
	if(t1p>20.0 || t1p<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &t2p);
	if(t2p>20.0 || t2p<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if(tp>10.0 || tp<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &tz);
	if(tz>10.0 || tz<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzi);
	if(tzi>40.0 || tzi<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &b1p);
	if(b1p>20.0 || b1p <0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b2p);
	if(b2p<0.0 ||b2p>20.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bp);
	if(bp<0.0 || bp>10.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &bz);
	if(bz>10.0 ||bz<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzi);
	if(bzi<0.0 ||bzi>40.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &m1p);
	if(m1p<0.0 ||m1p>20.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &m2p);
	if(m2p>20.0 || m2p < 0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &mp);
	if(mp>10.0 || mp<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &mz);
	if(mz>10.0 ||mz < 0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mzi);
	if(mzi>40.0 ||mzi<0.0)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	tuk = t1p + t2p + tp + tz + tzi;
	buk = b1p + b2p + bp + bz + bzi;
	muk = m1p + m2p + mp + mz + mzi;
	
	if(tuk < 55.0) t = 5;
	else if(tuk < 65.0) t = 6;
	else if(tuk < 75.0) t = 7;
	else if(tuk < 85.0) t = 8;
	else if(tuk < 92.0) t = 9;
	else if(tuk <= 100.0) t = 10;
	
	if(buk < 55.0) b = 5;
	else if(buk < 65.0) b = 6;
	else if(buk < 75.0) b = 7;
	else if(buk < 85.0) b = 8;
	else if(buk < 92.0) b = 9;
	else if(buk <= 100.0) b = 10;
	
	if(muk < 55.0) m = 5;
	else if(muk < 65.0) m = 6;
	else if(muk < 75.0) m = 7;
	else if(muk < 85.0) m = 8;
	else if(muk < 92.0) m = 9;
	else if(muk <= 100.0) m = 10;
	
	if(t == 5) br--;
	if(b == 5) br--;
	if(m == 5) br--;
	
	if(br == 0)
	{
		printf("Nijedan student nije polozio.\n");
	}
	else if(br==1)
	{
		printf("Jedan student je polozio.\n");
	}
	else if(br==2)
	{
		printf("Dva studenta su polozila.\n");
	}
	else if(br==3)
	{
		printf("Sva tri studenta su polozila.\n");
		if(t==b && t==m) printf("Sva tri studenta imaju istu ocjenu.");
		else if(t==b || t==m || b==m) printf("Dva od tri studenta imaju istu ocjenu.");
		else printf("Svaki student ima razlicitu ocjenu.");
	}
	
	return 0;
}
