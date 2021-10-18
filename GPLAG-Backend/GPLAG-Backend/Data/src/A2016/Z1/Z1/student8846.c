#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001
int main() {
	double IT, IIT, PT, ZT, ZIT, IB, IIB, PB, ZB, ZIB, IM, IIM, PM, ZM, ZIM, BT, BM, BB;
	int OM, OB, OT, Polozili;
	OM=0, OB=0, OT=0, Polozili=0;
	
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf", &IT);
	if(IT<0 ||IT>20)
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIT);
	if((IIT<0) || (IIT>20)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &PT);
	if((PT<0) || (PT>10))
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &ZT);
	if ((ZT<0) || (ZT>10))
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT);
	if((ZIT<0) || (ZIT>40)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf", &IB);
	if((IB<0) || (IB>20)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIB);
	if((IIB<0) || (IIB>20)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &PB);
	if((PB<0) || (PB>10)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &ZB);
	if ((ZB<0) || (ZB>10))
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIB);
	if((ZIB<0) || (ZIB>40)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf", &IM);
	if((IM<0) || (IM>20)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIM);
	if((IIM<0) || (IIM>20)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &PM);
	if((PM<0) || (PM>10)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &ZM);
	if ((ZM<0) || (ZM>10))
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIM);
	if((ZIM<0) || (ZIM>40)) 
	{
		printf("Neispravan broj bodova\n");
		return 0;
	}
	BT=IT+IIT+PT+ZT+ZIT;
	BB=IB+IIB+PB+ZB+ZIB;
	BM=IM+IIM+PM+ZM+ZIM;
	if(BT>=55 && BT<65)
	OT=6;
	else if(BT>=65 && BT<75)
	OT=7;
	else if(BT>=75 && BT<85)
	OT=8;
	else if(BT>=85 && BT<92)
	OT=9;
	else if(BT>=92)
	OT=10;
		if(BB>=55 && BB<65)
	OB=6;
	else if(BB>=65&& BB<75)
	OB=7;
	else if(BB>=75 && BB<85)
	OB=8;
	else if(BB>=85 && BB<92)
	OB=9;
	else if(BB>=92)
	OB=10;
		if(BM>=55 && BM<65)
	OM=6;
	else if(BM>=65 && BM<75)
	OM=7;
	else if(BM>=75 && BM<85)
	OM=8;
	else if(BM>=85&& BM<92)
	OM=9;
	else if(BM>=92)
	OM=10;
	if(OM!=0) Polozili++;
	if(OT!=0) Polozili++;
	if(OB!=0) Polozili++;
	if(Polozili==0)
	printf("Nijedan student nije polozio.\n");
	else if(Polozili==1)
	printf("Jedan student je polozio.\n");
	else if(Polozili==2)
	printf("Dva studenta su polozila.\n");
	else if(Polozili==3) {
		printf("Sva tri studenta su polozila.\n");
		if(OT==OM && OM==OB)
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if(OT!=OM && OM!=OB && OT!=OB)
		printf("Svaki student ima razlicitu ocjenu.\n");
		else 
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	return 0;
}
