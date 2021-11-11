#include <stdio.h>
#include <math.h>
#define epsilon1 0.001
#define epsilon2 0.1

int main() {
	float a,b,c,diskriminanta,x1,x2,unesi_x1,unesi_x2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f %f %f",&a,&b,&c);
	
	diskriminanta = b*b - 4*a*c;
	x1 = (((b*(-1)) + (sqrt(diskriminanta))) / 2*a);
	x2 = (((b*(-1)) -  (sqrt(diskriminanta))) / 2*a);
	
	if(diskriminanta < 0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	do
	{
		printf("Unesite rjesenje x1:");
		scanf("%f",&unesi_x1);
		if(fabs(unesi_x1 - x1) < epsilon1)
		{
			printf(" Tacno\n");
			break;
		}
		else if(((x1 - unesi_x1) < epsilon2)  && ((x1 - unesi_x1) > 0))
		{
			printf(" Priblizno manje\n");
		}
		else if(((x1-unesi_x1) < 0)  && ((x1 - unesi_x1)> -epsilon2))
		{
			printf(" Priblizno vece\n");
		}
		else if(unesi_x1 > x1)
		{
			printf(" Vece\n");
		}
		else if(unesi_x1 < x1)
		{
			printf(" Manje\n");
		}
	} while(1);
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%f",&unesi_x2);
		if(fabs(unesi_x2 - x2) < epsilon1)
		{
			printf("Tacno\n");
			break;
		}
		else if(((x2 - unesi_x2) < 0) && ((x2 - unesi_x2) > -epsilon2))
		{
			printf(" Priblizno vece\n");
		}
		else if(((x2 - unesi_x2) < epsilon2) && ((x2 - unesi_x2) > 0))
		{
			printf(" Priblizno manje\n");
		}
		else if(unesi_x2 < x2)
		{
			printf("Manje\n");
		}
		else if(unesi_x2 > x2)
		{
			printf("Vece\n");
		}
	} while(1);
	return 0;
}
