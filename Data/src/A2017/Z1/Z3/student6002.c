#include <stdio.h>
#include<math.h>
#define E 0.001

int main() {
double a, b, c, D, x1, x2, rx1, rx2, o;
printf("Unesite koeficijente a, b i c: ");
scanf("%lf %lf %lf", &a, &b, &c);
D = sqrt(b*b-4*a*c);
if(D>=0){
	x2 =(double)(-b-D)/(2*a);
	x1 = (double)(-b+D)/(2*a);
	do{
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &rx1);
		o =  rx1 - x1;
		if ( o >= 0.1 )
			printf( "Vece\n" );
		else if ( o <=-0.1 )
			printf( "Manje\n" );
		else if ( o < 0.1 && o >= E )
			printf( "Priblizno vece\n" );
		else if ( o > -0.1 && o <= -E )
			printf( "Priblizno manje\n" );
		else break;
	}while( o>=E || o<=-E );
	printf ("Tacno\n");
	o=0;
	do{
		printf( "Unesite rjesenje x2: " );
		scanf("%lf", &rx2);
		o =  rx2 - x2;
		if(o>=0.1)
			printf("Vece\n");
		else if (o <=-0.1)
			printf("Manje\n");
		else if (o < 0.1 && o>=E)
			printf("Priblizno vece\n");
		else if (o > -0.1 && o<=-E)
		printf("Priblizno manje\n");
	}while(o>=E || o<=-E);
	printf("Tacno");
}
else printf("Rjesenja su imaginarni brojevi.");
	return 0;
}