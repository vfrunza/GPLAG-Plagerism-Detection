#include<stdio.h>
#include<math.h>
#define eps 0.001
int main() {
	double a,b,c,x_1,x_2,d,rj_1,rj_2,tmp;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf", &a,&b,&c);
	d=b*b-4*a*c;
	if(d<0)  {
		printf("Rjesenja su imaginarni brojevi.");
		return 0;
	}
	x_1=(-b-sqrt(d))/(2*a);
	x_2=(-b+sqrt(d))/(2*a);
	if(x_1>x_2) {
		tmp=x_1;
		x_1=x_2;
		x_2=tmp;
	}
	do {
		printf("Unesite rjesenje x1: ");
		scanf("%lf",&rj_1);
		if(fabs(rj_1-x_1)<eps) printf("Tacno\n");
		else if(rj_1<x_1 && fabs(rj_1-x_1)>=0.1) printf("Manje\n");
		else if(rj_1>x_1 && fabs(rj_1-x_1)>=0.1) printf("Vece\n");
		else if(fabs(rj_1-x_1)<0.1 && rj_1<x_1) printf("Priblizno manje\n");
		else if(fabs(rj_1-x_1)<0.1 && rj_1>x_1) printf("Priblizno vece\n");
	} while(fabs(rj_1-x_1)>=eps);
	do {
		printf("Unesite rjesenje x2: ");
		scanf("%lf",&rj_2);
		if(fabs(rj_2-x_2)<eps) printf("Tacno\n");
		else if((rj_2<x_2  || fabs(rj_2)<x_2) && fabs(rj_2-x_2)>=0.1) printf("Manje\n");
		else if((rj_2>x_2 || fabs(rj_2)<x_2)&& fabs(rj_2-x_2)>=0.1) printf("Vece\n");
		else if(fabs(rj_2-x_2)<0.1 && rj_2<x_2) printf("Priblizno manje\n");
		else if(fabs(rj_2-x_2)<0.1 && rj_2>x_2) printf("Priblizno vece\n");
	} while(fabs(rj_2-x_2)>=eps);
	return 0;
}
