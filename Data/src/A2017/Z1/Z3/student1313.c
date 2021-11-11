#include <stdio.h>

int main() {
	printf("Zadaća 1, Zadatak 3");
	return 0;
}

#include <stdio.h>
#include <math.h>
#define EPSILON 0.001
int main() {
	double a,b,c,D,x1,x2,br1,br2,t1=0,t2=0;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	
	D=b*b-4*a*c;
	/*printf("%f",D);*/
	if (D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	
		x1=(-b-sqrt(D))/(2*a);
		x2=(-b+sqrt(D))/(2*a);
	/*printf("x1=%f x2=%f",x1,x2);*/
	if (x1<=x2)
	{
		t1=x1;
		t2=x2;
	}
	else if (x1>=x2)
	{
		t1=x2;
		t2=x1;
	}
	
	while(1)
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&br1);
		if (fabs(t1-br1)<EPSILON)
		{
			printf("Tacno\n");
			break;
		}
		else if (t1>br1 && fabs(t1-br1)>=0.1)
			printf("Manje\n");
		else if (t1<br1 && fabs(t1-br1)>=0.1)
			printf("Vece\n");
		else if (fabs(t1-br1)<0.1 && t1>br1)
			printf("Priblizno manje\n");
		else if (fabs(t1-br1)<0.1 && t1<br1)
			printf("Priblizno vece\n");
	}

	while(1)
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&br2);
		if (fabs(t2-br2)<EPSILON)
		{
			printf("Tacno\n");
			break;
		}	
		else if (t2>br2 && fabs(t2-br2)>=0.1)
			printf("Manje\n");
		else if (t2<br2 && fabs(t2-br2)>=0.1)
			printf("Vece\n");
		else if (fabs(t2-br2)<0.1 && t2>br2)
			printf("Priblizno manje\n");
		else if (fabs(t2-br2)<0.1 && t2<br2)
			printf("Priblizno vece\n");
	
	
	}
	
	return 0;
}