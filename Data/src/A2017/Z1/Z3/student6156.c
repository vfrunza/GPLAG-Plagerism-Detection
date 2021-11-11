#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	double t,a,b,c,x1,x2,xp2,xp1,D;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		
	}
	else 
	{
		xp1=(-b-sqrt(D))/(2*a);
		xp2=(-b+sqrt(D))/(2*a);
		t=xp1;
		if(xp1>xp2)
		{
			xp1=xp2;
			xp2=t;
			
		}
		///racunanje 
		
		do{
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1);
			
			if(fabs(xp1-x1)<e)
			{
				printf("Tacno\n");break;//ako je rjesenje tacno prekidam petlju 
				
			}
			else if(fabs(xp1-x1)<100*e && fabs(xp1-x1)>=e && xp1>x1)
			{
				printf("Priblizno manje\n");
				
			}
			else if(fabs(xp1-x1)<100*e && fabs(xp1-x1)>=e && xp1<x1)
			{
				printf("Priblizno vece\n");
				
			}
			else if(x1>xp1)
			{
				printf("Vece\n");
			}
			else
			{
				printf("Manje\n");
			}
			
		}while(1);
		
		
	do{
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&x2);
			if(fabs(xp2-x2)<e)
			{
				printf("Tacno\n");
				break;
			}
			else if (fabs(xp2-x2)<100*e && fabs(xp2-x2)>=e && xp2>x2)
			{
				printf("Priblizno manje\n");
			}
			else if (fabs(xp2-x2)<100*e && fabs(xp2-x2)>=e && xp2<x2)
			{
				printf("Priblizno vece\n");
			}
			else if(x2>xp2)
			{
				printf("Vece\n");
			}
			else
			{
				printf("Manje\n");
			}
			
		}while(1);
		
		
		
		
	}
	return 0;
}
