#include <stdio.h>

int main() {
	float ppit,dpit,zadt,prist,zavit,ppib,dpib,zadb,prisb,zavib,ppim,dpim,zadm,prism,zavim,tarik,bojan,mirza;
	int ocjenat,ocjenab,ocjenam;
	ocjenat=0;
	ocjenab=0;
	ocjenam=0;
	bojan=0;
	mirza=0;
	tarik=0;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&ppit);
	if(ppit<0 || ppit>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dpit);
	if(dpit<0 || dpit>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&prist);
	if(prist<0 || prist>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zadt);
	if(zadt<0 || zadt>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zavit);
	if(zavit<0 || zavit>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&ppib);
	if(ppib<0 || ppib>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dpib);
	if(dpib<0 || dpib>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&prisb);
	if(prisb<0 || prisb>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zadb);
	if(zadb<0 || zadb>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zavib);
	if(zavib<0 || zavib>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&ppim);
	if(ppim<0 || ppim>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dpim);
	if(dpim<0 || dpim>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&prism);
	if(prism<0 || prism>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zadm);
	if(zadm<0 || zadm>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zavim);
	if(zavim<0 || zavim>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	tarik=ppit+dpit+zadt+prist+zavit;
	bojan=ppib+dpib+zadb+prisb+zavib;
	mirza=ppim+dpim+zadm+prism+zavim;
	if(tarik>=55 && tarik<65)
	{
		ocjenat=6;
	}
	if(tarik>=65 && tarik<75)
	{
		ocjenat=7;
	}
	if(tarik>=75 && tarik<85)
	{
		ocjenat=8;
	}
	if(tarik>=85 && tarik<92)
	{
		ocjenat=9;
	}
	if(tarik>=92 && tarik<=100)
	{
		ocjenat=10;
	}
	if(bojan>=55 && bojan<65)
	{
		ocjenab=6;
	}
	if(bojan>=65 && bojan<75)
	{
		ocjenab=7;
	}
	if(bojan>=75 && bojan<85)
	{
		ocjenab=8;
	}
	if(bojan>=85 && bojan<92)
	{
		ocjenab=9;
	}
	if(bojan>=92 && bojan<=100)
	{
		ocjenab=10;
	}
	if(mirza>=55 && mirza<65)
	{
		ocjenam=6;
	}
	if(mirza>=65 && mirza<75)
	{
		ocjenam=7;
	}
	if(mirza>=75 && mirza<85)
	{
		ocjenam=8;
	}
	if(mirza>=85 && mirza<92)
	{
		ocjenam=9;
	}
	if(mirza>=92 && mirza<=100)
	{
		ocjenam=10;
	}
	if(tarik<55 && bojan<55 && mirza<55)
	{
		printf("Nijedan student nije polozio.\n");
	}
	if((tarik>=55 && bojan<55 && mirza<55) || (tarik<55 && bojan>=55 && mirza<55) || (tarik<55 && bojan<55 && mirza>=55))
	{
		printf("Jedan student je polozio.\n");
	}
	if((tarik>55 && bojan>55 && mirza<55) || (tarik<55 && bojan>55 && mirza>55) || (tarik>55 && bojan<55 && mirza>55))
	{
		printf("Dva studenta su polozila.\n");
	}
	if(tarik>55 && bojan>55 && mirza>55)
	{
		printf("Sva tri studenta su polozila.\n");
		if((ocjenat==ocjenam) && (ocjenam==ocjenab) && (ocjenab==ocjenat))
		{
			printf("Sva tri studenta imaju istu ocjenu.\n");
		}
		if(((ocjenat==ocjenab) && (ocjenat!=ocjenam)) || ((ocjenat==ocjenam) && (ocjenat!=ocjenab)) || ((ocjenab==ocjenam) && (ocjenab!=ocjenat)))
		{
			printf("Dva od tri studenta imaju istu ocjenu.\n");
		}
		else
		{
			printf("Svaki student ima razlicitu ocjenu.\n");
		}
	}
	return 0;
}