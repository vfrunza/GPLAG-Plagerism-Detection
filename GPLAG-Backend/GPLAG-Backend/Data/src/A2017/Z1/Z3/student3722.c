#include <stdio.h>
#include <math.h>
#define EPS 0.001

int main() {
	double a, b, c, x1, x2, rj1=0, rj2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	rj1+=(-b+sqrt(b*b-4*a*c))/(2*a);
	rj2+=(-b-sqrt(b*b-4*a*c))/(2*a);
	
	/* Imaginarni brojevi */
	
	if((b*b-4*a*c)<0)
	printf("Rjesenja su imaginarni brojevi.");
	else
	{
	
		/* Slucajevi za x1 */ 
	
	do 
	{
	printf("Unesite rjesenje x1: ");
	scanf("%lf", &x1); 
	
	if(fabs(rj1-x1)<0.1 && fabs(rj1-x1)>=EPS && x1>rj1) 
	printf("Priblizno vece\n");
	
	else if(fabs(rj1-x1)<0.1 && fabs(rj1-x1)>=EPS && x1<rj1) 
	printf("Priblizno manje\n");
	
	else if(fabs(rj1-x1)>=0.1 && x1>rj1) 
    printf("Vece\n");
	
	else if(fabs(rj1-x1)>=0.1 && x1<rj1) 
	printf("Manje\n");
	
    }
	while(fabs(rj1-x1)>=EPS);
	printf("Tacno\n");


    	/* Slucajevi za x2 */
	
	do
	{
	printf("Unesite rjesenje x2: ");
    scanf("%lf", &x2); 
	
    if(fabs(rj2-x2)<0.1 && fabs(rj2-x2)>=EPS && x2>rj2) 
    printf("Priblizno vece\n");
    
	if (fabs(rj2-x2)<0.1 && fabs(rj2-x2)>=EPS && x2<rj2) 
	printf("Priblizno manje\n");
		    
	if(fabs(rj2-x2)>=0.1 && x2>rj2) 
    printf("Vece\n");
	
	if(fabs(rj2-x2)>=0.1 && x2<rj2) 
	printf("Manje\n");
	}
    while(fabs(rj2-x2)>=EPS);
    printf("Tacno\n");
	}


	return 0;
}
