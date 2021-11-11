#include <stdio.h>
#include <math.h>
#define E1 0.001
#define E2 0.1
#define E3 -0.001
#define E4 -0.1
int main() {
	double a,b,c;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf", &a,&b,&c);
	double D=0;
	D=pow(b,2)-4.0*a*c;
	
	if(D<0) {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	double xp=0, xo=0;
	xp=(-b + sqrt(pow(b,2) - 4.0 * a * c))/(2.*a); /* prvo rjesenje jednacine*/ 
	xo=(-b - sqrt(pow(b,2) - 4.0 * a * c))/(2.*a); /* drugo rjesenje jednacine*/ 
	
	double x1=0,x2=0;
	
	do{
		printf("Unesite rjesenje x1: "); /* x1-Prvo rjesenje koje unosi korisnik*/ 
		scanf("%lf", &x1);
		if((x1-xp>=E1) && (x1-xp<E2)) {
			printf("Priblizno vece\n");
		} else if ((x1-xp<=E3) && (x1-xp>E4)) {
			printf("Priblizno manje\n");
		} if (x1-xp<=E4) 
			printf("Manje\n");
		  if (x1-xp>=E2)
		  printf("Vece\n");
		} while ((fabs(x1-xp)>=E1));
		if (fabs(x1-xp)<E1)
		printf ("Tacno\n");
		
		do{
		printf("Unesite rjesenje x2: "); 
		scanf("%lf", &x2);
		if((x2-xo>=E1) && (x2-xo<E2)) {
			printf("Priblizno vece\n");
		} else if ((x2-xo<=E3) && (x2-xo>E4)) {
			printf("Priblizno manje\n");
		} if (x2-xo<=E4) 
			printf("Manje\n");
		  if (x2-xo>=E2)
		  printf("Vece\n");
		} while ((fabs(x2-xo)>=E1));
		if (fabs(x2-xo)<E1)
		printf ("Tacno\n");
		
		return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
