#include <stdio.h>

int main() {
	double t1,t2,tz,tp,ti,b1,b2,bz,bi,bp,m1,m2,mz,mp=0,mi, ts=0, bs=0, ms=0;
	int to=0,mo=0,bo=0,i=0;
	printf ("Unesite bodove za Tarika:\n");
	
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &t1);
	if (t1>20 || t1<0)
	{
	printf ("Neispravan broj bodova");
	return;
	}
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &t2);
	if (t2>20 || t2<0)
	{
	printf ("Neispravan broj bodova");
	return;
	}
	printf ("Prisustvo: ");
	scanf ("%lf", &tp);
	if (tp>10 || tp<0)
	{
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Zadace: ");
	scanf ("%lf", &tz);
	if (tz<0 || tz>10)
	{
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &ti);
    if (ti<0 || ti>40)
    {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Unesite bodove za Bojana:\n");
	
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &b1);
	if (b1<0 || b1>20)
    {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &b2);
	if (b2>20 || b2<0)
    {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Prisustvo: ");
	scanf ("%lf", &bp);
	if (bp>10 || bp<0)
    {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Zadace: ");
	scanf ("%lf", &bz);
	if (bz>10 || bz<0)
   {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &bi);
	if (bi>40 || bi<0)
   {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Unesite bodove za Mirzu:\n");

	printf ("I parcijalni ispit: ");
	scanf ("%lf", &m1);
	if (m1>20 || m1<0)
    {
	printf ("Neispravan broj bodova");
	return;
	}

	printf ("II parcijalni ispit: ");
	scanf ("%lf", &m2);
	if (m2<0 || m2>20)
    {
	printf ("Neispravan broj bodova");
	return;
	}

	printf ("Prisustvo: ");
	scanf ("%lf", &mp);
	if (mp <0 || mp >10)
    {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Zadace: ");
	scanf ("%lf", &mz);
	if (mz<0 || mz>10)
    {
	printf ("Neispravan broj bodova");
	return;
	}
	
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &mi);
	if (mi<0 || mi>40)
    {
	printf ("Neispravan broj bodova");
	return;
	}
    
   
	
	ts=t1+t2+tp+tz+ti;
	bs=b1+b2+bp+bz+bi;
	ms=m1+m2+mp+mz+mi;  
	
	
	if (ts<55) to=5;
	else 
		if (ts>=55 && ts <65) to=6;
	else
        if (ts>=65 && ts <75) to=7;
    else
    	if (ts>=75 && ts <85) to=8;
    else
    	if (ts>=85 && ts <92) to=9;
    else
    	if (ts>=92 && ts <=100) to=6;
    	
	if (bs <55) bo=5;
	else 
   		if (bs>=55 && bs <65) bo=6;
	else
        if (bs>=65 && bs <75) bo=7;
    else
    	if (bs>=75 && bs <85) bo=8;
    else
    	if (bs>=85 && bs <92) bo=9;
    else
    	if (bs>=92 && bs <=100) bo=6; 
    	
   	if(ms<55)
   		mo=5;
   	else 
   		if (ms>=55 && ms <65) mo=6;
	else
        if (ms>=65 && ms <75) mo=7;
    else
    	if (ms>=75 && ms <85) mo=8;
    else
    	if (ms>=85 && ms <92) mo=9;
    else
    	if (ms>=92 && ms <=100) mo=6;	
    	
    if (to==5 && mo==5 && bo==5)
    	printf("Nijedan student nije polozio.");
    else
    	if (to > 5 && mo > 5 && bo  > 5)
    	{
    		if(to == mo)
    			i++;
    		if(to == bo)
    			i++;
    		if(mo == bo)
    			i++;
    		
    		printf("Sva tri studenta su polozila.\n");
    		
    		if(i==3)
    			printf("Sva tri studenta imaju istu ocjenu.");
    		else
    			if (i==1)
    			printf("Dva od tri studenta imaju istu ocjenu.");
    		else
    			if(i==0)
    			printf("Svaki student ima razlicitu ocjenu.");
    			
    	}
    else
    	if((to == 5 && bo != 5 && mo != 5) || (to!=5 && bo==5 && mo !=5) || (to!=5 && bo!=5 && mo==5))
    		printf("Dva studenta su polozila.");
    else
    	if((to==5 && bo==5 && mo != 5) || (to==5 && bo!=5 && mo==5) || (to!=5 && bo==5 && mo==5))
    		printf("Jedan student je polozio.");
    
    
    
	return 0;
}
