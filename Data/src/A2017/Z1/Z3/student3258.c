#include <stdio.h>
#include <math.h>
#define eps 0.001

int main() {
	int a, b, c;

	double x1, x2, X1, X2, t, D,u;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d", &a, &b, &c);
	D=pow(b,2)-4*a*c;
	if(D<0) printf("Rjesenja su imaginarni brojevi.");
	else
	{
		do
		{
		D=pow(b,2)-4*a*c;
		t=sqrt(D);
		X1=(-b+t)/(2*a);
		
		printf("Unesite rjesenje x1: ");
		scanf("%lf", &x1);
		if(fabs(x1-X1)<eps )  {printf("Tacno\n"); break;} 
		else if(fabs(X1-x1)<0.1 && x1>X1) printf("Priblizno vece\n");
		else if(fabs(x1-X1)<0.1 && X1>x1) printf("Priblizno manje\n");
		
		else if(X1>x1) printf("Manje\n");

		else printf("Vece\n");
		}
		while(1!=0);
	
		
		do
		{
		D=pow(b,2)-4*a*c;	
		t=sqrt(D);
		X2=(-b-t)/(2*a);
		
		printf("Unesite rjesenje x2: ");
		scanf("%lf", &x2);
		if(fabs(x2-X2)<eps ){ printf("Tacno"); break;}  
		else if(fabs(X2-x2)<0.1 && x2>X2) printf("Priblizno vece\n");
		else if(fabs(x2-X2)<0.1 && X2>x2) printf("Priblizno manje\n");
		
		else if( X2>x2) printf("Manje\n");
	
		
		 else printf("Vece\n");
		
		}
		while(1!=0);
			
	}
	return 0;
	
}

