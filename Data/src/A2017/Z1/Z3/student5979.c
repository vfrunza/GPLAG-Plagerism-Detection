#include <stdio.h>
#include <math.h>
#define E 0.001

int main() {
	double a,b,c,d,e,f,x1,x2,sw,e1,e2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	
	if(d<0)
		{printf("Rjesenja su imaginarni brojevi.");
		 return 0;	
		}
		x1=(-b-sqrt(d))/(2.00*a);
		x2=(-b+sqrt(d))/(2.00*a);
		if(x1>x2) {
			sw=x1;
			x1=x2;
			x2=sw;}
			
	
	do
	{	printf("Unesite rjesenje x1: ");
		scanf("%lf",&e);
	
		if(e-x1<E && e-x1>-E){ 
			printf("Tacno\n");
			break;
		}
		if (e-x1<0.1 && e-x1>=E) 
			printf("Priblizno vece\n"); 
		else if(x1-e<0.1 && x1-e>=E)
			printf("Priblizno manje\n");
		else if(e-x1>=0.1) 
			printf ("Vece\n");
		else 
			printf("Manje\n");
	}while(e>=x1+E || e<=x1-E);
	
	do{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&f);
		
		if(f-x2<E && f-x2>-E){
			printf("Tacno\n");
		 	break;
		}
		if(f-x2<0.1 && f-x2>=E) 
			printf("Priblizno vece\n");
		else if(x2-f<0.1 && x2-f>=E) 
			printf("Priblizno manje\n");
		else if(f-x2>=0.1) 
			printf("Vece\n");
		else
			printf("Manje\n");
		}while (f>=x2+E || f<=x2-E );
					
	
	
		
	return 0;
}
