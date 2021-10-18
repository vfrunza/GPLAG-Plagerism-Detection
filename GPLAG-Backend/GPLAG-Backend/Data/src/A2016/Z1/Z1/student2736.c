#include <stdio.h>

int main() 
{
	float IpT,IIpT,pT,zT,ziT,IpB,IIpB,pB,zB,ziB,IpM,IIpM,pM,zM,ziM,UBT,UBB,UBM;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&IpT);
	if(IpT<0 || IpT>20)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIpT);
	if(IIpT<0 || IIpT>20)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Prisustvo: ");
	scanf("%f",&pT);
	if(pT<0 || pT>10)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Zadace: ");
	scanf("%f",&zT);
	if(zT<0 || zT>10)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ziT);
	if(ziT<0 || ziT>40)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&IpB);
	if(IpB<0 || IpB>20)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIpB);
	if(IIpB<0 || IIpB>20)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Prisustvo: ");
	scanf("%f",&pB);
	if(pB<0 || pB>10)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Zadace: ");
	scanf("%f",&zB);
	if(zB<0 || zB>10)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ziB);
	if(ziB<0 || ziB>40)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f",&IpM);
	if(IpM<0 || IpM>20)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&IIpM);
	if(IIpM<0 || IIpM>20)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Prisustvo: ");
	scanf("%f",&pM);
	if(pM<0 || pM>10)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Zadace: ");
	scanf("%f",&zM);
	if(zM<0 || zM>10)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ziM);
	if(ziM<0 || ziM>40)
	{
		printf("Neispravan broj bodova");
	goto end;
	}
	
	UBT=IpT+IIpT+pT+zT+ziT+0.00001;
	UBB=IpB+IIpB+pB+zB+ziB+0.00001;
	UBM=IpM+IIpM+pM+zM+ziM+0.00001;
	
	if(UBT<55 && UBM<55 && UBB<55)
		printf("Nijedan student nije polozio.");
	else if((UBB<55 && UBM<55 && UBT>55)||(UBB<55 && UBM>55 && UBT<55)||(UBB>55 && UBM<55 && UBT<55))
		printf("Jedan student je polozio.");
	else if((UBB>55 && UBM>55 && UBT<55)||(UBB>55 && UBM<55 && UBT>55)||(UBB<55 && UBM>55 && UBT>55))
		printf("Dva studenta su polozila.");
	else if(UBB>55 && UBM>55 && UBT>55)
	{
		printf("Sva tri studenta su polozila.\n");
		
		if(((UBT>=55 && UBT<65) && (UBB>=55 && UBB<65) && (UBM>=55 && UBM<65)) || ((UBT>=65 && UBT<75) && (UBB>=65 && UBB<75) && (UBM>=65 && UBM<75)) || ((UBT>=75 && UBT<85) && (UBB>=75 && UBB<85) && (UBM>=75 && UBM<85)) || ((UBT>=85 && UBT<92) && (UBB>=85 && UBB<92) && (UBM>=85 && UBM<92)) || ((UBT>=92 && UBT<=100) && (UBB>=92 && UBB<=100) && (UBM>=92 && UBM<=100)))
            printf("Sva tri studenta imaju istu ocjenu.");
        else if(((UBT>=55 && UBT<65) && (UBB>=55 && UBB<65)) || ((UBB>=55 && UBB<65) && (UBM>=55 && UBM<65)) || ((UBT>=55 && UBT<65) && (UBM>=55 && UBM<65)))
            printf("Dva od tri studenta imaju istu ocjenu.");
        else if(((UBT>=65 && UBT<75) && (UBB>=65 && UBB<75)) || ((UBB>=65 && UBB<75) && (UBM>=65 && UBM<75)) || ((UBT>=65 && UBT<75) && (UBM>=65 && UBM<75)))
            printf("Dva od tri studenta imaju istu ocjenu.");
        else if(((UBT>=75 && UBT<85) && (UBB>=75 && UBB<85)) || ((UBB>=75 && UBB<85) && (UBM>=75 && UBM<85)) || ((UBT>=75 && UBT<85) && (UBM>=75 && UBM<85)))
            printf("Dva od tri studenta imaju istu ocjenu.");
        else if(((UBT>=85 && UBT<92) && (UBB>=85 && UBB<92)) || ((UBB>=85 && UBB<92) && (UBM>=85 && UBM<92)) || ((UBT>=85 && UBT<92) && (UBM>=85 && UBM<92)))
            printf("Dva od tri studenta imaju istu ocjenu.");
        else if(((UBT>=92 && UBT<=100) && (UBB>=92 && UBB<=100)) || ((UBB>=92 && UBB<=100) && (UBM>=92 && UBM<=100)) || ((UBT>=92 && UBT<=100) && (UBM>=92 && UBM<=100)))
            printf("Dva od tri studenta imaju istu ocjenu.");
        else
            printf("Svaki student ima razlicitu ocjenu.");
	}
	end:
	return 0;
}
