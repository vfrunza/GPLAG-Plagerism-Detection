#include <stdio.h>

int main() {
double ukbodt,ukbodb,ukbodm;
double prviparct,drugiparct,zadt,prist,zaist,prviparcb,drugiparcb,prisb,zadb,zaisb,prviparcm,drugiparcm,zadm,prism,zaism;
int ocm,oct,ocb;

printf("Unesite bodove za Tarika: \n");
printf("I parcijalni ispit: ");
scanf("%lf",&prviparct);
if( prviparct<0 || prviparct>20)
{
printf("Neispravan broj bodova");
return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&drugiparct);
if( drugiparct<0 || drugiparct>20)
{
printf("Neispravan broj bodova");
 return 0; 
}
printf("Prisustvo: ");
scanf("%lf",&prist);
if( prist<0 || prist>10)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Zadace: ");
scanf("%lf",&zadt);
if( zadt<0 || zadt>10)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf", &zaist);
if(zaist<0 || zaist>40)
{
printf("Neispravan broj bodova");
return 0;
}


printf("Unesite bodove za Bojana: \n");
printf("I parcijalni ispit: ");
scanf("%lf",&prviparcb);
if( prviparcb<0 || prviparcb>20)
{
printf("Neispravan broj bodova");
return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf", &drugiparcb);
if(drugiparcb<0 || drugiparcb>20)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prisb);
if( prisb<0 || prisb>10)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Zadace: ");
scanf("%lf",&zadb);
if( zadb<0 || zadb>10)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zaisb);
if(zaisb<0 || zaisb>40)
{
printf("Neispravan broj bodova");
return 0;
}


printf("Unesite bodove za Mirzu: \n");
printf("I parcijalni ispit: ");
scanf("%lf",&prviparcm);
if( prviparcm<0 || prviparcm>20)
{
printf("Neispravan broj bodova");
return 0;
}
printf("II parcijalni ispit: ");
scanf("%lf",&drugiparcm);
if( drugiparcm<0 || drugiparcm>20)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Prisustvo: ");
scanf("%lf",&prism);
if( prism<0 || prism>10)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Zadace: ");
scanf("%lf",&zadm);
if( zadm<0 || zadm>10)
{
printf("Neispravan broj bodova");
return 0;
}
printf("Zavrsni ispit: ");
scanf("%lf",&zaism);
if(zaism<0 || zaism>40)
{
printf("Neispravan broj bodova");
return 0;
}

ukbodt=prviparct+drugiparct+prist+zadt+zaist;
ukbodb=prviparcb+drugiparcb+prisb+zadb+zaisb;
ukbodm=prviparcm+drugiparcm+prism+zadm+zaism;

if(ukbodt<55)
{
	oct=5;
}
else if(ukbodt>=55 && ukbodt<66)
{
	oct=6;
}
else if(ukbodt>=67 && ukbodt<75)
{
	oct=7;
}
else if(ukbodt>=75 && ukbodt<85)
{
	oct=8;
}
else if (ukbodt>=85 && ukbodt<92)
{
	oct=9;
}
else 
{
	oct=10;
}

if(ukbodb<55)
{
	ocb=5;
}
else if(ukbodb>=55 && ukbodb<66)
{
	ocb=6;
}
else if(ukbodb>=67 && ukbodb<75)
{
	ocb=7;
}
else if(ukbodb>=75 && ukbodb<85)
{
	ocb=8;
}
else if(ukbodb>=85 && ukbodb<92)
{
	ocb=9;
}
else
{
	ocb=10;
}

if(ukbodm<55)
{
	ocm=5;
}
else if (ukbodm>=55 && ukbodm<66)
{
ocm=6;	
}
else if (ukbodm>=67 && ukbodm<75) 
{
	ocm=7;
}
else if(ukbodm>=75 && ukbodm<85)
{
	ocm=8;
}
else if(ukbodm>=85 && ukbodm<92)
{
	ocm=9;
}
else
{
	ocm=10;
}

if(ukbodt<55 && ukbodb<55 && ukbodm<55)
{
	printf("Nijedan student nije polozio.");
}
else if ((ukbodt<55 && ukbodb<55 && ukbodm>=55) || (ukbodt<55 && ukbodb>=55 && ukbodm<55) || (ukbodt>=55 && ukbodm<55 && ukbodb<55))
{
	printf("Jedan student je polozio.");
}
else if ((ukbodt>=55 && ukbodb>=55 && ukbodm<55) || (ukbodt<55 && ukbodb>=55 && ukbodm>=55) || (ukbodt>=55 && ukbodb<55 && ukbodm>=55))
{
	printf("Dva studenta su polozila.");
}
else if (ukbodt>55 && ukbodb>55 && ukbodm>55 )
{
	printf("Sva tri studenta su polozila.");
} 

if (ukbodt>55 && ukbodb>55 && ukbodm>55 )
{
if(oct==ocb && ocb==ocm && oct==ocm)
{
	printf("\nSva tri studenta imaju istu ocjenu.");
}
else if(oct!=ocb && ocb!=ocm && oct!=ocm)
{
	printf("\nSvaki student ima razlicitu ocjenu.");
}
else
{
	printf("\nDva od tri studenta imaju istu ocjenu.");
} }
return 0;
}

