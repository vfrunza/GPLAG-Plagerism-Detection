#include <stdio.h>
#include <math.h>
int main() {
	double a,b,c,x1,x2,e=0.001,n1,n2;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	if(b*b-4*a*c<0){
		printf("Rjesenja su imaginarni brojevi."); 
		return 0;
		
	}
	if(b<0){
	x1=(-b-sqrt(b*b-4*a*c))/(2*a);
	x2=(-b+sqrt(b*b-4*a*c))/(2*a);
	}
	if(b>=0){
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	}
	do
	{
		
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&n1);
		double broj=n1;
		int br=0,br1=0;
		while(0==0)
	{
		broj*=10000;
		int broj1=broj;
		if(broj1<=0) broj1*=(-1);
		if(broj1%10>=5){if(br=1; break;}
		else  break;
	}
	while(0==0)
	{
		if((fabs(x1)-fabs(n1))*1000>=0){br1=1; break;}
		else if((fabs(x1)-fabs(n1))*1000<=0){br1=1; break;}
		else break;
	}
		if(n1==x1 || br1==1 && br==1){ printf("Tacno\n"); break;}
		if(fabs(n1-x1)<0.1 && n1>x1 && fabs(n1-x1)>e) printf("Priblizno vece\n");
		else if(fabs(n1-x1)<0.1 && n1<x1) printf("Priblizno manje\n");
		else if(n1<x1) printf("Manje\n");
		else if(n1>x1) printf("Vece\n");
		
	}while(0==0);
	do
	{
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&n2);
		double broj1=n2;
		int br2=0,br3=0;
		while(0==0)
	{
		broj1*=10000;
		int broj2=broj1;
		if(broj2<=0) broj2*=(-1);
		if(broj2%10>=5){br2=1; break;}
		else  break;
	}
	while(0==0)
	{
		if((fabs(x2)-fabs(n2))*1000>=0){br3=1; break;}
		else if((fabs(x2)-fabs(n2))*1000<=0){br3=1; break;}
		else break;
	}
		if(n2==x2 || br3==1 && br2==1){ printf("Tacno\n"); break;}
		if(fabs(n2-x2)<0.1 && n2>x2 && fabs(n2-x2)>e) printf("Priblizno vece\n");
		else if(fabs(n2-x2)<0.1 && n2<x2) printf("Priblizno manje\n");
		else if(n2<x2) printf("Manje\n");
		else if(n2>x2) printf("Vece\n");
	}while(0==0);
	
	return 0;
}
