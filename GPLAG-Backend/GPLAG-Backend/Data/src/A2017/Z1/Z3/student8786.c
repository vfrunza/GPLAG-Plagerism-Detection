#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define e1 0.001
#define e2 0.1



int main() {
	double a,b,c,d,mx1,mx2,x1,pv;
		printf("Unesite koeficijente a, b i c: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	if(a==1 && b==1 && c==1){
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
		d=b*b-4*a*c;
	 if(d>0){
	mx1=(-b+sqrt(d))/(2*a);
	mx2=(-b-sqrt(d))/(2*a);
	}
	else if(d==0)
	{
		mx1=-b/(2*a);
		mx2=mx1;
		
		}
		do{
			printf("Unesite rjesenje x1: ");
			scanf("°%f",&x1);
		}
		
		while(x1=mx1);

if(x1>mx1)
printf("Vece\n");

	else if(x1<mx1)
		printf("Manje\n");
		
if(fabs(mx1-x1)<e2)
	printf("Priblizno vece\n");
	
return 0;
}
