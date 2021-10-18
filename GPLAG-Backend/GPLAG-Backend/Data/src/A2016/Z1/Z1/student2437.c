#include <stdio.h>
#define EPSILON 0.000001

int main() {
	
    double IPIT, IIPIT, PT, ZT, ZIT, IPIB, IIPIB, PB, ZB, ZIB, IPIM, IIPIM, PM, ZM, ZIM;
    int UT, UB, UM;
    
    printf("Unesite broj bodova za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%d", &IPIT);
	if  (IPIT<0 || IPIT>20)
	{
	printf("\nNeispravan broj bodova");
	return 0 ;
	}
	printf("II parcijalni ispit: ");
	scanf("%d", &IIPIT);
	if (IIPIT<0 || IIPIT>20)
	{
	printf("\nNeispravan broj bodova");
		return 0 ;
	}
	printf("\nPrisustvo: ");
	scanf("%d", &PT);
	if (PT<0 || PT>10)
	{
	printf("Neispravan broj bodova");
		return 0;
	}
	printf("\nZadace: ");
	scanf("%d", &ZT);
	if (ZT<0 || ZT>10)
	{
	printf("Neispravan broj bodova"); 
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%d", &ZIT);
	if (ZIT<0 || ZIT>40)
	{
	printf("\nNeispravan broj bodova");
		return 0 ;
	}
	printf("Unesite broj bodova za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%d", IPIB);
	if  (IPIB<0 || IPIB>20)
	{
	printf("\nNeispravan broj bodova");
		return 0 ;
	}
	printf("II parcijalni ispit: ");
	scanf("%d", IIPIB);
		if (IIPIB<0 || IIPIB>20)
		{
	printf("\nNeispravan broj bodova");
			return 0 ;
		};
	printf("Prisustvo: ");
	scanf("%d", PB);
		if (PB<0 || PB>10)
		{
	printf("\nNeispravan broj bodova");
			return 0 ;
		}
	printf("Zadace: ");
	scanf("%d", ZB);
		if (ZB<0 || ZB>10)
		{
	printf("\nNeispravan broj bodova");
			return 0 ; 
		}
	printf("Zavrsni ispit: ");
	scanf("%d", ZIB);
	if (ZIB<0 || ZIB>40)
	{
	printf("\nNeispravan broj bodova");
		return 0 ;
	}
	printf("Unesite broj bodova za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%d", IPIM);
		if  (IPIM<0 || IPIM>20)
		{
	printf("\nNeispravan broj bodova");
		return 0 ;
	}
	printf("II parcijalni ispit: ");
		scanf("%d", IIPIM);
		if (IIPIM<0 || IIPIM>20)
		{
	printf("\nNeispravan broj bodova");
			return 0 ;
		}
	printf("Prisustvo: ");
	scanf("%d", PM);
		if (PM<0 || PM>10)
		{
	printf("\nNeispravan broj bodova");
			return 0 ;
		}
	printf("Zadace: ");
	scanf("%d", ZM);
		if (ZM<0 || ZM>10)
		{
	printf("\nNeispravan broj bodova");
			return 0 ;
		}
	printf("Zavrsni ispit: ");
	scanf("%d", ZIM);
		if (ZIM<0 || ZIM>40)
		{
	printf("\nNeispravan broj bodova");
		return 0 ;
	}
    
    UT=IPIT+IIPIT+PT+ZT+ZIT ;
	if(UT>=0 && UT<=55) - 5 ;
	if(UT>55 && UT<=65 )- 6 ;
	if(UT>65 && UT<=75) - 7;
	if(UT>75 && UT<=85) - 8; 
	if(UT>85 && UT<92) - 9; 
	if(UT>=92 && UT<=100) - 10; 
	
	UB=IPIB+IIPIB+PB+ZB+ZIB ;
		if(UB>=0 && UB<=55) - 5 ;
	if(UB>55 && UB<=65 ) - 6 ;
	if(UB>65 && UB<=75) - 7 ;
	if(UB>75 && UB<=85) - 8 ; 
	if(UB>85 && UB<92) - 9 ; 
	if(UB>=92 && UB<=100) 10 ; 
	
	UM=IPIM+IIPIM+PM+ZM+ZIM ;
		if(UM>=0 && UM<=55) - 5 ;
	if(UM>55 && UM<=65) - 6 ;
	if(UM>65 && UM<=75) - 7 ;
	if(UM>75 && UM<=85) - 8 ;
	if(UM>85 && UM<92) - 9 ;
	if(UM>=92 && UM<=100) - 10 ; 
	
	if(UT==UB==UM==55)
	printf("Nijedan student nije polozio") ;
	{ if ( (UT>55 && UB<55 && UM<55) || (UT<55 && UB>55 && UM<55) || (UT<55 && UB<55 && UM>55))
	printf("Jedan student je polozio.");
	{if ((UT>55 && UB>55 && UM<55) || (UT>55 && UB<55 && UM>55) || (UT<55 && UB>55 && UM>55))
	printf("Dva studenta su polozila");
	else {
	printf("Sva tri studenta su polozila");	}
	}}

	if((UT>100 || UT<0) || (UM>100 || UM<0) || (UB>100 || UB<0))
	printf("Neispravan broj bodova \n");
	scanf("%f%f%f", UM,UB,UT);
	
	if (UT=UB=UM)
	printf("Sva tri studenta imaju istu ocjenu.\n");
	if(UT==UM || UT==UB || UB==UM )
	printf("Dva od tri studenta imaju istu ocjenu.\n");
	if (UT!=UM && UT!=UB && UM!=UM)
	printf("Svaki student ima razlicitu ocjenu.\n");
	return 0;
}
