#include <stdio.h>
#define PP 20.00
#define DP 20.00
#define P 10.00
#define Z 10.00
#define ZI 40.00
int main() 
{
	double tpp,tdp,tp,tz,tzi,tB,bpp,bdp,bp,bz,bzi,bB,mpp,mdp,mp,mz,mzi,mB,to,bo,mo;
	
	/*Tarik*/
	
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&tpp);
	if(tpp<0 || tpp>PP)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &tdp);
	if(tdp<0 || tdp>DP)
	{
		printf("Neispravan broj bodova");
		return 0;
		
	}
	
	
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if (tp<0 || tp>P)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf", &tz);
	if(tz<0 || tz>Z)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzi);
	if(tzi<0 || tzi>ZI)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	/*Bojan*/
	
	printf("Unesite bodove za Bojana: ");
	
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &bpp);
	if(bpp<0 || bpp>PP)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &bdp);
	if(bdp<0 || bdp>DP)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	printf("Prisustvo: ");
	scanf("%lf", &bp);
	if(bp<0 && bp>P)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	
	printf("Zadace: ");
	scanf("%lf", &bz);
	if(bz<0 && bz>Z)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzi);
	if(bzi<0 && bzi>ZI)
	{
		printf("Neispravan broj bodova");
		return 0;
	}

	 	
	
	
	
	
	/*Mikica*/
	
	printf("Unesite bodove za Mirzu: ");
	
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &mpp);
	if(mpp<0 || mpp>PP)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &mdp);
	if(mdp<0 || mdp>DP)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf", &mp);
	if(mp<0 || mp>P)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf", &mz);
	if(mz<0 || mz>Z)
	{
		printf("Neispravan broj bodova");
		return ;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &mzi);
	if(mzi<0 && mzi>ZI)
	{
		printf("Neispravan broj bodova");
		return 0;
	}
	
	tB=tpp+tdp+tp+tz+tzi;
	bB=bpp+bdp+bp+bz+bzi;
	mB=mpp+mdp+mp+mz+mzi;
	
	
	if(tB<55)
	{
		to=5;
	}
	if(tB>=55 && tB<65)
	{
		to=6;
	}
	 if(tB>=65 && tB<75)
	{
		to=7;
	}
	if(tB>=75 && tB<85)
	{
		to=8;
	}
	 if(tB>=85 && tB<92)
	{
		to=9;
	}
	if(tB>=92 && tB<=100)
	 {
	 	to=10;
	 }
	 
	 	if(bB<55)
	{
		bo=5;
	}
	if (bB>=55 && bB<65)
	{
		bo=6;
	}
	if(bB>=65 && bB<75)
	{
		bo=7;
	}
	if(bB>=75 && bB<85)
	{
		bo=8;
	}
	if(bB>=85 && bB<92)
	{
		bo=9;
	}
	if(bB>=92 && bB<=100)
	 {
	 	bo=10;
	 }
	 
	 	if(mB<55)
	{
		mo=5;
	}
	if(mB>=55 && mB<65)
	{
		mo=6;
	}
	if(mB>=65 && mB<75)
	{
		mo=7;
	}
	if(mB>=75 && mB<85)
	{
		mo=8;
	}
	if(mB>=85 && mB<92)
	{
		mo=9;
	}
	if(mB>=92 && mB<=100)
	 {
	 	mo=10;
	 }
	 
	 if((tB<55) && (bB<55) && (mB<55))
	 {
	 	printf("Nijedan student nije polozio.\n");
	 }
	 
	 if((tB>=55)&&(bB<55)&&(mB<55))
	 {
	  	printf("Jedan student je polozio.\n");
	 }
	 if((tB<55)&&(bB>=55)&&(mB<55))
	 {
	  	printf("Jedan student je polozio.\n");
	 }
	 
	 if ((tB<55)&&(bB<55)&&(mB>=55))
	 {
	  	printf("Jedan student je polozio.\n");
	 }
	 
	 if((tB>=55)&&(bB>=55)&&(mB<55))
	 {
	  	printf("Dva studenta su polozila.\n");
	 }
	 
	  if((tB<55)&&(bB>=55)&&(tB>=55))
	 {
	  	printf("Dva studenta su polozila.\n");
	 }
	 
	  if((tB>=55)&&(bB<55)&&(mB>=55))
	 {
	  	printf("Dva studenta su polozila.\n");
	 }
	 
	 if((tB>=55) && (bB>=55) && (mB>=55))
	 {
	 	printf("Sva tri studenta su polozila.\n");
	 
	
	 
	if((to==bo) && (to==mo) && (bo==mo))
	{
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	
	if((to==mo)&&(to!=bo))
	{
		printf("Dva od tri studenta su polozila");
	}
	
	if((to==bo) && (to!=mo))
	{
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}

	if((to!=bo) && (to!=mo) && (bo!=mo))
	{
		printf("Svaki student ima razlicitu ocjenu.\n");
	}
	 }
	
	
	
	 
	 return 0;
	 

	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
