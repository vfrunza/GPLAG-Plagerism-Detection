#include <stdio.h>
#include <math.h>

int main() {
	
	double tp1,tp2,tp,tz,tzav,tuk;
	double bp1,bp2,bp,bz,bzav,buk;
	double mp1,mp2,mp,mz,mzav,muk;
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&tp1);
	if(tp1<0 || tp1>20) 
	{ printf ("Neispravan broj bodova");
	return 0;}
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &tp2);
	if(tp2<0 || tp2>20)
	{ printf("Neispravan broj bodova");
	return 0; }
	
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if(tp<0 || tp>10)
	{ printf("Neispravan broj bodova");
	return 0; }
	
	printf("Zadace: ");
	scanf("%lf", &tz);
	if(tz<0 || tz>10)
	{ printf("Neispravan broj bodova");
	return 0; }
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzav);
	if(tzav<0 || tzav>40)
	{ printf ("Neispravan broj  bodova");
	return 0; }
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&bp1);
	if(bp1<0 || bp1>20)
	{printf ("Neispravan broj bodova");
	return 0; }
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &bp2);
	if(bp2<0 || bp2>40)
	{ printf ("Neispravan broj bodova");
	return 0; }
	
	printf("Prisustvo: ");
	scanf("%lf",&bp);
	if(bp<0 || bp>10) 
	{ printf("Neispravan broj bodova");
	return 0; }
	
	printf("Zadace: ");
	scanf("%lf", &bz);
	if(bz<0 || bz>10)
   {	printf("Neispravan broj bodova");
   return 0; }
   
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzav);
	if(bzav<0 || bzav>40)
	{printf("Neispravan broj bodova");
	return 0; }
	
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&mp1);
	if(mp1<0 || mp1>20)
	{ printf ("Neispravan broj bodova");
	return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf",&mp2);
	if(mp2<0 || mp2>20)
	{ printf("Neispravan broj bodova");
	return 0; }
	printf("Prisustvo: ");
	scanf("%lf", &mp);
	if(mp<0 || mp>10)
	{printf("Neispravan broj bodova");
	return 0; }
	printf("Zadace: ");
	scanf("%lf", &mz);
	if(mz<0 || mz>10)
	{ printf("Neispravan broj bodova");
	return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf",&mzav);
	if(mzav<0 || mzav>40)
	{printf ("Neispravan broj bodova");
	return 0; }
	
	tuk=tp1+tp2+tp+tz+tzav;
	buk=bp1+bp2+bp+bz+bzav;
	muk=mp1+mp2+mp+mz+mzav;

	 if (fabs(tuk-55>0) && (buk-55<0) && (muk-55<0))
	printf("Jedan student je polozio.\n"); 
    else if ((fabs(buk-55)<0.001 || buk-55>0) && (fabs(tuk-55<0.001 || tuk-55>0) && (muk-55<0)))
	printf("Dva studenta su polozila.\n"); 
    else if ((fabs(muk-55)<0.001 || muk-55>0) && (fabs(tuk-55<0.001 || tuk-55>0) && (fabs(buk-55<0.001 || buk-55>0))))
	printf("Sva tri studenta su polozila.\n"); 
	else printf("Nijedan student nije polozio.");
	
	int tk,bk,mk;
	if(fabs(tuk-92) || tuk>92)
    tk=(tuk+8)/10;
	else tk=(tuk+5)/10;
	
	
	if(fabs(buk-92) || buk>92)
   	bk=(buk+8)/10;
    else bk=(buk+5)/10;
	
	if(fabs(muk-92) || muk>92)
  	mk=(muk+8)/10;
	else mk=(muk+5)/10;
	
	if(tk==bk && bk!=mk && tk!= mk)
	printf("Dva od tri studenta imaju istu ocjenu.");
	if(tk==mk && tk!=bk && mk!=bk)
	printf("Dva od tri studenta imaju istu ocjenu.");
	if(bk==mk && bk!=mk && tk!=mk)
	printf("Dva od tri studenta imaju istu ocjenu");
	if(tk==bk && bk==mk && tk==mk)
	printf("Sva tri studenta imaju istu ocjenu.");
	else (tk!=bk && bk!=mk && tk!=mk);
	printf("Svaki student ima razlicitu ocjenu.");
	
	return 0;
}
