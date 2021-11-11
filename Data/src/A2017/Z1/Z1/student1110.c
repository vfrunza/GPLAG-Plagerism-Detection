#include <stdio.h>
#define p1 6.80
#define p2 8.00
#define p3 5.30
#define h1 3.30
#define h2 3.00
#define h3 5.00
#define c1 5.00
#define c2 3.90
#define c3 6.00

int main() 
{
	char T, M, B, red;
	float s=0, s1=0;
	int i=0;
	
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &T);
	scanf("%c", &red);
	
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &B);
	scanf("%c", &red);
	
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &M);
	scanf("%c", &red);
	
	if(T=='P' && M=='P' && B=='P')
	{
		s=p3+p3+p3;
		s1=p1+p1+p1-3*p1/10;
		i=3;
	}
	else if(T=='H' && M=='H' && B=='H')
	{
		s=h2+h2+h2;
		s1=h1+h1+h1-3*h1/10;
		i=2;
	}
	else if(T=='C' && M=='C' && B=='C') 
	{
		s=c2+c2+c2;
		s1=c1+c1+c1-3*c1/10;
		i=2;
	}
	else if((T=='P' && M=='P' && B=='H') || (T=='P' && M=='H' && B=='P') || (T=='H' && M=='P' && B=='P'))
	{
		s=p3+p3+h3;
		s1=p1+p1+h1-2*p1/10;
		i=3;
	}
	else if((T=='P' && M=='P' && B=='C') || (T=='P' && M=='C' && B=='P') || (T=='C' && M=='P' && B=='P'))
	{
		s=p3+p3+c3;
		s1=p1+p1+c1-2*p1/10;
		i=3;
	}
	else if((T=='P' && M=='H' && B=='H') || (T=='H' && M=='H' && B=='P') || (T=='H' && M=='P' && B=='H'))
	{
		s=h1+h1+p1;
		s1=s;
		i=1;
	}
	else if((T=='C' && M=='C' && B=='P') || (T=='C' && M=='P' && B=='C') || (T=='P' && M=='C' && B=='C'))
	{
		s=c2+c2+p2;
		s1=c1+c1+p1-2*c1/10;
		i=2;
	}
	else if((T=='C' && M=='C' && B=='H') || (T=='C' && M=='H' && B=='C') || (T=='H' && M=='C' && B=='C'))
	{
		s=c2+c2+h2;
		s1=c1+c1+h1-2*c1/10;
		i=2;
	}
	else if((T=='C' && M=='H' && B=='H') || (T=='H' && M=='H' && B=='C') || (T=='H' && M=='C' && B=='H'))
	{
		s=h2+h2+c2;
		s1=h1+h1+c1-2*h1/10;
		i=2;
	}
	else
	{
		s=p2+c2+h2;
		s1=p1+c1+h1-p1/10;
		i=2;
	}
	
	printf("Najjeftiniji je ");
	
	if(i==1) printf("Restoran \"Kod konja i konjusara\" (%.2f KM).", s);
	else if(i==2) printf("Fast-food \"Trovac\" (%.2f KM).", s);
	else if(i==3) printf("Bistro \"Lorelei\" (%.2f KM).", s);
	
	if(s1<s) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", s1);
	
	return 0;
}