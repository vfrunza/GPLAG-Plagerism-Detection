#include <stdio.h>

#include <math.h>
#define E 0.001
#define E2 0.1
int main() {
	double x1,x2,a,b,c,diskriminanta,r1,r2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	diskriminanta=b*b-4*a*c;
	if (diskriminanta<0) printf("Rjesenja su imaginarni brojevi.");
	else
	{
		r1=(-b+sqrt(diskriminanta))/(2*a);
		r2=(-b-sqrt(diskriminanta))/(2*a);
		do
		{
			printf("Unesite rjesenje x1: ");
			scanf("%lf",&x1);
			if (fabs(r1-x1)<E) printf("Tacno\n");
			else if (x1<r1 && fabs (x1-r1)>=E2) printf("Manje\n");
			else if (x1>r1 && fabs(x1-r1)>=E2) printf("Vece\n");
			
			else {
				if (fabs(r1-x1)<E2 && r1-x1<0)
					printf ("Priblizno vece\n");
				else 
					printf ("Priblizno manje\n");
			}
		}while (fabs(x1-r1)>E);
		do
		{
			printf("Unesite rjesenje x2: ");
			scanf("%lf",&x2);
			if (fabs(r2-x2)<E) printf("Tacno\n");
			else if (x2<r2) printf("Manje\n");
			else if (x2>r2) printf("Vece\n");
			else if (fabs(r2-x2)<0.1) printf("Priblizno manje\n");
			else {
				if (fabs(r1-x1)<E2 && r1-x1<0)
					printf ("Priblizno vece\n");
				else 
					printf ("Priblizno manje\n");
			}
		}while (fabs(x2-r2)>E);
	}
	return 0;
}

