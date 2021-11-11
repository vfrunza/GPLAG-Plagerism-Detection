#include <stdio.h>
#include <math.h>

int main() {
int D;
int a,b,c;
float x1, x2;
float rezultat1,rezultat2;
printf("Unesite koeficijente a, b i c: ");
scanf("%d %d %d", &a, &b, &c);

D=b*b-4*a*c;
if(D<0) 
{
	printf("Rjesenja su imaginarni brojevi.");
	return 0;
}

rezultat1=(-b-sqrt(D))/2*a;
rezultat2=(-b+sqrt(D))/2*a;

while(1)
{
	printf("Unesite rjesenje x1: ");
	scanf("%f", &x1);
	
	if(fabs(rezultat1-x1)<=0.001) {printf("Tacno\n");break;}
	
		else if(x1-rezultat1<0.001 && x1-rezultat1>0) printf("Priblizno manje\n");
		else if(x1-rezultat1>0.001 && x1-rezultat1<0.01) printf("Priblizno vece\n");
	
	else if(rezultat1<x1) printf("Vece\n");
	else if(rezultat1>x1) printf("Manje\n");

}		
	
while(1)
{
	printf("Unesite rjesenje x2: ");
	scanf("%f", &x2);
	
	if(fabs(rezultat2-x2)<=0.001) {printf("Tacno\n");break;}
	
		else if(fabs(x2-rezultat2)<0.001 && fabs(x2-rezultat2)<1) printf("Priblizno vece\n");
		else if(fabs(x2-rezultat2)>0.001 && fabs(x2-rezultat2)<1) printf("Priblizno manje\n");
	
	else if(rezultat2<x2) printf("Vece\n");
	else if(rezultat2>x2) printf("Manje\n");
}		
	
return 0;
}
