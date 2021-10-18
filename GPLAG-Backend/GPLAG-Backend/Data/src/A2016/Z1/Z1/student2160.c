#include <stdio.h>
#include <math.h>

int main() {
	double t1,t2,t3,t4,t5,b1,b2,b3,b4,b5,x1,x2,x3,x4,x5,t,b,m;
	int  ocjenaT,ocjenaB,ocjenaM;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&t1);
	if(t1<0 || t1>20) { printf("Neispravan broj bodova\n");
						return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf",&t2);
	if(t2<0 || t2>20) { printf("Neispravan broj bodova\n");
						return 0;}
	printf("Prisustvo: ");
	scanf("%lf",&t3);
	if(t3<0 || t3>10) { printf("Neispravan broj bodova\n");
						return 0; }
	printf("Zadace: ");
	scanf("%lf",&t4);
	if(t4<0 || t4>10) { printf("Neispravan broj bodova\n");
						return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf",&t5);
	if(t5<0 || t5>40) { printf("Neispravan broj bodova\n");
						return 0; }
	
	
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&b1);
	if(b1<0 || b1>20) { printf("Neispravan broj bodova\n");
						return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf",&b2);
	if(b2<0 || b2>20) { printf("Neispravan broj bodova\n");
						return 0; }
	printf("Prisustvo: ");
	scanf("%lf",&b3);
		if(b3<0 || b3>10)
	{ printf("Neispravan broj bodova\n");
						return 0; }
	printf("Zadace: ");
	scanf("%lf",&b4);
		if(b4<0 || b4>10)
	{ printf("Neispravan broj bodova\n");
						return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf",&b5);
		if(b5<0 || b5>40)
	{ printf("Neispravan broj bodova\n");
						return 0; }
			
		printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&x1);
	if(x1<0 || x1>20)   	{ printf("Neispravan broj bodova\n");
							return 0; }
	printf("II parcijalni ispit: ");
	scanf("%lf",&x2);
	if(x2<0 || x2>20)   	{ printf("Neispravan broj bodova\n");
							return 0; }
	printf("Prisustvo: ");
	scanf("%lf",&x3);
	if(x3<0 || x3>10)   	{ printf("Neispravan broj bodova\n");
							return 0; }
	printf("Zadace: ");
	scanf("%lf",&x4);
	if(x4<0 || x4>10)   	{ printf("Neispravan broj bodova\n");
							return 0; }
	printf("Zavrsni ispit: ");
	scanf("%lf",&x5);
	if(x5<0 || x5>40)   	{ printf("Neispravan broj bodova\n");
							return 0; }
	
	t=t1+t2+t3+t4+t5;
	b=b1+b2+b3+b4+b5;
	m=x1+x2+x3+x4+x5;

	if(t<55 && b<55 && m<55)
		 printf("Nijedan student nije polozio.\n");
	
	else if((t>=55 && b<55 && m<55) || (t<55 && b>=55 && m<55) || (t<55 && b<55 && m>=55)) printf("Jedan student je polozio.\n");
	else if((t>=55 && b>=55 && m<55) || (t<55 && b>=55 && m>=55) || (t>=55 && b<55 && m>=55))  printf("Dva studenta su polozila.\n");
	
	if(t<55 ) ocjenaT=5;
	else if (t>=55 && t<65) ocjenaT=6;
	else if (t>=65 && t<75) ocjenaT=7;
	else if (t>=75 && t<85) ocjenaT=8;
	else if (t>=85 && t<95) ocjenaT=9;
	else if (t>=95 && t<=100) ocjenaT=10;
	
	if (b<55)  ocjenaB=5;
	else if (b>=55 && b<65)  ocjenaB=6;
	else if (b>=65 && b<75)  ocjenaB=7;
	else if (b>=75 && b<85)  ocjenaB=8;
	else if (b>=85 && b<95)  ocjenaB=9;
	else if (b>=95 && b<=100) ocjenaB=10;
	
	
	if	(m<55) 	ocjenaM=5;
	else if(m>=55 && m<65)  	ocjenaM=6;
	else if(m>=65 && m<75)  	ocjenaM=7;
	else if(m>=75 && m<85) 	    ocjenaM=8;
	else if(m>=85 && m<95)  	ocjenaM=9;
	else if(m>=95 && m<=100)  	ocjenaM=10;
	
	 if(t>=55 && b>=55 && m>=55) 
	{ 	printf("Sva tri studenta su polozila.\n");
 		if((ocjenaT==ocjenaB) && (ocjenaB==ocjenaM)  && (ocjenaT==ocjenaM))  
			{  printf("Sva tri studenta imaju istu ocjenu.");} 
		else  if((ocjenaT!=ocjenaM) && (ocjenaB!=ocjenaM) &&(ocjenaT!=ocjenaB))  {
 		printf("Svaki student ima razlicitu ocjenu.\n");}
		else if(((ocjenaT==ocjenaB) && (ocjenaB!=ocjenaM)) || ((ocjenaT==ocjenaM) && (ocjenaT!=ocjenaB)) || ((ocjenaB==ocjenaM) && (ocjenaM!=ocjenaT))) 
			{ printf("Dva od tri studenta imaju istu ocjenu.\n");} 
	 }
	return 0;
}

