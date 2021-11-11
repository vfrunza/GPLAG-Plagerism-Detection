#include <stdio.h>
#include <math.h>
#define e 0.001
int main() {
	double a,b,c,D,x,y,x1,x2,pom;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	D=((b*b)-(4*a*c));
	if(D<0) { printf("Rjesenja su imaginarni brojevi."); return 0; }
	x=(-b-(sqrt(D)))/(2*a);
	y=(-b+(sqrt(D)))/(2*a);
	if(x>y) 
	{
		pom=y;
		y=x;
		x=pom;
	}
	if(b==0&&c==0) { x=0; y=0; }
	do
	{
		int t,f;
		t=0; f=0;
	printf("Unesite rjesenje x1: ");
	scanf("%lf",&x1);
	if(fabs(x1-x)<e) { t=1; f=1; printf("Tacno\n"); }
	if((x1-x)>=0.1) { t=1; printf("Vece\n"); }
	if((x-x1)>=0.1) { f=1; printf("Manje\n"); }
	if(!fabs(x1-x)<e&&(x-x1)<0&&(x-x1)<0.1&&t==0) printf("Priblizno vece\n");
	if(!fabs(x1-x)<e&&(x-x1)>0&&(x1-x)<=0.1&&f==0) printf("Priblizno manje\n");
	}
	while(fabs(x1-x)>=e);
		do
	{
		int t1,f1;
		t1=0; f1=0;
	printf("Unesite rjesenje x2: ");
	scanf("%lf",&x2);
	if(fabs(x2-y)<e) { t1=1;f1=1; printf("Tacno\n"); }
	if((x2-y)>=0.1) { t1=1; printf("Vece\n"); }
	if((y-x2)>=0.1) { f1=1; printf("Manje\n"); }
	if(!fabs(x2-y)<e&&(y-x2)<0&&(y-x2)<0.1&&t1==0) printf("Priblizno vece\n");
	if(!fabs(x2-y)<e&&(y-x2)>0&&(x2-y)<=0.1&&f1==0) printf("Priblizno manje\n");
	}
	while(fabs(x2-y)>=e);
	return 0;
}

