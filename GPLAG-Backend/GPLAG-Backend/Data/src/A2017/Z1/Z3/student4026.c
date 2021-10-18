#include <stdio.h>
#include <math.h>
#define e 0.001
int main()
{
	double x1,x2,unos,temp;
	int D;
	int a,b,c;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%d %d %d",&a,&b,&c);
	D=b*b-4*a*c;
	if(D<0)
	{
		printf("Rjesenja su imaginarni brojevi.");
		return 1;
	}
	else if (D==0)
	{
		x1=(-b)/(2.*a);
		x2=x1;
	}
	else
	{
		x1=(-b-sqrt(D))/(2*a);
		x2=(-b+sqrt(D))/(2*a);
	}
	if(x1>x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
	}
	
	
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&unos);
	if(x1>(unos-e) && x1<(unos+e)) printf("Tacno\n");
	else if(fabs(unos-x1)<0.1 && unos<x1) printf("Priblizno manje\n");
	else if(fabs(unos-x1)<0.1 && unos>x1) printf("Priblizno vece\n");
	else if(unos>x1) printf("Vece\n");
	else if(unos<x1) printf("Manje\n");
	while(unos<=(x1-e) || unos>=(x1+e))
	{
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&unos);
		if(x1>(unos-e) && x1<(unos+e)) printf("Tacno\n");
		else if(fabs(unos-x1)<0.1 && unos<x1) printf("Priblizno manje\n");
		else if(fabs(unos-x1)<0.1 && unos>x1) printf("Priblizno vece\n");
		else if(unos>x1) printf("Vece\n");
		else if(unos<x1) printf("Manje\n");
	}
	
	
   	printf("Unesite rjesenje x2: ");
    scanf("%lf",&unos);
    if(x2>(unos-e) && x2<(unos+e)) printf("Tacno\n");
    else if(fabs(unos-x2)<0.1 && unos<x2) printf("Priblizno manje\n");
    else if(fabs(unos-x2)<0.1 && unos>x2) printf("Priblizno vece\n");
    else if(unos>x2) printf("Vece\n");
    else if(unos<x2) printf("Manje\n");
    while(unos<=(x2-e) || unos>=(x2+e))
    {
        printf("Unesite rjesenje x2: ");
        scanf("%lf",&unos);
        if(x2>(unos-e) && x2<(unos+e)) printf("Tacno\n");
        else if(fabs(unos-x2)<0.1 && unos<x2) printf("Priblizno manje\n");
        else if(fabs(unos-x2)<0.1 && unos>x2) printf("Priblizno vece\n");
        else if(unos>x2) printf("Vece\n");
        else if(unos<x2) printf("Manje\n");
    }
	return 0;
}

