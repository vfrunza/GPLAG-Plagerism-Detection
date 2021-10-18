#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

int main() {
	float T,B,M,IT,IIT,PT,ZT,ZIT,IB,IIB,PB,ZB,ZIB,IM,IIM,PM,ZM,ZIM,OT,OB,OM;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&IT);
	if(IT<0 || IT>20)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIT);
	if(IIT<0 || IIT>20)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&PT);
	if(PT<0 || PT>10)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%f",&ZT);
	if(ZT<0 || ZT>10)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ZIT);
	if(ZIT<0 || ZIT>40)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&IB);
	if(IB<0 || IB>20)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIB);
	if(IIB<0 || IIB>20)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&PB);
	if(PB<0 || PB>10)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%f",&ZB);
	if(ZB<0 || ZB>10)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ZIB);
	if(ZIB<0 || ZIB>40)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&IM);
	if(IM<0 || IM>20)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIM);
	if(IIM<0 || IIM>20)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&PM);
	if(PM<0 || PM>10)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%f",&ZM);
	if(ZM<0 || ZM>10)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ZIM);
	if(ZIM<0 || ZIM>40)
	{
	printf("Neispravan broj bodova");
	return 0;
	}
	
	OT=IT+IIT+PT+ZT+ZIT;
	if(OT>=55 && OT<65)
	T=6;
	if(OT>=65 && OT<75)
	T=7;
	if(OT>=75 && OT<85)
	T=8;
	if(OT>=85 && OT<92)
	T=9;
	if(OT>=92 && OT<=100)
	T=10;
	
	OB=IB+IIB+PB+ZB+ZIB;
    if(OB>=55 && OB<65)
	B=6;
	if(OB>=65 && OB<75)
	B=7;
	if(OB>=75 && OB<85)
	B=8;
	if(OB>=85 && OB<92)
	B=9;
	if(OB>=92 && OB<=100)
	B=10;
	
	OM=IM+IIM+PM+ZM+ZIM;
	if(OM>=55 && OM<65)
	M=6;
	if(OM>=65 && OM<75)
	M=7;
	if(OM>=75 && OM<85)
	M=8;
	if(OM>=85 && OM<92)
	M=9;
	if(OM>=92 && OM<=100)
	M=10;
	
	if(OT<54.999 && OB<54.999 && OM<54.999)
	printf("Nijedan student nije polozio.");
	if(OT>=55 && OB>=55 && OM>=55)
	{
	printf("Sva tri studenta su polozila.\n");
	if(fabs(T-B) >= epsilon && fabs(T-M) >= epsilon && fabs(B-M) >= epsilon)
	printf("Svaki student ima razlicitu ocjenu.");
	if((fabs(T-B) < epsilon && fabs(B-M) >= epsilon) || (fabs(T-M) < epsilon && fabs(M-B) >= epsilon) || (fabs(B-M) < epsilon && fabs(T-M) >= epsilon))
	printf("Dva od tri studenta imaju istu ocjenu.");
	if(fabs(T-B) < epsilon && fabs(B-M) < epsilon)
	printf("Sva tri studenta imaju istu ocjenu.");
	}
	if((OT>=54.999 && OB<54.999 && OM<54.999) || (OT<54.999 && OB>=54.999 && OM<54.999) || (OT<54.999 && OB<54.999 &&OM>=54.999))
	printf("Jedan student je polozio.");
	if((OT>=55 && OB>=55 && OM<55) || (OT>=55 && OB<55 && OM>=55) || (OT<55 && OB>=55 &&OM>=55))
	printf("Dva studenta su polozila.");
	return 0;
}
