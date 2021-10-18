#include <stdio.h>
#include <math.h>
#define  e 0.001

int main() {
	double d,a,b,c,x1s,x2s,x1,x2,t;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	if(d<0)
	{ 
		printf("Rjesenja su imaginarni brojevi.");
	return 0;
	}
	
	x1s=(-b-sqrt(d))/(2*a);
	x2s=(-b+sqrt(d))/(2*a);
	if(x1s>x2s){
		t=x1s;
		x1s=x2s;
		x2s=t;
	}

	
	do {	
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&x1);
	
	if(fabs(x1-x1s)<e)
	printf("Tacno\n");
	
	else if (x1<=x1s-0.1)
	printf("Manje\n");
	
	else if(x1>=x1s+0.1){
	printf("Vece\n");}
	
	else if (x1>=x1s+e)
	printf("Priblizno vece\n");
	
	else if(x1<=x1s-e)
	printf("Priblizno manje\n");
	}
	while(fabs(x1-x1s)>=e);

	do{
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&x2);
	
	if(fabs(x2-x2s)<e)
	printf("Tacno\n");
	
	
	else if (x2<=x2s-0.1)
	printf("Manje\n");
	
	else if (x2>=x2s+0.1)
	printf("Vece\n");
	
	else if(x2>=x2s+e)
	printf("Priblizno vece\n");
	
	else if(x2<=x2s-e)
	printf("Priblizno manje\n");
	}
	while(fabs(x2-x2s)>=e);

	return 0;
}
