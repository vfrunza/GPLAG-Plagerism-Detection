#include <stdio.h>

int main() {
	double PPIST,PPISB,PPISM,DPIST,DPISB,DPISM,PT,PB,PM,DZT,DZB,DZM,ZIT,ZIB,ZIM,ZBT,ZBB,ZBM;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &PPIST);
	if(PPIST<0 || PPIST>20)
	{
		printf("Neispravan broj bodova");
	
		return 0;
	};
	printf("II parcijalni ispit: ");
	scanf("%lf",&DPIST);
	if(DPIST<0 || DPIST>20)
	{
		printf("Neispravan broj bodova");
		return 0;
	};
	printf("Prisustvo: ");
	scanf("%lf", &PT);
	if(PT<0 || PT>10)
	{ 
		printf("Neispravan broj bodova");
		return 0;
	};
	printf("Zadace: ");
	scanf("%lf", &DZT);
	if(DZT<0 || DZT>10)
	{
		printf("Neispravan broj bodova");
		return 0;
	};
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT);
	if(ZIT<0 || ZIT>40)
	{
		printf("Neispravan broj bodova");
		return 0;
	};
	ZBT=PPIST+DPIST+PT+DZT+ZIT;
	 printf("Unesite bodove za Bojana: \n");
	 printf("I parcijalni ispit: ");
	 scanf("%lf", &PPISB);
	 if(PPISB<0 || PPISB>20)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 
	 printf("II parcijalni ispit: ");
	 scanf("%lf", &DPISB);
	 if(DPISB<0 || DPISB>20)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 printf("Prisustvo: ");
	 scanf("%lf", &PB);
	 if(PB<0 || PB>10)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 printf("Zadace: ");
	 scanf("%lf", &DZB);
	 if(DZB<0 || DZB>10)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 printf("Zavrsni ispit: ");
	 scanf("%lf", &ZIB);
	 if(ZIB<0 || ZIB>40)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 ZBB=PPISB+DPISB+PB+DZB+ZIB;
	 printf("Unesite bodove za Mirzu: \n");
	 printf("I parcijalni ispit: ");
	 scanf("%lf", &PPISM);
	 if(PPISM<0 || PPISM>20)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 printf("II parcijalni ispit: ");
	 scanf("%lf", &DPISM);
	 if(DPISM<0 || DPISM>20)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 printf("Prisustvo: ");
	 scanf("%lf", &PM);
	 if(PM<0 || PM>10)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 
	 };
	 
	 
	 printf("Zadace: ");
	 scanf("%lf", &DZM);
	 if(DZM<0 || DZM>10)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 printf("Zavrsni ispit: ");
	 scanf("%lf", &ZIM);
	 if(ZIM<0 || ZIM>40)
	 {
	 	printf("Neispravan broj bodova");
	 	return 0;
	 };
	 ZBM=PPISM+DPISM+PM+DZM+ZIM;
	 
	 int TO,MO,BO;
	 if(ZBT<55)
	 {
	 	TO=5;
	 }
	 else if (ZBT>=55 && ZBT<65)
	 {
	 	TO=6;
	 }
	 else if(ZBT>=65 && ZBT<75)
	 {
	 	TO=7;
	 }
	 else if(ZBT>=75 && ZBT<85)
	 {
	 	TO=8;
	 }
	 else if(ZBT>=85 && ZBT<92)
	 {
	 	TO=9;
	 }
	 else if(ZBT>=92 && ZBT<=100)
	 {
	 	TO=10;
	 };
	 if(ZBM<55)
	 {
	 	MO=5;
	 }
	  else if(ZBM>=55 && ZBM<65)
	  {
	  	MO=6;
	  }
	 else if(ZBM>=65 && ZBM<75)
	 {
	 	MO=7;
	 }
	 else if(ZBM>=75 && ZBM<85)
	 {
	 	MO=8;
	 }
	 	else if(ZBM>=85 && ZBM<92)
	 	{
	 		MO=9;
	 	}
	else if(ZBM>=92 && ZBM<=100)
	{
		MO=10;
	};
	if(ZBB<55)
	{
		BO=5;
	}
	else if(ZBB>=55 && ZBB<65)
	{
		BO=6;
	}
	else if(ZBB>=65 && ZBB<75)
	{
		BO=7;
	}
	else if(ZBB>=75 && ZBB<85)
	{
		BO=8;
	}
	else if(ZBB>=85 && ZBB<92)
	{
		BO=9;
	}
	else if(ZBB>=92 && ZBB<=100)
	{
		BO=10;
	};
	if(TO==5 && MO==5 && BO==5)
	{
		printf("Nijedan student nije polozio.");
	};
	if((TO==5 && MO==5 && BO!=5)||(MO==5 && BO==5 && TO!=5)||(TO==5 && BO==5 && MO!=5))
	{
		printf("Jedan student je polozio.");
	};
	if((TO==5 && MO!=5 && BO!=5) || (BO==5 && MO!=5 && TO!=5)||(MO==5 && BO!=5 && TO!=5))
	{
		printf("Dva studenta su polozila.");
	}
	if(TO!=5 && BO!=5 && MO!=5)
	{
		printf("Sva tri studenta su polozila.\n");
	
	if(MO==BO && BO==TO)
	{
		printf("Sva tri studenta imaju istu ocjenu.");
	};
	if((MO==BO && MO!=TO)||(MO==TO && MO!=BO)||(TO==BO && TO!=MO))
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	};
	if(MO!=BO && BO!=TO)
	{
		printf("Svaki student ima razlicitu ocjenu.\n");
	};
	};/*
	do 55 bodova - student pao
	[55,65) bodova-ocjena 6
	[65,75) bodova-ocjena 7
	[75,85) bodova-ocjena 8
	[85,92) bodova-ocjena 9
	[92,100]bodova-ocjena 10 */
	

	return 0;
}






















