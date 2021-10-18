#include <stdio.h>

int main() {
	double t1parc,t2parc,t_pris,t_zadace,t_zavrsni,b1parc,b2parc,b_pris,b_zadace,b_zavrsni,m1parc,m2parc,m_pris,m_zadace,m_zavrsni,tarik_bodovi,bojan_bodovi,
	mirza_bodovi;
	int tarik_pao=0,bojan_pao=0,mirza_pao=0,tarik_ocjena,bojan_ocjena,mirza_ocjena;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&t1parc);
	if(t1parc<0 || t1parc>20) 
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&t2parc);
	if(t2parc<0 || t2parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&t_pris);
	if(t_pris<0 || t_pris>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&t_zadace);
	if(t_zadace<0 || t_zadace>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&t_zavrsni);
	if(t_zavrsni<0 || t_zavrsni>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&b1parc);
	if(b1parc<0 || b1parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&b2parc);
	if(b2parc<0 || b2parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&b_pris);
	if(b_pris<0 || b_pris>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&b_zadace);
	if(b_zadace<0 || b_zadace>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&b_zavrsni);
	if(b_zavrsni<0 || b_zavrsni>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&m1parc);
	if(m1parc<0 || m1parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&m2parc);
	if(m2parc<0 || m2parc>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf",&m_pris);
	if(m_pris<0 || m_pris>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&m_zadace);
	if(m_zadace<0 || m_zadace>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&m_zavrsni);
	if(m_zavrsni<0 || m_zavrsni>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	tarik_bodovi=t1parc+t2parc+t_pris+t_zadace+t_zavrsni;
	bojan_bodovi=b1parc+b2parc+b_pris+b_zadace+b_zavrsni;
	mirza_bodovi=m1parc+m2parc+m_pris+m_zadace+m_zavrsni;

	if(tarik_bodovi>=0 && tarik_bodovi<55) tarik_pao=1;
	else if(tarik_bodovi>=55 && tarik_bodovi<65) tarik_ocjena=6;
	else if(tarik_bodovi>=65 && tarik_bodovi<75) tarik_ocjena=7;
	else if(tarik_bodovi>=75 && tarik_bodovi<85) tarik_ocjena=8;
	else if(tarik_bodovi>=85 && tarik_bodovi<92) tarik_ocjena=9;
	else if(tarik_bodovi>=92 && tarik_bodovi<=100) tarik_ocjena=10;
	if(bojan_bodovi>=0 && bojan_bodovi<55) bojan_pao=1;
	else if(bojan_bodovi>=55 && bojan_bodovi<65) bojan_ocjena=6;
	else if(bojan_bodovi>=65 && bojan_bodovi<75) bojan_ocjena=7;
	else if(bojan_bodovi>=75 && bojan_bodovi<85) bojan_ocjena=8;
	else if(bojan_bodovi>=85 && bojan_bodovi<92) bojan_ocjena=9;
	else if(bojan_bodovi>=92 && bojan_bodovi<=100) bojan_ocjena=10;
	if(mirza_bodovi>=0 && mirza_bodovi<55) mirza_pao=1;
	else if(mirza_bodovi>=55 && mirza_bodovi<65) mirza_ocjena=6;
	else if(mirza_bodovi>=65 && mirza_bodovi<75) mirza_ocjena=7;
	else if(mirza_bodovi>=75 && mirza_bodovi<85) mirza_ocjena=8;
	else if(mirza_bodovi>=85 && mirza_bodovi<92) mirza_ocjena=9;
	else if(mirza_bodovi>=92 && mirza_bodovi<=100) mirza_ocjena=10;
	
	if(tarik_pao==1 && bojan_pao==1 && mirza_pao==1) printf("Nijedan student nije polozio.");
	else if((tarik_pao!=1 && bojan_pao==1 && mirza_pao==1) || (tarik_pao==1 && bojan_pao!=1 && mirza_pao==1) || (tarik_pao==1 && bojan_pao==1 && mirza_pao!=1))
	printf("Jedan student je polozio.");
	else if((tarik_pao==1 && bojan_pao!=1 && mirza_pao!=1) || (tarik_pao!=1 && bojan_pao==1 && mirza_pao!=1) || (tarik_pao!=1 && tarik_pao!=1 && mirza_pao==1))
	printf("Dva studenta su polozila.");
	else if(tarik_pao!=1 && bojan_pao!=1 && mirza_pao!=1)
	{
		printf("Sva tri studenta su polozila.\n");
		if(tarik_ocjena==bojan_ocjena && bojan_ocjena==mirza_ocjena && tarik_ocjena==mirza_ocjena) printf("Sva tri studenta imaju istu ocjenu.");
		else if((tarik_ocjena==bojan_ocjena && tarik_ocjena!=mirza_ocjena && bojan_ocjena!=mirza_ocjena) || (bojan_ocjena==mirza_ocjena && bojan_ocjena!=tarik_ocjena
		&& mirza_ocjena!=tarik_ocjena) || (tarik_ocjena==mirza_ocjena && tarik_ocjena!=bojan_ocjena && mirza_ocjena!=bojan_ocjena))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if(tarik_ocjena!=bojan_ocjena && bojan_ocjena!=mirza_ocjena && mirza_ocjena!=tarik_ocjena) printf("Svaki student ima razlicitu ocjenu.");
	}

	return 0;
}
